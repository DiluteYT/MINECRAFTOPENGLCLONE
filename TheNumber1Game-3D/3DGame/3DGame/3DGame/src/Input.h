#pragma once

#include "glfw3.h"
#include "glm/glm.hpp"

class Input {
public:
	static bool KeyPressed(int key, GLFWwindow* window);

	static glm::vec2 UpdateMouse(glm::vec2 oldpos, GLFWwindow* window);
};

