#pragma once

#include "Lesson.h"
#include "glad/glad.h"

class Lesson02 : public Lesson
{
public:
	Lesson02();
	~Lesson02();

	// ���ƿ�ʼ����
	virtual void prefix() override;
	// ѭ������
	virtual void show() override;
	// �����������
	virtual void over() override;

	float vertices[12] = {
		// ��һ��������
		0.5f, 0.5f, 0.0f,
		0.5f, -0.5f, 0.0f,
		-0.5f, -0.5f, 0.0f,
		-0.5f, 0.5f, 0.0f
	};

	// ע��������0��ʼ
	unsigned int indices[6] = {
		0, 1, 3, // ��һ��������
		1, 2, 3 // �ڶ���������
	};

	const GLchar* verticesBufferCode = "\n"
		"#version 330 core\n"
		"layout (location = 0) in vec3 aPos;\n"
		"void main()\n"
		"{\n"
		"gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
		"}\n";

	const GLchar* fragmentShaderCode = "\n"
		"#version 330 core\n"
		"out vec4 FragColor;\n"
		"\n"
		"void main()\n"
		"{\n"
		"FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
		"}";

	unsigned int program;
	unsigned int VAO;

};

