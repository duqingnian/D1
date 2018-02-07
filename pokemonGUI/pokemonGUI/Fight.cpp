#include "Fight.h"
#include "Player.h"
#include <time.h>
#include "Game.h"


Fight::Fight() : player(Player()), pokemon(Pokemon()){
	this->enemy = Pokemon();
	this->fighting = true;
}
Fight::~Fight()
{
}

Fight::Fight(Player& playerIN, Pokemon& enemy) : player(playerIN), pokemon(playerIN.getPokemon()){
	this->enemy = enemy;
	this->fighting = true;
}

string Fight::useAbility1(Pokemon& dealer, Pokemon& receiver) { //Ability 1 used
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
		game.setEnemyTurn(true); //Time for enemy to attack back
		if (damage == 0) {
			return (dealer.getName() + " used " + dealer.getAbility1().getName() + ", but it missed.");
		}
		else {
			return (dealer.getName() + " used " + dealer.getAbility1().getName() + ", it did " + to_string(damage) + " damage.");
		}
	}
	return ("You don't have enough stamina for " + dealer.getAbility1().getName());
}
string Fight::useAbility2(Pokemon& dealer, Pokemon& receiver) { //Ability 2 used
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
		game.setEnemyTurn(true); //Time for enemy to attack back
		if (damage == 0) {
			return (dealer.getName() + " used " + dealer.getAbility2().getName() + ", but it missed.");
		}
		else {
			return (dealer.getName() + " used " + dealer.getAbility2().getName() + ", it did " + to_string(damage) + " damage.");
		}
	}
	return ("You don't have enough stamina for " + dealer.getAbility2().getName());
}
string Fight::useAbility3(Pokemon& dealer, Pokemon& receiver) { //Ability 3 used
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
		game.setEnemyTurn(true); //Time for enemy to attack back
		if (damage == 0) {
			return (dealer.getName() + " used " + dealer.getAbility3().getName() + ", but it missed.");
		}
		else {
			return (dealer.getName() + " used " + dealer.getAbility3().getName() + ", it did " + to_string(damage) + " damage.");
		}
	}
	return ("You don't have enough stamina for " + dealer.getAbility3().getName());
}
string Fight::declareWinner(Pokemon& winner) { // When other pokemon's HP is 0
	if (winner.getName() == this->pokemon.getName()) {
		game.getPlayer().addMoney(MONEY_FOR_WIN); //Updated in Fight.h
		winner.gainExp(EXPERIENCE_FOR_WIN); //Updated in Fight.h
		return ("You have beated " + this->enemy.getName() + " and earned yourself 100$");
	}
	else {
		return ("You lost to " + this->enemy.getName());
	}
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
string Fight::useHealthPotion() {
	if (game.getPlayer().getHealthPotions() > 0) {
		game.getPlayer().removeHealthPotion();
		game.getPlayer().getPokemon().heal(POTION_HEAL_AMOUNT); //Updated in Fight.h
		return("Health potion used.");
		game.setEnemyTurn(true); //Time for enemy to attack back
	}
	else {
		return("You're out of health potions.");
	}
}
string Fight::useStaminaPotion() {
	if (game.getPlayer().getStaminaPotions() > 0) {
		game.getPlayer().removeStaminaPotion();
		game.getPlayer().getPokemon().addStamina(POTION_HEAL_AMOUNT); //Updated in Fight.h
		return("Stamina potion used.");
		game.setEnemyTurn(true); //Time for enemy to attack back
	}
	else {
		return ("You're out of stamina potions.");
	}
}
