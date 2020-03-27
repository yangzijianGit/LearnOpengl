/*
 * @Description: 
 * @Author: yangzijian
 * @Date: 2019-12-25 18:44:40
 * @LastEditors: yangzijian
 * @LastEditTime: 2020-02-26 12:19:59
 */
#pragma once

#include "Lesson.h"

class Lesson06 : public Lesson
{
public:

	// 绘制开始处理
	virtual void prefix() override;
	// 循环绘制
	virtual void show() override;
	// 程序结束处理
	virtual void over() override;

	float texCoord[6] = {
		0.0f, 0.0f,
		1.0f, 0.0f,
		0.5f, 1.0f
	};

	float triangle[9] = {
		0.0f, 0.5f, 1.0f,
		0.5f, -0.5f, 1.0f,
		-0.5f, -0.5f, 1.0f
	};


	unsigned int m_nProgramId;
	unsigned int m_nVAO;




};

