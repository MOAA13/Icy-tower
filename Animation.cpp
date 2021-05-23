#include "Animation.h"

Animation::Animation(sf::Texture* texture, sf::Vector2u ImageCount, float switchTime)
{
	// using pointers to this specific class to be able to access similar variable names
	this-> ImageCount = ImageCount;
	this-> switchTIme = switchTime;

	totalTime = 0.0f; // setting the total time 

	CurrentImage.x = 0; // the current image being accessed 
	// Calculating the height and width of each tux 
	uvRect.width = texture->getSize().x / float(ImageCount.x);
	uvRect.height = texture->getSize().y / float(ImageCount.y);
}

void Animation::update(int row, float deltaTime , bool faceRight )
{
	CurrentImage.y = row; // setting the y-axis of the current image to the row
	totalTime += deltaTime; // incrementation of the time
	if (totalTime >= switchTIme)
	{
		totalTime -= switchTIme; // to get a smooth animation 
		CurrentImage.x++; // switching the current image 
		if (CurrentImage.x >= ImageCount.x) // to make sure of being on the range of tuxes
		{
			CurrentImage.x = 0; // setting it back
		}
	}

	// setting up the uvrect 
	uvRect.top = CurrentImage.y * uvRect.height;
	//Flip
	if (faceRight)
	{
		uvRect.left = (CurrentImage.x ) * uvRect.width;
		uvRect.width = abs(uvRect.width);
	}
	else
	{
		uvRect.left = (CurrentImage.x + 1) * abs(uvRect.width);
		uvRect.width = -abs(uvRect.width);
	} 
}
