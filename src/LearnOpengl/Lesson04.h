/*** 
 * @Author       : yangzijian
 * @Description  : VAO Test
 * @Date         : 2021-01-06 16:25:11
 */

#pragma once
#include "OGL.h"

class Lesson04 : public OGL
{
public:
	// 绘制开始处理
	virtual void prefix() override;
	// 循环绘制
	virtual void show() override;
	// 程序结束处理
	virtual void over() override;

	void CreateVAO1();
	void CreateVAO2();

	unsigned int VAO1;
	unsigned int VAO2;
	unsigned int program1;
	unsigned int program2;
	unsigned int VBO1;
	unsigned int VBO2;

	float vertices1[9] = {
		-0.5f, 0.5f, 1.0f,
		0.5f, 0.5f, 1.0f,
		0.0f, -0.5f, 1.0f};

	float vertices2[9] = {
		-0.5f, -0.5f, 0.0f,
		0.5f, -0.5f, 0.0f,
		0.0f, 0.5f, 0.0f};

	int bIsShow = false;

	const char *vertexShaderSource =
		"#version 330 core\n"
		"layout (location = 0) in vec3 aPos;\n"
		"void main()\n"
		"{\n"
		"gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0f);\n"
		"}\n";

	const char *fragmentShaderSource =
		"#version 330 core\n"
		"out vec4 FragColor;\n"
		"uniform vec4 ourColor;\n"
		"void main()\n"
		"{\n"
		"FragColor = ourColor;\n"
		"}\n";

	bool bIsBind1 = false;
};
