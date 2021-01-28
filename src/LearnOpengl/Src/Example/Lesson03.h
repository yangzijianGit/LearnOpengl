/*** 
 * @Author       : yangzijian
 * @Description  : uniform
 * @Date         : 2021-01-06 16:25:11
 */

#pragma once
#include "OGL.h"
class Lesson03 : public OGL
{
public:
	// 绘制开始处理
	virtual void prefix() override;
	// 循环绘制
	virtual void show() override;
	// 程序结束处理
	virtual void over() override;

	unsigned int VAO;
	unsigned int program;

	void ourColorFrame();

	float vertices[9] = {
		-0.5f, 0.5f, 1.0f,
		0.5f, 0.5f, 1.0f,
		0.0f, -0.5f, 1.0f
	};

	const char* vertexShaderSource =
		"#version 330 core\n"
		"layout (location = 0) in vec3 aPos;\n"
		"void main()\n"
		"{\n"
		"gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0f);\n"
		"}\n";

	const char* fragmentShaderSource =
		"#version 330 core\n"
		"out vec4 FragColor;\n"
		"uniform vec4 ourColor;\n"
		"void main()\n"
		"{\n"
		"FragColor = ourColor;\n"
		"}\n";



};

