#include "mainState.h"

void mainState::draw(const float dt) {
	game->window.clear(sf::Color::Black);
	//game->window.draw(game->backround);
}

void mainState::update(const float dt) {
	//update for game
}

void mainState::handleInput() {
	sf::Event event;

	while (game->window.pollEvent(event)) {
		switch (event.type) {
		case sf::Event::Closed:
			game->window.close();
			break;
		case sf::Event::Resized:
			gameView.setSize(float(event.size.width), float(event.size.height));
			guiView.setSize(float(event.size.width), float(event.size.height));
			//game->background.setPosition(game->window.mapPixelToCoords(sf::Vector2i(0, 0),guiView));
			//game->backround.setScale(float(event.size.width) / float(game->background.getTexture()->getSize().x), float(event.size.height) / float(game->background.getTexture()->getSize().y));
			break;
		default:
			break;

		}
	}
}

mainState::mainState(Game* game) {
	this->game = game;

	sf::Vector2f pos = sf::Vector2f(this->game->window.getSize());
	guiView.setSize(pos);
	gameView.setSize(pos);
	pos *= 0.5f; //get center of screen
	guiView.setCenter(pos);
	gameView.setCenter(pos);
}