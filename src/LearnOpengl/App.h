/*** 
 * @Author       : yangzijian
 * @Description  : App
 * @Date         : 2021-01-06 17:01:00
 */

#include <glad/glad.h>
#include <glfw3.h>

class App
{
public:
    App();
    ~App();

public:
    bool Init();
    void Run();
    GLFWwindow *m_pWindow = nullptr;
};
