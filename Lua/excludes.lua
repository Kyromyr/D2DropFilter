local f = io.open("items.txt", "rb");

local gemTypes = {Amethyst=1, Topaz=1, Sapphire=1, Emerald=1, Ruby=1, Diamond=1, Skull=1, Onyx=1, Bloodstone=1, Turquoise=1, Amber=1, ["Rainbow Stone"]=1};
local gemGrades = {Chipped=1,Flawed=2,[""]=3,Flawless=4,Perfect=5};

local itemType, code, hex, name, rune, gemGrade, gemType;

local readable = {};
local output = {};

for line in f:lines() do
	code, name = line:match("%[.?(....)%] <(.*)>");
	if (code and name) then
		hex = string.format("'%s'", code);
		rune = tonumber(code:match("r(%d%d) "));
		
		gemGrade, gemType = name:match("^(%w+) (.+)$");
		if (not gemGrade or not gemGrades[gemGrade]) then
			gemGrade = "";
			gemType = name;
		end
		gemGrade = gemGrades[gemGrade];
		
		if ((itemType ~= "misc" and name:match"%(%d%)$") -- Non-sacred equipment
			or (rune and rune < 18) -- Runes below Ko
			or (gemTypes[gemType] and gemGrade and gemGrade < 4) -- Gems below Flawless
			or name == "Mystic Orb" -- Worse than trash
			or (code:match("hp%d ") or code:match("mp%d ")) -- Health and mana potions
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
