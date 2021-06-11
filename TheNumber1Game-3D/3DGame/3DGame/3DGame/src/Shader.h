#pragma once

#include <glew.h>
#include <string>
#include <tuple>

#include "glm/glm.hpp"

class Shader
{
private:
	std::string m_FilePath;
public:
	Shader(const std::string& filepath);
	~Shader();

	void Bind() const;
	void Unbind() const;

	unsigned int m_RendererID;

	void SetUniformMatrix4fv(const char* name, const glm::mat4& value);
	void SetUniformInteger(const char* name, const int value);

private:
	std::tuple<std::string, std::string> ParseShader(const std::string& filepath);
	unsigned int CreateShader(const std::string& vertexShader, const std::string& fragmentShader);
	unsigned int CompileShader(unsigned int type, const std::string& source);
};


