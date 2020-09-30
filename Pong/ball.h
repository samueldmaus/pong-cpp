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
	float xVelocity = .1f;
	float yVelocity = .1f;
	Ball(float startX, float startY);
	FloatRect getPosition();
	RectangleShape getShape();
	float getXVelocity();
	void reboundSides();
	void reboundBatOrTop();
	void hitBottom();
	void update();
};

