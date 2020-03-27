#include "Shader.h"

Shader::Shader(const GLchar* vertexPath, const GLchar* fragmentPath)
{
	std::string vertexCode;
	std::string fragmentCode;

	std::ifstream vShaderFile;
	std::ifstream fShaderFile;
	// 保证ifstream对象可以抛出异常
	vShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
	fShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);

	try
	{
		vShaderFile.open(vertexPath);
		fShaderFile.open(fragmentPath);

		std::stringstream vShaderStream, fShaderStream;
		// 读取文件的缓冲内容到数据流中
		vShaderStream << vShaderFile.rdbuf();
		fShaderStream << fShaderFile.rdbuf();
		// 关闭文件处理器

		vShaderFile.close();
		fShaderFile.close();

		// 转换数据到string 
		vertexCode = vShaderStream.str();
		fragmentCode = fShaderStream.str();
	}
	catch(std::ifstream::failure e){
		std::cout << "ERROR::SHADER::FILE_NOT_SUCCESFULLY_READ" << std::endl;
	}

	const char* vShaderCode = vertexCode.c_str();
	const char* fShaderCode = fragmentCode.c_str();
	
	unsigned int vertex, fragment;
	int success;
	char info[512];

	// 顶点着色器
	vertex = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertex, 1, &vShaderCode, NULL);
	glCompileShader(vertex);
	glGetShaderiv(vertex, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(vertex, 512, NULL, info);
		std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << info << std::endl;
	}

	fragment = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragment, 1, &fShaderCode, NULL);
	glGetShaderiv(fragment, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(fragment, 512, NULL, info);
		std::cout << "ERROR::SHADER::FRAGMENT::COMPLATION_FAILED\n" << info << std::endl;
	}

	m_nProgramId = glCreateProgram();
	glAttachShader(m_nProgramId, vertex);
	glAttachShader(m_nProgramId, fragment);
	glLinkProgram(m_nProgramId);

	// 打印错误信息
	glGetProgramiv(m_nProgramId, GL_LINK_STATUS, &success);
	if (!success)
	{
		glGetProgramInfoLog(m_nProgramId, 512, NULL, info);
		std::cout << "ERROR: Program link" << info << std::endl;
	}

	glDeleteShader(vertex);
	glDeleteShader(fragment);
}
Shader::~Shader()
{
	if (m_nProgramId)
	{
		glDeleteProgram(m_nProgramId);
	}
}

// 使用/激活程序
bool Shader::use() const
{
	if (!m_nProgramId)
	{
		std::cout << "ERROR: Program Id is null " << std::endl;
		return false;
	}
	glUseProgram(m_nProgramId);
}
// uniform 工具函数
void Shader::setBool(const std::string& strName, bool bValue) const
{
	if (use())
	{
		GLint nValueLocation = glGetUniformLocation(m_nProgramId, strName.c_str());
		glUniform1i(nValueLocation, (int)bValue);
	}
}
void Shader::setInt(const std::string& strName, int nValue) const
{
	if (use())
	{
		GLint nValueLocation = glGetUniformLocation(m_nProgramId, strName.c_str());
		glUniform1i(nValueLocation, nValue);
	}
}
void Shader::setFloat(const std::string& strName, float fValue) const
{
	if (use())
	{
		GLint nValueLocation = glGetUniformLocation(m_nProgramId, strName.c_str());
		glUniform1f(nValueLocation, fValue);
	}
}