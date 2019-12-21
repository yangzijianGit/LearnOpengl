/*
		author		:		yangzijian
		time		:		2019-12-16 21:18:22
		function	:		uniform
*/

#pragma once
#include "Lesson.h"
class Lesson03 : public Lesson
{
public:
	// ���ƿ�ʼ����
	virtual void prefix() override;
	// ѭ������
	virtual void show() override;
	// �����������
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

