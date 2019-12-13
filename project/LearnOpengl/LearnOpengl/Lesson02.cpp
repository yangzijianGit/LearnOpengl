#include "Lesson02.h"
#include "Util.h"

Lesson02::Lesson02()
{

}


Lesson02::~Lesson02()
{

}

// 绘制开始处理
void Lesson02::prefix()
{
	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);

	unsigned int VBO;
	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	unsigned int EBO;
	glGenBuffers(1, &EBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShader, 1, &verticesBufferCode, 0);
	glCompileShader(vertexShader);
	util::showCompileError(vertexShader);

	unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, &fragmentShaderCode, 0);
	glCompileShader(fragmentShader);
	util::showCompileError(fragmentShader);

	program = glCreateProgram();
	glAttachShader(program, vertexShader);
	glAttachShader(program, fragmentShader);
	glLinkProgram(program);
	util::showLinkShaderError(program);

	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);

}

// 循环绘制
void Lesson02::show()
{
	glUseProgram(program);
	glBindVertexArray(VAO);
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}

// 程序结束处理
void Lesson02::over()
{

}
