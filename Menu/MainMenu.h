#pragma once
#include "MenuState.h"

class MainMenu : public MenuState
{
public:
	// public functions
	MainMenu(int menu_options_count);

	void draw(sf::RenderWindow& window);

	void setBackgroundMusic(std::string musicFile);
	void volumeDown();
	void volumeUp();

public:
	// private variables
	sf::Music backgroundMusic;
};

