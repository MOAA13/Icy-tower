#include "Menu.h"
#include "DEFINITIONS.h"
#include <iostream>
#include <string.h>

// constructor
Menu::Menu()
{
	// load font file
	if (!font.loadFromFile("Pacifico.ttf")){}

	// load theme music
	if (!themeMusic.openFromFile(THEME_MUSIC)) {}

	// load mouth clap sound file
	if (!mouthClapSound.loadFromFile(MOUTH_CLAP_SOUND)){}

	// play theme music
	themeMusic.play();
	//themeMusic.setPitch(0.9f);
	themeMusic.setVolume(50.f);
	themeMusic.setLoop(true);

	// set sound buffer
	clap.setBuffer(mouthClapSound);

	// Start Game
	// set font type
	menuOptions[0].setFont(font);
	// set color
	menuOptions[0].setFillColor(sf::Color::Blue);
	// set text string
	menuOptions[0].setString("Start Game");
	// set text size
	menuOptions[0].setCharacterSize(20);
	// set position
	menuOptions[0].setPosition(sf::Vector2f(SCREEN_WIDTH / 2, SCREEN_HEIGHT / (MAX_MENU_OPTIONS + 1)));

	// Options
	// set font type
	menuOptions[1].setFont(font);
	// set color
	menuOptions[1].setFillColor(sf::Color::White);
	// set text string
	menuOptions[1].setString("Options");
	// set text size
	menuOptions[1].setCharacterSize(20);
	// set position
	menuOptions[1].setPosition(sf::Vector2f(SCREEN_WIDTH / 2, SCREEN_HEIGHT / (MAX_MENU_OPTIONS + 1) * 2));

	// Exit
	// set font type
	menuOptions[2].setFont(font);
	// set color
	menuOptions[2].setFillColor(sf::Color::White);
	// set text string
	menuOptions[2].setString("Exit");
	// set text size
	menuOptions[2].setCharacterSize(20);
	// set position
	menuOptions[2].setPosition(sf::Vector2f(SCREEN_WIDTH / 2, SCREEN_HEIGHT / (MAX_MENU_OPTIONS + 1) * 3));

	currentSelectedOption = 0;

}

Menu::~Menu()
{

}

void Menu::draw(sf::RenderWindow &window)
{
	for (int i = 0; i < 3; i++)
	{
		window.draw(menuOptions[i]);
	}
}

void Menu::moveDown()
{
	// check if it is not the last option
	if (currentSelectedOption + 1 <= MAX_MENU_OPTIONS)
	{
		clap.play();
		// change the color of the current option to white
		menuOptions[currentSelectedOption].setFillColor(sf::Color::White);

		currentSelectedOption++;

		// check if we got to the final option; in order to loop through the options
		if (currentSelectedOption == 3) currentSelectedOption = 0;

		// change the color of the next option to blue
		menuOptions[currentSelectedOption].setFillColor(sf::Color::Blue);
	}
}

void Menu::moveUp()
{
	// check if it is not the last option
	if (currentSelectedOption + 1 <= MAX_MENU_OPTIONS)
	{
		clap.play();
		// change the color of the current option to white
		menuOptions[currentSelectedOption].setFillColor(sf::Color::White);

		currentSelectedOption--;

		// check if we got to the final option; in order to loop through the options
		if (currentSelectedOption == -1) currentSelectedOption = 2;

		// change the color of the next option to blue
		menuOptions[currentSelectedOption].setFillColor(sf::Color::Blue);
	}
}