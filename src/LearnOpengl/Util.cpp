/*
 * @Description: 
 * @Author: yangzijian
 * @Date: 2020-03-26 16:12:53
 * @LastEditors: yangzijian
 * @LastEditTime: 2020-03-26 17:31:30
 */
#include "Util.h"
#include <glad/glad.h>
#include <iostream>
#include <stdio.h>
#include <memory.h>

GLchar util::info[512] = { 0 };

void util::showCompileError(unsigned int shader)
{
	memset(info, 0, sizeof(info));
	int success;
	glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(shader, sizeof(info), nullptr, info);
		std::cout << "ERROR::SHADRE::COMPILATION_FAILED\n" << info << std::endl;
	}
}

void util::showLinkShaderError(unsigned int program)
{
	memset(info, 0, sizeof(info));
	int success;
	glGetProgramiv(program, GL_LINK_STATUS, &success);
	if (!success)
	{
		glGetProgramInfoLog(program, sizeof(info), nullptr, info);
		std::cout << "ERROR::PROGRAM::LINK_FAILED\n" << info << std::endl;
	}
}


void util::showGlInfo()
{
	int nrAttributes;
	glGetIntegerv(GL_MAX_VERTEX_ATTRIBS, &nrAttributes);
	std::cout << "Maximun nr of vertex attributes supported:" << nrAttributes << std::endl;
}
