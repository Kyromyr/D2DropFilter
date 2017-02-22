/************************************************
*	D2Ptrs.h									*
*												*
*	This file is meant to declare various		*
*	pointer types used by the game, to use		*
*	in your custom code							*
*												*
*	As always, keep this file well organized.	*
*	Keep functions ordered by address, or by	*
*	ordinals if one exists. Also keep pointers	*
*	of the same dll grouped together			*
*												*
*************************************************/

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

/////////////////////////
// DEFINITIONS MACROS ///
/////////////////////////

#define D2FUNC(DLL, NAME, RETURN, CONV, ARGS, OFFSET) \
	typedef RETURN (##CONV##* DLL##_##NAME##_t ) ARGS; \
	static DLL##_##NAME##_t DLL##_##NAME = (DLL##_##NAME##_t )( DLLBASE_##DLL + OFFSET);

#define D2VAR(DLL, NAME, TYPE, OFFSET) \
	typedef TYPE DLL##_##NAME##_vt; \
	static DLL##_##NAME##_vt* DLL##_##NAME = (DLL##_##NAME##_vt *)( DLLBASE_##DLL + OFFSET);

#define D2PTR(DLL, NAME, OFFSET) \
	static DWORD NAME = (DLLBASE_##DLL + OFFSET);

///////////////////
// D2CLIENT.DLL ///
///////////////////

D2FUNC(D2CLIENT, GetItemName, BOOL, __stdcall, (D2UnitStrc*, wchar_t*, size_t), 0x914F0)	//D2Client.0x914F0(D2UnitStrc* pItem, wchar_t* wszBuffer, size_t nBufferSize);

D2PTR(D2CLIENT, D2CLIENT_6FB09419, 0x59419)		//return bad
D2PTR(D2CLIENT, D2CLIENT_6FB09087, 0x59087)		//return good

///////////////////
// D2COMMON.DLL ///
///////////////////

D2FUNC(D2COMMON, GetItemTxtRecord, D2ItemsTXT*, __stdcall, (DWORD), 0x719A0)

/////////////////
// D2LANG.DLL ///
/////////////////

D2FUNC(D2LANG, GetStringFromIndex, const wchar_t*, __fastcall, (WORD), 0x9450)