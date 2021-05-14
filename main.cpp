#include <SFML/Graphics.hpp>
#include "DEFINITIONS.h"
#include "Menu.h"
#include <iostream>
#include "Animation.h"
#include <time.h>
#include <vector>
#include "Player.h"


int main()
{
	// Creating window object with (close and resize)
 	sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Icy Tower", sf::Style::Close | sf::Style::Resize);

	// Main menu
	Menu mainMenu;
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
	//Temp Player
	sf::Texture playerTexture;
	playerTexture.loadFromFile(CHARACTER_IMG); 
	//Animation
	Player player(&playerTexture, sf::Vector2u(9, 4), 0.3f , 100.0f);
	float deltatime = 0.0f;
	sf::Clock clock; 

	// Game loop
	while (window.isOpen())
	{


		deltatime = clock.restart().asSeconds(); // this will return the delta time
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

			/*			
			player.setTextureRect(animation.uvRect);
			if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) || (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left)))
				player.move(-0.1, 0);
			if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) || (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up)))
				player.move(0, -0.1);
			if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) || (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right)))
				player.move(0.1, 0);
			if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) || (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down)))
				player.move(0, 0.1);
			*/

			
			player.Update(deltatime);
			
			// Display
			window.clear();

			
		
			window.draw(gameBackground);
			player.Draw(window);
			/*Menu
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
			
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
			{
				mainMenu.volumeDown();
				break;
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
			{
				mainMenu.volumeUp();
			}

			/*
			//window.draw(characterSprite);
			window.draw(gameBackground);
			window.draw(block);
			window.draw(rightWall);
			window.draw(leftWall);
			*/
			
			window.display();
			
			
		}
	}
	return 0;
}