/********************************************
*	D2Patch.h								*
*											*
*	All patches are defined in this file.	*
*	As always try to keep it organized.		*
*	Keep patches that are done in the same	*
*	DLL grouped together, etc...			*
*											*
*********************************************/

static const CodePatch gCodePatches[] =
{
	{D2DLL_D2CLIENT,	DLLBASE_D2CLIENT+0x5907E,	(DWORD)0x000000E9,			0},
	{D2DLL_D2CLIENT,	DLLBASE_D2CLIENT+0x5907F,	(DWORD)PATCH_DropFilter,	1},

	{D2DLL_INVALID},	//Must be the last entry in the array!
};