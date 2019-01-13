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


	for (int i = 0; i < 108; i++)
	{
		vertex_index[i] = i;
	}
	for (int i = 0; i < 8; i++)
	{
		translationArray[i] = { 1,1,1 };
	}




}

Game::~Game() {}

 //Vertices for one Triangle
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
	1.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 1.0f ,//1

	1.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 1.0f , //2

	1.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 1.0f,//3

	1.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 1.0f,

	1.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 1.0f,

	1.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 1.0f,

	1.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 1.0f,

	1.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 1.0f,

	1.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 1.0f,

	1.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 1.0f,

	1.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 1.0f,

	1.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 1.0f,
};   


// Index to be drawn
unsigned int vertex_index[] = { 0, 1, 2 ,3 ,4 , 5,6,7,8,9,10,11,12,13,14,15,16,17,18,19
,22,23 ,24 ,25 ,26, 27, 28,29 ,30,31 , 32 , 33,34,35,36};

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
	



	/// <summary>
	/// translation
	/// </summary>
	/// 
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		for (int i = 0; i < 8; i++)
		{
			if (translationArray[i].z >= 0)
			{

				translationArray[i] = (MyMatrix3::translation(MyVector3{ 0,0.01, 0 }) * translationArray[i]);
			}
			else
			{
				translationArray[i] = (MyMatrix3::translation(MyVector3{ 0,-0.01, 0 }) * translationArray[i]);
			}
		}
	}
	/// <summary>
	/// key presses for the translation down
	/// </summary>
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		for (int i = 0; i < 8; i++)
		{

			if (translationArray[i].z >= 0)
			{

				translationArray[i] = (MyMatrix3::translation(MyVector3{ 0, -0.01, 0 }) * translationArray[i]);
			}
			else
			{
				translationArray[i] = (MyMatrix3::translation(MyVector3{ 0,0.01, 0 }) * translationArray[i]);
			}
		}
	}
	/// <summary>
	/// key presses for the translation left
	/// </summary>
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		for (int i = 0; i < 8; i++)
		{

			if (translationArray[i].z >= 0)
			{

				translationArray[i] = (MyMatrix3::translation(MyVector3{ -0.01, 0, 0 }) * translationArray[i]);
			}
			else
			{
				translationArray[i] = (MyMatrix3::translation(MyVector3{ 0.01, 0, 0 }) * translationArray[i]);
			}
		}
	}
	/// <summary>
	/// key presses for the translation Right
	/// </summary>
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		for (int i = 0; i < 8; i++)
		{
			if (translationArray[i].z >= 0)
			{

				translationArray[i] = (MyMatrix3::translation(MyVector3{ 0.01, 0, 0 }) * translationArray[i]);
			}
			else
			{
				translationArray[i] = (MyMatrix3::translation(MyVector3{ -0.01, 0, 0 }) * translationArray[i]);
			}
		}
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
	{
		for (int i = 0; i < 8; i++)
		{
			vectorArray[i] = (MyMatrix3::scale(0.99) * vectorArray[i]);
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::X))
	{
		for (int i = 0; i < 8; i++)
		{
			vectorArray[i] = (MyMatrix3::scale(1.01) * vectorArray[i]);
		}
	}


	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		glLoadIdentity();
	}

	for (int i = 0; i < 8; i++)
	{
		resultVec[i] = vectorArray[i] + translationArray[i];
	}

	vertices[0] = resultVec[0].x;
	vertices[1] = resultVec[0].y;
	vertices[2] = resultVec[0].z;

	vertices[3] = resultVec[1].x;
	vertices[4] = resultVec[1].y;
	vertices[5] = resultVec[1].z;

	vertices[6] = resultVec[2].x;
	vertices[7] = resultVec[2].y;
	vertices[8] = resultVec[2].z;

	vertices[9] = resultVec[0].x;
	vertices[10] = resultVec[0].y;
	vertices[11] = resultVec[0].z;

	vertices[12] = resultVec[3].x;
	vertices[13] = resultVec[3].y;
	vertices[14] = resultVec[3].z;

	vertices[15] = resultVec[2].x;
	vertices[16] = resultVec[2].y;
	vertices[17] = resultVec[2].z;

	vertices[18] = resultVec[4].x;
	vertices[19] = resultVec[4].y;
	vertices[20] = resultVec[4].z;
	
	vertices[21] = resultVec[5].x;
	vertices[22] = resultVec[5].y;
	vertices[23] = resultVec[5].z;
	
	vertices[24] = resultVec[6].x;
	vertices[25] = resultVec[6].y;
	vertices[26] = resultVec[6].z;
	
	vertices[27] = resultVec[4].x;
	vertices[28] = resultVec[4].y;
	vertices[29] = resultVec[4].z;
	
	vertices[30] = resultVec[7].x;
	vertices[31] = resultVec[7].y;
	vertices[32] = resultVec[7].z;
	
	vertices[33] = resultVec[6].x;
	vertices[34] = resultVec[6].y;
	vertices[35] = resultVec[6].z;
	
	vertices[36] = resultVec[0].x;
	vertices[37] = resultVec[0].y;
	vertices[38] = resultVec[0].z;
	
	vertices[39] = resultVec[1].x;
	vertices[40] = resultVec[1].y;
	vertices[41] = resultVec[1].z;
	
	vertices[42] = resultVec[5].x;
	vertices[43] = resultVec[5].y;
	vertices[44] = resultVec[5].z;
	
	vertices[45] = resultVec[4].x;
	vertices[46] = resultVec[4].y;
	vertices[47] = resultVec[4].z;
	
	vertices[48] = resultVec[5].x;
	vertices[49] = resultVec[5].y;
	vertices[50] = resultVec[5].z;
	
	vertices[51] = resultVec[0].x;
	vertices[52] = resultVec[0].y;
	vertices[53] = resultVec[0].z;
	
	vertices[54] = resultVec[0].x;
	vertices[55] = resultVec[0].y;
	vertices[56] = resultVec[0].z;
	
	vertices[57] = resultVec[3].x;
	vertices[58] = resultVec[3].y;
	vertices[59] = resultVec[3].z;
	
	vertices[60] = resultVec[7].x;
	vertices[61] = resultVec[7].y;
	vertices[62] = resultVec[7].z;
	
	vertices[63] = resultVec[7].x;
	vertices[64] = resultVec[7].y;
	vertices[65] = resultVec[7].z;

	vertices[66] = resultVec[4].x;
	vertices[67] = resultVec[4].y;
	vertices[68] = resultVec[4].z;
	
	vertices[69] = resultVec[0].x;
	vertices[70] = resultVec[0].y;
	vertices[71] = resultVec[0].z;
	
	vertices[72] = resultVec[1].x;
	vertices[73] = resultVec[1].y;
	vertices[74] = resultVec[1].z;
	
	vertices[75] = resultVec[2].x;
	vertices[76] = resultVec[2].y;
	vertices[77] = resultVec[2].z;
	
	vertices[78] = resultVec[6].x;
	vertices[79] = resultVec[6].y;
	vertices[80] = resultVec[6].z;
	
	vertices[81] = resultVec[6].x;
	vertices[82] = resultVec[6].y;
	vertices[83] = resultVec[6].z;
	
	vertices[84] = resultVec[5].x;
	vertices[85] = resultVec[5].y;
	vertices[86] = resultVec[5].z;
	
	vertices[87] = resultVec[1].x;
	vertices[88] = resultVec[1].y;
	vertices[89] = resultVec[1].z;
	
	vertices[90] = resultVec[3].x;
	vertices[91] = resultVec[3].y;
	vertices[92] = resultVec[3].z;
	
	vertices[93] = resultVec[7].x;
	vertices[94] = resultVec[7].y;
	vertices[95] = resultVec[7].z;
	
	vertices[96] = resultVec[6].x;
	vertices[97] = resultVec[6].y;
	vertices[98] = resultVec[6].z;
	
	vertices[99] = resultVec[6].x;
	vertices[100] = resultVec[6].y;
	vertices[101] = resultVec[6].z;
	
	vertices[102] = resultVec[2].x;
	vertices[103] = resultVec[2].y;
	vertices[104] = resultVec[2].z;
	
	vertices[105] = resultVec[3].x;
	vertices[106] = resultVec[3].y;
	vertices[107] = resultVec[3].z;







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

	glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, &vertex_index);
	
	glDisableClientState(GL_COLOR_ARRAY);
	glDisableClientState(GL_VERTEX_ARRAY);

	window.display();

}

void Game::unload()
{
	cout << "Cleaning up" << endl;
}

