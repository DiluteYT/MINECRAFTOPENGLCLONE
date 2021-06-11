#pragma once

#include "glew.h"
#include "glfw3.h"
#include "glm/glm.hpp"

class WindowCreation
{
public:


	WindowCreation(const glm::vec2 windowsize, const char* windowname);
	GLFWwindow* window;

	glm::vec2 windowSize;
	const char *windowName = "";

};
