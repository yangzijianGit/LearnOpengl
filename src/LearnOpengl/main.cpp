﻿/*
		author		:		yangzijian
		time		:		2019-12-9 13:05:36
		function	:		this is use for learn opengl project. main function 
*/


#include <glad/glad.h>
#include <glfw3.h>
#include <iostream>
#include "Lesson.h"
#include "Lesson01.h"
#include "Lesson02.h"
#include "Lesson03.h"
#include "Lesson04.h"
#include "Lesson05.h"

void framebuffer_size_callback(GLFWwindow* pWindow, int nWidth, int nHeight)
{
	glViewport(0, 0, nWidth, nHeight);
}

void processInput(GLFWwindow* pWindow)
{
	if (glfwGetKey(pWindow, GLFW_KEY_ESCAPE))
	{
		glfwSetWindowShouldClose(pWindow, true);
	}
}

void setBackgroundColor()
{
	glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
}

int main()
{
	glfwInit();

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	// glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

	GLFWwindow* pWindow = glfwCreateWindow(800, 600, "LearnOpengl", nullptr, nullptr);
	if (pWindow == nullptr)
	{
		std::cout << "ERROR: Failed to create GLFW window " << std::endl;
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(pWindow);

	// 初始化glad 
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "ERROR: Failed to initialize GLAD" << std::endl;
		return -1;
	}

	glViewport(0, 0, 800, 600);
	// 设置窗口大小改变时， 回调函数
	glfwSetFramebufferSizeCallback(pWindow, framebuffer_size_callback);
	// render 


	Lesson* pLesson = new Lesson05();
	pLesson->prefix();
	while (!glfwWindowShouldClose(pWindow))
	{
		// input control
		processInput(pWindow);
		// 渲染
		// 清除颜色缓冲
		setBackgroundColor();
		// gl render command
		//...
		pLesson->show();

		// gl render command end
		glfwSwapBuffers(pWindow);
		glfwPollEvents();
	}
	pLesson->over();
	delete pLesson;
	glfwTerminate();

	return 0;
}




