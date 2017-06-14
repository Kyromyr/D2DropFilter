local f = io.open("items.txt", "rb");

local gemTypes = {Amethyst=1, Topaz=1, Sapphire=1, Emerald=1, Ruby=1, Diamond=1, Skull=1, Onyx=1, Bloodstone=1, Turquoise=1, Amber=1, ["Rainbow Stone"]=1};
local gemGrades = {Chipped=1,Flawed=2,[""]=3,Flawless=4,Perfect=5};

local itemType, code, hex, name, rune, pot, gemGrade, gemType;

local readable = {};
local output = {};

for line in f:lines() do
	code, name = line:match"%[.?(....)%] <(.*)>";
	if (code and name) then
		hex = string.format("'%s'", code);
		rune = tonumber(code:match"r(%d%d) ");
		pot = tonumber(code:match"hp(%d) ");

		gemGrade, gemType = name:match"^(%w+) (.+)$";
		if (not gemGrade or not gemGrades[gemGrade]) then
			gemGrade = "";
			gemType = name;
		end
		gemGrade = gemGrades[gemGrade];
		
		if ((itemType ~= "misc" and name:match"%(%d%)$") -- Non-sacred equipment
			or (rune and rune < 34) -- cLOD runes
			or (gemTypes[gemType] and gemGrade and gemGrade < 6) -- All gems
			or (pot and pot < 4) -- Health potions below Greater
			or code:match"mp%d " -- Mana potions
			or code == "tsc " or code == "isc " or code == "key " or code == "tbk " or code == "ibk " -- TP/ID scrolls and tomes, keys
			or code == "ey2 " or code == "ey3 " or code == "et1 " -- Elixirs of Experience, Greed & Concentration
			) then
			table.insert(readable, line);
			table.insert(output, hex);
		end
	else
		code = line:match"{(%w+)}";
		itemType = code or itemType;
	end
end
f:close();

f = io.open("output-readable.txt", "w+b");
f:setvbuf"no";
f:write(table.concat(readable, "\r\n"));
f:flush();
f:close();

f = io.open("output.txt", "w+b");
f:setvbuf"no";
f:write("DWORD excludes[] = { ", table.concat(output, ","), " };");
f:flush();
f:close();
