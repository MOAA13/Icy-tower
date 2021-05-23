#pragma once
#include "MainMenu.h"
#include "OptionsMenu.h"

class Menu
{
	// Main menu
	MainMenu mainMenu;
	// Options menu
	OptionsMenu optionsMenu;

public:
	// public functions
	Menu();

	void draw(sf::RenderWindow& window);
	void handle(sf::Event& evnt);

public:

	bool isActive = true;
};
