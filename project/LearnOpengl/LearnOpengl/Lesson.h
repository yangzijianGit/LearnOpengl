/*
		author		:		yangzijian
		time		:		2019-12-13 12:23:24
		function	:		create lesson for opengl 
*/

#pragma once


class Lesson
{
public:
	// 绘制开始处理
	virtual void prefix() = 0;
	// 循环绘制
	virtual void show() = 0;
	// 程序结束处理
	virtual void over() = 0;
};

