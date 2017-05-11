#include "Scene_Manager.h"
#include <glm\glm.hpp>
#include <glm\common.hpp>
#include <glm\mat4x4.hpp>
#include <glm\vec3.hpp>
#include <glm\vec4.hpp>
#include <glm\gtc\matrix_transform.hpp>
#include <glm\gtc\quaternion.hpp>
#include <glm\gtc\type_ptr.hpp>
#include <glm\gtx\euler_angles.hpp>
#include <glm\gtx\quaternion.hpp>
#include <glm\detail\func_common.hpp>
#include <time.h>
#include "..\Core\Camera.h"
using namespace Managers;

Scene_Manager::Scene_Manager() {
	glEnable(GL_DEPTH_TEST);
	GLfloat density = 0.3;
	GLfloat fogColor[4] = { 0.0, 0.0, 1.0, 1.0 };
	glEnable(GL_FOG);
	glFogi(GL_FOG_MODE, GL_EXP2);
	glFogfv(GL_FOG_COLOR, fogColor);
	glFogf(GL_FOG_DENSITY, density);
	glEnable(GL_BUFFER);
	glEnable(GL_MULTISAMPLE);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glShadeModel(GL_SMOOTH);
	glColor3f(1, 0, 0);
	glEnable(GL_COLOR_MATERIAL);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	//glColor4f(0.0f, 1.0f, 0.0f, 1.0f); // Set the colour to green and fully opaque  
	//glutSolidCube(1.0f); // Render the primitive  
	//bool* keyStates = new bool[256]{ 0 }; // Create an array of boolean values of length 256 (0-255)  
	glHint(GL_FOG_HINT, GL_NICEST);
	shader_manager = new Shader_Manager();
	shader_manager->CreateProgram("tcubeShader", "Shaders\\TVertex_Shader.glsl", "Shaders\\TFragment_Shader.glsl");
	eye_pos = glm::vec3(1.0f, 0.0f, 0.0f);
	view_mat = glm::mat4(1.0f, 0.0f, 0.0f, 0.0f,
		0.0f, 1.0f, 0.0f, 0.0f,
		0.0f, 0.0f, -1.0f, 0.0f,
		0.0f, 0.0f, 0.0f, 1.0f);
	cam = new Camera(view_mat);
	models_manager = new Models_Manager();
}

Scene_Manager::~Scene_Manager() {
	delete shader_manager;
	delete models_manager;
}

void Scene_Manager::notifyBeginFrame() {
	char key = '1';
	if (GetAsyncKeyState('W')) {
		key = 'w';
		cam->KeyPressed(key, 0, 0);

	}if (GetAsyncKeyState('A')) {
		key = 'a';
		cam->KeyPressed(key, 0, 0);

	}if (GetAsyncKeyState('S')) {
		key = 's';
		cam->KeyPressed(key, 0, 0);

	}if (GetAsyncKeyState('D')) {
		key = 'd';
		cam->KeyPressed(key, 0, 0);
	}
	POINT mousePos;
	GetCursorPos(&mousePos);
	cam->MouseMove(mousePos.x, mousePos.y, 1280, 720);
	models_manager->Update();
}

void Scene_Manager::Move() {
	if (GetKeyState(50)) {
		view_mat = glm::mat4(1.0f, 0.0f, 0.0f, 0.0f,
			0.0f, 1.0f, 0.0f, 0.0f,
			0.0f, 0.0f, -1.0f, 0.0f,
			0.0f, 0.0f, 10.0f, 1.0f);
	}

}
void processNormalKeys(unsigned char key, int x, int y) {

	if (key == 'w') {
		std::cout << "W";
		//Scene_Manager::Move();
	}
	else if (key == 'a') {
		std::cout << "A";

	}
	else if (key == 's') {
		std::cout << "S";

	}
	else if (key == 'd') {
		std::cout << "D";

	}

	if (key == 27)
		exit(0);
}
void Scene_Manager::notifyDisplayFrame() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0.3, 0.3, 0.3, 1.0);
	glutKeyboardFunc(processNormalKeys);

	models_manager->Draw();
	models_manager->Draw(proj_mat, view_mat);
}
/*
void Scene_Manager::KeyPressed(const unsigned char key) {
	float dx = 0; //how much we strafe on x
	float dz = 0; //how much we walk on z
	switch (key)
	{
	case 'w':
	{
		dz = 2;
		break;
	}

	case 's':
	{
		dz = -2;
		break;
	}
	case 'a':
	{
		dx = -2;
		break;
	}

	case 'd':
	{
		dx = 2;
		break;
	}
	default:
		break;
	}

	//get current view matrix
	glm::mat4 mat = view_mat;
	//row major
	glm::vec3 forward(mat[0][2], mat[1][2], mat[2][2]);
	glm::vec3 strafe(mat[0][0], mat[1][0], mat[2][0]);

	const float speed = 0.12f;//how fast we move
	//eyeVector += (-dz * forward + dx * strafe) * speed;

}*/

void Scene_Manager::notifyEndFrame() {

}

void Scene_Manager::notifyReshape(int width, int height, int previous_width, int previous_height) {
	float ar = (float)glutGet(GLUT_WINDOW_WIDTH) / (float)glutGet(GLUT_WINDOW_HEIGHT);
	float angle = 45.0f, near1 = 0.1f, far1 = 2000.0f;
	proj_mat[0][0] = 1.0f / (ar * tan(angle / 2.0f));
	proj_mat[1][1] = 1.0f / tan(angle / 2.0f);
	proj_mat[2][2] = (-near1 - far1) / (near1 - far1);
	proj_mat[2][3] = 1.0f;
	proj_mat[3][2] = 2.0f * near1 * far1 / (near1 - far1);
}