#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;



int main()
{
	//MRU
	/*
	RenderWindow window(VideoMode(800, 600), "Ejemplo de MRU");
	Vector2f position(100.0f, 300.0f); //Posicion inicial
	const float speed = 1.0f; //Velocidad constante del objeto en eje x

	while (window.isOpen())
	{
		Event evt;
		while(window.pollEvent(evt))
			if (evt.type == Event::Closed)
			{
				window.close();
			}

		float deltaTime = 1.0f / 60.0f; //Actualizo la posicion en funcion de la velocidad y el tiempo. El deltatime parte de 60fps
		position.x += speed * deltaTime; //Esto se puede cambiar usando la clase Clock

		window.clear();
		RectangleShape object(Vector2f(50.0f, 50.0f));
		object.setPosition(position);
		object.setFillColor(Color::Blue);
		window.draw(object);

		window.display();
	}
	*/

	//MRUV
	/*
	RenderWindow window(VideoMode(800, 600), "Ejemplo de MRUV");
	Vector2f position(100.0f, 100.0f);
	Vector2f velocity(50.0f, 0.0f); //Velocidad inicial en el eje x (MRU) y en el eje y (MRUV)
	const float acceleration = 0.1f;
	Clock clock;

	while (window.isOpen())
	{
		Event evt;
		while (window.pollEvent(evt))
		{
			if (evt.type == Event::Closed)
			{
				window.close();
			}
		}

		//float deltaTime = 0.1f / 60.0f; //Actualizar la velocidad del objeto en funcion de la aceleracion y el tiempo transcurrido. Suponemos que el juego esta en 60fps
		float deltaTime = clock.restart().asSeconds();
		velocity.y += acceleration * deltaTime;
		position += velocity * deltaTime; //Actualizar la posicion del objketo en funcion de la velocidad y el tiempo transcurrido

		if (position.y > 550.0f) //Si el objeto ha llegado al suelo, hacer que rebote invirtiendo su velocidad en y
		{
			position.y = 550.0f;
			velocity.y = -velocity.y;
		}

		window.clear();

		RectangleShape rectangle(Vector2f(50.0f, 50.0f));
		rectangle.setPosition(position);
		rectangle.setFillColor(Color::Red);
		window.draw(rectangle);
		window.display();
	}
	*/

	//Caida libre
	/*
	RenderWindow window(VideoMode(800, 600), "Ejemplo de Caida Libre");
	Vector2f position(400.0f, 100.0f);
	Vector2f velocity(0.0f, 0.0f);

	const float gravity = 0.000098f;

	while (window.isOpen())
	{
		Event evt;
		while (window.pollEvent(evt))
		{
			if (evt.type == Event::Closed)
			{
				window.close();
			}
		}

		velocity.y += gravity;
		position += velocity;

		if (position.y > 600.0f)
		{
			position.y = 100.0f;
			velocity.y = 0.0f;
		}
		window.clear();

		CircleShape ball(20.0f);
		ball.setFillColor(Color::Red);
		ball.setPosition(position);
		window.draw(ball);
		window.display();
	}
	*/

	//Tiro vertical con rebote
	/*
	RenderWindow window(VideoMode(800, 600), "Ejemplo de Tiro Vertical");
	Vector2f position(100.0f, 500.0f);
	Vector2f velocity(0.0f, -300.0f); //velocidad inivial en el eje y MRUV hacia arriba

	const float acceleration = 9.8f;

	while (window.isOpen())
	{
		Event evt;
		while (window.pollEvent(evt))
		{
			if (evt.type == Event::Closed)
			{
				window.close();
			}
		}

		float deltaTime = 0.1f / 60.0f;
		velocity.y += acceleration * deltaTime;
		position += velocity * deltaTime;

		if (velocity.y > 0.0f && position.y > 500.0f)
		{
			velocity.y = -velocity.y;
		}

		window.clear();
		CircleShape ball(20.0f);
		ball.setPosition(position);
		ball.setFillColor(Color::Red);
		window.draw(ball);
		window.display();
	}
	*/

	//Tiro oblicuo
	/*
		RenderWindow window(VideoMode(800, 600), "Ejemplo de Tiro Oblicuo");
		Vector2f position(100.0f, 500.0f);
		Vector2f velocity(150.0f, -150.0f);

		const float acceleration = 9.8f;

		while (window.isOpen())
		{
			Event evt;
			while (window.pollEvent(evt))
			{
				if (evt.type == Event::Closed)
				{
					window.close();
				}
			}

			float deltaTime = 0.01f / 60.0f;
			velocity.y += acceleration * deltaTime;
			position += velocity * deltaTime;

			if (position.y > 500.0f)
			{
				position.y = 500.0f;
				velocity.y = -velocity.y;
				velocity.x *= 0.95f;
			}

			window.clear();

			CircleShape ball(20.0f);
			ball.setPosition(position);
			ball.setFillColor(Color::Green);
			window.draw(ball);
			window.display();
		}
	*/
	return 0;
}
























// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
