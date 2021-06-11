#include "WindowCreation.h"
#include "stb/stb_image.h"

#include <iostream>

void framebuffer_size_callback(GLFWwindow* window, const int width, const int height)
{
	glViewport(0, 0, width, height);
}

WindowCreation::WindowCreation(const glm::vec2 windowsize, const char* windowname)
	: windowSize(windowsize),
	windowName(windowname)
{

	stbi_set_flip_vertically_on_load(true);

	/* Initialize the library */
	if (!glfwInit())
		std::cout << "GLFW INIT ERROR" << std::endl;

	/* NOTE:
	Legacy OpenGL code such as glBegin() and glEnd()
	will not work with the OpenGL profile being set
	to Core 3.3 below this note.
	
	With the latest OpenGL version, VAOs are deprecated,
	and you no longer need them.
	*/
	

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	/* Create a windowed mode window and its OpenGL context */
	window = glfwCreateWindow(windowSize.x, windowSize.y, windowName, NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		std::cout << "WINDOW CREATION ERROR" << std::endl;
	}

	glViewport(0, 0, windowSize.x, windowSize.y);

	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

	/* Make the window's context current */
	glfwMakeContextCurrent(window);

	glfwSwapInterval(0); // 0 = unlimited, 1 = vsync
	glewExperimental = GL_TRUE;
	if (glewInit() != GLEW_OK)
	{
		std::cout << "GLEW WAS NOT INITIALIZED PROPERLY" << std::endl;
	}

	glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

	glEnable(GL_CULL_FACE);
	glEnable(GL_DEPTH_TEST);
	glClearColor(0.2f, 0.2f, 0.2f, 1.0f);
}