#include <antrock/renderer/GL/VBO.hpp>

VBO::VBO(const void* data, unsigned int size)
{
	glCreateBuffers(1, &vboID);
	Bind();
	glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);
}

VBO::~VBO()
{
}

void VBO::Bind() const
{
	glBindBuffer(GL_ARRAY_BUFFER, vboID);
}

void VBO::Unbind() const
{
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

const unsigned int VBO::getID() const
{
	return vboID;
}
