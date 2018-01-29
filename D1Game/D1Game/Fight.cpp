#include "Fight.h"
#include <time.h>



Fight::Fight()
{
	this->player = Pokemon();
	this->enemy = Pokemon();
	this->fighting = true;
}


Fight::~Fight()
{
}

Fight::Fight(Pokemon& player, Pokemon& enemy) {
	this->player = player;
	this->enemy = enemy;
	this->fighting = true;
}

int Fight::useAbility1(Pokemon& dealer, Pokemon& receiver) { //Ability 1 used
	int damage;
	int abilityStamina = dealer.getAbility1().getStamina();
	int stamina = dealer.getStamina();
	if (stamina >= abilityStamina) { //If enough stamina to perform the attack
		dealer.removeStamina(abilityStamina);
		damage = calculateDamage(dealer.getAbility1(), dealer, receiver);
		receiver.receiveDmg(damage);
		if (receiver.getHP() == 0) { //If attack was the killing blow
			declareWinner(dealer);
		}
	}
	return damage;
}
int Fight::useAbility2(Pokemon& dealer, Pokemon& receiver) { //Ability 2 used
	int damage;
	int abilityStamina = dealer.getAbility2().getStamina();
	int stamina = dealer.getStamina();
	if (stamina >= abilityStamina) { //If enough stamina to perform the attack
		dealer.removeStamina(abilityStamina);
		damage = calculateDamage(dealer.getAbility2(), dealer, receiver);
		receiver.receiveDmg(damage);
		if (receiver.getHP() == 0) { //If attack was the killing blow
			declareWinner(dealer);
		}
	}
	return damage;
}
int Fight::useAbility3(Pokemon& dealer, Pokemon& receiver) { //Ability 3 used
	int damage;
	int abilityStamina = dealer.getAbility3().getStamina();
	int stamina = dealer.getStamina();
	if (stamina >= abilityStamina) { //If enough stamina to perform the attack
		dealer.removeStamina(abilityStamina);
		damage = calculateDamage(dealer.getAbility3(), dealer, receiver);
		receiver.receiveDmg(damage);
		if (receiver.getHP() == 0) { //If attack was the killing blow
			declareWinner(dealer);
		}
	}
	return damage;
}
void Fight::declareWinner(Pokemon& winner) { // When other pokemon's HP is 0

}
int Fight::calculateDamage(Ability ability, Pokemon& dealer, Pokemon& receiver) {
	srand(time(NULL));
	int str = dealer.getStrength()/100 + 1; // Strength 0-100. Damage modifier. 20 - Adds 20% to damage.
	int agi = dealer.getAgility(); 
	int isWeak = (dealer.getType()==receiver.getWeakness()) ? 1 : 0; // Add 50% to damage is enemy is weak against your type
	int miss = ((rand() % 100 + 1) < agi) ? 1 : 0; // Agility 0-100% how often will the attack miss. 0 - always miss, 100 - never miss.
	int dmg = ability.getDamage();

	int damage = miss * ((str*dmg) - (rand() % 5)) + (isWeak * str*dmg);
	return damage;
}
void Fight::doDmg(Pokemon pokemon) {
	enemy.gainExp(15);
}
