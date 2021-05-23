#pragma once
#include "MenuState.h"

class OptionsMenu : public MenuState
{
public:
	// public functions
	OptionsMenu(int menu_options_count);

	void draw(sf::RenderWindow& window);

	void setStatusText(int status);
	void setVolumeText(float floatVolumeValue, int status);

private:
	// private variables
	sf::Text statusText;
	sf::Text volumeText;

	position backBtnPosition;
};
