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

	

//	MyVector3 C1{ 1.0f, 1.0f, -5.0f };
//MyVector3 C2{ -1.0f, 1.0f, -5.0f };
//MyVector3 C3{ -1.0f, -1.0f, -5.0f };
//MyVector3 C4{ 1.0f, -1.0f, -5.0f };
//
//MyVector3 C5{ 1.0f, 1.0f, -6.0f };
//MyVector3 C6{ -1.0f, 1.0f, -6.0f };
//MyVector3 C7{ -1.0f, -1.0f, -6.0f };
//MyVector3 C8{ 1.0f, -1.0f, -6.0f };


//C1 , -1.0f, 1.0f , -5.0f, -1.0f , -1.0f, -5.0f,
//1.0f, 1.0f, -5.0f , 1.0f, -1.0f , -5.0f, -1.0f , -1.0f, -5.0f ,	//front face
//
//1.0f, 1.0f, -5.0f,   -1.0f, -1.0f, -5.0f,   1.0f, 1.0f, -6.0f,	// Right side Face
//1.0f, 1.0f, -6.0f, -1.0f, -1.0f, -6.0f, -1.0f, -1.0f, -5.0f,
//
//1.0f, 1.0f, -5.0f,   -1.0f, 1.0f, -5.0f,   -1.0f, 1.0f, -6.0f,	// Top Face
//1.0f, 1.0f, -6.0f,   -1.0f, 1.0f, -6.0f,   1.0f, 1.0f, -5.0f,
//
//1.0f, 1.0f, -6.0f,   -1.0f, 1.0f, -6.0f,   -1.0f, -1.0f, -6.0f,	// Back face
//1.0f, 1.0f, -6.0f,   1.0f, -1.0f, -6.0f,   -1.0f, -1.0f, -6.0f,



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
	/*if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		for (int i = 0; i < 24; i++)
		{
			vertices[i] = (MyMatrix3::rotationX(0.01) * vertices[i]);
		}
	}
*/
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

