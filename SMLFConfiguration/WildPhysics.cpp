#include "WildPhysics.h"
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;
using namespace std;

WildPhysics::WildPhysics() : window(VideoMode(800, 600), "Wild"),
velocity(0.0f),
acceleration(0.1f),
isActive(false)
{
	srand(time(NULL));
}

void WildPhysics::Play()
{
	while (window.isOpen())
	{
		ProcessEvents();
		Update();
		Render();
	}
}

void WildPhysics::ProcessEvents()
{
	while (window.pollEvent(evt))
	{
		if (evt.type == Event::Closed)
		{
			window.close();
		}
		if (evt.type == Event::MouseButtonPressed && evt.mouseButton.button == Mouse::Left)
		{
			Vector2f mousePos(evt.mouseButton.x, evt.mouseButton.y);
			CheckCollisions(mousePos);
		}
	}
}

void WildPhysics::Update()
{
	if (isActive)
	{
		velocity += acceleration * deltaTime;
		obstacle.move(velocity * deltaTime, 0.0f);
		if (obstacle.getPosition().x > window.getSize().x)
		{
			isActive = false;
		}
	}
	else
	{
		SpawnObstacles();
	}
}

void WildPhysics::Render()
{
	window.clear();
	if (isActive)
	{
		window.draw(obstacle);
	}
	window.display();
}

void WildPhysics::SpawnObstacles()
{
	obstacle.setRadius(20.0f);
	obstacle.setFillColor(Color::Green);
	obstacle.setPosition(0.0f, static_cast<float>(rand() % window.getSize().y));

	//velocity = static_cast<float>(50 + rand() % 100);
	isActive = true;
}

void WildPhysics::CheckCollisions(sf::Vector2f mousePos)
{
	if (obstacle.getGlobalBounds().contains(mousePos))
	{
		isActive = false;
	}
}