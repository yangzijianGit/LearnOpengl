#include "Lesson04.h"
#include "glad/glad.h"
#include "Util.h"
#include <glfw3.h>
#include <cmath>

void Lesson04::CreateVAO1()
{
	util::showGlInfo();
	glGenVertexArrays(1, &VAO1);
	glBindVertexArray(VAO1);

	unsigned int VBO;
	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices1), vertices1, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, false, 3 * sizeof(float), 0);
	glEnableVertexAttribArray(0);

	unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShader, 1, &vertexShaderSource, nullptr);
	glCompileShader(vertexShader);
	util::showCompileError(vertexShader);

	unsigned int fragmenetShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmenetShader, 1, &fragmentShaderSource, nullptr);
	glCompileShader(fragmenetShader);
	util::showCompileError(fragmenetShader);

	program1 = glCreateProgram();
	glAttachShader(program1, vertexShader);
	glAttachShader(program1, fragmenetShader);
	glLinkProgram(program1);
	util::showLinkShaderError(program1);

	glDeleteShader(vertexShader);
	glDeleteShader(fragmenetShader);

	int vertexColorLocation = glGetUniformLocation(program1, "ourColor");
	glUseProgram(program1);
	glUniform4f(vertexColorLocation, 0.0f, 1.0f, 0.0f, 1.0f);
}
void Lesson04::CreateVAO2()
{
	util::showGlInfo();
	glGenVertexArrays(1, &VAO2);
	glBindVertexArray(VAO2);

	unsigned int VBO;
	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices2), vertices2, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, false, 3 * sizeof(float), 0);
	glEnableVertexAttribArray(0);

	unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShader, 1, &vertexShaderSource, nullptr);
	glCompileShader(vertexShader);
	util::showCompileError(vertexShader);

	unsigned int fragmenetShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmenetShader, 1, &fragmentShaderSource, nullptr);
	glCompileShader(fragmenetShader);
	util::showCompileError(fragmenetShader);

	program2 = glCreateProgram();
	glAttachShader(program2, vertexShader);
	glAttachShader(program2, fragmenetShader);
	glLinkProgram(program2);
	util::showLinkShaderError(program2);

	glDeleteShader(vertexShader);
	glDeleteShader(fragmenetShader);

	int vertexColorLocation = glGetUniformLocation(program2, "ourColor");
	glUseProgram(program2);
	glUniform4f(vertexColorLocation, 1.0f, 0.0f, 0.0f, 1.0f);
}

// 绘制开始处理
void Lesson04::prefix()
{
	CreateVAO1();
	CreateVAO2();
}
// 循环绘制
void Lesson04::show()
{
	if (bIsShow)
	{
		glUseProgram(program1);
		glBindVertexArray(VAO1);
		glDrawArrays(GL_TRIANGLES, 0, 3);
	}
	else {
		glUseProgram(program2);
		glBindVertexArray(VAO2);
		glDrawArrays(GL_TRIANGLES, 0, 3);
	}
	bIsShow = !bIsShow;
}
// 程序结束处理
void Lesson04::over()
{

}

