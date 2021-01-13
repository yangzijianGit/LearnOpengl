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

	// program id
	unsigned int m_nProgramId;

private:
	void clear();
};
