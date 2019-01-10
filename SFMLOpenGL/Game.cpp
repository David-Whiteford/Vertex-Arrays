#include <Game.h>

bool flip = false;
int current = 1;

Game::Game() : window(VideoMode(800, 600), "OpenGL Cube")
{
	vectorArray[0] = C1;
	vectorArray[1] = C2;
	vectorArray[2] = C3;
	vectorArray[3] = C4;
	vectorArray[4] = C5;
	vectorArray[5] = C6;
	vectorArray[6] = C7;
	vectorArray[7] = C8;
}

Game::~Game() {}

// Vertices for one Triangle
float vertices[] = 
{					
	1.0f, 1.0f, -5.0f , -1.0f, 1.0f , -5.0f, -1.0f , -1.0f, -5.0f,
	1.0f, 1.0f, -5.0f , 1.0f, -1.0f , -5.0f, -1.0f , -1.0f, -5.0f ,	//front face

	1.0f, 1.0f, -5.0f,   -1.0f, -1.0f, -5.0f,   1.0f, 1.0f, -6.0f,	// Right side Face
	1.0f, 1.0f, -6.0f, -1.0f, -1.0f, -6.0f, -1.0f, -1.0f, -5.0f,
	
	1.0f, 1.0f, -5.0f,   -1.0f, 1.0f, -5.0f,   -1.0f, 1.0f, -6.0f,	// Top Face
	1.0f, 1.0f, -6.0f,   -1.0f, 1.0f, -6.0f,   1.0f, 1.0f, -5.0f,

	1.0f, 1.0f, -6.0f,   -1.0f, 1.0f, -6.0f,   -1.0f, -1.0f, -6.0f,	// Back face
	1.0f, 1.0f, -6.0f,   1.0f, -1.0f, -6.0f,   -1.0f, -1.0f, -6.0f,

};

						


// Colors for those vertices
float colors[] =
{ 
	1.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 1.0f ,
	1.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 1.0f , //front face color
	1.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 1.0f,
	1.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 1.0f,

	1.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 1.0f,
	1.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 1.0f,
	1.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 1.0f,
	1.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 1.0f,
};   


// Index to be drawn
unsigned int vertex_index[] = { 0, 1, 2 ,3 ,4 , 5,6,7,8,9,10,11,12,13,14,15,16,17,18,19
,22,23};

void Game::run()
{

	initialize();

	Event event;

	while (isRunning) {

		cout << "Game running..." << endl;

		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				isRunning = false;
			}
		}
		update();
		render();
	}

}

void Game::initialize()
{
	isRunning = true;

	//glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0, window.getSize().x / window.getSize().y, 1.0, 500.0);
	glMatrixMode(GL_MODELVIEW);
}

void Game::update()
{
	elapsed = clock.getElapsedTime();
	//rotation
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		for (int i = 0; i < 24; i++)
		{
			vectorArray[i] = (MyMatrix3::rotationX(0.01) * vectorArray[i]);
		}
	}
	/// <summary>
	/// Key presses for the rotation of the cube down
	/// </summary>
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		for (int i = 0; i < 24; i++)
		{
			vectorArray[i] = (MyMatrix3::rotationX(-0.01) * vectorArray[i]);
		}
	}
	/// <summary>
	/// Key presses for the rotation of the cube left
	/// </summary>
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		for (int i = 0; i < 24; i++)
		{
			vectorArray[i] = (MyMatrix3::rotationZ(0.01) * vectorArray[i]);
		}
	}
	/// <summary>
	/// Key presses for the rotation of the cube right
	/// </summary>
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		for (int i = 0; i < 24; i++)
		{
			vectorArray[i] = (MyMatrix3::rotationZ(-0.01) * vectorArray[i]);
		}
	}
	



	vertices[0] = vectorArray[0].x;
	vertices[1] = vectorArray[0].y;
	vertices[2] = vectorArray[0].z;

	vertices[3] = vectorArray[1].x;
	vertices[4] = vectorArray[1].y;
	vertices[5] = vectorArray[1].z;

	vertices[6] = vectorArray[2].x;
	vertices[7] = vectorArray[2].y;
	vertices[8] = vectorArray[2].z;

	vertices[9] = vectorArray[0].x;
	vertices[10] = vectorArray[0].y;
	vertices[11] = vectorArray[0].z;

	vertices[12] = vectorArray[3].x;
	vertices[13] = vectorArray[3].y;
	vertices[14] = vectorArray[3].z;

	vertices[15] = vectorArray[4].x;
	vertices[16] = vectorArray[4].y;
	vertices[17] = vectorArray[4].z;







	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	cout << "Update up" << endl;
}

void Game::render()
{
	cout << "Drawing" << endl;

	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_COLOR_ARRAY);


	glVertexPointer(3, GL_FLOAT, 0, &vertices);
	glColorPointer(3, GL_FLOAT, 0, &colors);

	//glDrawArrays(GL_TRIANGLES, 0, 3);

	glDrawElements(GL_TRIANGLES, 24, GL_UNSIGNED_INT, &vertex_index);
	
	glDisableClientState(GL_COLOR_ARRAY);
	glDisableClientState(GL_VERTEX_ARRAY);

	window.display();

}

void Game::unload()
{
	cout << "Cleaning up" << endl;
}

