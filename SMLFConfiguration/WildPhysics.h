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
	
private:
	int score = 0;
	const float gravity = 0.98f;
	const float acceleration = 0.1f;
	float deltaTime = 0.1f / 60.0f;

	RenderWindow window;
	Event evt;
	Font font;
	Text scoreText;
	Vector2f velocity;
	//Vector2f position;
	vector<CircleShape> obstacles;
};

