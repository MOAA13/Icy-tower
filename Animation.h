#pragma once
#include "SFML/Graphics.hpp"
#include "DEFINITIONS.h"

// define Animation class
class Animation 
{
public:
	// public functions
	Animation(sf::Texture* texture, sf::Vector2u ImageCount, float switchTime);

	void update(int row, float deltaTime, bool faceRight); // delta time is the time between the previous and the current frame

public:
	// public variables
	sf::IntRect uvRect; // this will be used to display the animation

private:
	// private variables
	sf::Vector2u ImageCount; // amount of images 
	sf::Vector2u CurrentImage; // current image

	float totalTime; // time since we last changed image
	float switchTIme; // time taken to change an image 
	};
