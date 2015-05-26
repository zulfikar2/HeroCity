#include "menu.h"
#include "gameState.h"
#include "mainState.h"

Menu::Menu(Game* game) {

	this->game = game;

	float width = float(game->window.getSize().x);
	float height = float(game->window.getSize().y);

	sf::Vector2f pos = sf::Vector2f(game->window.getSize());
	view.setSize(pos);
	pos *= 0.5f; //get center of screen
	view.setCenter(pos);

	if (!font.loadFromFile("Dutch_&_Harley.ttf")) {
		//error handling
	}

	txt[0].setFont(font);
	txt[0].setColor(sf::Color::Red);
	txt[0].setString("Play");
	txt[0].setPosition(sf::Vector2f((width / 2) - width / 15, height / (NUMITEMS + 1) * 1));

	txt[1].setFont(font);
	txt[1].setColor(sf::Color::White);
	txt[1].setString("Load Game");
	txt[1].setPosition(sf::Vector2f((width / 2) - width / 15, height / (NUMITEMS + 1) * 2));

	txt[2].setFont(font);
	txt[2].setColor(sf::Color::White);
	txt[2].setString("Options");
	txt[2].setPosition(sf::Vector2f((width / 2) - width / 15, height / (NUMITEMS + 1) * 3));

	txt[3].setFont(font);
	txt[3].setColor(sf::Color::White);
	txt[3].setString("About");
	txt[3].setPosition(sf::Vector2f((width / 2) - width / 15, height / (NUMITEMS + 1) * 4));

	txt[4].setFont(font);
	txt[4].setColor(sf::Color::White);
	txt[4].setString("Exit");
	txt[4].setPosition(sf::Vector2f((width / 2) - width / 15, height / (NUMITEMS + 1) * 5));

	selectedItemIndex = 0;
}

Menu::~Menu() {
	//destroy
}

void Menu::draw(const float dt) {

	for (int x = 0; x < NUMITEMS; x++) {
		game->window.draw(txt[x]);
	}

	game->window.setView(view);
	//game->window.clear(sf::Color::Black);
	//game->window.draw(game->backround);
}

void Menu::update(const float dt) {
	//update function for menu
}

void Menu::handleInput() {
	sf::Event event;
	while (game->window.pollEvent(event)) {
		switch (event.type) {

		case sf::Event::Closed:
			game->window.close(); //add confirmation
			break;

		case sf::Event::Resized:
			view.setSize(float(event.size.width), float(event.size.height));
			//game->backround.setPosition(game->window.mapPixelToCoords(sf::Vector2i(0, 0)));
			//game->backround.setScale(float(event.size.width) / float(game->backround.getTexture()->getSize().x), float(event.size.height) / float(game->backround.getTexture()->getSize().y));
			break;
		case sf::Event::KeyPressed:
			if (event.key.code == sf::Keyboard::Escape) game->window.close(); //add confirmation
			break;
		case (sf::Event::KeyReleased) :
			switch (event.key.code) {
			case sf::Keyboard::Up:
				MoveUp();
				break;
			case sf::Keyboard::Down:
				MoveDown();
				break;
			case sf::Keyboard::Return: //menu enter pressed
				switch (getPressedItem()) {
				case 0:
					//play
					break;
				case 1:
					//load game
					loadgame();
					break;
				case 2:
					//options
					break;
				case 3:
					//about
					break;
				case 4:
					//exit
					game->window.close();
					break;
				}
			}
			default:
				break;
		}
	}
}

void Menu::MoveUp() {

	if (selectedItemIndex - 1 >= 0) {
		txt[selectedItemIndex].setColor(sf::Color::White);
		selectedItemIndex--;
		txt[selectedItemIndex].setColor(sf::Color::Red);
	}
}

void Menu::MoveDown() {

	if (selectedItemIndex + 1 < NUMITEMS) {
		txt[selectedItemIndex].setColor(sf::Color::White);
		selectedItemIndex++;
		txt[selectedItemIndex].setColor(sf::Color::Red);
	}
}

void Menu::loadgame() {
	game->pushState(new mainState(game));
}