#pragma once

#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"

struct Transform
{
	glm::vec3 rotation = glm::vec3(0.0f, 0.0f, 0.0f);
	glm::vec3 position = glm::vec3(0.0f, 0.0f, 0.0f);
	glm::vec3 scale = glm::vec3(1.0f, 1.0f, 1.0f);
	Transform(glm::vec3 in_position, glm::vec3 in_rotation, glm::vec3 in_scale) : position(in_position), rotation(in_rotation), scale(in_scale) { }
	Transform() { }

	glm::mat4 to_mat4()
	{
		glm::mat4 m = glm::mat4(1.0f);
		m = glm::translate(m, position);
		m = glm::rotate(m, glm::radians(rotation.z), glm::vec3(0, 0, 1));
		m = glm::rotate(m, glm::radians(rotation.y), glm::vec3(0, 1, 0));
		m = glm::rotate(m, glm::radians(rotation.x), glm::vec3(1, 0, 0));
		m = glm::scale(m, scale);

		return m;
	}
};
