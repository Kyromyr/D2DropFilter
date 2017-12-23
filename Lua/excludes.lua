local f = io.open("items.txt", "rb");

local gemTypes = {Amethyst=1, Topaz=1, Sapphire=1, Emerald=1, Ruby=1, Diamond=1, Skull=1, Onyx=1, Bloodstone=1, Turquoise=1, Amber=1, ["Rainbow Stone"]=1};
local gemGrades = {Chipped=1,Flawed=2,[""]=3,Flawless=4,Perfect=5};

local hide, itemType, code, name, rune, pot, gemGrade, gemType;

local readable = {};
local output = {};
local class = 0;

for line in f:lines() do
	code, name = line:match"%[.?(....)%] <(.*)>";
	if (code and name) then
		hide = 0;
		
		rune = tonumber(code:match"r(%d%d) ");
		pot = tonumber(code:match"hp(%d) ");

		gemGrade, gemType = name:match"^(%w+) (.+)$";
		if (not gemGrade or not gemGrades[gemGrade]) then
			gemGrade = "";
			gemType = name;
		end
		gemGrade = gemGrades[gemGrade];
		
		if ((itemType ~= "misc" and name:match"%(%d%)$") -- Non-sacred equipment
			or (rune and rune < 34) -- cLOD runes (Zod and below)
			or (gemTypes[gemType] and gemGrade and gemGrade < 5) -- Gems below perfect
			or (pot and pot < 4) -- Health potions below Greater
			or code:match"mp%d " -- Mana potions
			or code == "tsc " or code == "isc " or code == "key " or code == "tbk " or code == "ibk " -- TP/ID scrolls and tomes, keys
			) then
			table.insert(readable, line);
			hide = 1;
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
