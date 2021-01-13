/*** 
 * @Author       : yangzijian
 * @Description  : App cpp
 * @Date         : 2021-01-06 17:01:00
 */

#include "App.h"
#include <iostream>
#include "OGL.h"
#include "Lesson01.h"
#include "Lesson02.h"
#include "Lesson03.h"
#include "Lesson04.h"
#include "Lesson05.h"
#include "Lesson06.h"
#include "Lesson07.h"
#include "Lesson08.h"

namespace
{
    void framebuffer_size_callback(GLFWwindow *m_pWindow, int nWidth, int nHeight)
    {
        glViewport(0, 0, nWidth, nHeight);
    }

    int processInput(GLFWwindow *m_pWindow, int eFunctionkey)
    {
        return glfwGetKey(m_pWindow, eFunctionkey);
    }

    void setBackgroundColor()
    {
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
    }
} // namespace

App::App()
{
}

App::~App()
{
}

bool App::Init()
{
    glfwInit();

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

    m_pWindow = glfwCreateWindow(800, 600, "LearnOpengl", nullptr, nullptr);
    if (m_pWindow == nullptr)
    {
        std::cout << "ERROR: Failed to create GLFW window " << std::endl;
        glfwTerminate();
        return false;
    }
    glfwMakeContextCurrent(m_pWindow);

    // 初始化glad
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "ERROR: Failed to initialize GLAD" << std::endl;
        glfwTerminate();
        return false;
    }

    glViewport(0, 0, 800, 600);
    // 设置窗口大小改变时， 回调函数
    glfwSetFramebufferSizeCallback(m_pWindow, framebuffer_size_callback);
    // render
    return true;
}

void App::Run()
{
    OGL *pLesson = new Lesson08();
    pLesson->setProcessFunction([=](int eFunctionKey) {
        return processInput(m_pWindow, eFunctionKey);
    });
    pLesson->addProcessInputFunc(GLFW_KEY_ESCAPE, [=]() {
        glfwSetWindowShouldClose(m_pWindow, true);
    });
    pLesson->prefix();
    while (!glfwWindowShouldClose(m_pWindow))
    {
        // input control
        // 渲染
        // 清除颜色缓冲
        setBackgroundColor();
        // gl render command
        //...
        pLesson->show();
        pLesson->processInput();

        // gl render command end
        glfwPollEvents();
        glfwSwapBuffers(m_pWindow);
    }
    pLesson->over();
    delete pLesson;
    glfwTerminate();
}