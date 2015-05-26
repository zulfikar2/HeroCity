#ifndef MENU_H
#define MENU_H

#include "SFML\Graphics.hpp"
#include "gameState.h"

#define NUMITEMS 5

class Menu : public gameState{

public:
	Menu(Game* game);
	~Menu();

	virtual void draw(const float dt);
	virtual void update(const float dt);
	virtual void handleInput();

	void MoveUp();
	void MoveDown();
	int getPressedItem() { return selectedItemIndex; }

private:
	sf::View view;
	void loadgame();
	int selectedItemIndex;
	sf::Font font;
	sf::Text txt[NUMITEMS];

};

#endif