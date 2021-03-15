/*** 
 * @Author       : yangzijian
 * @Description  : 
 * @Date         : 2021-01-06 16:25:11
 */
#include "Lesson32_cubeMaps_skybox2.h"
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
    unsigned int skyBoxVBO, skyBoxVAO;
    unsigned int skyboxTexture;
    std::vector<std::string> faces =
        {
            "res/skybox/right.jpg",
            "res/skybox/left.jpg",
            "res/skybox/top.jpg",
            "res/skybox/bottom.jpg",
            "res/skybox/front.jpg",
            "res/skybox/back.jpg"};
    Shader shader_reflect;
    Shader shader_refract;
    Shader skyboxShader;
    glm::mat4 projection;
    // transparent window locations
    // --------------------------------
    std::vector<glm::vec3> windows{
        glm::vec3(-1.5f, 0.0f, -0.48f),
        glm::vec3(1.5f, 0.0f, 0.51f),
        glm::vec3(0.0f, 0.0f, 0.7f),
        glm::vec3(-0.3f, 0.0f, -2.3f),
        glm::vec3(0.5f, 0.0f, -0.6f)};

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
        -0.5f, -0.5f, -0.5f, 0.0f, 0.0f, -1.0f,
        0.5f, -0.5f, -0.5f, 0.0f, 0.0f, -1.0f,
        0.5f, 0.5f, -0.5f, 0.0f, 0.0f, -1.0f,
        0.5f, 0.5f, -0.5f, 0.0f, 0.0f, -1.0f,
        -0.5f, 0.5f, -0.5f, 0.0f, 0.0f, -1.0f,
        -0.5f, -0.5f, -0.5f, 0.0f, 0.0f, -1.0f,

        -0.5f, -0.5f, 0.5f, 0.0f, 0.0f, 1.0f,
        0.5f, -0.5f, 0.5f, 0.0f, 0.0f, 1.0f,
        0.5f, 0.5f, 0.5f, 0.0f, 0.0f, 1.0f,
        0.5f, 0.5f, 0.5f, 0.0f, 0.0f, 1.0f,
        -0.5f, 0.5f, 0.5f, 0.0f, 0.0f, 1.0f,
        -0.5f, -0.5f, 0.5f, 0.0f, 0.0f, 1.0f,

        -0.5f, 0.5f, 0.5f, -1.0f, 0.0f, 0.0f,
        -0.5f, 0.5f, -0.5f, -1.0f, 0.0f, 0.0f,
        -0.5f, -0.5f, -0.5f, -1.0f, 0.0f, 0.0f,
        -0.5f, -0.5f, -0.5f, -1.0f, 0.0f, 0.0f,
        -0.5f, -0.5f, 0.5f, -1.0f, 0.0f, 0.0f,
        -0.5f, 0.5f, 0.5f, -1.0f, 0.0f, 0.0f,

        0.5f, 0.5f, 0.5f, 1.0f, 0.0f, 0.0f,
        0.5f, 0.5f, -0.5f, 1.0f, 0.0f, 0.0f,
        0.5f, -0.5f, -0.5f, 1.0f, 0.0f, 0.0f,
        0.5f, -0.5f, -0.5f, 1.0f, 0.0f, 0.0f,
        0.5f, -0.5f, 0.5f, 1.0f, 0.0f, 0.0f,
        0.5f, 0.5f, 0.5f, 1.0f, 0.0f, 0.0f,

        -0.5f, -0.5f, -0.5f, 0.0f, -1.0f, 0.0f,
        0.5f, -0.5f, -0.5f, 0.0f, -1.0f, 0.0f,
        0.5f, -0.5f, 0.5f, 0.0f, -1.0f, 0.0f,
        0.5f, -0.5f, 0.5f, 0.0f, -1.0f, 0.0f,
        -0.5f, -0.5f, 0.5f, 0.0f, -1.0f, 0.0f,
        -0.5f, -0.5f, -0.5f, 0.0f, -1.0f, 0.0f,

        -0.5f, 0.5f, -0.5f, 0.0f, 1.0f, 0.0f,
        0.5f, 0.5f, -0.5f, 0.0f, 1.0f, 0.0f,
        0.5f, 0.5f, 0.5f, 0.0f, 1.0f, 0.0f,
        0.5f, 0.5f, 0.5f, 0.0f, 1.0f, 0.0f,
        -0.5f, 0.5f, 0.5f, 0.0f, 1.0f, 0.0f,
        -0.5f, 0.5f, -0.5f, 0.0f, 1.0f, 0.0f};
    float skyboxVertices[] = {
        // positions
        -1.0f, 1.0f, -1.0f,
        -1.0f, -1.0f, -1.0f,
        1.0f, -1.0f, -1.0f,
        1.0f, -1.0f, -1.0f,
        1.0f, 1.0f, -1.0f,
        -1.0f, 1.0f, -1.0f,

        -1.0f, -1.0f, 1.0f,
        -1.0f, -1.0f, -1.0f,
        -1.0f, 1.0f, -1.0f,
        -1.0f, 1.0f, -1.0f,
        -1.0f, 1.0f, 1.0f,
        -1.0f, -1.0f, 1.0f,

        1.0f, -1.0f, -1.0f,
        1.0f, -1.0f, 1.0f,
        1.0f, 1.0f, 1.0f,
        1.0f, 1.0f, 1.0f,
        1.0f, 1.0f, -1.0f,
        1.0f, -1.0f, -1.0f,

        -1.0f, -1.0f, 1.0f,
        -1.0f, 1.0f, 1.0f,
        1.0f, 1.0f, 1.0f,
        1.0f, 1.0f, 1.0f,
        1.0f, -1.0f, 1.0f,
        -1.0f, -1.0f, 1.0f,

        -1.0f, 1.0f, -1.0f,
        1.0f, 1.0f, -1.0f,
        1.0f, 1.0f, 1.0f,
        1.0f, 1.0f, 1.0f,
        -1.0f, 1.0f, 1.0f,
        -1.0f, 1.0f, -1.0f,

        -1.0f, -1.0f, -1.0f,
        -1.0f, -1.0f, 1.0f,
        1.0f, -1.0f, -1.0f,
        1.0f, -1.0f, -1.0f,
        -1.0f, -1.0f, 1.0f,
        1.0f, -1.0f, 1.0f};

    glm::vec3 cameraPos = glm::vec3(0.0f, 0.0f, 3.0f);
    glm::vec3 cameraFront = glm::vec3(0.0f, 0.0f, -1.0f);
    glm::vec3 cameraUp = glm::vec3(0.0f, 1.0f, 0.0f);

    double mouseX = 0.0f;
    double mouseY = 0.0f;

} // namespace

