#include "WildPhysics.h"
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;
using namespace std;

WildPhysics::WildPhysics() :
	window(VideoMode(800, 600, 32), "WildPhysics")
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
			for (size_t i = 0; i < obstacles.size(); i++)
			{
				if (obstacles[i].getGlobalBounds().contains(mousePos))
				{
					obstacles.erase(obstacles.begin() + 1);
					++score;
					break;
				}
			}
		}

	}
}

void WildPhysics::Update()
{
	for (size_t i = 0; i < obstacles.size(); i++)
	{
		auto& obstacle = obstacles[i];
		if (obstacle.getPosition().y <= window.getSize().y)
		{
			obstacle.move(0.0f, gravity * deltaTime);
		}
		else
		{
			obstacle.move(acceleration * deltaTime, 0.0f);
		}
		if (obstacle.getPosition().y > window.getSize().y || obstacle.getPosition().x > window.getSize().x)
		{
			obstacles.erase(obstacles.begin() + 1);
			--i;
		}
	}

}

void WildPhysics::Render()
{
	window.clear();
	//window.draw();
	window.display();
}

void WildPhysics::SpawnObstacles()
{
	CircleShape obstacle(20.0f);
	obstacle.setFillColor(Color::Red);

	if (rand() % 2 == 0)
	{
		obstacle.setPosition(rand() % window.getSize().x, 0.0f);
	}
	else
	{
		float xPos = (rand() % 2 == 0) ? 0.0f : window.getSize().x - 20.0f;
		obstacle.setPosition(xPos, rand() % window.getSize().y);
	}
	obstacles.push_back(obstacle);
}