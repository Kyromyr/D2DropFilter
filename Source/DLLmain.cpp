#define VARS

#include "DLLmain.h"
#include "D2Patch.h"

static const int gnDllFiles = sizeof(gDllFiles) / sizeof(DllFile);

void __fastcall D2TEMPLATE_ErrorMessage(char* szMessage)
{
	MessageBox(NULL, szMessage, "D2Template", MB_OK | MB_ICONERROR);
	TerminateProcess(GetCurrentProcess(), -1);
}

int __fastcall D2TEMPLATE_ApplyPatch(void* hGame, const CodePatch* hPatch)
{
	while (hPatch->nDllFile != D2DLL_INVALID)
	{
		int nDll = hPatch->nDllFile;
		if (nDll < 0 || nDll >= gnDllFiles)
			return 0;

		DWORD nAddress = hPatch->nAdddress;
		if (gDllFiles[nDll].nRelocated == 1)
			nAddress = (nAddress - gDllFiles[nDll].nKnownAddress) + gDllFiles[nDll].nAddress;

		int nData = hPatch->nData;
		if (hPatch->nFixMe == 1)
			nData = nData - (nAddress + sizeof(nData));

		void* hAddress = (void*)nAddress;
		DWORD nOldPage;
		VirtualProtect(hAddress, sizeof(nData), PAGE_EXECUTE_READWRITE, &nOldPage);
		int nReturn = WriteProcessMemory(hGame, hAddress, &nData, sizeof(nData), 0);
		VirtualProtect(hAddress, sizeof(nData), nOldPage, 0);
		if (nReturn == 0)
			return 0;

		hPatch++;
	}

	return 1;
}

int __stdcall D2TEMPLATE_LoadModules()
{
	for (int i = 0; i < gnDllFiles; i++)
	{
		DllFile* hDllFile = gDllFiles + i;

		void* hModule = GetModuleHandle(hDllFile->szName);
		if (hModule == 0)
		{
			hModule = LoadLibrary(hDllFile->szName);
			if (hModule == 0)
				return 0;
		}

		hDllFile->hModule = hModule;
		unsigned long nAddress = (unsigned long)hModule;
		if (nAddress != hDllFile->nKnownAddress)
			hDllFile->nRelocated = 1;

		hDllFile->nAddress = nAddress;
	}

	return 1;
}

int __stdcall D2TEMPLATE_GetDebugPrivilege()
{
	void* hToken;
	LUID luid;
	TOKEN_PRIVILEGES tokenPrivileges;

	if (OpenProcessToken(GetCurrentProcess(), TOKEN_ALL_ACCESS, &hToken) == 0)
		return 0;

	if (LookupPrivilegeValue(0, SE_DEBUG_NAME, &luid) == 0)
	{
		CloseHandle(hToken);
		return 0;
	}

	tokenPrivileges.PrivilegeCount = 1;
	tokenPrivileges.Privileges[0].Attributes = SE_PRIVILEGE_ENABLED;
	tokenPrivileges.Privileges[0].Luid = luid;
	if (AdjustTokenPrivileges(hToken, 0, &tokenPrivileges, sizeof(tokenPrivileges), 0, 0) == 0)
	{
		CloseHandle(hToken);
		return 0;
	}

	CloseHandle(hToken);
	return 1;
}

int __stdcall DllAttach()
{
	D2TEMPLATE_GetDebugPrivilege();
	void* hGame = OpenProcess(PROCESS_ALL_ACCESS, FALSE, GetCurrentProcessId());
	if (hGame == 0)
		return 0;

	if (D2TEMPLATE_LoadModules() == 0)
	{
		CloseHandle(hGame);
		return 0;
	}

	D2TEMPLATE_ApplyPatch(hGame, gCodePatches);

	CloseHandle(hGame);

	return 1;
}

int __stdcall DllMain(void* hModule, unsigned long nReason, void* hReserved)
{
	switch (nReason)
	{
	case DLL_PROCESS_ATTACH:
		DllAttach();
		break;
	}

	return 1;
}