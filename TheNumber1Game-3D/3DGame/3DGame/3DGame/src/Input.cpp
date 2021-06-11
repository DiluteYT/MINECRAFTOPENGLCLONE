#include "Input.h"

bool Input::KeyPressed(int key, GLFWwindow* window)
{
	if (glfwGetKey(window, key) == GLFW_PRESS)
		return true;
	else return false;
}


glm::vec2 Input::UpdateMouse(glm::vec2 oldpos, GLFWwindow* window)
{
	double newx, newy;

	glfwGetCursorPos(window, &newx, &newy);
	float xoffset = (float)newx - oldpos.x;
	float yoffset = oldpos.y - (float)newy; // reversed since y-coordinates go from bottom to top

	return glm::vec2(yoffset, -xoffset) / glm::vec2(200);
}