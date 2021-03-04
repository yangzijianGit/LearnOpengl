/*** 
 * @Author       : yangzijian
 * @Description  : 
 * @Date         : 2021-01-06 16:25:11
 */
#include "Lesson26_StencilTest.h"
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
    unsigned int planeVBO, planeVAO;
    unsigned int cubeTexture, floorTexture;
    Shader shader;
    Shader shaderSingleColor;
    glm::mat4 projection;
    // positions of the point lights
    glm::vec3 pointLightPositions[] = {
        glm::vec3(0.7f, 0.2f, 2.0f),
        glm::vec3(2.3f, -3.3f, -4.0f),
        glm::vec3(-4.0f, 2.0f, -12.0f),
        glm::vec3(0.0f, 0.0f, -3.0f)};

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
        // positions          // texture Coords
        -0.5f, -0.5f, -0.5f, 0.0f, 0.0f,
        0.5f, -0.5f, -0.5f, 1.0f, 0.0f,
        0.5f, 0.5f, -0.5f, 1.0f, 1.0f,
        0.5f, 0.5f, -0.5f, 1.0f, 1.0f,
        -0.5f, 0.5f, -0.5f, 0.0f, 1.0f,
        -0.5f, -0.5f, -0.5f, 0.0f, 0.0f,

        -0.5f, -0.5f, 0.5f, 0.0f, 0.0f,
        0.5f, -0.5f, 0.5f, 1.0f, 0.0f,
        0.5f, 0.5f, 0.5f, 1.0f, 1.0f,
        0.5f, 0.5f, 0.5f, 1.0f, 1.0f,
        -0.5f, 0.5f, 0.5f, 0.0f, 1.0f,
        -0.5f, -0.5f, 0.5f, 0.0f, 0.0f,

        -0.5f, 0.5f, 0.5f, 1.0f, 0.0f,
        -0.5f, 0.5f, -0.5f, 1.0f, 1.0f,
        -0.5f, -0.5f, -0.5f, 0.0f, 1.0f,
        -0.5f, -0.5f, -0.5f, 0.0f, 1.0f,
        -0.5f, -0.5f, 0.5f, 0.0f, 0.0f,
        -0.5f, 0.5f, 0.5f, 1.0f, 0.0f,

        0.5f, 0.5f, 0.5f, 1.0f, 0.0f,
        0.5f, 0.5f, -0.5f, 1.0f, 1.0f,
        0.5f, -0.5f, -0.5f, 0.0f, 1.0f,
        0.5f, -0.5f, -0.5f, 0.0f, 1.0f,
        0.5f, -0.5f, 0.5f, 0.0f, 0.0f,
        0.5f, 0.5f, 0.5f, 1.0f, 0.0f,

        -0.5f, -0.5f, -0.5f, 0.0f, 1.0f,
        0.5f, -0.5f, -0.5f, 1.0f, 1.0f,
        0.5f, -0.5f, 0.5f, 1.0f, 0.0f,
        0.5f, -0.5f, 0.5f, 1.0f, 0.0f,
        -0.5f, -0.5f, 0.5f, 0.0f, 0.0f,
        -0.5f, -0.5f, -0.5f, 0.0f, 1.0f,

        -0.5f, 0.5f, -0.5f, 0.0f, 1.0f,
        0.5f, 0.5f, -0.5f, 1.0f, 1.0f,
        0.5f, 0.5f, 0.5f, 1.0f, 0.0f,
        0.5f, 0.5f, 0.5f, 1.0f, 0.0f,
        -0.5f, 0.5f, 0.5f, 0.0f, 0.0f,
        -0.5f, 0.5f, -0.5f, 0.0f, 1.0f};
    float planeVertices[] = {
        // positions          // texture Coords (note we set these higher than 1 (together with GL_REPEAT as texture wrapping mode). this will cause the floor texture to repeat)
        5.0f, -0.5f, 5.0f, 2.0f, 0.0f,
        -5.0f, -0.5f, 5.0f, 0.0f, 0.0f,
        -5.0f, -0.5f, -5.0f, 0.0f, 2.0f,

        5.0f, -0.5f, 5.0f, 2.0f, 0.0f,
        -5.0f, -0.5f, -5.0f, 0.0f, 2.0f,
        5.0f, -0.5f, -5.0f, 2.0f, 2.0f};
    glm::vec3 cameraPos = glm::vec3(0.0f, 0.0f, 3.0f);
    glm::vec3 cameraFront = glm::vec3(0.0f, 0.0f, -1.0f);
    glm::vec3 cameraUp = glm::vec3(0.0f, 1.0f, 0.0f);

    double mouseX = 0.0f;
    double mouseY = 0.0f;

} // namespace

