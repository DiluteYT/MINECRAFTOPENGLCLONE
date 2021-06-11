#pragma once

#include <glm/gtc/matrix_transform.hpp>
#include "glm/glm.hpp"

class Shader;
class WindowCreation;
class InternalData;

struct ctransform {
	glm::vec3 position = glm::vec3(0, 0, 0);
	glm::vec3 rotation = glm::vec3(0, 0, 0);
};

class Camera
{

public:

	glm::vec3 right = glm::vec3(0);
	glm::vec3 up = glm::vec3(0);
	glm::vec3 forward = glm::vec3(0);

	ctransform transform;

	Camera(glm::mat4 c_proj, Shader& shader)
		: projection(c_proj)
	{ 
		shader.SetUniformMatrix4fv("projection", projection);
	}

	glm::mat4 projection;
	glm::mat4 view = glm::mat4(1.0f);

	void BindProjection(Shader& shader);
	glm::mat4 transform_to_mat4();
	void CalculateMatrices(Shader& shader);

};

class CameraMovement
{
	InternalData* data;

	float movementSpeed = 15.0f;

	double tempX = 0; double tempY = 0;
	glm::vec2 m = glm::vec2(0);

public:

	CameraMovement(InternalData* in_data, const float in_movementSpeed);
	void StartOfFrame();
	void EndOfFrame();
};
