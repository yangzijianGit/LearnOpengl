/*
 * @Description: 
 * @Author: yangzijian
 * @Date: 2019-12-13 13:42:32
 * @LastEditors: yangzijian
 * @LastEditTime: 2020-02-26 12:17:29
 */
#pragma once

#include "Lesson.h"
#include "glad/glad.h"

class Lesson01 : public Lesson
{
public:

	// 绘制开始处理
	virtual void prefix() override;
	// 循环绘制
	virtual void show() override;
	// 程序结束处理
	virtual void over() override;

	void glGetComileError(unsigned int shader);
	void bindBuffer();
	void createShader();

public:

	float vertices[9] = {
		-0.5f, -0.5f, 0.0f,
		0.5f, -0.5f, 0.0f,
		0.0f, 0.5f, 0.0f
	};

	unsigned int VAO;
	unsigned int VBO;
	unsigned int shaderProgram;

	const GLchar* verticesBufferCode = "\
		#version 330 core\n\
		layout (location = 0) in vec3 aPos;\n\
		\n\
		void main()\n\
		{\n\
			gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n\
		}\n\
		";

	const GLchar* fragmentShaderBufferCode = "\
		#version 330 core\n\
		out vec4 FragColor;\n\
		\n\
		void main()\n\
		{\n\
			FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n\
		}\n\
		";



};