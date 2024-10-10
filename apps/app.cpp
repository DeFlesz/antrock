#include <iostream>

#include <glad/gl.h>
#include <GLFW/glfw3.h>

#include <antrock/renderer/renderer.hpp>

int main()
{
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
	while (!glfwWindowShouldClose(window))
	{
		// Keep running
	}
	return 0;
}
