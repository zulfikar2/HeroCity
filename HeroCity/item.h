#ifndef ITEMS_H
#define ITEMS_H

#include <iostream>
#include <string>

const int numEquips = 2;
const int numFoods = 2;

struct equip {
	std::string name;
	float damage,
		defense,
		movement;
};

struct food {
	std::string name;
	float eatVal;
};

std::string getItemName(int itemCode);

float getItemDmg(int itemCode);

float getItemDef(int itemCode);

float getItemMove(int itemCode);

std::string getFoodName(int itemCode);

float getFoodVal(int itemCode);

#endif