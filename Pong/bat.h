#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;


// creating Bat class - 
class Bat
{
private:
	Vector2f position;
	RectangleShape batShape;
	float batSpeed = .3f;
public:
	Bat(float startX, float startY);
	FloatRect getPosition();
	RectangleShape getShape();
	void moveLeft();
	void moveRight();
	void update();

};
