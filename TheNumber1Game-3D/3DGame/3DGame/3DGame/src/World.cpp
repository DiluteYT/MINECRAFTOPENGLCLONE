#include "World.h"
#include "Texture.h"

World::World(Shader& in_shader, Texture& in_textureAtlas, glm::vec2 atlasSize)
	:	shader(&in_shader),
	textureAtlas(&in_textureAtlas)
{

	chunks.emplace_back(shader, &atlasSize, &pm, Transform{glm::vec3(0), glm::vec3(0, 0, 0), glm::vec3(1)});

}