#include "FastAndFurious.h"
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;

FastAndFurious::FastAndFurious()
{
	RenderWindow window(VideoMode(800, 600), "Ejemplo de MRU");
	Vector2f position(0.0f, 300.0f);
	Vector2f initialVelocity(1.0f, 0.0f);
	Vector2f finalVelocity(100.0f, 0.0f);
	Vector2f velocityAccumulator(2.0f, 0.0f);

	while (window.isOpen())
	{
		Event evt;
		while (window.pollEvent(evt))
			if (evt.type == Event::Closed)
			{
				window.close();
			}

		float deltaTime = 1.0f / 60.0f;
		position.x += initialVelocity.x * deltaTime;
		if (initialVelocity.x < finalVelocity.x)
		{
			if (position.x > 800)
			{
				position.x = 0.0f;
				initialVelocity.x += velocityAccumulator.x;
			}
		}
		else
		{
			window.close();
		}

		window.clear();
		CircleShape circle(20.0f);
		circle.setPosition(position);
		circle.setFillColor(Color::Blue);
		window.draw(circle);

		window.display();
	}
}
