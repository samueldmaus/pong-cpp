#pragma once
#include <SFML/Graphics.hpp>

// using sf:: from SFML
using namespace sf;

// creating Ball class
class Ball
{
public:
	Vector2f position;
	RectangleShape ballShape;
	float xVelocity = .2f;
	float yVelocity = .2f;
	Ball(float startX, float startY);
	FloatRect getPosition();
	RectangleShape getShape();
	float getXVelocity();
	void reboundSides();
	void reboundBatOrTop();
	void hitBottom();
	void update();
};

