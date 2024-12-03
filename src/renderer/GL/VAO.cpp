#include <antrock/renderer/GL/VAO.hpp>
/* TODO
* [] - make sure that you don't bind when unnecessary
* 
*/

VAO::VAO()
{
	glGenVertexArrays(1, &vaoID);
}

VAO::~VAO()
{
	glDeleteVertexArrays(1, &vaoID);
}

void VAO::Bind() const
{
	glBindVertexArray(vaoID);
}

void VAO::Unbind() const
{
	glBindVertexArray(0);
}

void VAO::AddBuffer(const VBO& vbo)
{
	Bind();
	vbo.Bind();
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);
}
