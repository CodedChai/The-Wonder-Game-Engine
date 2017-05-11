#pragma once
#include "glm\glm.hpp"
#include "../Dependencies/freeglut/glut.h"
#include "glm/gtx/rotate_vector.hpp"
#include "glm/gtx/rotate_normalized_axis.hpp"
#include "glm/gtx/euler_angles.hpp"
#include <iostream>
class Camera
{
public:
	Camera(glm::mat4& view);
	~Camera();
	void UpdateView();
	glm::mat4 GetViewMatrix() const;
	void KeyPressed(unsigned char key, int x, int y);
	void MouseMove(int x, int y, int width, int height);
	void MousePressed(int button, int state, int x, int y);
	glm::mat4* viewMatrix;
	bool isMousePressed;
	glm::vec2 mousePosition;

	float yaw, pitch, roll;
	glm::vec3 eyeVector;
};