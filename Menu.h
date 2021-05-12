#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#define MAX_MENU_OPTIONS 3

class Menu
{

public:

	Menu();

	void draw(sf::RenderWindow &window);
	void moveDown();
	void moveUp();
	void selectOption();

	void volumeDown();
	void volumeUp();

	~Menu();

private:

	// Background
	sf::RectangleShape menuBackground;
	sf::Texture menuBackgroundTexture;

	// Audio
	sf::Music themeMusic;
	sf::SoundBuffer mouthClapSound;
	sf::Sound clap;

	sf::SoundBuffer chooseOptionSound;
	sf::Sound choose;

	// Menu Functionality
	int currentSelectedOption;
	sf::Font font;
	sf::Text menuOptions[MAX_MENU_OPTIONS];

};
