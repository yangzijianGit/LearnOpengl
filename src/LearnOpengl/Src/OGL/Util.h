/*** 
 * @Author       : yangzijian
 * @Description  : 
 * @Date         : 2020-03-26 16:12:53
 */
#pragma once

#include <glad/glad.h>

class util
{
public :
	static void showCompileError(unsigned int shader);
	static void showLinkShaderError(unsigned int program);
	static void showGlInfo();
	static unsigned int loadTexture(const char* path);
private:
	static GLchar info[512];
};