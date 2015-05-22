#include "menu.h"

Menu::Menu(float width, float height) {

	if (!font.loadFromFile("Dutch_&_Harley.ttf")) {
		//error handling
	}

	txt[0].setFont(font);
	txt[0].setColor(sf::Color::Red);
	txt[0].setString("Play");
	txt[0].setPosition(sf::Vector2f((width / 2) - width / 15, height / (NUMITEMS + 1) * 1));

	txt[1].setFont(font);
	txt[1].setColor(sf::Color::White);
	txt[1].setString("Options");
	txt[1].setPosition(sf::Vector2f((width / 2) - width / 15, height / (NUMITEMS + 1) * 2));

	txt[2].setFont(font);
	txt[2].setColor(sf::Color::White);
	txt[2].setString("About");
	txt[2].setPosition(sf::Vector2f((width / 2) - width/15, height / (NUMITEMS + 1)*3));

	txt[3].setFont(font);
	txt[3].setColor(sf::Color::White);
	txt[3].setString("Exit");
	txt[3].setPosition(sf::Vector2f((width / 2) - width / 15, height / (NUMITEMS + 1) * 4));

	selectedItemIndex = 0;
}

Menu::~Menu() {
	//destroy
}

void Menu::draw(sf::RenderWindow &win) {
	for (int x = 0; x < NUMITEMS; x++) {
		win.draw(txt[x]);
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