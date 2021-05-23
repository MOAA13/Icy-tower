#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include "../DEFINITIONS.h"
#include <string.h>

// defining menu state base class
class MenuState
{
public:
	// public functions
	MenuState();

	void show();
	void hide();

	void setBackgroundImg(std::string backgound_img);

	void moveDown();
	void moveUp();

public:
	// public variables
	bool menuOptionsSelection[MAX_MENU_OPTIONS_COUNT][2];
	bool display;
	int currentSelectedOption;

protected:
	// protected functions
	void selectOption(int optionIndex);
	void unselectOption(int optionIndex);

protected:
	// protected variables
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
