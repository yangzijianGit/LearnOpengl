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

util::Image::Image() : data(nullptr), width(0), height(0), nrChannels(0)
{
}
util::Image::~Image()
{
	if (data)
		stbi_image_free(data);
}
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

GLenum util::nrChannelToGLType(int nrChannels)
{
	GLenum format;
	switch (nrChannels)
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
	return format;
}

util::Image *util::loadImage(const char *path)
{
	util::Image *image = new util::Image();
	// stbi_set_flip_vertically_on_load(true); // tell stb_image.h to flip loaded diffuseTex's on the y-axis.
	image->data = stbi_load(path, &image->width, &image->height, &image->nrChannels, 0);
	if (image->data == nullptr)
		throw "ERROR: load image error. ";
	return image;
}

unsigned int util::loadTexture(const char *path)
{
	unsigned int textureID;
	glGenTextures(1, &textureID);

	util::Image *image = nullptr;
	try
	{
		image = loadImage(path);
		if (image->data)
		{
			GLenum format = nrChannelToGLType(image->nrChannels);
			glBindTexture(GL_TEXTURE_2D, textureID);
			glTexImage2D(GL_TEXTURE_2D, 0, format, image->width, image->height, 0, format, GL_UNSIGNED_BYTE, image->data);
			glGenerateMipmap(GL_TEXTURE_2D);

			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, format == GL_RGBA ? GL_CLAMP_TO_EDGE : GL_REPEAT);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, format == GL_RGBA ? GL_CLAMP_TO_EDGE : GL_REPEAT);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		}
	}
	catch (const std::exception &e)
	{
		std::cerr << "ER:LOAD TEXTURE:" << e.what() << '\n';
	}
	safe_delete(image);
	return textureID;
}

unsigned int util::TextureFromFile(const char *path, const std::string &driectory, bool gamma)
{
	std::string filename = path;
	filename = driectory + '/' + filename;
	return loadTexture(filename.c_str());
}

unsigned int util::loadCubeMaps(const std::vector<std::string> &faces)
{
	if (faces.size() != 6)
	{
		std::cout << "ERROR:the number of cube map faces does not equal six.";
		return 0;
	}

	unsigned int textureId = 0;
	glGenTextures(1, &textureId);
	glBindTexture(GL_TEXTURE_CUBE_MAP, textureId);

	for (unsigned int i = 0; i < faces.size(); ++i)
	{
		util::Image *image = nullptr;
		try
		{
			image = loadImage(faces[i].c_str());
			if (image->data)
			{
				glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_X + i, 0, nrChannelToGLType(image->nrChannels), image->width, image->height, 0, nrChannelToGLType(image->nrChannels), GL_UNSIGNED_BYTE, image->data);
			}
		}
		catch (const std::exception &e)
		{
			std::cerr << e.what() << '\n';
		}
		safe_delete(image);
	}
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	return textureId;
}
