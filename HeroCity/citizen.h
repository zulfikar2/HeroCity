#ifndef CITIZEN_H
#define CITIZEN_H

#include "basestats.h"
#include "equipment.h"
#include <fstream>

class citizen {

private:
	float baseDmg,
		baseEat,
		baseSleep;
public:
	basestats stats;
	equipment equip;
	citizen();
	citizen(std::string n);

	int job = -1; //no job assigned at start

	void update();
	void sleepTick();
	void eatTick();
	void toDo();
	void test(); //test stats and stuff
	std::string generateName(); // name gen

};

#endif