#include "Lesson03.h"
#include "Util.h"
#include <glad/glad.h>
#include <glfw3.h>
#include <cmath>

// 绘制开始处理
void Lesson03::prefix()
{
	util::showGlInfo();
	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);

	unsigned int VBO;
	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

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

	program = glCreateProgram();
	glAttachShader(program, vertexShader);
	glAttachShader(program, fragmenetShader);
	glLinkProgram(program);
	util::showLinkShaderError(program);

	glDeleteShader(vertexShader);
	glDeleteShader(fragmenetShader);


}
void Lesson03::ourColorFrame()
{
	float timeValue = glfwGetTime();
	float greenValue = (sin(timeValue) / 2.0f) + 0.5f;
	int vertexColorLocation = glGetUniformLocation(program, "ourColor");
	glUseProgram(program);
	glUniform4f(vertexColorLocation, 0.0f, greenValue, 0.0f, 1.0f);
}
// 循环绘制
void Lesson03::show()
{
	ourColorFrame();
	glUseProgram(program);
	glBindVertexArray(VAO);
	glDrawArrays(GL_TRIANGLES, 0, 3);
}
// 程序结束处理
void Lesson03::over()
{

}



