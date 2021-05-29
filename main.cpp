#include <SFML/Graphics.hpp>
#include "DEFINITIONS.h"

#include "Menu/Menu.h"

#include "Player.h"
#include "Animation.h"

#include <iostream>
#include <time.h>

int main()
{
	// Creating window object with (close and resize)
 	sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Icy Tower", sf::Style::Close);

	/* Menu
	Menu gameMenu;
	*/
	// Background
	sf::RectangleShape gameBackground(sf::Vector2f(float(SCREEN_WIDTH) - 70, float(SCREEN_HEIGHT)));
	sf::Texture gameBackgroundTexture;
	gameBackgroundTexture.loadFromFile(GAME_BACKGROUND_IMG);
	gameBackground.setTexture(&gameBackgroundTexture);
	gameBackground.setPosition(50.0f, 0.0f);

	// Wall - right
	sf::RectangleShape rightWall(sf::Vector2f(80.0f, float(SCREEN_HEIGHT)));
	sf::Texture rightTexture;
	rightTexture.loadFromFile(SIDE_WALL_IMG);
	rightWall.setTexture(&rightTexture);
	rightWall.setPosition(float(SCREEN_WIDTH) - 81, 0.0f);

	// Wall - left
	sf::RectangleShape leftWall(sf::Vector2f(80.0f, float(SCREEN_HEIGHT)));
	sf::Texture leftTexture;
	leftTexture.loadFromFile(SIDE_WALL_IMG);
	leftWall.setTexture(&leftTexture);
	leftWall.setScale(sf::Vector2f(-1, 1));
	leftWall.setPosition(81.0f, 0.0f);

	// Floor
	sf::RectangleShape block(sf::Vector2f(float(SCREEN_WIDTH) - 70.0f, 50.0f));
	sf::Texture blockTexture;
	blockTexture.loadFromFile(BLOCK_IMG);
	block.setTexture(&blockTexture);
	block.setPosition(50.0f, SCREEN_HEIGHT - 75);

	//Player
	sf::Texture playerTexture;
	playerTexture.loadFromFile(CHARACTER_IMG);

	//Animation
	Player player(&playerTexture, sf::Vector2u(7, 4), 0.3f, 100.0f);
	float deltatime = 0.0f;
	sf::Clock clock;

	// Game loop
	while (window.isOpen())
	{
		// return the delta time
		deltatime = clock.restart().asSeconds(); 

		sf::Event evnt;

		while (window.pollEvent(evnt))
		{
			switch (evnt.type) {
			// close the game
			case sf::Event::Closed:
				window.close();
				break;
            /*
			case sf::Event::KeyReleased:
				if (gameMenu.isActive)
					gameMenu.handle(evnt);
				break;
				*/
			}

			window.clear();

			/* Game Menu
			gameMenu.draw(window);
			*/
		
			player.update(deltatime);
			window.draw(gameBackground);
			window.draw(block);
			window.draw(rightWall);
			window.draw(leftWall);
			player.draw(window);
			window.display();
			
		}
	}
	return 0;
}