#pragma once
#include "MenuState.h"
#include "../DEFINITIONS.h"

class MainMenu : public MenuState
{
public:

	MainMenu(int menu_options_count);
	void draw(sf::RenderWindow& window);

	void setBackgroundMusic(std::string musicFile);
	void volumeDown();
	void volumeUp();

public:
	sf::Music backgroundMusic;
};

