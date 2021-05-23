#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "../DEFINITIONS.h"
#include <string.h>

class MenuState
{

public:

	MenuState();

	void show();
	void hide();

	void setBackgroundImg(std::string backgound_img);

	void moveDown();
	void moveUp();

public:

	bool menuOptionsSelection[MAX_MENU_OPTIONS_COUNT][2];
	bool display;
	int currentSelectedOption;

protected:

	void selectOption(int optionIndex);
	void unselectOption(int optionIndex);

protected:

	// Background
	sf::RectangleShape menuBackground;
	sf::Texture menuBackgroundTexture;

	// Audio
	sf::SoundBuffer mouthClapSound;
	sf::Sound clapSound;

	sf::SoundBuffer chooseOptionSound;
	sf::Sound chooseSound;

	// Font
	sf::Font font;

	// Menu Functionality

	// Position datatype
	struct position {
		float x;
		float y;
	};

	int menu_options_count;

	position optionsShapesStartPosition;

	sf::RectangleShape menuOptions[MAX_MENU_OPTIONS_COUNT][2];
	sf::Texture menuOptionsTextures[MAX_MENU_OPTIONS_COUNT][2];

};
