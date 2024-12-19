#include "WildPhysics.h"
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;
using namespace std;

WildPhysics::WildPhysics() : window(VideoMode(800, 600), "Wild"),
velocity(0.0f, 0.0f),
//acceleration(1.0f),
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
		//velocity.x += (movingRight ? acceleration : -acceleration) * deltaTime;
		position = obstacle.getPosition();
		position.x += velocity.x * deltaTime;
		obstacle.setPosition(position);
		if ((movingRight && position.x > window.getSize().x) || (!movingRight && position.x + obstacle.getRadius() * 2 < 0))
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
	movingRight = rand() % 2 == 0;

	if (movingRight) 
	{
		float yPos = static_cast<float>(rand() % (window.getSize().y - static_cast<int>(obstacle.getRadius() * 2)));
		obstacle.setPosition(0.0f, yPos);
	}
	else
	{
		float yPos = static_cast<float>(rand() % (window.getSize().y - static_cast<int>(obstacle.getRadius() * 2)));
		obstacle.setPosition(static_cast<float>(window.getSize().x - obstacle.getRadius() * 2), yPos);
	}
	float speed = static_cast<float>(10 + rand() % 20);
	velocity = Vector2f(movingRight ? speed : -speed, 0.0f);
	isActive = true;
}

void WildPhysics::CheckCollisions(sf::Vector2f mousePos)
{
	if (obstacle.getGlobalBounds().contains(mousePos))
	{
		isActive = false;
	}
}