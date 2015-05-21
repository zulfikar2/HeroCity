#include "item.h"

equip equips[numEquips] = {  //every addition should increment numEquips
	{ "TEST", 1, 1, 0 },
	{ "TEST2", 2, 2, 0 }
};

food foods[numFoods] = {
	{ "TESTF", 100 },
	{ "TESTF2", 200 }
};

std::string getItemName(int itemCode) {
	if (itemCode < numEquips) {
		//std::cout << "item name " << equips[itemCode].name << std::endl;
		return equips[itemCode].name;
	}
	return "ITEM CODE ERROR " + itemCode;
}
float getItemDmg(int itemCode) {
	if (itemCode < numEquips) {
		//std::cout << "item name " << equips[itemCode].damage << std::endl;
		return equips[itemCode].damage;
	}
	std::cout << "ITEM CODE ERROR " << itemCode << std::endl;
	return 0;
}
float getItemDef(int itemCode) {
	if (itemCode < numEquips) {
		//std::cout << "item name " << equips[itemCode].defense << std::endl;
		return equips[itemCode].defense;
	}
	std::cout << "ITEM CODE ERROR " << itemCode << std::endl;
	return 0;
}
float getItemMove(int itemCode) {
	if (itemCode < numEquips) {
		//std::cout << "item name " << equips[itemCode].movement << std::endl;
		return equips[itemCode].movement;
	}
	std::cout << "ITEM CODE ERROR " << itemCode << std::endl;
	return 0;
}

std::string getFoodName(int itemCode) {
	if (itemCode < numFoods) {
		return foods[itemCode].name;
	}
	return "ITEM CODE ERROR " + itemCode;
}
float getFoodVal(int itemCode) {
	if (itemCode < numFoods) {
		return foods[itemCode].eatVal;
	}
	std::cout << "ITEM CODE ERROR " << itemCode << std::endl;
	return 0;
}