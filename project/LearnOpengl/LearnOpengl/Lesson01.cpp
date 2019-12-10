/*
		author		:		yangzijian
		time		:		2019-12-9 19:31:49
		function	:		lesson01 create a trangle 
*/

/*
顶点数组对象：Vertex Array Object，VAO
顶点缓冲对象：Vertex Buffer Object，VBO
索引缓冲对象：Element Buffer Object，EBO或Index Buffer Object，IBO
*/
#include <glfw3.h>
#include <glad/glad.h>
#include <iostream>


namespace lesson01
{

	float vertices[] = {
		-0.5f, -0.5f, 0.0f,
		0.5f, -0.5f, 0.0f,
		0.0f, 0.5f, 0.0f
	};

	const GLchar* verticesBufferCode = "\
		#version 330 core\n\
		layout (location = 0) in vec3 aPos\n\
		\n\
		void main()\n\
		{\n\
			gl_Position = vec4(aPos.x, aPos,y, aPos.z, 1.0);\n\
		}\n\
		";

	const GLchar* fragmentShaderBufferCode = "\
		#version 330 core\n\
		out vec4 FragColor\n\
		\n\
		void main()\n\
		{\n\
			FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n\
		}\n\
		";

	void glGetComileError(unsigned int shader)
	{
		static GLchar info[512];
		memset(info, 0, sizeof(info));
		int success;
		glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
		if (!success)
		{
			glGetShaderInfoLog(shader, sizeof(info), NULL, info);
			std::cout << "ERROR::SHADRE::VERTEX::COMPILATION_FAILED\n" << info << std::endl;
		}
	}

	void show()
	{
		unsigned int VBO;
		glGenBuffers(1, &VBO);
		glBindBuffer(GL_ARRAY_BUFFER, VBO);
		glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

		unsigned int vertexShader;
		vertexShader = glCreateShader(GL_VERTEX_SHADER);
		glShaderSource(vertexShader, 1, &verticesBufferCode, NULL);
		glCompileShader(vertexShader);

		glGetComileError(vertexShader);

		unsigned int fragmentShader;
		fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
		glShaderSource(fragmentShader, 1, &fragmentShaderBufferCode, NULL);
		glCompileShader(fragmentShader);

		glGetComileError(fragmentShader);

		unsigned int shaderProgram;
		shaderProgram = glCreateProgram();
		glAttachShader(shaderProgram, vertexShader);
		glAttachShader(shaderProgram, fragmentShader);
		glLinkProgram(shaderProgram);

		int success;
		glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
		if (!success)
		{
			char info[512];
			glGetProgramInfoLog(shaderProgram, 512, NULL, info);
			std::cout << "ERROR::PROGRAM:" << info << std::endl;
		}
		glUseProgram(shaderProgram);
		glDeleteShader(vertexShader);
		glDeleteShader(fragmentShader);


	}



}




