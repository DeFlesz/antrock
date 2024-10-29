#include <iostream>

#include <glad/gl.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

#include <antrock/renderer/renderer.hpp>
#include <antrock/renderer/GL/Shader.hpp>
#include <antrock/renderer/GL/VBO.hpp>
#include <antrock/renderer/GL/VAO.hpp>

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}

int main()
{
	std::string vertexShaderCode = 
	R"(#version 330 core

layout (location = 0) in vec3 position;

out vec3 vertColor;

void main(void)
{
	vertColor = vec3(1.0, 0.0, 1.0);
	gl_Position = vec4(position, 1.0);
})";

	std::string fragmentShaderCode = 
	R"(#version 330 core

in vec3 vertColor;

out vec4 color;

void main(void)
{
	color = vec4(vertColor, 1.0);
})";

	float vertices[] = {
		// first triangle
		0.5f,  0.5f, 0.0f,  // top right
		0.5f, -0.5f, 0.0f,  // bottom right
		-0.5f,  0.5f, 0.0f,  // top left 
		// second triangle
		0.5f, -0.5f, 0.0f,  // bottom right
		-0.5f, -0.5f, 0.0f,  // bottom left
		-0.5f,  0.5f, 0.0f   // top left
	};


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
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

	Shader shader1(vertexShaderCode, fragmentShaderCode);
	shader1.use();

	VAO vao;
	VBO vbo(vertices, sizeof(vertices));
	vao.AddBuffer(vbo);

	while (!glfwWindowShouldClose(window))
	{
		glDrawArrays(GL_TRIANGLES, 0, 3);
		glfwSwapBuffers(window);
		// Keep running
	}
}
