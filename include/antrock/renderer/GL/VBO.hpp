#pragma once
#include <glad/gl.h>

class VBO
{
private:
	unsigned int vboID;

public:
	VBO(const void* data, unsigned int size);
	~VBO();
	
	void Bind() const;
	void Unbind() const;
	const unsigned int getID() const;
};
