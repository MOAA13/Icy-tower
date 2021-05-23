#pragma once
#include <SFML/Graphics.hpp>
#include "DEFINITIONS.h"
#include "Animation.h"

// defining player class
class Player
{
public:
	// public functions
	Player(sf::Texture* texture, sf::Vector2u ImageCount, float switchTime , float speed);

	void update(float deltatime);
	void draw(sf::RenderWindow& window);

private:
	// private variables

	// player body
	sf::RectangleShape body;
	Animation animation;
	unsigned int row; // unsigned because it's never gonna be less that zero
	float speed;
	bool faceRight; 
};


