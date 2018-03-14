#include "OurWorlds.h"
#include "OurEnemies.h"


World world;
World World1;
World World2{ "map2", 2 , "./Maps/tree test.png" , 351 ,{ &Enemy4, &Enemy5, &Enemy6, &Enemy7 },{ &World1 }, 'l' };