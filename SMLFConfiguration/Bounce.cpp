#include "Bounce.h"
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;

Bounce::Bounce()
{
	RenderWindow window(VideoMode(800, 600), "Bounce");
	Vector2f position(400.0f, 100.0f);
	Vector2f velocity(0.0f, 0.0f);
	const float bounceVelocity = 0.8f;
	const float gravity = 0.98f;
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
		
		velocity.y += gravity * deltaTime;
		position.y += velocity.y * deltaTime;

		if (position.y > 500)
		{
			velocity.y = -velocity.y * bounceVelocity;
		}

		window.clear();

		CircleShape ball(20.0f);
		ball.setPosition(position);
		ball.setFillColor(Color::Green);
		window.draw(ball);

		window.display();
	}
}