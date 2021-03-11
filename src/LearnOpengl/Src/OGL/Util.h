/*** 
 * @Author       : yangzijian
 * @Description  : 
 * @Date         : 2020-03-26 16:12:53
 */
#pragma once

#include <glad/glad.h>
#include <string>
#include <vector>
#include "Image.h"

class util
{
public:
	static void showCompileError(unsigned int shader);
	static void showLinkShaderError(unsigned int program);
	static void showGlInfo();
	class Image
	{
	public:
		Image();
		~Image();
		unsigned char *data;
		int width;
		int height;
		int nrChannels;
	};
	static Image *loadImage(const char *path);
	static GLenum nrChannelToGLType(int nrChannels);
	static unsigned int loadTexture(const char *path);
	static unsigned int TextureFromFile(const char *path, const std::string &driectory, bool gamma = false);
	static unsigned int loadCubeMaps(const std::vector<std::string> &faces);

private:
	static GLchar info[512];
};

#define safe_delete(ptr)   \
	{                      \
		if (ptr)           \
		{                  \
			delete ptr;    \
			ptr = nullptr; \
		}                  \
	}