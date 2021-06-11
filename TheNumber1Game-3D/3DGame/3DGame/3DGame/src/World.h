#pragma once

#include "Chunk.h"
#include "pn/Perlin.h"

#include <vector>

class Texture;	

class World
{
public:
	Texture* textureAtlas;
	std::vector<Chunk> chunks;

	World(Shader& in_shader, Texture& in_textureAtlas, glm::vec2 atlasSize);
private:

	PerlinMath pm;
	Shader* shader = nullptr;
};


