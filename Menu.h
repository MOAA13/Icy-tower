#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "DEFINITIONS.h"
#include <string.h>

class Menu
{

public:

	Menu(int menu_options_count);

	void show();
	void hide();
	void draw(sf::RenderWindow& window);

	void setBackgroundImg(std::string backgound_img);
	void setBackgroundMusic(std::string musicFile);

	void moveDown();
	void moveUp();

	void volumeDown();
	void volumeDown(sf::Music music);
	void volumeUp();
	void volumeUp(sf::Music music);

public:

	sf::Music backgroundMusic;
	bool menuOptionsSelection[MAX_MENU_OPTIONS_COUNT][2];

private:

	void selectOption(int optionIndex);
	void unselectOption(int optionIndex);

private:

	// Background
	sf::RectangleShape menuBackground;
	sf::Texture menuBackgroundTexture;

	// Audio
	sf::SoundBuffer mouthClapSound;
	sf::Sound clapSound;

	sf::SoundBuffer chooseOptionSound;
	sf::Sound chooseSound;

	// Menu Functionality
	bool display;
	int menu_options_count;
	int currentSelectedOption;

	position optionsShapesStartPosition;

	sf::RectangleShape menuOptions[MAX_MENU_OPTIONS_COUNT][2];
	sf::Texture menuOptionsTextures[MAX_MENU_OPTIONS_COUNT][2];

};
