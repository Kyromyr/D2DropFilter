local f = io.open("items.txt", "rb");

local gemTypes = {Amethyst=1, Topaz=1, Sapphire=1, Emerald=1, Ruby=1, Diamond=1, Skull=1, Onyx=1, Bloodstone=1, Turquoise=1, Amber=1, ["Rainbow Stone"]=1};
local gemGrades = {Chipped=1,Flawed=2,[""]=3,Flawless=4,Perfect=5};

local hide, itemType, code, name, rune, pot, gemGrade, gemType;

local readable = {};
local output = {};
local class = 0;

for line in f:lines() do
	code, name = line:match"%[%d+%:.?(....)%] <(.*)>";
	if (code and name) then
		hide = 0;
		
		local tmp = {
			"^(Amethyst|Topaz|Sapphire|Emerald|Ruby|Diamond|Skull|Onyx|Bloodstone|Turquoise|Amber|Rainbow Stone)$",
			"^Flawless",
			"Minor",
			"Light|Light",
			"Mana Potion",
			"^Key$",
			"^(El|Eld|Tir|Nef|Eth|Ith|Tal|Ral|Ort|Thul|Amn|Sol|Shael|Dol|Hel|Io|Lum|Ko|Fal|Lem|Pul|Mal|Ist|Gul|Vex|Ohm|Lo|Sur|Ber|Jah|Cham|Zod) Rune$",
		};
		
		for i = 1, #tmp do
			if (name:match(tmp[i])) then
				table.insert(readable, line);
				hide = 1;
			end
		end
		
		table.insert(output, hide);
		class = class + 1;
	else
		code = line:match"{(%w+)}";
		itemType = code or itemType;
	end
end
f:close();

f = io.open("excludes-readable.txt", "w+b");
f:setvbuf"no";
f:write(table.concat(readable, "\r\n"));
f:flush();
f:close();

f = io.open("excludes.cpp", "w+b");
f:setvbuf"no";
f:write("char excludes[] = { ", table.concat(output, ","), " };");
f:flush();
f:close();
