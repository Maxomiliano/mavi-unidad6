#include "FastAndFurious.h"
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;

FastAndFurious::FastAndFurious()
{
	RenderWindow window(VideoMode(800, 600), "Ejemplo de MRU");
	Vector2f position(100.0f, 300.0f);
	Vector2f initialVelocity(50.0f, 0.0f);
	Vector2f finalVelocity(100.0f, 0.0f);
	Vector2f velocityAccumulator(1.0f, 0.0f);
	const float acceleration = 0.1f;
	const float speed = 1.0f;

	while (window.isOpen())
	{
		Event evt;
		while (window.pollEvent(evt))
			if (evt.type == Event::Closed)
			{
				window.close();
			}

		float deltaTime = 1.0f / 60.0f;
		position.x += speed * deltaTime;
		if (position.x > 600)
		{
			position.x = 100.0f;
		}

		window.clear();
		CircleShape circle(20.0f);
		circle.setPosition(position);
		circle.setFillColor(Color::Blue);
		window.draw(circle);

		window.display();
	}
}
