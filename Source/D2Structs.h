#ifndef D2STRUCTS_H__
#define D2STRUCTS_H__

/********************************************
*	D2Structs.h								*
*											*
*	This file is meant to declare structs	*
*	of the game, all in one file. Keep it	*
*	organized to simplify your life. Keep	*
*	the structs inalphabetical order and	*
*	give self descriving names to the		*
*	structs and their memebers				*
*											*
*********************************************/

#include "D2DataTables.h"
#include "D2PacketDef.h"

#pragma pack(1)

///////////////////
// DECLARATIONS ///
///////////////////

struct D2InventoryStrc;
struct D2ItemDataStrc;
struct D2UnitStrc;
struct StatListEx;
struct StatEx;
struct Stat;

//////////////////
// DEFINITIONS ///
//////////////////

struct D2InventoryStrc
{
	BYTE _1[0x28];
	DWORD dwItemCount;
};

struct D2ItemDataStrc
{
	DWORD dwQuality;
};

struct D2UnitStrc
{
	DWORD dwUnitType;
	DWORD dwClass;
	void* pMemoryPool;
	DWORD dwGUID;
	DWORD dwMode;
	D2ItemDataStrc* pItemData;
	BYTE _1[0x44];
	StatListEx* pStatsEx;
	D2InventoryStrc* pInventory;
};

struct Stat // size 0x8
{
	WORD wSubIndex;					//0x00
	WORD wStatIndex;				//0x02
	DWORD dwStatValue;				//0x04
};

struct StatEx	//size 0x8
{
	Stat* pStat;					//0x00 An Array[wStatCount]
	WORD wStatCount;				//0x04
	WORD wnBitSize;					//0x06
};

struct StatListEx  //size 0x64
{
	BYTE _1[0x24];
	StatEx BaseStats;
};

#pragma pack()
#endif