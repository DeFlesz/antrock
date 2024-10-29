#pragma once
#include <glad/gl.h>
#include <antrock/renderer/GL/VBO.hpp>

class VAO
{
private:
	unsigned int vaoID{};

public:
	VAO();
	~VAO();

	void Bind() const;
	void Unbind() const;
	void AddBuffer(const VBO& vbo);

};
