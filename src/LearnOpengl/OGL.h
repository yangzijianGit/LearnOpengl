/*** 
 * @Author       : yangzijian
 * @Description  :
 * @Date         : 2021-01-06 16:25:11
 */

#pragma once

#include <vector>
#include <functional>
#include <map>

class OGL
{
public:
	// 绘制开始处理
	virtual void prefix() = 0;
	// 循环绘制
	virtual void show() = 0;
	// 程序结束处理
	virtual void over() = 0;

	void Process_Input()
	{
		for (auto itKey : m_arrProcessInputFunc)
		{
			if (m_pCheckKeyStatus(itKey.first))
			{
				for (auto pFunc : itKey.second)
				{
					pFunc();
				}
			}
		}
	}

	void Process_MouseBtn(int mouse, int isPressed, int bit)
	{
		for (auto pFunc : m_arrProcessInput_MouseBtn)
		{
			pFunc(mouse, isPressed, bit);
		}
	}

	void Process_MouseMove(double dXPos, double dYPos)
	{
		for (auto pFunc : m_arrProcessInput_MouseMove)
		{
			pFunc(dXPos, dYPos);
		}
	}

	void Process_MouseScroll(double dXOffset, double dYOffect)
	{
		for (auto pFunc : m_arrProcessInput_MouseScroll)
		{
			pFunc(dXOffset, dYOffect);
		}
	}

	void SetProcessFunction(std::function<int(int)> pFunc)
	{
		m_pCheckKeyStatus = pFunc;
	}

	void addProcessInputFunc(int eFunctionKey, std::function<void(void)> pCallback)
	{
		if (m_arrProcessInputFunc.find(eFunctionKey) == m_arrProcessInputFunc.end())
		{
			m_arrProcessInputFunc[eFunctionKey] = std::vector<std::function<void(void)>>{};
		}
		m_arrProcessInputFunc[eFunctionKey].push_back(pCallback);
	}

	std::function<int(int)> m_pCheckKeyStatus = nullptr;
	std::map<int, std::vector<std::function<void(void)>>> m_arrProcessInputFunc;
	std::vector<std::function<void(double, double)>> m_arrProcessInput_MouseMove;
	std::vector<std::function<void(double, double)>> m_arrProcessInput_MouseScroll;
	std::vector<std::function<void(int, int, int)>> m_arrProcessInput_MouseBtn;
};

#define OGL_Class_Begin(Name)           \
	class Name : public OGL             \
	{                                   \
	public:                             \
		virtual void prefix() override; \
		virtual void show() override;   \
		virtual void over() override;

#define OGL_Class_End() \
	}\
