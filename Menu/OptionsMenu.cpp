#include "OptionsMenu.h"

// constructor
OptionsMenu::OptionsMenu(int menu_options_count)
{
	this->menu_options_count = menu_options_count;
	this->display = display;
	display = true;

	int backBtnIndex = 2;

	// define options textures in a 2D loop
	optionsShapesStartPosition.x = 150;
	optionsShapesStartPosition.y = 380;

	for (int i = 0; i < menu_options_count; i++)
	{
		for (int k = 0; k < 2; k++)
		{
			if (i != backBtnIndex)
			{
				menuOptions[i][k].setSize(sf::Vector2f(280, 170));
				menuOptions[i][k].setPosition(optionsShapesStartPosition.x, optionsShapesStartPosition.y);
			}
			menuOptionsTextures[i][k].loadFromFile(OPTIONS_MENU_OPTIONS_IMGS[i][k]);
			menuOptions[i][k].setTexture(&menuOptionsTextures[i][k]);
		}
		optionsShapesStartPosition.y += 60;
	}

	backBtnPosition.x = 330;
	backBtnPosition.y = 630;

	for (int i = 0; i < 2; i++)
	{
		menuOptions[backBtnIndex][i].setSize(sf::Vector2f(220, 140));
		menuOptions[backBtnIndex][i].setPosition(backBtnPosition.x, backBtnPosition.y);
	}

	// set music status text
	statusText.setFont(font);
	statusText.setString("On");
	statusText.setFillColor(sf::Color::Black);
	statusText.setPosition(460, 440);
	statusText.setCharacterSize(33);

	// set volume value text
	volumeText.setFont(font);
	volumeText.setString("100%");
	volumeText.setFillColor(sf::Color::Black);
	volumeText.setPosition(460, 500);
	volumeText.setCharacterSize(33);
}

void OptionsMenu::draw(sf::RenderWindow& window)
{
	if (display)
	{
		// draw menu's components
		window.draw(menuBackground);
		window.draw(statusText);
		window.draw(volumeText);

		// draw options textures in a 2D loop
		for (int i = 0; i < menu_options_count; i++)
		{
			for (int k = 0; k < 2; k++)
			{
				if (menuOptionsSelection[i][k] == 1) window.draw(menuOptions[i][k]);
			}
		}
	}
}

void OptionsMenu::setStatusText(int status)
{
	// set music status text
	if (status == 2)
		statusText.setString("On");
	else
		statusText.setString("Off");
}

void OptionsMenu::setVolumeText(float floatVolumeValue, int status)
{
	// set music volume text
	std::string volumeValueString;

	int intVolumeValue = static_cast<int>(floatVolumeValue);
	if (intVolumeValue % 5 != 0) intVolumeValue += 1;

	if (status == 0) volumeValueString = "0%";
	else volumeValueString = std::to_string(intVolumeValue) + "%";

	volumeText.setString(volumeValueString);
}
