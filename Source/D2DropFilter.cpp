#include "DLLmain.h"
#include <string>
#include "..\Lua\excludes.cpp"

BOOL __fastcall DROPFILTER_Main(D2UnitStrc* pItem)
{
	if (pItem == NULL || pItem->pItemData == NULL)
		return FALSE;

	if (GetAsyncKeyState(VK_CONTROL) & 0x8000)
		return TRUE;

	DWORD dwQuality = pItem->pItemData->dwQuality;
	if (dwQuality == 8 || dwQuality == 9) // CRAFTED, HONORIFIC
		return TRUE;
	else if (pItem->pInventory != NULL && pItem->pInventory->dwItemCount > 0) // Filled sockets
		return TRUE;

	if (*D2CLIENT_UseNotifierSettings == 1)
		return pItem->pItemData->bEarLevel == 2; // Experimental, set by Drop Notifier

	// UNIQUE, SET
	if (dwQuality == 7 || dwQuality == 5)
		return TRUE;

	D2ItemsTXT* pItemTxt = D2COMMON_GetItemTxtRecord(pItem->dwClass);
	if (pItemTxt == NULL) { return FALSE; }

	DWORD dwCode = CODE32(pItemTxt->dwCode);

	if (dwCode == 'gld ' && pItem->pStatsEx != NULL && pItem->pStatsEx->BaseStats.pStat != NULL && pItem->pStatsEx->BaseStats.pStat->dwStatValue < 2000)
		return FALSE; // Gold stacks below 2,000
	else if (dwQuality == 4 && (dwCode == 'rin ' || dwCode == 'amu '))
		return FALSE; // Magic rings and amulets
	else if (dwQuality <= 4 && (dwCode == 'aqv ' || dwCode == 'cqv '))
		return FALSE; // White and magic quivers
	else if (pItem->dwClass < sizeof(excludes) && excludes[pItem->dwClass])
		return FALSE;

	return TRUE;
}