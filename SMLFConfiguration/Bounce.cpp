#include "Bounce.h"
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;

Bounce::Bounce()
{
	RenderWindow window(VideoMode(1800, 600), "Space");
	Vector2f position(900.0f, 300.0f);
	Vector2f velocity(0.0f, 0.0f);
	const float acceleration = 0.1f;
	const float gravity = 0.098f;
	float deltaTime = 0.1 / 60.0f;

	while (window.isOpen())
	{
		Event evt;
		while (window.pollEvent(evt))
		{
			if (evt.type == Event::Closed)
			{
				window.close();
			}
		}
		







		window.clear();

		CircleShape ball(20.0f);
		ball.setPosition(position);
		ball.setFillColor(Color::Red);
		window.draw(ball);

		window.display();
	}
}