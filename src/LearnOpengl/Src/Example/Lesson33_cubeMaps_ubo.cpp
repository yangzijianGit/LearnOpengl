/*** 
 * @Author       : yangzijian
 * @Description  : 
 * @Date         : 2021-01-06 16:25:11
 */
#include "Lesson33_cubeMaps_ubo.h"
#include <glad/glad.h>
#include <iostream>
#include "Shader.h"
#include "glfw3.h"
#include "Util.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

namespace
{
    unsigned int cubeVBO, cubeVAO;
    Shader shaderRed;
    Shader shaderGreen;
    Shader shaderBlue;
    Shader shaderYellow;
    glm::mat4 projection;
    unsigned int uboMatrices;

    bool isButtonPressed = false;
    bool isPressedScreen = false;
    float yaw = -90.0f;
    float pitch = 0.0f;
    float lastX = 800.0f / 2.0f;
    float lastY = 600.0f / 2.0f;
    float fov = 45.0f;
    float deltaTime = 0.0f;
    float lastFrame = 0.0f;

    // set up vertex data (and buffer(s)) and configure vertex attributes
    // ------------------------------------------------------------------
    float cubeVertices[] = {
        // positions
        -0.5f,
        -0.5f,
        -0.5f,
        0.5f,
        -0.5f,
        -0.5f,
        0.5f,
        0.5f,
        -0.5f,
        0.5f,
        0.5f,
        -0.5f,
        -0.5f,
        0.5f,
        -0.5f,
        -0.5f,
        -0.5f,
        -0.5f,

        -0.5f,
        -0.5f,
        0.5f,
        0.5f,
        -0.5f,
        0.5f,
        0.5f,
        0.5f,
        0.5f,
        0.5f,
        0.5f,
        0.5f,
        -0.5f,
        0.5f,
        0.5f,
        -0.5f,
        -0.5f,
        0.5f,

        -0.5f,
        0.5f,
        0.5f,
        -0.5f,
        0.5f,
        -0.5f,
        -0.5f,
        -0.5f,
        -0.5f,
        -0.5f,
        -0.5f,
        -0.5f,
        -0.5f,
        -0.5f,
        0.5f,
        -0.5f,
        0.5f,
        0.5f,

        0.5f,
        0.5f,
        0.5f,
        0.5f,
        0.5f,
        -0.5f,
        0.5f,
        -0.5f,
        -0.5f,
        0.5f,
        -0.5f,
        -0.5f,
        0.5f,
        -0.5f,
        0.5f,
        0.5f,
        0.5f,
        0.5f,

        -0.5f,
        -0.5f,
        -0.5f,
        0.5f,
        -0.5f,
        -0.5f,
        0.5f,
        -0.5f,
        0.5f,
        0.5f,
        -0.5f,
        0.5f,
        -0.5f,
        -0.5f,
        0.5f,
        -0.5f,
        -0.5f,
        -0.5f,

        -0.5f,
        0.5f,
        -0.5f,
        0.5f,
        0.5f,
        -0.5f,
        0.5f,
        0.5f,
        0.5f,
        0.5f,
        0.5f,
        0.5f,
        -0.5f,
        0.5f,
        0.5f,
        -0.5f,
        0.5f,
        -0.5f,
    };
    glm::vec3 cameraPos = glm::vec3(0.0f, 0.0f, 3.0f);
    glm::vec3 cameraFront = glm::vec3(0.0f, 0.0f, -1.0f);
    glm::vec3 cameraUp = glm::vec3(0.0f, 1.0f, 0.0f);

    double mouseX = 0.0f;
    double mouseY = 0.0f;

} // namespace

