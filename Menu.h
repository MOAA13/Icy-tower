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

	~Menu();

private:

	int currentSelectedOption;
	
	sf::Font font;
	sf::Text menuOptions[MAX_MENU_OPTIONS];

	// Audio
	sf::Music themeMusic;
	sf::SoundBuffer mouthClapSound;
	sf::Sound clap;

	sf::SoundBuffer chooseOptionSound;
	sf::Sound choose;
};
