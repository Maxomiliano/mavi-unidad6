#include "FastAndFurious.h"
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;

FastAndFurious::FastAndFurious()
{
	RenderWindow window(VideoMode(800, 600), "Ejemplo de MRU");
	Vector2f position(100.0f, 300.0f);
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

		window.clear();
		RectangleShape object(Vector2f(50.0f, 50.0f));
		object.setPosition(position);
		object.setFillColor(Color::Blue);
		window.draw(object);

		window.display();
	}
}
