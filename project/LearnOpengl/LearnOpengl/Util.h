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