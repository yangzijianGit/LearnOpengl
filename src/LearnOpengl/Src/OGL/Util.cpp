/*** 
 * @Author       : yangzijian
 * @Description  : 
 * @Date         : 2020-03-26 16:12:53
 */
#include "Util.h"
#include <glad/glad.h>
#include <iostream>
#include <stdio.h>
#include <memory.h>

GLchar util::info[512] = {0};

void util::showCompileError(unsigned int shader)
{
	memset(info, 0, sizeof(info));
	int success;
	glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(shader, sizeof(info), nullptr, info);
		std::cout << "ERROR::SHADRE::COMPILATION_FAILED\n"
				  << info << std::endl;
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
		std::cout << "ERROR::PROGRAM::LINK_FAILED\n"
				  << info << std::endl;
	}
}

void util::showGlInfo()
{
	int nrAttributes;
	glGetIntegerv(GL_MAX_VERTEX_ATTRIBS, &nrAttributes);
	std::cout << "Maximun nr of vertex attributes supported:" << nrAttributes << std::endl;
}

unsigned int util::loadTexture(const char *path)
{
	unsigned int textureID;
	glGenTextures(1, &textureID);

	stbi_set_flip_vertically_on_load(true); // tell stb_image.h to flip loaded diffuseTex's on the y-axis.
	int width, height, nrComponents;
	unsigned char *data = stbi_load(path, &width, &height, &nrComponents, 0);
	if (data)
	{
		try
		{

			GLenum format;
			switch (nrComponents)
			{
			case 1:
				format = GL_RED;
				break;
			case 3:
				format = GL_RGB;
				break;
			case 4:
				format = GL_RGBA;
				break;
			default:
				throw "format type not supported.";
			}
			glBindTexture(GL_TEXTURE_2D, textureID);
			glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, data);
			glGenerateMipmap(GL_TEXTURE_2D);

			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		}
		catch (const std::exception &e)
		{
			std::cerr << "ER:LOAD TEXTURE:" << e.what() << '\n';
		}
		stbi_image_free(data);
	}
	else
	{
		std::cerr << "ER:LOAD TEXTURE: Path error " << '\n';
	}
	return textureID;
}

unsigned int util::TextureFromFile(const char *path, const std::string &driectory, bool gamma)
{
	std::string filename = path;
	filename = driectory + '/' + filename;
	return loadTexture(filename.c_str());
}
