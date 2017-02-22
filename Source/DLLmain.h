#define WIN32_LEAN_AND_MEAN
#define _CRT_SECURE_NO_DEPRECATE
#define _WIN32_WINNT 0x600

#include <windows.h>
#include <cstdlib>

#include "D2Vars.h"
#include "D2Structs.h"
#include "D2Constants.h"
#include "D2Ptrs.h"

#include "TemplateIncludes.h"

enum D2DLLS
{
	D2DLL_D2CLIENT,
	D2DLL_D2CMP,
	D2DLL_D2COMMON,
	D2DLL_D2GAME,
	D2DLL_D2GFX,
	D2DLL_D2LANG,
	D2DLL_D2LAUNCH,
	D2DLL_D2NET,
	D2DLL_D2SOUND,
	D2DLL_D2WIN,
	D2DLL_FOG,
	D2DLL_STORM,
	D2DLL_BNCLIENT,
	D2DLL_INVALID,
};

struct DllFile
{
	char* szName;
	void* hModule;
	int nRelocated;
	DWORD nAddress;
	DWORD nKnownAddress;
};

struct CodePatch
{
	int nDllFile;
	DWORD nAdddress;
	DWORD nData;
	int nFixMe;
};

#define DLLBASE_BNCLIENT		(DWORD)LoadLibraryA("Bnclient.dll")
#define DLLBASE_D2CLIENT		(DWORD)LoadLibraryA("D2Client.dll")
#define DLLBASE_D2CMP			(DWORD)LoadLibraryA("D2CMP.dll")
#define DLLBASE_D2COMMON		(DWORD)LoadLibraryA("D2Common.dll")
#define DLLBASE_D2DDRAW			(DWORD)LoadLibraryA("D2DDraw.dll")
#define DLLBASE_D2DIRECT3D		(DWORD)LoadLibraryA("D2Direct3D.dll")
#define DLLBASE_D2GAME			(DWORD)LoadLibraryA("D2Game.dll")
#define DLLBASE_D2GDI			(DWORD)LoadLibraryA("D2Gdi.dll")
#define DLLBASE_D2GFX			(DWORD)LoadLibraryA("D2Gfx.dll")
#define DLLBASE_D2GLIDE			(DWORD)LoadLibraryA("D2Glide.dll")
#define DLLBASE_D2LANG			(DWORD)LoadLibraryA("D2Lang.dll")
#define DLLBASE_D2LAUNCH		(DWORD)LoadLibraryA("D2Launch.dll")
#define DLLBASE_D2MCPCLIENT		(DWORD)LoadLibraryA("D2MCPClient.dll")
#define DLLBASE_D2MULTI			(DWORD)LoadLibraryA("D2Multi.dll")
#define DLLBASE_D2NET			(DWORD)LoadLibraryA("D2Net.dll")
#define DLLBASE_D2SOUND			(DWORD)LoadLibraryA("D2Sound.dll")
#define DLLBASE_D2WIN			(DWORD)LoadLibraryA("D2Win.dll")
#define DLLBASE_FOG				(DWORD)LoadLibraryA("Fog.dll")
#define DLLBASE_STORM			(DWORD)LoadLibraryA("Storm.dll")
#define DLLBASE_IJL11			(DWORD)LoadLibraryA("ijl11.dll")
#define DLLBASE_BINKW32			(DWORD)LoadLibraryA("binkw32.dll")
#define DLLBASE_SMACKW32		(DWORD)LoadLibraryA("SmackW32.dll")
#define DLLBASE_PLUGY			(DWORD)LoadLibraryA("PlugY.dll")
#define DLLBASE_GLIDE3X			(DWORD)LoadLibraryA("glide3x.dll")

static DllFile gDllFiles[] =
{
	{"D2CLIENT.DLL",	0,	0,	0,	(DWORD)LoadLibraryA("D2Client.dll")},
	{"D2CMP.DLL",		0,	0,	0,	(DWORD)LoadLibraryA("D2CMP.dll")},
	{"D2COMMON.DLL",	0,	0,	0,	(DWORD)LoadLibraryA("D2Common.dll")},
	{"D2GAME.DLL",		0,	0,	0,	(DWORD)LoadLibraryA("D2Game.dll")},
	{"D2GFX.DLL",		0,	0,	0,	(DWORD)LoadLibraryA("D2Gfx.dll")},
	{"D2LANG.DLL",		0,	0,	0,	(DWORD)LoadLibraryA("D2Lang.dll")},
	{"D2LAUNCH.DLL",	0,	0,	0,	(DWORD)LoadLibraryA("D2Launch.dll")},
	{"D2NET.DLL",		0,	0,	0,	(DWORD)LoadLibraryA("D2Net.dll")},
	{"D2SOUND.DLL",		0,	0,	0,	(DWORD)LoadLibraryA("D2Sound.dll")},
	{"D2WIN.DLL",		0,	0,	0,	(DWORD)LoadLibraryA("D2Win.dll")},
	{"FOG.DLL",			0,	0,	0,	(DWORD)LoadLibraryA("Fog.dll")},
	{"STORM.DLL",		0,	0,	0,	(DWORD)LoadLibraryA("Storm.dll")},
};