#include "InternalData.h"
#include "Shader.h"
#include "Scene.h"
#include "WindowCreation.h"
#include "Time.h"
#include "Shapes.h"
#include "pn/Perlin.h"
#include "Chunk.h"
#include "World.h"

int main()
{


	// WindowCreation should be first 99% of the time.
	WindowCreation wc(glm::vec2(1920, 1080), "3D Game");
	Shader shader("res/shaders/shader.shader");
	shader.Bind();
	Time time;

	Texture textureatlas1("res/textures/atlas1.png", true);

	World world(shader, textureatlas1, glm::vec2(4,4));
	world.chunks[0].transform.position += glm::vec3(10000, 0, 10000);

	Scene scene1(&wc, &shader, &world);
	scene1.SceneCamera.transform.position += glm::vec3(10000, 0, 10000);
	InternalData INTERNAL_DATA(&scene1, &shader, &wc, &time);

	float movementSpeed = 10.0f;

	CameraMovement cameramovement(&INTERNAL_DATA, movementSpeed);

	
	while (!glfwWindowShouldClose(wc.window))
	{

		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		INTERNAL_DATA.SoF_InternalUpdate();

		cameramovement.StartOfFrame();

		glfwSwapBuffers(wc.window); // Dont render anything after swapping the buffers.

		glfwPollEvents();

		INTERNAL_DATA.EoF_InternalUpdate();

		cameramovement.EndOfFrame();

	}

	glfwTerminate();
	return 0;
}