void Lesson32::prefix()
{
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    shader_reflect.read("6.1.cubemaps_reflect.vs", "6.1.cubemaps_reflect.fs");
    shader_refract.read("6.1.cubemaps_refract.vs", "6.1.cubemaps_refract.fs");
    skyboxShader.read("6.1.skybox.vs", "6.1.skybox.fs");

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

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void *)0);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void *)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);
    glBindVertexArray(0);

    glGenVertexArrays(1, &skyBoxVAO);
    glBindVertexArray(skyBoxVAO);
    glGenBuffers(1, &skyBoxVBO);
    glBindBuffer(GL_ARRAY_BUFFER, skyBoxVBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(skyboxVertices), &skyboxVertices, GL_STATIC_DRAW);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void *)0);

    skyboxTexture = util::loadCubeMaps(faces);
    shader_refract.use();
    shader_refract.setInt("skybox", 0);
    shader_reflect.use();
    shader_reflect.setInt("skybox", 0);
    skyboxShader.use();
    skyboxShader.setInt("skybox", 0);

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

void Lesson32::show()
{
    float currentFrame = glfwGetTime();
    deltaTime = currentFrame - lastFrame;
    lastFrame = currentFrame;
    glm::mat4 model = glm::mat4(1.0f);
    projection = glm::perspective(glm::radians(fov), 800.0f / 600.0f, 0.1f, 100.0f);
    glm::mat4 view = glm::lookAt(cameraPos, cameraPos + cameraFront, cameraUp);

    shader_reflect.use();
    shader_reflect.setMat4("view", view);
    shader_reflect.setMat4("projection", projection);
    shader_reflect.setVec3("cameraPos", cameraPos);
    // cubes
    glBindVertexArray(cubeVAO);
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, skyboxTexture);
    model = glm::translate(model, glm::vec3(-1.0f, 0.0f, -1.0f));
    shader_reflect.setMat4("model", model);
    glDrawArrays(GL_TRIANGLES, 0, 36);
    shader_refract.use();
    shader_refract.setMat4("view", view);
    shader_refract.setMat4("projection", projection);
    shader_refract.setVec3("cameraPos", cameraPos);
    model = glm::mat4(1.0f);
    model = glm::translate(model, glm::vec3(2.0f, 0.0f, 0.0f));
    shader_refract.setMat4("model", model);
    glDrawArrays(GL_TRIANGLES, 0, 36);

    // draw skybox as last
    glDepthFunc(GL_LEQUAL); // change depth function so depth test passes when values are equal to depth buffer's content
    skyboxShader.use();
    skyboxShader.setMat4("view", glm::mat4(glm::mat3(view)));
    skyboxShader.setMat4("projection", projection);
    // skybox cube
    glBindVertexArray(skyBoxVAO);
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_CUBE_MAP, skyboxTexture);
    glDrawArrays(GL_TRIANGLES, 0, 36);
    glBindVertexArray(0);
    glDepthFunc(GL_LESS); // set depth function back to default
}
void Lesson32::over()
{
}