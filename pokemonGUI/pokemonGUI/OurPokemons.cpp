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
	"water", "earth", "Pictures/catter.gif",
	Ability("Scratch", 10, 0),
	Ability("Meow", 20, 20),
	Ability("Tail Whip", 45, 55) };


Pokemon Zizi{ "Zizi", 1, 0, 20, 80, 50, 50, 80,
	"water", "wind", "Pictures/zizi.gif",
	Ability("Nut throw", 17, 0),
	Ability("Bite", 27, 20),
	Ability("Hurricane", 55, 50) };

Pokemon Pyro{ "Pyro", 1, 0, 18, 70, 80, 80, 90,
"water", "fire", "Pictures/pyro.gif",
Ability("Slash", 10, 0),
Ability("Ember", 30, 20),
Ability("Flameball", 60, 50) };

Pokemon Lemongrass{ "Lemongrass", 1, 0, 17, 65, 75, 75, 95,
"fire", "grass", "Pictures/lemongrass.gif",
Ability("Scratch", 10, 0),
Ability("Tail whip", 25, 10),
Ability("Leaf bomb", 55, 45) };

Pokemon Thundershock{ "Thundershock", 1, 0, 20, 75, 80, 80, 90,
"earth", "electric", "Pictures/thundershock.gif",
Ability("Claw", 10, 0),
Ability("Bolt", 30, 0),
Ability("Lightiningblast", 60, 50) };
