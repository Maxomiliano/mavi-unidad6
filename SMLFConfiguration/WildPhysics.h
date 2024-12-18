#pragma once
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
	float deltaTime = 0.1 / 60.0f;

	RenderWindow window;
	Event evt;
	Font font;
	Text scoreText;
	Vector2f position;
	Vector2f velocity;
	vector<Vector2f> spawnPositions;
	vector<CircleShape> obstacles;
};

