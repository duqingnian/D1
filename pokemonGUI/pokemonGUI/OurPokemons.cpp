#include "Pokemon.h"
#include "OurPokemons.h"


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

Pokemon Wail{ "Wail", 1, 0, 19, 80, 80, 80, 90,
"electric", "water", "Pictures/Wail.gif",
Ability("Dash", 10, 0),
Ability("Ocean jet", 45, 20),
Ability("Tsunami blast", 60, 50) };

Pokemon Blaze{ "Blaze", 1, 0, 20, 75, 75, 75, 100,
"water", "fire", "Pictures/Blaze.gif",
Ability("Claw", 10, 0),
Ability("Ember", 30, 20),
Ability("Sun beam", 60, 50) };

Pokemon Flyff{ "Flyff", 1, 0, 17, 80, 87, 87, 90,
"water", "wind", "Pictures/Flyff.gif",
Ability("Flap", 18, 0),
Ability("Bite", 27, 20),
Ability("Tornado", 60, 55) };

Pokemon Jolt{ "Jolt", 1, 0, 18, 80, 70, 70, 100,
"earth", "electric", "Pictures/Jolt.gif",
Ability("Slash", 10, 0),
Ability("Shock", 25, 10),
Ability("Lightning blast", 55, 40) };

Pokemon Treehouse{ "Treehouse", 1, 0, 20, 85, 100, 100, 80,
"water", "earth", "Pictures/Treehouse.gif",
Ability("Smash", 10, 0),
Ability("Crush", 30, 10),
Ability("Earthquake", 80, 60) };

Pokemon Deeria{ "Deeria", 1, 0, 18, 80, 80, 80, 90,
"fire", "grass", "Pictures/Deeria.gif",
Ability("Lunge", 10, 0),
Ability("Sonic dash", 30, 10),
Ability("Nature horn", 50, 40) };

Pokemon Hydros{ "Hydros", 1, 0, 22, 90, 100, 100, 100,
"electric", "water", "Pictures/Hydros.gif",
Ability("Tailwhip", 20, 0),
Ability("Whirlpool", 40, 20),
Ability("Hydro blast", 80, 60) };

Pokemon Flop{ "Flop", 1, 0, 18, 70, 70, 70, 70,
"electric", "water", "Pictures/Flop.gif",
Ability("Flop", 10, 0),
Ability("Flop", 10, 0),
Ability("Flop", 10, 0) };


array<Pokemon*, 13> pokemonArray = { &Catter, &Zizi, &Pyro, &Lemongrass, &Thundershock, &Wail, &Blaze, &Flyff, &Jolt, &Treehouse, &Deeria, &Hydros, &Flop };