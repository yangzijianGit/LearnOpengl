#include "Lesson06.h"
#include <glad/glad.h>


void Lesson06::prefix()
{
	glGenVertexArrays(1, &m_nVAO);
	glBindVertexArray(m_nVAO);

	unsigned int nVertexBuffer;
	glGenBuffers(1, &nVertexBuffer);
	glBufferData(nVertexBuffer, sizeof(triangle), triangle, GL_STATIC_DRAW);

	unsigned int nTexture;
	glGenTextures(1, &nTexture);

}
void Lesson06::show()
{

}
void Lesson06::over()
{

}