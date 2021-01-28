/*
 * @Description: 
 * @Author: yangzijian
 * @Date: 2020-03-26 16:12:53
 * @LastEditors: yangzijian
 * @LastEditTime: 2020-03-26 17:29:55
 */
#pragma once

#include <glad/glad.h>

class util
{
public :
	static void showCompileError(unsigned int shader);
	static void showLinkShaderError(unsigned int program);
	static void showGlInfo();
private:
	static GLchar info[512];
};