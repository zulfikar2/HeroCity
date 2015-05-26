#ifndef MAIN_STATE_H
#define MAIN_STATE_H

#include "gameState.h"

class mainState: public gameState {

public:
	virtual void draw(const float dt);
	virtual void update(const float dt);
	virtual void handleInput();

	mainState(Game* game);

private:
	sf::View gameView;
	sf::View guiView;
};

#endif