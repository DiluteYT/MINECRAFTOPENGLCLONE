#include "glew.h"
#include "Texture.h"

#define STB_IMAGE_IMPLEMENTATION
#include "stb/stb_image.h"
#include "glfw3.h"


Texture::Texture(const char* filename, bool nn)
	: Filename(filename)
{


	// TEXTURE
	glGenTextures(1, &ID);
	glBindTexture(GL_TEXTURE_2D, ID);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	// set the texture wrapping/filtering options (on the currently bound texture object)
	if (nn)
	{

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	}
	else
	{
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	}


	// load and generate the texture
	int width, height, nrChannels;
	unsigned char* data = stbi_load(Filename, &width, &height, &nrChannels, 0);

	GLint format = GL_RGB;
	if (nrChannels == 4)
		format = GL_RGBA;

	// Generate texture
	if (data) {
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, format, GL_UNSIGNED_BYTE, data);
	}
	else
		std::cout << "Failed to load texture: " << Filename << "\n";

	if (!nn)
	{
		glGenerateMipmap(GL_TEXTURE_2D);
	}


	// Cleanup
	stbi_image_free(data);
}