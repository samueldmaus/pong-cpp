#include "ball.h"
#include "bat.h"
#include <sstream>
#include <cstdlib>
#include <SFML/Graphics.hpp>

using namespace sf;

int main()
{
	// creates window to view the game
	int windowWidth = 1024;
	int windowHeight = 768;
	RenderWindow window(VideoMode(windowWidth, windowHeight), "PONG");
	int score = 0;
	int lives = 3;
	Bat bat(windowWidth / 2, windowHeight - 20);
	Ball ball(windowWidth / 2, 1);
	Text hud;
	Font font;
	font.loadFromFile("game-over.tff");
	hud.setFont(font);
	hud.setCharacterSize(75);
	hud.setFillColor(sf::Color::White);

	//controling when the game is running
	while (window.isOpen())
	{
		// handles the player input
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				window.close()
					;
			}
		}
	}
}