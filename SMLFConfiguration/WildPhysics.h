#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;
using namespace std;


class WildPhysics
{
public:
	WildPhysics();
	void Play();
	void Update();
	void Render();
	void ProcessEvents();
	void SpawnObstacles();
	void CheckCollisions(Vector2f mousePos);
	
private:
	int score = 0;
	const float gravity = 0.98f;
	const float acceleration = 0.1f;
	float velocity = 1.0f;
	float deltaTime = 0.1f / 60.0f;
	bool isActive;
	bool movingRight;

	//Font font;
	//Text scoreText;
	RenderWindow window;
	Event evt;
	CircleShape obstacle;	
	Vector2f position;
};

