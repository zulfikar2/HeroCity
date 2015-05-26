#include "game.h"
#include "gameState.h"

Game::Game() {

	window.create(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Hero City");
	window.setFramerateLimit(60);
}

Game::~Game() {
	while (!states.empty()) popState(); //removes all states from stack
}

void Game::gameLoop() {

	sf::Clock clock;
	while (window.isOpen()) {

		sf::Time time = clock.getElapsedTime();
		float dt = time.asSeconds();

		if (peekState() == nullptr) continue;
		peekState()->handleInput();
		peekState()->update(dt);

		clock.restart();

		window.clear(sf::Color::Black);

		window.display();
	}
}

void Game::pushState(gameState* state) {

	states.push(state);

}

void Game::popState() {

	delete states.top();
	states.pop();

}

void Game::changeState(gameState* state) {
	if (!states.empty())
		popState();
	pushState(state);
}

gameState* Game::peekState() {
	if (states.empty()) return nullptr;
	return states.top();
}