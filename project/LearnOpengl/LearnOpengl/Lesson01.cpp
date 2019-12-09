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


namespace lesson01
{

	float vertices[] = {
		-0.5f, -0.5f, 0.0f,
		0.5f, -0.5f, 0.0f, 
		0.0f, 0.5f, 0.0f
	};

	void show()
	{
		unsigned int VBO;
		glGenBuffers(1, &VBO);
		glBindBuffer(GL_ARRAY_BUFFER, VBO);
		glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);


	}



}




