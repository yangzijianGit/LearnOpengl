/*** 
 * @Author       : yangzijian
 * @Description  : 
 * @Date         : 2021-01-06 16:25:11
 */

#pragma once

#include "OGL.h"
#include "glad/glad.h"

class Lesson02 : public OGL
{
public:

	// 绘制开始处理
	virtual void prefix() override;
	// 循环绘制
	virtual void show() override;
	// 程序结束处理
	virtual void over() override;

	float vertices[12] = {
		// 第一个三角形
		0.5f, 0.5f, 0.0f,
		0.5f, -0.5f, 0.0f,
		-0.5f, -0.5f, 0.0f,
		-0.5f, 0.5f, 0.0f
	};

	// 注意索引从0开始
	unsigned int indices[6] = {
		0, 1, 3, // 第一个三角形
		1, 2, 3 // 第二个三角形
	};

	const GLchar* verticesBufferCode = "\n"
		"#version 330 core\n"
		"layout (location = 0) in vec3 aPos;\n"
		"out vec4 vertexColor;\n"
		"void main()\n"
		"{\n"
		"gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
		"vertexColor = vec4(0.5f, 0.0f, 0.0f, 1.0f);"
		"}\n";

	const GLchar* fragmentShaderCode = "\n"
		"#version 330 core\n"
		"out vec4 FragColor;\n"
		"in vec4 vertexColor;\n"
		"\n"
		"void main()\n"
		"{\n"
		"FragColor = vertexColor;\n"
		"}";

	unsigned int program;
	unsigned int VAO;

};

