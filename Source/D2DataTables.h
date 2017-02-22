/********************************************************
*	D2DataTables.h										*
*														*
*	Same deal as D2Structs.h except it's meant			*
*	to declare all txt file structs. There are			*
*	a lot of them and I always thought that having		*
*	them in a separated declaration file helped with	*
*	the organization									*
*														*
*********************************************************/

#pragma pack(1)

///////////////////
// DECLARATIONS ///
///////////////////

struct D2ItemsTXT;

//////////////////
// DEFINITIONS ///
//////////////////

struct D2ItemsTXT
{
	char szFlippyFile[32];			//0x000
	char szInvFile[32];				//0x020
	char szUniqueInvFile[32];		//0x040
	char szSetInvFile[32];			//0x060
	union							//0x080
	{
		DWORD dwCode;
		char szCode[4];
	};
	DWORD dwNormCode;				//0x084
	DWORD dwUberCode;				//0x088
	DWORD dwUltraCode;				//0x08C
	DWORD dwAlternateGfx;			//0x090
	DWORD dwPspell;					//0x094
	WORD nState;					//0x098
	WORD nCurseState[2];			//0x09A
	WORD nStat[3];					//0x09E
	DWORD dwCalc[3];				//0x0A4
	DWORD dwLen;					//0x0B0
	WORD nSpellDesc;				//0x0B4
	WORD nSpellDescStr;				//0x0B6
	DWORD dwSpellDescCalc;			//0x0B8
	DWORD dwBetterGem;				//0x0BC
	DWORD dwWeapClass;				//0x0C0
	DWORD dwWeapClass2Hand;			//0x0C4
	DWORD dwTransmogrifyCode;		//0x0C8
	DWORD dwMinAc;					//0x0CC
	DWORD dwMaxAc;					//0x0D0
	DWORD dwGambleCost;				//0x0D4
	DWORD dwSpeed;					//0x0D8
	DWORD dwBitField1;				//0x0DC
	DWORD dwCost;					//0x0E0
	DWORD dwMinStack;				//0x0E4
	DWORD dwMaxStack;				//0x0E8
	DWORD dwSpawnStack;				//0x0EC
	DWORD dwGemOffset;				//0x0F0
	WORD nNameStr;					//0x0F4
	WORD nVersion;					//0x0F6
	WORD nAutomod;					//0x0F8
	WORD nMissileType;				//0x0FA
	BYTE nRarity;					//0x0FC
	BYTE nLevel;					//0x0FD
	BYTE nMinDam;					//0x0FE
	BYTE nMaxDam;					//0x0FF
	BYTE nMinMisDam;				//0x100
	BYTE nMaxMisDam;				//0x101
	BYTE n2HandMinDam;				//0x102
	BYTE n2HandMaxDam;				//0x103
	WORD nRangeAdder;				//0x104
	WORD nStrBonus;					//0x106
	WORD nDexBonus;					//0x108
	WORD nReqStr;					//0x10A
	WORD nReqDex;					//0x10C
	BYTE nAbsorb;					//0x10E
	BYTE nInvWidth;					//0x10F
	BYTE nInvHeight;				//0x110
	BYTE nBlock;					//0x111
	BYTE nDurability;				//0x112
	BYTE nNoDurability;				//0x113
	BYTE nMissile;					//0x114
	BYTE nComponent;				//0x115
	BYTE nArmorComp[6];				//0x116
	BYTE n2Handed;					//0x11C
	BYTE nUseable;					//0x11D
	WORD nType;						//0x11E
	WORD nType2;					//0x120
	WORD nSubType;					//0x122
	WORD nDropSound;				//0x124
	WORD nUseSound;					//0x126
	BYTE nDropSfxFrame;				//0x128
	BYTE nUnique;					//0x129
	BYTE nQuest;					//0x12A
	BYTE nQuestDiffCheck;			//0x12B
	BYTE nTransparent;				//0x12C
	BYTE nTransTbl;					//0x12D
	BYTE __12E;						//0x12E
	BYTE nLightRadius;				//0x12F
	BYTE nBelt;						//0x130
	BYTE nAutoBelt;					//0x131
	BYTE nStackable;				//0x132
	BYTE nSpawnable;				//0x133
	BYTE nSpellIcon;				//0x134
	BYTE nDurWarning;				//0x135
	BYTE nQuantityWarning;			//0x136
	BYTE nHasInv;					//0x137
	BYTE nGemSockets;				//0x138
	BYTE nTransmogrify;				//0x139
	BYTE nTmogMin;					//0x13A
	BYTE nTmogMax;					//0x13B
	BYTE nHitClass;					//0x13C
	BYTE n1or2Handed;				//0x13D
	BYTE nGemApplyType;				//0x13E
	BYTE nLevelReq;					//0x13F
	BYTE nMagicLevel;				//0x140
	BYTE nTransform;				//0x141
	BYTE nInvTrans;					//0x142
	BYTE nCompactSave;				//0x143
	BYTE nSkipName;					//0x144
	BYTE nNameable;					//0x145
	BYTE nMerchantMin[17];			//0x146
	BYTE nMerchantMax[17];			//0x157
	BYTE nMerchantMagicMin[17];		//0x168
	BYTE nMerchantMagicMax[17];		//0x179
	BYTE nMerchantMagicLvl[18];		//0x18A
	DWORD dwNightmareUpgrade;		//0x19C
	DWORD dwHellUpgrade;			//0x1A0
	BYTE nPermStoreItem;			//0x1A4
	BYTE nMultiBuy;					//0x1A5
	WORD __1A6;						//0x1A6
};

#pragma pack()