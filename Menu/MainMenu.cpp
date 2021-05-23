#include "MainMenu.h"

// constructor
MainMenu::MainMenu(int menu_options_count)
{
	this->menu_options_count = menu_options_count;
	this->display = display;
	display = true;

	// define options textures in a 2D loop
	optionsShapesStartPosition.x = 90;
	optionsShapesStartPosition.y = 240;

	for (int i = 0; i < menu_options_count; i++)
	{
		for (int k = 0; k < 2; k++)
		{
			menuOptions[i][k].setSize(sf::Vector2f(380, 250));
			menuOptionsTextures[i][k].loadFromFile(MAIN_MENU_OPTIONS_IMGS[i][k]);
			menuOptions[i][k].setTexture(&menuOptionsTextures[i][k]);
			menuOptions[i][k].setPosition(optionsShapesStartPosition.x, optionsShapesStartPosition.y);
		}
		optionsShapesStartPosition.y += 100;
	}
}

void MainMenu::draw(sf::RenderWindow& window)
{	
	if (display)
	{
		// draw menu's background
		window.draw(menuBackground);

		// draw options textures in a 2D loop
		for (int i = 0; i < menu_options_count; i++)
		{
			for (int k = 0; k < 2; k++)
			{
				if (menuOptionsSelection[i][k] == 1) window.draw(menuOptions[i][k]);
			}
		}
	}
}

void MainMenu::setBackgroundMusic(std::string musicFile)
{
	// load theme music
	if (!backgroundMusic.openFromFile(musicFile)) {}

	// play theme music
	backgroundMusic.play();
	backgroundMusic.setVolume(100.0f);
	backgroundMusic.setLoop(true);
}

void MainMenu::volumeDown()
{
	// turn volume down
	float currentVolume = backgroundMusic.getVolume();

	if (currentVolume > 5) backgroundMusic.setVolume(currentVolume - 5);
	else backgroundMusic.stop();
}

void MainMenu::volumeUp()
{
	// turn volume up
	float currentVolume = backgroundMusic.getVolume();
	// check if the music is paused
	if (backgroundMusic.getStatus() == 0) backgroundMusic.play();
	if (currentVolume < 95) backgroundMusic.setVolume(currentVolume + 5);
}
