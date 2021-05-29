#include "Collider.h"

Collider::Collider(sf::RectangleShape& body) :
	body(body)
{
}

Collider::~Collider()
{
}

bool Collider::CheckCollision(Collider& other, sf::Vector2f Direction, float push)
{
	sf::Vector2f otherPosiotion = other.GetPosition();
	sf::Vector2f otherHalfSize = other.GetHalfSize();
	sf::Vector2f thisPosiotion = GetPosition();
	sf::Vector2f thisHalfSize = GetHalfSize();
	float deltaX = otherPosiotion.x - thisPosiotion.x;
	float deltaY = otherPosiotion.y - thisPosiotion.y;
	float intersectX = abs(deltaX) - (otherHalfSize.x + thisHalfSize.x);
	float intersectY = abs(deltaY) - (otherHalfSize.y + thisHalfSize.y);
	if (intersectX < 0.0f && intersectY < 0.0f) {
		push = std::min(std::max(push, 0.0f), 1.0f);
		if (intersectX > intersectY) {
			if (deltaX > 0.0f) {
				Move(intersectX * (1.0f - push), 0.0f);
				other.Move(-intersectX * push, 0.0f);
				Direction.x = 1.0f;
				Direction.y = 0.0f;
			}
			else {
				Move(-intersectX * (1.0f - push), 0.0f);
				other.Move(intersectX * push, 0.0f);
				Direction.x = -1.0f;
				Direction.y = 0.0f;
			}
		}
		else {
			if (deltaY > 0.0f) {
				Move(0.0f, intersectY * (1.0f - push));
				other.Move(0.0f, -intersectY * push);
				Direction.x = 0.0f;
				Direction.y = 1.0f;
			}
			else {
				Move(0.0f, -intersectY * (1.0f - push));
				other.Move(0.0f, intersectY * push);
				Direction.x = 0.0f;
				Direction.y = -1.0f;
			}
		}
		return true;
	}
	return false;
}

