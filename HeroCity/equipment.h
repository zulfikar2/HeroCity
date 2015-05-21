#ifndef EQUIPMENT_H
#define EQUIPMENT_H

#include <iostream>
#include "item.h"

class equipment {

private:

	int head, chest, weapon, boots;

public:

	int getHead() { if (head == -1) return 0; else return head; }
	int getChest() { if (chest == -1) return 0; else return chest; }
	int getWeapon() { if (weapon == -1) return 0; else return weapon; }
	int getBoots() { if (boots == -1) return 0; else return boots; }

	void setHead(int h) { head = h; }
	void setChest(int c) { chest = c; }
	void setWeapon(int wep) { weapon = wep; }
	void setBoots(int b) { boots = b; }

};

#endif