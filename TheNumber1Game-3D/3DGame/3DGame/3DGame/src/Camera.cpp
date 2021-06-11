#include "Shader.h"
#include "InternalData.h"
#include "Camera.h"
#include "Input.h"
#include "Scene.h"
#include "Time.h"
#include "WindowCreation.h"

#include <iostream>

void Camera::BindProjection(Shader& shader) 
{
	shader.SetUniformMatrix4fv("projection", projection);
}

glm::mat4 Camera::transform_to_mat4()
{
	glm::mat4 m = glm::mat4(1.0f);

	m = glm::translate(m, transform.position);
	m = glm::rotate(m, transform.rotation.z, glm::vec3(0, 0, 1));
	m = glm::rotate(m, transform.rotation.y, glm::vec3(0, 1, 0));
	m = glm::rotate(m, transform.rotation.x, glm::vec3(1, 0, 0));

	return m;
		
}

void Camera::CalculateMatrices(Shader& shader) {
	glm::mat4 transform = transform_to_mat4();

	right = glm::vec3(transform[0]);
	up = glm::vec3(transform[1]);
	forward = -glm::vec3(transform[2]);

	view = glm::inverse(transform);
	shader.SetUniformMatrix4fv("view", view);
}

CameraMovement::CameraMovement(InternalData* in_data, const float in_movementSpeed)
	:	movementSpeed(in_movementSpeed), data(in_data)
{

}

void CameraMovement::StartOfFrame()
{

	glfwGetCursorPos(data->wc->window, &tempX, &tempY);
}

void CameraMovement::EndOfFrame()
{
	data->boundScene->SceneCamera.transform.rotation.x += m.x;
	data->boundScene->SceneCamera.transform.rotation.y += m.y;


	if (Input::KeyPressed(83, data->wc->window))
		data->boundScene->SceneCamera.transform.position -= (data->boundScene->SceneCamera.forward * movementSpeed) * data->time->deltaTime;
	else if (Input::KeyPressed(87, data->wc->window))
		data->boundScene->SceneCamera.transform.position += (data->boundScene->SceneCamera.forward * movementSpeed) * data->time->deltaTime;

	if (Input::KeyPressed(65, data->wc->window))
		data->boundScene->SceneCamera.transform.position -= (data->boundScene->SceneCamera.right * movementSpeed) * data->time->deltaTime;
	else if (Input::KeyPressed(68, data->wc->window))
		data->boundScene->SceneCamera.transform.position += (data->boundScene->SceneCamera.right * movementSpeed) * data->time->deltaTime;

	if (Input::KeyPressed(32, data->wc->window))
		data->boundScene->SceneCamera.transform.position.y += movementSpeed * data->time->deltaTime;
	else if (Input::KeyPressed(340, data->wc->window))
		data->boundScene->SceneCamera.transform.position.y -= movementSpeed * data->time->deltaTime;

	m = Input::UpdateMouse(glm::vec2(tempX, tempY), data->wc->window);
}
