#pragma once
#include "Lesson.h"

class Lesson05 : public Lesson
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

	float vertices[18] = {
		// λ��				// ��ɫ
		0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 0.0f, // ����
		-0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f,  // ����
		0.0f, 0.5f, 0.0f, 0.0f, 0.0f, 1.0f
	};

	const char* vertexShaderSource =
		"#version 330 core\n"
		"layout (location = 0) in vec3 aPos;\n" // λ�ñ���������λ��ֵΪ0
		"layout (location = 1) in vec3 aColor;\n"// ��ɫ����������λ��ֵΪ1
		"out vec3 outColor;\n" // ��Ƭ����ɫ�����һ����ɫ
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

