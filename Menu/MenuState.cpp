#include "MenuState.h"

// constructor
MenuState::MenuState()
{
	// load mouth clap sound file
	if (!font.loadFromFile(FONT_TYPE_2)) {}
	
	// load mouth clap sound file
	if (!mouthClapSound.loadFromFile(MOUTH_CLAP_SOUND)) {}

	// load choose option sound file
	if (!chooseOptionSound.loadFromFile(CHOOSE_OPTION_SOUND)) {}

	// set sound buffer
	clapSound.setBuffer(mouthClapSound);
	chooseSound.setBuffer(chooseOptionSound);

	// set the first option selected by default
	currentSelectedOption = 0;

	for (int i = 0; i < MAX_MENU_OPTIONS_COUNT; i++)
	{
		if (i == 0)
		{
			menuOptionsSelection[i][0] = false;
			menuOptionsSelection[i][1] = true;
		}
		else
		{
			menuOptionsSelection[i][0] = true;
			menuOptionsSelection[i][1] = false;
		}
	}
}

void MenuState::show()
{
	// set display variable to true
	display = true;
}

void MenuState::hide()
{
	// set display variable to false
	display = false;
}

void MenuState::setBackgroundImg(std::string backgound_img)
{
	// set menu background img
	menuBackground.setSize(sf::Vector2f(SCREEN_WIDTH, SCREEN_HEIGHT));
	menuBackgroundTexture.loadFromFile(backgound_img);
	menuBackground.setTexture(&menuBackgroundTexture);
}

void MenuState::unselectOption(int optionIndex)
{
	// unselect option
	for (int i = 0; i < menu_options_count; i++)
	{
		for (int k = 0; k < 2; k++)
		{
			if (i == currentSelectedOption)
			{
				if (k == 0) menuOptionsSelection[i][k] = true;
				else menuOptionsSelection[i][k] = false;
			}
		}
	}
}

void MenuState::selectOption(int optionIndex)
{
	// select option
	for (int i = 0; i < menu_options_count; i++)
	{
		for (int k = 0; k < 2; k++)
		{
			if (i == currentSelectedOption)
			{
				if (k == 0) menuOptionsSelection[i][k] = false;
				else menuOptionsSelection[i][k] = true;
			}
		}
	}
}

void MenuState::moveDown()
{
	// check if it is not the last option
	if (currentSelectedOption + 1 <= menu_options_count)
	{
		clapSound.play();
		unselectOption(currentSelectedOption);
		currentSelectedOption++;
		// check if we got to the final option; in order to loop through the options
		if (currentSelectedOption == 3) currentSelectedOption = 0;
		selectOption(currentSelectedOption);
	}
}

void MenuState::moveUp()
{
	// check if it is not the last option
	if (currentSelectedOption + 1 <= menu_options_count)
	{
		// play clap sound
		clapSound.play();
		unselectOption(currentSelectedOption);
		currentSelectedOption--;
		// check if we got to the final option; in order to loop through the options
		if (currentSelectedOption == -1) currentSelectedOption = 2;
		selectOption(currentSelectedOption);
	}
}
