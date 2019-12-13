/*
		author		:		yangzijian
		time		:		2019-12-9 19:31:49
		function	:		lesson01 create a trangle
*/

/*
顶点数组对象：Vertex Array Object，VAO
顶点缓冲对象：Vertex Buffer Object，VBO
索引缓冲对象：Element Buffer Object，EBO或Index Buffer Object，IBO
*/
#include "Lesson01.h"
#include <iostream>
#include "Util.h"

void Lesson01::bindBuffer()
{
	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);
	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
	glBindVertexArray(0);
}

void Lesson01::createShader()
{
	unsigned int vertexShader;
	unsigned int fragmentShader;

	vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShader, 1, &verticesBufferCode, NULL);
	glCompileShader(vertexShader);

	util::showCompileError(vertexShader);

	fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, &fragmentShaderBufferCode, NULL);
	glCompileShader(fragmentShader);

	util::showCompileError(fragmentShader);

	shaderProgram = glCreateProgram();
	glAttachShader(shaderProgram, vertexShader);
	glAttachShader(shaderProgram, fragmentShader);
	glLinkProgram(shaderProgram);

	int success;
	glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
	if (!success)
	{
		char info[512];
		glGetProgramInfoLog(shaderProgram, 512, NULL, info);
		std::cout << "ERROR::PROGRAM:" << info << std::endl;
	}
	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);
}

// 绘制开始处理
void Lesson01::prefix() {
	bindBuffer();
	createShader();
}
// 循环绘制
void Lesson01::show() {
	glUseProgram(shaderProgram);
	glBindVertexArray(VAO);
	glDrawArrays(GL_TRIANGLES, 0, 3);
}
// 程序结束处理
void Lesson01::over() {

}