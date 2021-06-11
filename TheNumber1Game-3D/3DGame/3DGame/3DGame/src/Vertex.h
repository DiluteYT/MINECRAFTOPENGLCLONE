#pragma once

#include "glm/glm.hpp"

class Vertex {
	glm::vec3 Position = glm::vec3(0);
	glm::vec2 texCoord = glm::vec2(0);
public:


	Vertex(glm::vec3 p, glm::vec2 t)
		: Position(p), texCoord(t) {}
};