void Lesson26::prefix()
{
    glEnable(GL_DEPTH_TEST);

    shader.read("2.stencil_testing.vs", "2.stencil_testing.fs");
    shaderSingleColor.read("2.stencil_testing.vs", "2.stencil_single_color.fs");

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

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void *)0);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void *)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);
    glBindVertexArray(0);

    glGenVertexArrays(1, &planeVAO);
    glBindVertexArray(planeVAO);
    glGenBuffers(1, &planeVBO);
    glBindBuffer(GL_ARRAY_BUFFER, planeVBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(planeVertices), planeVertices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void *)0);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void *)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);
    glBindVertexArray(0);

    cubeTexture = util::loadTexture("res/container.jpg");
    floorTexture = util::loadTexture("res/wall.jpg");
    shader.use();
    shader.setInt("texture1", 0);

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
    glStencilFunc(GL_NOTEQUAL, 1, 0xFF);
    glStencilOp(GL_KEEP, GL_KEEP, GL_REPLACE);
}

namespace
{
    void drawTwoBox(Shader &ss, float scale)
    {
        ss.use();
        glm::mat4 model(1.0);
        glBindVertexArray(cubeVAO);

        model = glm::translate(model, glm::vec3(-1.0f, 0.0f, -1.0f));
        model = glm::scale(model, glm::vec3(scale));
        ss.setMat4("model", model);
        glDrawArrays(GL_TRIANGLES, 0, 36);
        model = glm::mat4(1.0f);
        model = glm::translate(model, glm::vec3(2.0f, 0.0f, 0.0f));
        model = glm::scale(model, glm::vec3(scale));
        ss.setMat4("model", model);
        glDrawArrays(GL_TRIANGLES, 0, 36);
    }
} // namespace
void Lesson26::show()
{
    float currentFrame = glfwGetTime();
    deltaTime = currentFrame - lastFrame;
    lastFrame = currentFrame;
    glm::mat4 model = glm::mat4(1.0f);
    projection = glm::perspective(glm::radians(fov), 800.0f / 600.0f, 0.1f, 100.0f);
    glm::mat4 view = glm::lookAt(cameraPos, cameraPos + cameraFront, cameraUp);

    shader.use();
    shader.setMat4("projection", projection);
    shader.setMat4("view", view);
    // floor
    glStencilMask(0x00);
    glBindVertexArray(planeVAO);
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, floorTexture);
    shader.setMat4("model", glm::mat4(1.0f));
    glDrawArrays(GL_TRIANGLES, 0, 6);
    glBindVertexArray(0);

    // cube
    glStencilFunc(GL_ALWAYS, 1, 0xFF);
    glStencilMask(0xFF);
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, cubeTexture);
    drawTwoBox(shader, 1.0f);

    glStencilFunc(GL_NOTEQUAL, 1, 0xFF);
    glStencilMask(0x00);
    glDisable(GL_DEPTH_TEST);
    shaderSingleColor.use();
    shaderSingleColor.setMat4("projection", projection);
    shaderSingleColor.setMat4("view", view);
    drawTwoBox(shaderSingleColor, 1.1f);
    glStencilMask(0xFF);
    glStencilFunc(GL_ALWAYS, 0, 0xFF);
    glEnable(GL_DEPTH_TEST);
}
void Lesson26::over()
{
}