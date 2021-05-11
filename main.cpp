#include <SFML/Graphics.hpp>
#include "DEFINITIONS.h"
#include "Menu.h"
#include <iostream>
#include <time.h>
#include <vector>


int main()
{
	// Creating window object with (close and resize)
 	sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Icy Tower", sf::Style::Close | sf::Style::Resize);

	// Main menu
	Menu mainMenu;

	// Background
	sf::RectangleShape background(sf::Vector2f(float(SCREEN_WIDTH) - 70, float(SCREEN_HEIGHT)));
	sf::Texture backgroundTexture;
	backgroundTexture.loadFromFile(GAME_BACKGROUND_IMG);
	background.setTexture(&backgroundTexture);
	background.setPosition(50.0f, 0.0f);

	// Wall - right
	sf::RectangleShape right_wall(sf::Vector2f(80.0f, float(SCREEN_HEIGHT)));
	sf::Texture rightTexture;
	rightTexture.loadFromFile(SIDE_WALL_IMG);
	right_wall.setTexture(&rightTexture);
	right_wall.setPosition(float(SCREEN_WIDTH) - 81, 0.0f);

	// Wall - left
	sf::RectangleShape left_wall(sf::Vector2f(80.0f, float(SCREEN_HEIGHT)));
	sf::Texture leftTexture;
	leftTexture.loadFromFile(SIDE_WALL_IMG);
	left_wall.setTexture(&leftTexture);
	left_wall.setScale(sf::Vector2f(-1, 1));
	left_wall.setPosition(81.0f, 0.0f);

	// Floor
	sf::RectangleShape block(sf::Vector2f(float(SCREEN_WIDTH) - 70.0f, 50.0f));
	sf::Texture blockTexture;
	blockTexture.loadFromFile(BLOCK_IMG);
	block.setTexture(&blockTexture);
	block.setPosition(50.0f, SCREEN_HEIGHT - 75);

	//sf::Texture characterTexture;
	//characterTexture.loadFromFile(CHARACTER_IMG);

	//sf::Sprite characterSprite;
	//characterSprite.setTexture(characterTexture);
	//characterSprite.setTextureRect(sf::IntRect(4 * (1280 / 30),0,540/15,80));

	// Game loop
	while (window.isOpen())
	{
		// Creating event object
		sf::Event evnt;

		while (window.pollEvent(evnt))
		{
			switch (evnt.type) {
			// Close the game
			case sf::Event::Closed:
				window.close();
				break;
			}

			//player.setTextureRect(animation.uvRect);
			//if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) || (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left)))
			//	player.move(-0.1, 0);
			//if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) || (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up)))
			//	player.move(0, -0.1);
			//if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) || (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right)))
			//	player.move(0.1, 0);
			//if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) || (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down)))
			//	player.move(0, 0.1);

			// Display
			window.clear();
			//window.draw(characterSprite);
			// 
			//Menu
			mainMenu.draw(window);

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up))
			{
				mainMenu.moveUp();
				break;
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down))
			{
				mainMenu.moveDown();
				break;
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Enter))
			{
				mainMenu.selectOption();
				break;
			}
			
			//window.draw(background);
			//window.draw(block);
			//window.draw(right_wall);
			//window.draw(left_wall);
			window.display();
		}
	}
	return 0;
}