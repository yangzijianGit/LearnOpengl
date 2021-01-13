/*** 
 * @Author       : yangzijian
 * @Description  : 
 * @Date         : 2021-01-06 16:25:11
 */
#pragma once

#include "OGL.h"

class Lesson06 : public OGL
{
public:

	// 绘制开始处理
	virtual void prefix() override;
	// 循环绘制
	virtual void show() override;
	// 程序结束处理
	virtual void over() override;
	
};

