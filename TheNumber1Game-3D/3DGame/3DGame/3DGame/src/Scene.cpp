#include "Scene.h"
#include "WindowCreation.h"
#include "Chunk.h"
#include "World.h"

Scene::Scene(WindowCreation* WC, Shader* in_shader, World* in_world)
	:	SceneCamera(glm::perspective(glm::radians(90.0f), WC->windowSize.x / WC->windowSize.y, 0.1f, 1000.0f), *in_shader),
	shader(in_shader),
	world(in_world)
{
}

void Scene::Update()
{
	for (size_t i = 0; i < Meshes.size(); i++)
	{
		if (Meshes[i]->modelMatrices.size() < 1)
			return;
		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, Meshes[i]->Mesh_Texture.ID);
		glBindVertexArray(Meshes[i]->mesh_VAO);
		if (Meshes[i]->instanced)
		{
			Meshes[i]->meshShader.SetUniformInteger("instanced", true);
			glDrawArraysInstanced(GL_TRIANGLES, 0, Meshes[i]->Vertices.size(), Meshes[i]->modelMatrices.size());


		} 
		else {
			Meshes[i]->meshShader.SetUniformInteger("instanced", false);
			for (size_t j = 0; j < Meshes[i]->modelMatrices.size(); j++)
			{
				Meshes[i]->meshShader.SetUniformMatrix4fv("model", Meshes[i]->modelMatrices[j]);
				glDrawArrays(GL_TRIANGLES, 0, Meshes[i]->Vertices.size());
			}
		}

		glBindVertexArray(0);
		glBindTexture(GL_TEXTURE_2D, 0);

	}
	shader->SetUniformInteger("instanced", false);
	glBindTexture(GL_TEXTURE_2D, world->textureAtlas->ID);
	for (size_t i = 0; i < world->chunks.size(); i++)
	{
		shader->SetUniformMatrix4fv("model", world->chunks[i].transform.to_mat4());

		glBindVertexArray(world->chunks[i].VAO);
		glDrawArrays(GL_TRIANGLES, 0, world->chunks[i].verts.size());
	}
}