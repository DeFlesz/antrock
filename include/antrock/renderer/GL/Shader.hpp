#pragma once
#include <glad/gl.h>
#include <iostream>
#include <vector>

class Shader
{
private:
	unsigned int shaderID;

	std::string vertexShaderCode;
	std::string fragmentShaderCode;

	void createShader();
	int compileShader(unsigned int shaderType, const std::string& shaderSrc);
public:
	Shader();
	Shader(std::string vertexShaderCode, std::string fragmentShaderCode);
	Shader(const char* vertexShaderCode, const char* fragmentShaderCode);
	~Shader();

	void use();
};
