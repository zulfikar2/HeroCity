#include "game.h"

game::game() {

	window.create(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Hero City");
	window.setFramerateLimit(60);
}

game::~game() {

}

void game::gameLoop() {

	sf::Clock clock;
	while (window.isOpen()) {

		sf::Time time = clock.getElapsedTime();
		float dt = time.asSeconds();
		clock.restart();

		window.clear();
		window.display();
	}
}