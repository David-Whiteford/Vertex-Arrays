#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/OpenGL.hpp>
#include <gl/GL.h>
#include <gl/GLU.h>

#include <MyVector3.h>
#include <MyMatrix3.h>

using namespace std;
using namespace sf;


class Game
{
public:
	Game();
	~Game();
	void run();
private:
	Window window;
	bool isRunning = false;
	MyVector3 vectorArray[8]; 
	MyVector3 translationArray[8];
	MyVector3 C1{ 1.0f, 1.0f, -5.0f };
	MyVector3 C2{ -1.0f, 1.0f, -5.0f };
	MyVector3 C3{ -1.0f, -1.0f, -5.0f };
	MyVector3 C4{ 1.0f, -1.0f, -5.0f };

	MyVector3 C5{ 1.0f, 1.0f, -6.0f };
	MyVector3 C6{ -1.0f, 1.0f, -6.0f };
	MyVector3 C7{ -1.0f, -1.0f, -6.0f };
	MyVector3 C8{ 1.0f, -1.0f, -6.0f };

	void initialize();
	void update();
	void render();
	void unload();

	Clock clock;
	Time elapsed;

	float rotationAngle = 0.0f;
};