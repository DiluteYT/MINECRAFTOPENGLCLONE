#include "glew.h"
#include "Chunk.h"
#include "Shader.h"

Chunk::Chunk(Shader* in_shader, glm::vec2* in_atlasSize, PerlinMath* in_pm, Transform in_transform)
	: shader(in_shader),
	atlasSize(in_atlasSize),
	pm(in_pm),
	transform(in_transform)
{
	generateHeightValues();
	generateMesh();
	buildVAO();
}


Chunk::~Chunk() {

}

void Chunk::generateHeightValues()
{
	for (size_t x = 0; x < heightValues[0].size(); x++)
	{
		for (size_t z = 0; z < heightValues[1].size(); z++)
		{
			heightValues[x][z] = pm->noise(x + transform.position.x, z + transform.position.z);
		}
	}

}

void Chunk::generateMesh()
{
	for (int x = 0; x < heightValues[0].size(); x++)
	{
		for (int z = 0; z < heightValues[1].size(); z++)
		{
			x0 = x;
			z0 = z;
			x1 = x + 1;
			z1 = z - 1;
				height = heightValues[x][z];

			// Top corners
			glm::vec3 cornerA(glm::vec3(x0, height, z0));
			glm::vec3 cornerB(glm::vec3(x1, height, z0));
			glm::vec3 cornerC(glm::vec3(x1, height, z1));
			glm::vec3 cornerD(glm::vec3(x0, height, z1));

			AddTop(cornerA, cornerB, cornerC, cornerD);
			AddSide(cornerA, cornerD, x - 1, height, z);
			AddSide(cornerD, cornerC, x, height, z - 1);
			AddSide(cornerC, cornerB, x + 1, height, z);
			AddSide(cornerB, cornerA, x, height, z + 1);
			
		}
	}

}

void Chunk::AddTop(glm::vec3 cornerA, glm::vec3 cornerB, glm::vec3 cornerC, glm::vec3 cornerD) {
	// Top Triangle 1
	verts.emplace_back(cornerD, coordsFromAtlas(0, 1, atlasOffset.x, atlasOffset.y));
	verts.emplace_back(cornerA, coordsFromAtlas(0, 0, atlasOffset.x, atlasOffset.y));
	verts.emplace_back(cornerB, coordsFromAtlas(1, 0, atlasOffset.x, atlasOffset.y));

	// Top Triangle 2
	verts.emplace_back(cornerD, coordsFromAtlas(0, 1, atlasOffset.x, atlasOffset.y));
	verts.emplace_back(cornerB, coordsFromAtlas(1, 0, atlasOffset.x, atlasOffset.y));
	verts.emplace_back(cornerC, coordsFromAtlas(1, 1, atlasOffset.x, atlasOffset.y));
}

void Chunk::AddSide(glm::vec3 topL, glm::vec3 topR, int x, int height, int z)
{
	// Bail if outside of array bounds
	if ((x < 0) || (z < 0) || (x >= heightValues[0].size()) || (z >= heightValues[1].size()))
		return;

	// Find the height this side needs to be
	sideHeight = height - heightValues[x][z];

	// Bail if there's no side to draw
	if (sideHeight <= 0)
		return;


	// Add all dem sides
	for (size_t i = 0; i < sideHeight; i++)
	{	

		pseudoTopL = glm::vec3(topL.x, topL.y - i, topL.z);
		pseudoTopR = glm::vec3(topR.x, topR.y - i, topR.z);
		pseudoBottomL = glm::vec3(topL.x, topL.y - i - 1, topL.z);
		pseudoBottomR = glm::vec3(topR.x, topR.y - i - 1, topR.z);

		Vertex vert0 = Vertex(pseudoTopL, coordsFromAtlas(0, 1, atlasOffset.x, atlasOffset.y));
		Vertex vert1 = Vertex(pseudoTopR, coordsFromAtlas(1, 1, atlasOffset.x, atlasOffset.y));
		Vertex vert2 = Vertex(pseudoBottomL, coordsFromAtlas(0, 0, atlasOffset.x, atlasOffset.y));
		Vertex vert3 = Vertex(pseudoBottomR, coordsFromAtlas(1, 0, atlasOffset.x, atlasOffset.y));

		// Triangle 1
		verts.emplace_back(vert2);
		verts.emplace_back(vert0);
		verts.emplace_back(vert3);
		// Triangle 2
		verts.emplace_back(vert3);
		verts.emplace_back(vert0);
		verts.emplace_back(vert1);
	}
}

glm::vec2 Chunk::coordsFromAtlas(int x, int y, int elementX, int elementY) {
	return glm::vec2((x / atlasSize->x) + (elementX / atlasSize->x), (y / atlasSize->y) + (elementY / atlasSize->y));
}

void Chunk::buildVAO()
{
	unsigned int VBO;
	// create buffers/arrays
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	glGenBuffers(1, &VBO);

	// load data into vertex buffers
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, verts.size() * sizeof(Vertex), &verts[0], GL_STATIC_DRAW);

	glBindVertexArray(VAO);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
}