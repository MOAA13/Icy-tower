#pragma once
#include "MenuState.h"
#include "../DEFINITIONS.h"

class OptionsMenu : public MenuState
{
public:

	OptionsMenu(int menu_options_count);
	void draw(sf::RenderWindow& window);

	void setStatusText(int status);
	void setVolumeText(float floatVolumeValue, int status);

	void turnOffMusic();
	void turnOnMusic();

private:

	sf::Text statusText;
	sf::Text volumeText;

	position backBtnPosition;
};
