#include "DLLmain.h"

__declspec (naked) void __stdcall PATCH_DropFilter()
{
	__asm
	{
		cmp dword ptr [esi], 0x04
		jnz EXIT

		mov ecx, esi
		call DROPFILTER_Main
		cmp eax, 0x00000000
		je EXIT

		jmp [D2CLIENT_6FB09087]

		EXIT:
		jmp [D2CLIENT_6FB09419]
	}
}