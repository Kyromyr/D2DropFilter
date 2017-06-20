#include "DLLmain.h"
#include <string>
#include "..\Lua\excludes.cpp"

BOOL __fastcall DROPFILTER_Main(D2UnitStrc* pItem)
{
	if (pItem == NULL || pItem->pItemData == NULL)
		return FALSE;

	if (GetAsyncKeyState(VK_CONTROL) & 0x8000)
		return TRUE;

	// Filled sockets
	if (pItem->pInventory != NULL && pItem->pInventory->dwItemCount > 0)
		return TRUE;

	DWORD dwQuality = pItem->pItemData->dwQuality;
	// UNIQUE, SET, CRAFTED, HONORIFIC
	if (dwQuality == 7 || dwQuality == 5 || dwQuality == 8 || dwQuality == 9)
		return TRUE;

	D2ItemsTXT* pItemTxt = D2COMMON_GetItemTxtRecord(pItem->dwClass);
	if (pItemTxt == NULL){ return FALSE; }

	DWORD dwCode = CODE32(pItemTxt->dwCode);

	if (dwCode == 'gld ' && pItem->pStatsEx != NULL && pItem->pStatsEx->BaseStats.pStat != NULL && pItem->pStatsEx->BaseStats.pStat->dwStatValue < 2000)
		return FALSE; // Gold stacks below 2,000
	else if (dwQuality == 4 && (dwCode == 'rin ' || dwCode == 'amu '))
		return FALSE; // Magic rings and amulets
	else if (dwQuality <= 4 && (dwCode == 'aqv ' || dwCode == 'cqv '))
		return FALSE; // White and magic quivers
	else if (excludes[pItem->dwClass])
		return FALSE;

	return TRUE;
}