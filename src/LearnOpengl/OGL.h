/*** 
 * @Author       : yangzijian
 * @Description  :
 * @Date         : 2021-01-06 16:25:11
 */

#pragma once

#include <vector>
#include <functional>

class OGL
{
public:
	// 绘制开始处理
	virtual void prefix() = 0;
	// 循环绘制
	virtual void show() = 0;
	// 程序结束处理
	virtual void over() = 0;

	void processInput()
	{
		if (m_pProcessFunction == nullptr)
		{
			return;
		}
		for (auto it : m_arrProcessInputFunc)
		{
			if (m_pProcessFunction(it.first))
			{
				it.second();
			}
		}
	}
	void setProcessFunction(std::function<int(int)> pProcessFunction)
	{
		m_pProcessFunction = pProcessFunction;
	}
	std::function<int(int)> m_pProcessFunction = nullptr;
	void addProcessInputFunc(int eFunctionKey, std::function<void(void)> pCallback)
	{
		m_arrProcessInputFunc.push_back(std::pair<int, std::function<void(void)>>(eFunctionKey, pCallback));
	}
	std::vector<std::pair<int, std::function<void(void)>>> m_arrProcessInputFunc;
};

#define OGL_Class(Name)\
class Name : public OGL\
{\
public:\
	virtual void prefix() override;\
	virtual void show() override;\
	virtual void over() override;\
};\



