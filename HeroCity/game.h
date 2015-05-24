#include <iostream>
#include "citizen.h"
#include "menu.h"

class game {
private :
	const int WINDOW_WIDTH = 800;
	const int WINDOW_HEIGHT = 600;
public:
	sf::RenderWindow window; //main game window
	game();
	~game();
	void gameLoop(); //loop which controls game events
};