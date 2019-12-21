#pragma once
#include "Lesson.h"

class Lesson05 : public Lesson
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

	float vertices[18] = {
		// 位置				// 颜色
		0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 0.0f, // 右下
		-0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f,  // 左下
		0.0f, 0.5f, 0.0f, 0.0f, 0.0f, 1.0f
	};

	const char* vertexShaderSource =
		"#version 330 core\n"
		"layout (location = 0) in vec3 aPos;\n" // 位置变量的属性位置值为0
		"layout (location = 1) in vec3 aColor;\n"// 颜色变量的属性位置值为1
		"out vec3 outColor;\n" // 向片段着色器输出一个颜色
		"void main()\n"
		"{\n"
		"gl_Position = vec4(aPos, 1.0f);\n"
		"outColor = aColor;\n"
		"}\n";

	const char* fragmentShaderSource =
		"#version 330 core\n"
		"out vec4 FragColor;\n"
		"in vec3 outColor;\n"
		"void main()\n"
		"{\n"
		"FragColor = vec4(outColor, 1.0f);\n"
		"}\n";

};

