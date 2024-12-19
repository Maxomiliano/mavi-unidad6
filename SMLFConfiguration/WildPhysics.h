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
	void SpawnHorizontalObstacles();
	void SpawnVerticalObstacles();
	void CheckCollisions(Vector2f mousePos);
	
private:
	RenderWindow window;
	Event evt;
	//Font font;
	//Text scoreText;
	CircleShape horizontalObstacle;	
	CircleShape verticalObstacle;
	Vector2f position;
	Vector2f horizontalObjectVelocity;
	Vector2f verticalObjectVelocity;

	bool isVerticalObjectActive;
	bool isHorizontalObjectActive;
	bool movingRight;
	int score = 0;
	float deltaTime = 0.1f / 60.0f;
	const float gravity = 0.98f;
	//const float acceleration;
};

