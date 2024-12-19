#include "WildPhysics.h"
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;
using namespace std;

WildPhysics::WildPhysics() : window(VideoMode(800, 600), "Wild")
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
			for (size_t i = 0; i < movingObstacles.size(); i++)
			{
				if (movingObstacles[i].getGlobalBounds().contains(mousePos))
				{
					movingObstacles.erase(movingObstacles.begin() + 1);
					score++;
					break;
				}
			}
		}
	}
}

void WildPhysics::Update()
{
	static float spawnTimer = 0.0f;
	spawnTimer += deltaTime;
	if (spawnTimer > 1.0f)
	{
		SpawnObstacles();
		spawnTimer = 0.0f;
	}
	for (size_t i = 0; i < movingObstacles.size(); i++)
	{
		auto& obstacle = movingObstacles[i];
		float& velocity = movingVelocities[i];

		obstacle.move(velocity * deltaTime, 0.0f);
		velocity += acceleration * deltaTime;

		if (obstacle.getPosition().x < -20.0f || obstacle.getPosition().x > window.getSize().x + 20.0f)
		{
			movingObstacles.erase(movingObstacles.begin() + 1);
			movingVelocities.erase(movingVelocities.begin() + 1);
			--i;
		}
	}

	for (size_t i = 0; i < fallingObstacles.size(); ++i)
	{
		auto& obstacle = fallingObstacles[i];
		obstacle.move(0.0f, gravity * deltaTime);

		if (obstacle.getPosition().y > window.getSize().y + 20.0f)
		{
			fallingObstacles.erase(fallingObstacles.begin() + i);
			--i;
		}
	}
}

void WildPhysics::Render()
{
	window.clear();
	for (const auto& obstacle : movingObstacles)
	{
		window.draw(obstacle);
	}
	for(const auto & obstacle : fallingObstacles)
	{
		window.draw(obstacle);
	}
	window.display();
}

void WildPhysics::SpawnObstacles()
{
	CircleShape obstacle(20.0f);
	obstacle.setFillColor(Color::Green);

	if (rand() % 2 == 0)
	{
		float yPos = rand() % window.getSize().y;
		float xPos = (rand() % 2 == 0) ? 0.0f : window.getSize().x - 20.0f;
		obstacle.setPosition(xPos, yPos);
		movingObstacles.push_back(obstacle);
		movingVelocities.push_back((xPos == 0.0f) ? velocity : -velocity);
	}
	else
	{
		float xPos = rand() % window.getSize().x;
		obstacle.setPosition(xPos, 0.0f);
		fallingObstacles.push_back(obstacle);
	}
	
}