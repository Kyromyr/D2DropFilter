
#define REVERSE16(w)	( ( (  & 0xFF00) >> 8 ) | ( (  & 0x00FF) << 8 ) )
#define REVERSE32(dw)	( ( ((dw) & 0xFF000000) >> 24 ) | ( ((dw) & 0x00FF0000) >> 8 ) | ( ((dw) & 0x0000FF00) << 8 ) | ( ((dw) & 0x000000FF) << 24 ) )
#define CODE16(sz)		REVERSE16( ( ( const unsigned short)( (sz) ) ) )
#define CODE32(sz)		REVERSE32( ( ( const unsigned long )( (sz) ) ) )

BOOL __fastcall DROPFILTER_Main(D2UnitStrc* pItem);