#pragma once

#include "pn/Perlin.h"
#include "Vertex.h"
#include "Transform.h"

#include <array>
#include <vector>

class Shader;

class Chunk
{
private:

	glm::vec2* atlasSize = nullptr;

	PerlinMath* pm;

	glm::vec2 atlasOffset = glm::vec2(0, 3);


	glm::vec2 coordsFromAtlas(int x, int y, int elementX, int elementY);
	void generateMesh();
	void generateHeightValues();
	void buildVAO();
	void AddSide(glm::vec3 topL, glm::vec3 topR, int x, int height, int z);
	void AddTop(glm::vec3 cornerA, glm::vec3 cornerB, glm::vec3 cornerC, glm::vec3 cornerD);

public:

	std::array<std::array<int, 80>, 80> heightValues;

	std::vector<Vertex> verts;
	unsigned int VAO;
	Shader* shader;
	Transform transform;

	Chunk(Shader* in_shader, glm::vec2* in_atlasSize, PerlinMath* in_pm, Transform in_transform);
	~Chunk();

private:
	float x0 = 0;
	float z0 = 0;
	float x1 = 0;
	float z1 = 0;
	float height = 0;
	float sideHeight = 0;

	glm::vec3 pseudoTopL = glm::vec3(0);
	glm::vec3 pseudoTopR = glm::vec3(0);
	glm::vec3 pseudoBottomL = glm::vec3(0);
	glm::vec3 pseudoBottomR = glm::vec3(0);
};