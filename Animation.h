#pragma once
// include the libraries needed
#include "SFML/Graphics.hpp"
#include "DEFINITIONS.h"



// define the class
class Animation 
	{
	// define the public function used
	public:
		Animation(sf::Texture* texture, sf::Vector2u ImageCount, float switchTime);
		~Animation();


		void Update(int row, float deltaTime, bool faceRight); // delta time is the time between the previous and the current frame



	// define public variables used
	public:

		sf::IntRect uvRect; // this will be used to display the animation

	// define private variables
	private:
		sf::Vector2u ImageCount; // amount of images 
		sf::Vector2u CurrentImage; // current image

		float totalTime; // time since we last changed image
		float switchTIme; // time taken to change an image 
	};
