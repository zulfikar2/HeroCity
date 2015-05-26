#ifndef BASESTATS_H
#define BASESTATS_H

#include <string>

class basestats{

private:

	float health, damage, defense, movement, sleep, eat;
	std::string name;

public:

	basestats() { health = 100; damage = 1; defense = 0; movement = 50; sleep = 10000; eat = 10000;  name = "DEFAULT"; }

	float getHealth() { return health; }
	float getDamage() { return damage; }
	float getDefense() { return defense; }
	float getMovement() { return movement; }
	float getSleep() { return sleep; }
	float getEat() { return eat; }
	std::string getName() { return name; }

	void setHealth(float hp) { health = hp; }
	void setDamage(float dmg) { damage = dmg; }
	void setDefense(float def) { defense = def; }
	void setMovement(float move) { movement = move; }
	void setSleep(float slp) { sleep = slp; }
	void setEat(float et) { eat = et; }
	void setName(std::string n) { name = n; }

	void decrementEat(float val) { eat -= val; }
	void incrementEat(float val) { eat += val; }

	void decrementSleep(float val) { sleep -= val; }
	void incrementSleep(float val) { sleep += val; }

};

#endif