void Lesson33::prefix()
{
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    shaderRed.read("8.advanced_glsl.vs", "8.red.fs");
    shaderGreen.read("8.advanced_glsl.vs", "8.green.fs");
    shaderBlue.read("8.advanced_glsl.vs", "8.blue.fs");
    shaderYellow.read("8.advanced_glsl2.vs", "8.yellow.fs");

    m_arrProcessInput_MouseBtn.push_back([](int key, int isPressed, int bit) {
        if (isPressedScreen != isPressed)
        {
            isPressedScreen = isPressed;
            lastX = mouseX;
            lastY = mouseY;
        }
    });

    glGenVertexArrays(1, &cubeVAO);
    glBindVertexArray(cubeVAO);
    glGenBuffers(1, &cubeVBO);
    glBindBuffer(GL_ARRAY_BUFFER, cubeVBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(cubeVertices), cubeVertices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void *)0);
    glEnableVertexAttribArray(0);

    unsigned int uniformBlockIndexRed = glGetUniformBlockIndex(shaderRed.m_nProgramId, "Matrices");
    unsigned int uniformBlockIndexGreen = glGetUniformBlockIndex(shaderGreen.m_nProgramId, "Matrices");
    unsigned int uniformBlockIndexBlue = glGetUniformBlockIndex(shaderBlue.m_nProgramId, "Matrices");
    unsigned int uniformBlockIndexYellow = glGetUniformBlockIndex(shaderYellow.m_nProgramId, "Matrices");
    unsigned int uniformBlockIndexYellow2= glGetUniformBlockIndex(shaderYellow.m_nProgramId, "Matrices22");
    glUniformBlockBinding(shaderRed.m_nProgramId, uniformBlockIndexRed, 0);
    glUniformBlockBinding(shaderGreen.m_nProgramId, uniformBlockIndexGreen, 0);
    glUniformBlockBinding(shaderBlue.m_nProgramId, uniformBlockIndexBlue, 0);
    glUniformBlockBinding(shaderYellow.m_nProgramId, uniformBlockIndexYellow, 0);

    glGenBuffers(1, &uboMatrices);
    glBindBuffer(GL_UNIFORM_BUFFER, uboMatrices);
    glBufferData(GL_UNIFORM_BUFFER, 2 * sizeof(glm::mat4), NULL, GL_STATIC_DRAW);
    glBindBuffer(GL_UNIFORM_BUFFER, 0);
    glBindBufferRange(GL_UNIFORM_BUFFER, 0, uboMatrices, 0, 2 * sizeof(glm::mat4));

    m_arrProcessInput_MouseMove.push_back([](double x, double y) {
        mouseX = x;
        mouseY = y;
        if (!isPressedScreen)
        {
            return;
        }
        float xOffect = lastX - x;
        float yOffect = lastY - y;
        lastX = x;
        lastY = y;

        float sensitivity = 0.1f;
        xOffect *= sensitivity;
        yOffect *= sensitivity;

        yaw += xOffect;
        pitch += yOffect;

        if (pitch > 89.0f)
        {
            pitch = 89.0f;
        }
        if (pitch < -89.0f)
        {
            pitch = -89.0f;
        }

        glm::vec3 front;
        front.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
        front.y = sin(glm::radians(pitch));
        front.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
        cameraFront = glm::normalize(front);
    });

    m_arrProcessInput_MouseScroll.push_back([](double x, double y) {
        fov -= (float)y;
        if (fov < 1.0f)
        {
            fov = 1.0f;
        }
        if (fov > 45.0f)
        {
            fov = 45.0f;
        }
    });

    addProcessInputFunc(GLFW_KEY_W, []() {
        float cameraSpeed = 2.5 * deltaTime;
        cameraPos += cameraSpeed * cameraFront;
    });
    addProcessInputFunc(GLFW_KEY_S, []() {
        float cameraSpeed = 2.5 * deltaTime;
        cameraPos -= cameraSpeed * cameraFront;
    });
    addProcessInputFunc(GLFW_KEY_A, []() {
        float cameraSpeed = 2.5 * deltaTime;
        cameraPos -= cameraSpeed * glm::normalize(glm::cross(cameraFront, cameraUp));
    });
    addProcessInputFunc(GLFW_KEY_D, []() {
        float cameraSpeed = 2.5 * deltaTime;
        cameraPos += cameraSpeed * glm::normalize(glm::cross(cameraFront, cameraUp));
    });

    glEnable(GL_STENCIL_TEST);
    glDepthFunc(GL_LESS);
}

void Lesson33::show()
{
    float currentFrame = glfwGetTime();
    deltaTime = currentFrame - lastFrame;
    lastFrame = currentFrame;
    glm::mat4 model = glm::mat4(1.0f);
    projection = glm::perspective(glm::radians(fov), 800.0f / 600.0f, 0.1f, 100.0f);
    glm::mat4 view = glm::lookAt(cameraPos, cameraPos + cameraFront, cameraUp);

    glBindBuffer(GL_UNIFORM_BUFFER, uboMatrices);
    glBufferSubData(GL_UNIFORM_BUFFER, 0, sizeof(glm::mat4), glm::value_ptr(projection));
    glBufferSubData(GL_UNIFORM_BUFFER, sizeof(glm::mat4), sizeof(glm::mat4), glm::value_ptr(view));
    glBindBuffer(GL_UNIFORM_BUFFER, 0);

    glBindVertexArray(cubeVAO);
    shaderRed.use();
    model = glm::translate(glm::mat4(1.0f), glm::vec3(-0.75f, 0.75f, 0.0f));
    shaderRed.setMat4("model", model);
    glDrawArrays(GL_TRIANGLES, 0, 36);
    shaderGreen.use();
    model = glm::translate(glm::mat4(1.0f), glm::vec3(0.75f, 0.75f, 0.0f));
    shaderGreen.setMat4("model", model);
    glDrawArrays(GL_TRIANGLES, 0, 36);
    shaderBlue.use();
    model = glm::translate(glm::mat4(1.0f), glm::vec3(-0.75f, -0.75f, 0.0f));
    shaderBlue.setMat4("model", model);
    glDrawArrays(GL_TRIANGLES, 0, 36);
    shaderYellow.use();
    model = glm::translate(glm::mat4(1.0f), glm::vec3(0.75f, -0.75f, 0.0f));
    shaderYellow.setMat4("model", model);
    glDrawArrays(GL_TRIANGLES, 0, 36);
}
void Lesson33::over()
{
}