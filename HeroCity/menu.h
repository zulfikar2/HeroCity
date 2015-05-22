#ifndef MENU_H
#define MENU_H

#include "SFML\Graphics.hpp"

#define NUMITEMS 4

class Menu {
public:
	Menu(float width, float height);
	~Menu();

	void draw(sf::RenderWindow &win);
	void MoveUp();
	void MoveDown();
	int getPressedItem() { return selectedItemIndex; }

private:
	int selectedItemIndex;
	sf::Font font;
	sf::Text txt[NUMITEMS];

};

#endif