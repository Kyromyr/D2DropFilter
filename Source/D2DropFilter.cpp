#include "DLLmain.h"
#include <string>

BOOL __fastcall DROPFILTER_Main(D2UnitStrc* pItem)
{
	if (pItem == NULL || pItem->pItemData == NULL)
		return FALSE;

	if (pItem->pInventory != NULL && pItem->pInventory->dwItemCount > 0) // Filled sockets
		return TRUE;

	if (pItem->pItemData->bEarLevel == 1) // Handled by d2stats
		return TRUE;

	return FALSE;
}