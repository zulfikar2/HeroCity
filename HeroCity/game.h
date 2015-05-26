#ifndef GAME_H
#define GAME_H

#include "SFML\Graphics.hpp"
#include <stack>

class gameState;

class Game {
private :
	const int WINDOW_WIDTH = 800;
	const int WINDOW_HEIGHT = 600;
public:
	sf::RenderWindow window; //main game window
	Game();
	~Game();
	void gameLoop(); //loop which controls game events

	std::stack<gameState*> states; //store states of game (menu, game, pause...etc)

	void popState(); //takes off the current state from list
	void pushState(gameState* state); //puts a state on the stack
	void changeState(gameState* state); //changes the top state in the stack
	gameState* peekState(); //checks current state (top state)

	int getWinWidth() { return window.getSize().x;  }
	int getWinHeight() { return window.getSize().y; }
};

#endif