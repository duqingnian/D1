#include "Pokemon.h"


/* These are guidlines on how you create your pokemon
Pokemon(name, level,
		exp, strength, agility,
		hp, maxHP, maxStamina,
		weakness, type,
		pictureFileName,
		ability1,
		ability2,
		ability3);
		*/
Pokemon Catter{ "Catter", 1, 0, 12, 40, 90, 90, 100,
	"water", "earth", "Pictures/cat.txt",
	{ {"name","Scratch"},{"damage","10"},{"stamina","0"} },
	{ { "name","Meow" },{ "damage","20" },{ "stamina","20" } },
	{ { "name","Tail Whip" },{ "damage","45" },{ "stamina","55" } } };

Pokemon Zizi{ "Zizi", 1, 0, 20, 80, 50, 50, 80,
"fire", "wind", "Pictures/zizi.txt",
{ { "name","Nut throw" },{ "damage","17" },{ "stamina","0" } },
{ { "name","Bite" },{ "damage","27" },{ "stamina","20" } },
{ { "name","Hurricane" },{ "damage","55" },{ "stamina","50" } } };
