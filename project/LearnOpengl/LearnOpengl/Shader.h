#pragma once

#include <glad/glad.h>

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

class Shader
{
public:
	// ��������ȡ��������ɫ��
	Shader(const GLchar* vertexPath, const GLchar* fragmentPath);
	~Shader();

	// ʹ��/�������
	bool use() const;
	// uniform ���ߺ���
	void setBool(const std::string& strName, bool bValue) const;
	void setInt(const std::string& strName, int nValue) const;
	void setFloat(const std::string& strName, float fValue) const;

	// program id
	unsigned int m_nProgramId = 0;

};

