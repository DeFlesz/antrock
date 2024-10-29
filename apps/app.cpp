#include <iostream>

#include <glad/gl.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

#include <antrock/renderer/renderer.hpp>
#include <antrock/renderer/GL/Shader.hpp>

int main()
{
	std::string vertexShaderCode = 
	R"(#version 330 core

	layout (location = 0) in vec3 position;

	out vec3 vertColor;

	void main(void)
	{
		vertColor = vec3(1.0, 0.0, 0.0);
		gl_Position = vec4(position, 1.0);
	}
	)";

	std::string fragmentShaderCode = 
	R"(
	#version 330 core

	in vec3 vertColor;

	out vec4 color;

	void main(void)
	{
		color = vec4(vertColor, 1.0);
	}
	)";



	std::cout << "Hello, world!" << std::endl;
	//renderer r;
	//r.test();
	if (!glfwInit())
	{
	    // Initialization failed
	}
	GLFWwindow* window = glfwCreateWindow(640, 480, "My Title", NULL, NULL);
	if (!window)
	{
		// Window or OpenGL context creation failed
	}
	glfwMakeContextCurrent(window);
	gladLoadGL(glfwGetProcAddress);
	
	Shader shader1(vertexShaderCode, fragmentShaderCode);
	shader1.use();
	while (!glfwWindowShouldClose(window))
	{
		// Keep running
	}
	return 0;
}
