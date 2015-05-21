#include <SFML/Graphics.hpp>
#include <iostream>
#include "citizen.h"

int main() {

	sf::RenderWindow window(sf::VideoMode(600, 600), "SFML_TEST");
	sf::Texture character;
	if (!character.loadFromFile("../CharSpriteSheet(BannedStory_PlaceHolder)/alert_0.png")){
		std::cout << "CHARACTER TEXTURE ERROR!" << std::endl;
	}

	sf::Sprite sprite_char(character);
	sprite_char.setPosition(255, 255);

	citizen guy;
	guy.test();
	citizen guy2;
	guy2.test();

	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			switch (event.type) {
			case sf::Event::Closed:
				window.close();
				break;
			case sf::Event::LostFocus:
				std::cout << "PAUSED" << std::endl;
				//PAUSE IF NOT ALREADY PAUSED
				break;
			case sf::Event::GainedFocus:
				std::cout << "UNPAUSED" << std::endl;
				//UNPAUSE IF PAUSED
				break;
			}
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
			//W
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
			if (sprite_char.getTextureRect() != sf::IntRect(0, 0, 68, 68))
				sprite_char.setTextureRect(sf::IntRect(0, 0, 68, 68));
			//A
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
			//S
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
			if (sprite_char.getTextureRect() != sf::IntRect(68, 0, -68, 68))
				sprite_char.setTextureRect(sf::IntRect(68, 0, -68, 68));
			//D
		}
		window.clear();
		window.draw(sprite_char);
		window.display();
	}
	return 0;
}