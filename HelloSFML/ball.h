#pragma once
#include <SFML/Graphics.hpp>

// using sf:: from SFML
using namespace sf;

// creating Ball class
class Ball
{
private:
	Vector2f postion;
	RectangleShape ballShape;
	float xVelocity = .2f;
	float yVelocity = .2f;
public:
	Ball(float startX, float startY);
	FloatRect getPosition();
	RectangleShape getShape();
	float getXVelocity();
	void reboundSides();
	void reboundBatOrTop();
	void hitBottom();
	void update();
};

