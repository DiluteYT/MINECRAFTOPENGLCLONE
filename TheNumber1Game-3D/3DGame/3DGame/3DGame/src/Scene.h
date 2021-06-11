#pragma once

#include "Renderer2D.h"
#include "Camera.h"

class WindowCreation;
class CameraMovement;
class Chunk;
class World;

class Scene
{
public:
	std::vector<Mesh*> Meshes;	

	World* world;

	Shader* shader;

	Camera SceneCamera;

	Scene(WindowCreation* WC, Shader* shader, World* in_world);

	void Update();

};
