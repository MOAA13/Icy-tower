#include <SFML/Graphics.hpp>
#include "DEFINITIONS.h"

#include "Menu/MainMenu.h"
#include "Menu/OptionsMenu.h"

#include "Player.h"
#include "Animation.h"

#include <iostream>
#include <time.h>

int main()
{
	// Creating window object with (close and resize)
 	sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Icy Tower", sf::Style::Close | sf::Style::Resize);

	// Main menu
	const int mainMenuOptionsCount = 3;
	MainMenu mainMenu(mainMenuOptionsCount);
	mainMenu.setBackgroundImg(MAIN_MENU_BACKGROUND_IMG);
	mainMenu.setBackgroundMusic(THEME_MUSIC);

	// Options menu
	const int optionsMenuOptionsCount = 3;
	OptionsMenu optionsMenu(optionsMenuOptionsCount);
	optionsMenu.setBackgroundImg(OPTIONS_MENU_BACKGROUND_IMG);
	optionsMenu.hide();

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
	Player player(&playerTexture, sf::Vector2u(3, 9), 0.3f , 100.0f);
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

			case sf::Event::KeyPressed:

				switch (evnt.key.code)
				{

				case sf::Keyboard::Key::Up:
					if (mainMenu.display)
						mainMenu.moveUp();
					else if (optionsMenu.display)
						optionsMenu.moveUp();
					break;

				case sf::Keyboard::Key::Down:
					if (mainMenu.display)
						mainMenu.moveDown();
					else if (optionsMenu.display)
						optionsMenu.moveDown();
					break;

				case sf::Keyboard::Key::Enter:
					std::cout << mainMenu.display << " " << optionsMenu.display << std::endl;
					if (mainMenu.display)
					{
						mainMenu.hide();
						switch (mainMenu.currentSelectedOption)
						{
						case 0:
							// start game
							mainMenu.backgroundMusic.stop();
							break;
						case 1:
							// options menu
							std::cout << "Showing options menu" << std::endl;

							optionsMenu.display = false;
							optionsMenu.show();
							break;
						case 2:
							// exit game
							exit(0);
							break;
						}
					}
					if (optionsMenu.display)
					{
						switch (optionsMenu.currentSelectedOption)
						{
						case 0:
							// stop or pause music
							if (mainMenu.backgroundMusic.getStatus() == 0)
							{
								mainMenu.backgroundMusic.play();
								optionsMenu.setStatusText(mainMenu.backgroundMusic.getStatus());
							}
							else if (mainMenu.backgroundMusic.getStatus() == 2)
							{
								mainMenu.backgroundMusic.stop();
								optionsMenu.setStatusText(mainMenu.backgroundMusic.getStatus());
							}
							break;
						case 2:
							// back to main menu
							optionsMenu.hide();
							mainMenu.show();
							break;
						}
					}
					break;

				case sf::Keyboard::Key::Left:

					if (optionsMenu.display)
					{
						if (optionsMenu.currentSelectedOption == 1)
						{
							mainMenu.volumeDown();
							optionsMenu.setVolumeText(mainMenu.backgroundMusic.getVolume(), mainMenu.backgroundMusic.getStatus());
						}
					}
					break;

				case sf::Keyboard::Key::Right:

					if (optionsMenu.display)
					{
						if (optionsMenu.currentSelectedOption == 1)
						{
							mainMenu.volumeUp();
							optionsMenu.setVolumeText(mainMenu.backgroundMusic.getVolume(), mainMenu.backgroundMusic.getStatus());
						}
					}
					break;
				}
			}

			window.clear();
			// Main Menu
			mainMenu.draw(window);
			// Options Menu
			optionsMenu.draw(window);
			/*
			player.Update(deltatime);
			player.Draw(window);
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