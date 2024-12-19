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
	RenderWindow window;
	Event evt;
	//Font font;
	//Text scoreText;
	CircleShape obstacle;	
	Vector2f position;
	Vector2f velocity;

	bool isActive;
	bool movingRight;
	int score = 0;
	float deltaTime = 0.1f / 60.0f;
	const float gravity = 0.98f;
	//const float acceleration;
};

