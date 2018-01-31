#include "Pokemon.h"


/* These are guidlines on how you create your pokemon
Pokemon{name, level,
		exp, strength, agility,
		hp, maxHP, maxStamina,
		weakness, type,
		pictureFileName,
		ability1(name, damage, stamina),
		ability2(name, damage, stamina),
		ability3(name, damage, stamina)};
		*/
Pokemon Catter{ "Catter", 1, 0, 12, 60, 90, 90, 100,
	"water", "earth", "Pictures/cat.txt",
	Ability("Scratch", 10, 0),
	Ability("Meow", 20, 20),
	Ability("Tail Whip", 45, 55) };


Pokemon Zizi{ "Zizi", 1, 0, 20, 80, 50, 50, 80,
	"water", "wind", "Pictures/zizi.txt",
	Ability("Nut throw", 17, 0),
	Ability("Bite", 27, 20),
	Ability("Hurricane", 55, 50) };