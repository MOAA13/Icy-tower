// including needed libraries
#include "Player.h"

Player::Player(sf::Texture* texture, sf::Vector2u ImageCount, float switchTime , float speed):
	animation(texture,ImageCount,switchTime) // calling the constructor for member variables 
{ 
	//initializing private variables
	this->speed = speed;
	row = 0;
	faceRight = true;
	//initializing the body 
    body.setSize(sf::Vector2f(100.0f, 150.0f));
	body.setPosition(SCREEN_WIDTH / 2, SCREEN_HEIGHT - 220);
	body.setTexture(texture);
}


Player::~Player()
{
}

void Player::Update(float deltatime)
{
	sf::Vector2f movement(0.0f, 0.0f); //creating a movement variable 
	if ( (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left)) && body.getPosition().x >= SCREEN_WIDTH - 720)
		movement.x -= speed * deltatime + 5 ;
	if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right)) && body.getPosition().x <= SCREEN_WIDTH - 180)
		movement.x += speed * deltatime + 5 ;
	if (movement.x == 0.0f) {
		row = 0; 
	}
	else {
		row = 1;
		if (movement.x > 0.0f) {
			faceRight = true;
		}
		else
			faceRight = false;
		
	}
	animation.Update(row , deltatime, faceRight);
	body.setTextureRect(animation.uvRect);
	body.move(movement);

}

void Player::Draw(sf::RenderWindow &window)
{
	//to display the player
	window.draw(body);
}
