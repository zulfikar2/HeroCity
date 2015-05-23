#ifndef CITIZEN_H
#define CITIZEN_H

#include "basestats.h"
#include "equipment.h"
#include <fstream>
#include "SFML\Graphics.hpp"

class citizen {

private:
	float baseDmg,
		baseEat,
		baseSleep;
	sf::Sprite citizenSprite;
	sf::Texture citizenTexture;
public:
	basestats stats;
	equipment equip;
	citizen(float pos_x, float pos_y);
	citizen(std::string n, float pos_x, float pos_y);
	~citizen();

	int job = -1; //no job assigned at start
	float pos_x = 10, pos_y = 10, pos_z = 0; //position in x, y and z plane for citizen

	void refreshStats();
	void update(float dt); //updates eat, sleep, frame rate independant stuff
	void toDo();
	void test(); //test stats and stuff
	std::string generateName(); // name gen
	void draw(sf::RenderWindow &window);

};

#endif