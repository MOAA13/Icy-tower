#include "Menu.h"

Menu::Menu() : mainMenu(MAIN_MENU_OPTIONS_COUNT), optionsMenu(OPTIONS_MENU_OPTIONS_COUNT)
{
	// Main menu
	mainMenu.setBackgroundImg(MAIN_MENU_BACKGROUND_IMG);
	mainMenu.setBackgroundMusic(THEME_MUSIC);

	// Options menu
	optionsMenu.setBackgroundImg(OPTIONS_MENU_BACKGROUND_IMG);
	optionsMenu.hide();
}

void Menu::draw(sf::RenderWindow& window)
{
	// draw menu
	mainMenu.draw(window);
	optionsMenu.draw(window);
}

void Menu::handle(sf::Event& evnt)
{
	switch (evnt.key.code)
	{
	case sf::Keyboard::Key::Up:
		if (mainMenu.display)
			mainMenu.moveUp();
		else if (optionsMenu.display)
			optionsMenu.moveUp();
		break;

	case sf::Keyboard::Key::Down:
		if (mainMenu.display)
			mainMenu.moveDown();
		else if (optionsMenu.display)
			optionsMenu.moveDown();
		break;

	case sf::Keyboard::Key::Enter:

		if (mainMenu.display)
		{
			mainMenu.hide();
			switch (mainMenu.currentSelectedOption)
			{
			case 0:
				// start game
				isActive = false;
				mainMenu.backgroundMusic.stop();
				break;
			case 1:
				// options menu
				optionsMenu.show();
				break;
			case 2:
				// exit game
				exit(0);
				break;
			}
		}
		else if (optionsMenu.display)
		{
			switch (optionsMenu.currentSelectedOption)
			{
			case 0:
				// stop or pause music
				if (mainMenu.backgroundMusic.getStatus() == 0)
				{
					mainMenu.backgroundMusic.play();
					optionsMenu.setStatusText(mainMenu.backgroundMusic.getStatus());
				}
				else if (mainMenu.backgroundMusic.getStatus() == 2)
				{
					mainMenu.backgroundMusic.stop();
					optionsMenu.setStatusText(mainMenu.backgroundMusic.getStatus());
				}
				break;
			case 2:
				// back to main menu
				optionsMenu.hide();
				mainMenu.show();
				break;
			}
		}
		break;

	case sf::Keyboard::Key::Left:

		if (optionsMenu.display)
		{
			if (optionsMenu.currentSelectedOption == 1)
			{
				mainMenu.volumeDown();
				optionsMenu.setVolumeText(mainMenu.backgroundMusic.getVolume(), mainMenu.backgroundMusic.getStatus());
			}
		}
		break;

	case sf::Keyboard::Key::Right:

		if (optionsMenu.display)
		{
			if (optionsMenu.currentSelectedOption == 1)
			{
				mainMenu.volumeUp();
				optionsMenu.setVolumeText(mainMenu.backgroundMusic.getVolume(), mainMenu.backgroundMusic.getStatus());
			}
		}
	}
}