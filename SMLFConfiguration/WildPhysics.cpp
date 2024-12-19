#include "WildPhysics.h"
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;
using namespace std;

WildPhysics::WildPhysics() : window(VideoMode(800, 600), "Wild"),
//acceleration(1.0f),
horizontalObjectVelocity(0.0f, 0.0f),
verticalObjectVelocity(0.0f, 0.0f),
isVerticalObjectActive(false),
isHorizontalObjectActive(false)
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
	if (isHorizontalObjectActive)
	{
		//velocity.x += (movingRight ? acceleration : -acceleration) * deltaTime;
		position = horizontalObstacle.getPosition();
		position.x += horizontalObjectVelocity.x * deltaTime;
		horizontalObstacle.setPosition(position);
		if ((movingRight && position.x > window.getSize().x) || (!movingRight && position.x + horizontalObstacle.getRadius() * 2 < 0))
		{
			isHorizontalObjectActive = false;
		}
	}
	else
	{
		SpawnHorizontalObstacles();
	}
	if (isVerticalObjectActive)
	{
		verticalObjectVelocity.y += gravity * deltaTime;
		Vector2f position = verticalObstacle.getPosition();
		position.y += verticalObjectVelocity.y * deltaTime;
		verticalObstacle.setPosition(position);

		if (position.y > window.getSize().y - verticalObstacle.getRadius() * 2)
		{
			//verticalObjectVelocity.y = 0.0f;
			isVerticalObjectActive = false;
		}
	}
	else
	{
		SpawnVerticalObstacles();
	}
}

void WildPhysics::Render()
{
	window.clear();
	if (isHorizontalObjectActive)
	{
		window.draw(horizontalObstacle);
	}
	if (isVerticalObjectActive)
	{
		window.draw(verticalObstacle);
	}
	window.display();
}

void WildPhysics::SpawnHorizontalObstacles()
{
	horizontalObstacle.setRadius(20.0f);
	horizontalObstacle.setFillColor(Color::Green);
	movingRight = rand() % 2 == 0;

	if (movingRight) 
	{
		float yPos = static_cast<float>(rand() % (window.getSize().y - static_cast<int>(horizontalObstacle.getRadius() * 2)));
		horizontalObstacle.setPosition(0.0f, yPos);
	}
	else
	{
		float yPos = static_cast<float>(rand() % (window.getSize().y - static_cast<int>(horizontalObstacle.getRadius() * 2)));
		horizontalObstacle.setPosition(static_cast<float>(window.getSize().x - horizontalObstacle.getRadius() * 2), yPos);
	}
	float speed = static_cast<float>(10 + rand() % 20);
	horizontalObjectVelocity = Vector2f(movingRight ? speed : -speed, 0.0f);
	isHorizontalObjectActive = true;
}

void WildPhysics::SpawnVerticalObstacles()
{
	verticalObstacle.setRadius(20.0f);
	verticalObstacle.setFillColor(Color::Blue);

	float xPos = static_cast<float>(rand() % (window.getSize().x - static_cast<int>(verticalObstacle.getRadius() * 2)));
	verticalObstacle.setPosition(xPos, 0.0f);
	verticalObjectVelocity = Vector2f(0.0f, static_cast<float>(1 + rand() % 5));
	isVerticalObjectActive = true;
}

void WildPhysics::CheckCollisions(sf::Vector2f mousePos)
{
	if (horizontalObstacle.getGlobalBounds().contains(mousePos))
	{
		isHorizontalObjectActive = false;
	}
	if (verticalObstacle.getGlobalBounds().contains(mousePos))
	{
		isVerticalObjectActive = false;
	}
}