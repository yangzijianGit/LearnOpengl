/*** 
 * @Author       : yangzijian
 * @Description  : shader
 * @Date         : 2021-01-06 16:25:11
 */
#pragma once

#include <glad/glad.h>

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <glm/glm.hpp>

class Shader
{
public:
	// 构造器读取并构建着色器
	Shader();
	Shader(const GLchar *vertexPath, const GLchar *fragmentPath);
	~Shader();

	void read(const GLchar *vertexPath, const GLchar *fragmentPath);
	// 使用/激活程序
	bool use() const;
	// uniform 工具函数
	void setBool(const std::string &strName, bool bValue) const;
	void setInt(const std::string &strName, int nValue) const;
	void setFloat(const std::string &strName, float fValue) const;
	// ------------------------------------------------------------------------
	void setVec2(const std::string &name, const glm::vec2 &value) const;
	void setVec2(const std::string &name, float x, float y) const;
	// ------------------------------------------------------------------------
	void setVec3(const std::string &name, const glm::vec3 &value) const;
	void setVec3(const std::string &name, float x, float y, float z) const;
	// ------------------------------------------------------------------------
	void setVec4(const std::string &name, const glm::vec4 &value) const;
	void setVec4(const std::string &name, float x, float y, float z, float w);
	// ------------------------------------------------------------------------
	void setMat2(const std::string &name, const glm::mat2 &mat) const;
	// ------------------------------------------------------------------------
	void setMat3(const std::string &name, const glm::mat3 &mat) const;
	// ------------------------------------------------------------------------
	void setMat4(const std::string &name, const glm::mat4 &mat) const;

	// program id
	unsigned int m_nProgramId;

private:
	void clear();
};
