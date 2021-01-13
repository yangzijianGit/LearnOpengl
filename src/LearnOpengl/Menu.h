/*** 
 * @Author       : yangzijian
 * @Description  : 
 * @Date         : 2021-01-06 17:58:28
 */

#include "OGL.h"
#include <vector>

class Menu : public OGL
{
public:
    // 绘制开始处理
    virtual void prefix() override;
    // 循环绘制
    virtual void show() override;
    // 程序结束处理
    virtual void over() override;

private:
    float m_fScrollPos; // 滑动位置
    std::vector<OGL> m_arrSubMenu; // menu 
    
};
