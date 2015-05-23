#include "citizen.h"

//spawn will always happen on z pos 0. Only x and y are allowed to change to stop spawning in dungeons/undergound

citizen::citizen(float pos_x, float pos_y) { // no name is defined. Pick one from list randomly

	citizen::pos_x = pos_x;
	citizen::pos_y = pos_y;
	stats.setName(generateName());
	baseDmg = (float)(rand() % 6); //0-5
	stats.setHealth(100.f);
	stats.setDamage(baseDmg);
	stats.setDefense(0);
	baseEat = (float)(rand() % 10001); //0-10000
	stats.setEat(baseEat);
	baseSleep = (float)(rand() % 10001); //0-10000
	stats.setSleep(baseSleep);

	equip.setHead(-1); //-1 means none
	equip.setChest(-1);
	equip.setWeapon(-1);
	equip.setWeapon(-1);
}

citizen::citizen(std::string n, float pos_x, float pos_y) { //name is defined

	citizen::pos_x = pos_x;
	citizen::pos_y = pos_y;
	stats.setName(n); //name is defined
	baseDmg = (float)(rand() % 6); //0-5
	stats.setHealth(100.f);
	stats.setDamage(baseDmg);
	stats.setDefense(0);
	baseEat = (float)(rand() % 10001); //0-10000
	stats.setEat(baseEat);
	baseSleep = (float)(rand() % 10001); //0-10000
	stats.setSleep(baseSleep);

	equip.setHead(-1); //-1 means none
	equip.setChest(-1);
	equip.setWeapon(-1);
	equip.setWeapon(-1);
}

citizen::~citizen() {

}

void citizen::update(float dt) {
	
	if (stats.getSleep() > 0)
		stats.decrementSleep(-1 * dt);

	//else
	//function to sleep if below or equal to 0
	//sleeping on floor doesn't fill bar fully

	if (stats.getEat() > 0)
		stats.decrementEat(-1 * dt);
	//else
	//function to eat if below or equal to 0
	//if no food found, enter starve state and debuff

	std::cout << stats.getSleep() << std::endl;
}

void citizen::refreshStats() {

	stats.setDefense(getItemDef(equip.getHead()) + getItemDef(equip.getChest()) + getItemDef(equip.getBoots()) + getItemDef(equip.getWeapon()));
	stats.setDamage(baseDmg + getItemDmg(equip.getWeapon()));
}

void citizen::toDo() {
	//handle events that move around citizens and make them do stuff
}

void citizen::test() {
	std::cout << "Name : " << stats.getName()
		<< "\nHealth : " << stats.getHealth() 
		<< "\nDamage : " << stats.getDamage() 
		<< "\nDefense : " << stats.getDefense() 
		<< "\nEat : " << stats.getEat() 
		<< "\nSleep : " << stats.getSleep() 
		<< "\nMovement : " << stats.getMovement() 
		<<  "\n-------------------" << std::endl;
}

std::string citizen::generateName() {
	int counter = 0;
	std::string line;
	std::ifstream file("citizen_names.txt");
	if (file.fail()) std::cout << "CITIZEN NAME FETCH ERROR!" << std::endl;
	while (std::getline(file, line))
		counter++;
	int ranName = (rand() % (counter+1))+1;
	std::cout << ranName << " " << counter << std::endl; //test
	file.clear();
	file.seekg(0);
	counter = 1;
	std::cout << ranName << " " << counter << std::endl; //test
	while (std::getline(file, line)) {
		if (ranName == counter) {
			std::cout << "broke at " << counter << std::endl; //test
			break;
		}
		counter++;
	}
	return line;
}

void citizen::draw(sf::RenderWindow &window) {
	window.draw(citizenSprite);
}