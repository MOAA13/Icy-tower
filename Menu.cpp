#include "Menu.h"
#include "DEFINITIONS.h"
#include <iostream>
#include <string.h>

// constructor
Menu::Menu(int menu_options_count)
{
	// load font file
	//if (!font.loadFromFile(FONT_TYPE)){}

	// load mouth clap sound file
	if (!mouthClapSound.loadFromFile(MOUTH_CLAP_SOUND)){}

	// load choose option sound file
	if (!chooseOptionSound.loadFromFile(CHOOSE_OPTION_SOUND)) {}

	this->menu_options_count = menu_options_count;
	this->display = display;
	display = true;

	// set the first option selected by default
	currentSelectedOption = 0;

	for (int i = 0; i < MAX_MENU_OPTIONS_COUNT; i++)
	{
		if (i == 0)
		{
			menuOptionsSelection[i][0] = false;
			menuOptionsSelection[i][1] = true;
		}
		else
		{
			menuOptionsSelection[i][0] = true;
			menuOptionsSelection[i][1] = false;
		}
	}

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

	// set sound buffer
	clapSound.setBuffer(mouthClapSound);
	chooseSound.setBuffer(chooseOptionSound);


	/*
	sf::Text volume;
	volume.setFont(font);
	// set color
	volume.setFillColor(sf::Color::White);
	// set text string
	std::string volumeText = std::to_string(themeMusic.getVolume()) + "%";
	volume.setString(volumeText);
	// set text size
	volume.setCharacterSize(20);
	// set position
	volume.setPosition(sf::Vector2f(SCREEN_WIDTH / 2, SCREEN_HEIGHT / (MAX_MENU_OPTIONS + 1) * 4));
	*/
}

void Menu::show()
{
	display = true;
}

void Menu::hide()
{
	display = false;
}

void Menu::draw(sf::RenderWindow &window)
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

void Menu::setBackgroundImg(std::string backgound_img)
{
	// set menu background img
	menuBackground.setSize(sf::Vector2f(SCREEN_WIDTH, SCREEN_HEIGHT));
	menuBackgroundTexture.loadFromFile(backgound_img);
	menuBackground.setTexture(&menuBackgroundTexture);
}

void Menu::setBackgroundMusic(std::string musicFile)
{
	// load theme music
	if (!backgroundMusic.openFromFile(musicFile)) {}

	// play theme music
	backgroundMusic.play();
	backgroundMusic.setVolume(100.0f);
	backgroundMusic.setLoop(true);
}

void Menu::unselectOption(int optionIndex)
{
	for (int i = 0; i < menu_options_count; i++)
	{
		for (int k = 0; k < 2; k++)
		{
			if (i == currentSelectedOption)
			{
				if (k == 0) menuOptionsSelection[i][k] = true;
				else menuOptionsSelection[i][k] = false;
			}
		}
	}
}

void Menu::selectOption(int optionIndex)
{
	for (int i = 0; i < menu_options_count; i++)
	{
		for (int k = 0; k < 2; k++)
		{
			if (i == currentSelectedOption)
			{
				if (k == 0) menuOptionsSelection[i][k] = false;
				else menuOptionsSelection[i][k] = true;
			}
		}
	}
}

void Menu::moveDown()
{
	// check if it is not the last option
	if (currentSelectedOption + 1 <= menu_options_count)
	{
		clapSound.play();
		unselectOption(currentSelectedOption);
		currentSelectedOption++;
		// check if we got to the final option; in order to loop through the options
		if (currentSelectedOption == 3) currentSelectedOption = 0;
		selectOption(currentSelectedOption);
		std::cout << "Current selected option: "<< currentSelectedOption << std::endl;

		std::cout << menuOptionsSelection[currentSelectedOption][0] << std::endl;
		std::cout << menuOptionsSelection[currentSelectedOption][1] << std::endl;	
		std::cout << std::endl;	

	}
}

void Menu::moveUp()
{
	// check if it is not the last option
	if (currentSelectedOption + 1 <= menu_options_count)
	{
		clapSound.play();
		unselectOption(currentSelectedOption);
		currentSelectedOption--;
		if (currentSelectedOption == -1) currentSelectedOption = 2;
		selectOption(currentSelectedOption);
	}
}

void Menu::volumeDown()
{
	float currentVolume = backgroundMusic.getVolume();

	if (currentVolume > 5) backgroundMusic.setVolume(currentVolume - 5);
	else backgroundMusic.stop();
}

void Menu::volumeDown(sf::Music music)
{
	float currentVolume = music.getVolume();

	if (currentVolume > 5) music.setVolume(currentVolume - 5);
	else music.stop();
}

void Menu::volumeUp()
{
	float currentVolume = backgroundMusic.getVolume();

	if (backgroundMusic.getStatus() == 0) backgroundMusic.play();
	if (currentVolume < 95) backgroundMusic.setVolume(currentVolume + 5);
}

void Menu::volumeUp(sf::Music music)
{
	float currentVolume = music.getVolume();

	if (music.getStatus() == 0) music.play();
	if (currentVolume < 95) music.setVolume(currentVolume + 5);
}
