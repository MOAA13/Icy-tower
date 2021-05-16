#pragma once
// including needed libraries
#include "DEFINITIONS.h"
#include <SFML/Graphics.hpp>
#include "Animation.h"
// defining the class
class Player
{
	// defining public functions
public:
	Player(sf::Texture* texture, sf::Vector2u ImageCount, float switchTime , float speed);
	~Player();
	void Update(float deltatime);
	void Draw(sf::RenderWindow& window);
   // defining private variables
private:
	sf::RectangleShape body; // player body
	Animation animation;
	unsigned int row; // unsigned because it's never gonna be less that zero
	float speed;
	bool faceRight; 
};

