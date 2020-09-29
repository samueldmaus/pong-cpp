#include "ball.h"
#include "bat.h"
#include "item.h"
#include <sstream>
#include <cstdlib>
#include <SFML/Graphics.hpp>

using namespace sf;

int gameLives = 3;
int gameScore = 0;
int gameLevel = 0;
int Item::getLives()
{
	gameLives = Item::lives;
	return gameLevel;
}
int Item::subtractLife()
{
	return Item::lives--;
}
int Item::addScore()
{
	return Item::score;
}
int Item::getScore()
{
	gameScore = Item::score;
	return gameScore;
}

int main()
{
	// creates window to view the game

	int windowWidth = 1024;
	int windowHeight = 768;
	RenderWindow window(VideoMode(windowWidth, windowHeight), "PONG");
	Bat bat(windowWidth / 2, windowHeight - 20);
	Ball ball(windowWidth / 2, 1);
	Text hud;
	Font font;
	font.loadFromFile("game_over.ttf");
	hud.setFont(font);
	hud.setCharacterSize(75);
	hud.setFillColor(sf::Color::White);

	//control the bat when the game is running
	while (window.isOpen())
	{
		Event event;
		// handles the player input
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				window.close();
			}
		}
		if (Keyboard::isKeyPressed(Keyboard::Right) && bat.getPosition().left < (window.getSize().x - bat.getPosition().width))
		{
			//move bat to the right
			bat.moveRight();
		}
		if (Keyboard::isKeyPressed(Keyboard::Left) && bat.getPosition().left > 0)
		{
			// move left
			bat.moveLeft();
		}
		if (Keyboard::isKeyPressed(Keyboard::Escape))
		{
			window.close();
		}
		if (ball.getPosition().top < 0) {
			ball.reboundBatOrTop();
		}
		if (ball.getPosition().top > windowHeight)
		{
			ball.hitBottom();
			int subtractLife();
			int getLives();
			// check for zero lives and reset game if true
			/*if (gameLives < 1)
			{
				gameScore = 0;
				gameLives = 3;
				level = 1;
			}*/
		}
		if (ball.getPosition().left < 0 || ball.getPosition().left + 10 > windowWidth)
		{
			ball.reboundSides();
		}
		if (ball.getPosition().intersects(bat.getPosition()))
		{
			ball.reboundBatOrTop();
			int addScore();
			int getScore();
			//if (score > 2)
			//{
			//	score = 0;
			//	level++;
			//}
		}
		ball.update();
		bat.update();
		std::stringstream ss;
		ss << "Level:" << gameLevel << "    Score:" << gameScore << "   Lives:" << gameLives;
		hud.setString(ss.str());
		window.clear(Color(36, 128, 182, 255));
		window.draw(bat.getShape());
		window.draw(ball.getShape());
		window.draw(hud);
		window.display();
	}
	return 0;
}