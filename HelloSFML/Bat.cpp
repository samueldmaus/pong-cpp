#include "bat.h"

// bat function to set the position of the bat
Bat::Bat(float startX, float startY)
{
	position.x = startX;
	position.y = startY;
	batShape.setSize(sf::Vector2f(50, 5));
	batShape.setPosition(position);
}

// returns the four corners of the bat
FloatRect Bat::getPosition()
{
	return batShape.getGlobalBounds();
}

// uses the four corners to draw the bat shape
RectangleShape Bat::getShape()
{
	return batShape;
}

//moves the bat to the left
void Bat::moveLeft()
{
	position.x -= batSpeed;
}

//move the bat the right
void Bat::moveRight() {
	position.x += batSpeed;
}