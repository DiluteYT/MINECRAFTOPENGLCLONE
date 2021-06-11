#pragma once
#include "Transform.h"
#include "Shader.h"
#include "Texture.h"
#include "Vertex.h"

#include <iostream>
#include <vector>




class Mesh {
public:
	std::vector<Vertex> Vertices;
	std::vector<glm::mat4> modelMatrices;

	Texture Mesh_Texture;

	bool instanced = false;
	
	unsigned int mesh_VAO;

	void InjectObject(Transform& transform);

	Shader meshShader;

	void instancingUpdate();
	Mesh(std::vector<Vertex> vertices, const char* texture, bool in, bool nn, Shader& thisShader);
private:

	unsigned int mesh_VBO;
	unsigned int instanced_mesh_VBO;


};