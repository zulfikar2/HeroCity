#include <iostream>
#include "citizen.h"
#include "menu.h"

int main() {
	const int WINDOW_WIDTH = 800;
	const int WINDOW_HEIGHT = 600;

	sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "SFML_TEST");

	/*
	-------EXAMPLE. SHOULD TRY NOT TO LOAD SPRITES/TEXTURES IN MAIN----------
	sf::Texture character;
	if (!character.loadFromFile("../CharSpriteSheet(BannedStory_PlaceHolder)/alert_0.png")){
	std::cout << "CHARACTER TEXTURE ERROR!" << std::endl;
	}*/

	Menu menu(WINDOW_WIDTH, WINDOW_HEIGHT);

	sf::Clock clock;

	bool paused = false;

	//add view to map. Have it move when going over invisible thin rectangles at edges of screen.
	//window should be resizable with fullscreen option

	float rect_thick = 15.f;
	sf::RectangleShape mouse_rect_N(sf::Vector2f(WINDOW_WIDTH, rect_thick)); //top mouse rectangle
	mouse_rect_N.setFillColor(sf::Color::Red);
	sf::RectangleShape mouse_rect_S(sf::Vector2f(WINDOW_WIDTH, rect_thick)); //bottom mouse rectangle
	mouse_rect_S.setPosition(sf::Vector2f(0, WINDOW_HEIGHT - rect_thick));
	mouse_rect_S.setFillColor(sf::Color::White);
	sf::RectangleShape mouse_rect_E(sf::Vector2f(WINDOW_WIDTH - rect_thick * 2, rect_thick)); //right side mouse rectangle
	mouse_rect_E.rotate(90);
	mouse_rect_E.move(sf::Vector2f(WINDOW_WIDTH, rect_thick));
	mouse_rect_E.setFillColor(sf::Color::Blue);
	sf::RectangleShape mouse_rect_W(sf::Vector2f(WINDOW_WIDTH - rect_thick * 2, rect_thick)); //left side mouse rectangle
	mouse_rect_W.rotate(90);
	mouse_rect_W.move(sf::Vector2f(rect_thick, rect_thick));
	mouse_rect_W.setFillColor(sf::Color::Green);

	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			switch (event.type) {
			case sf::Event::Closed:
				window.close();
				break;
			case sf::Event::LostFocus:
				std::cout << "PAUSED" << std::endl;
				if (!paused)
					paused = true;
				//PAUSE IF NOT ALREADY PAUSED
				break;
			case sf::Event::GainedFocus:
				std::cout << "UNPAUSED" << std::endl;
				if (paused)
					paused = false;
				//UNPAUSE IF PAUSED
				break;
			case sf::Event::KeyReleased: // menu selection (up/down/enter)
				switch (event.key.code) {
				case sf::Keyboard::Up: // up
					menu.MoveUp();
					break;
				case sf::Keyboard::Down: // down
					menu.MoveDown();
					break;
				case sf::Keyboard::Return: //menu enter pressed
					switch (menu.getPressedItem()) {
					case 0:
						//play
						break;
					case 1:
						//options
						break;
					case 2:
						//about
						break;
					case 3:
						//exit
						window.close();
						break;
					}
				}
			}

			//if (sf::Event::MouseEntered(mouse_rect_N.getGlobalBounds())){

			//}
		}

		sf::Time time = clock.getElapsedTime();
		//citizen.update(time.asMilliseconds());  updates sprites/textures...etc frame independant of citizen object

		std::cout << 1.0f / time.asSeconds() << std::endl; //shows frame rate

		clock.restart().asMilliseconds();

		window.clear();

		menu.draw(window);

		window.draw(mouse_rect_N);
		window.draw(mouse_rect_S);
		window.draw(mouse_rect_E);
		window.draw(mouse_rect_W);

		window.display();
	}
	return 0;
}