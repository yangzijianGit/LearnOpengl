/*** 
 * @Author       : yangzijian
 * @Description  : 
 * @Date         : 2021-01-06 16:25:11
 */
#include "Lesson23_LightSource_Multi.h"
#include <glad/glad.h>
#include "Util.h"
#include <iostream>
#include "Shader.h"
#include "glfw3.h"
#include "Util.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

namespace
{
	unsigned int VBO, VAO;
	unsigned int lightVBO, lightVAO;
	Shader lightSourceShader;
	Shader lightShader;
	glm::mat4 projection;
	// positions all containers
	glm::vec3 cubePositions[] = {
		glm::vec3(0.0f, 0.0f, 0.0f),
		glm::vec3(2.0f, 5.0f, -15.0f),
		glm::vec3(-1.5f, -2.2f, -2.5f),
		glm::vec3(-3.8f, -2.0f, -12.3f),
		glm::vec3(2.4f, -0.4f, -3.5f),
		glm::vec3(-1.7f, 3.0f, -7.5f),
		glm::vec3(1.3f, -2.0f, -2.5f),
		glm::vec3(1.5f, 2.0f, -2.5f),
		glm::vec3(1.5f, 0.2f, -1.5f),
		glm::vec3(-1.3f, 1.0f, -1.5f)};

	// set up vertex data (and buffer(s)) and configure vertex attributes
	// ------------------------------------------------------------------
	float vertices[] = {
		// positions          // normals           // diffuseTex coords
		-0.5f, -0.5f, -0.5f, 0.0f, 0.0f, -1.0f, 0.0f, 0.0f,
		0.5f, -0.5f, -0.5f, 0.0f, 0.0f, -1.0f, 1.0f, 0.0f,
		0.5f, 0.5f, -0.5f, 0.0f, 0.0f, -1.0f, 1.0f, 1.0f,
		0.5f, 0.5f, -0.5f, 0.0f, 0.0f, -1.0f, 1.0f, 1.0f,
		-0.5f, 0.5f, -0.5f, 0.0f, 0.0f, -1.0f, 0.0f, 1.0f,
		-0.5f, -0.5f, -0.5f, 0.0f, 0.0f, -1.0f, 0.0f, 0.0f,

		-0.5f, -0.5f, 0.5f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f,
		0.5f, -0.5f, 0.5f, 0.0f, 0.0f, 1.0f, 1.0f, 0.0f,
		0.5f, 0.5f, 0.5f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f,
		0.5f, 0.5f, 0.5f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f,
		-0.5f, 0.5f, 0.5f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f,
		-0.5f, -0.5f, 0.5f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f,

		-0.5f, 0.5f, 0.5f, -1.0f, 0.0f, 0.0f, 1.0f, 0.0f,
		-0.5f, 0.5f, -0.5f, -1.0f, 0.0f, 0.0f, 1.0f, 1.0f,
		-0.5f, -0.5f, -0.5f, -1.0f, 0.0f, 0.0f, 0.0f, 1.0f,
		-0.5f, -0.5f, -0.5f, -1.0f, 0.0f, 0.0f, 0.0f, 1.0f,
		-0.5f, -0.5f, 0.5f, -1.0f, 0.0f, 0.0f, 0.0f, 0.0f,
		-0.5f, 0.5f, 0.5f, -1.0f, 0.0f, 0.0f, 1.0f, 0.0f,

		0.5f, 0.5f, 0.5f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f,
		0.5f, 0.5f, -0.5f, 1.0f, 0.0f, 0.0f, 1.0f, 1.0f,
		0.5f, -0.5f, -0.5f, 1.0f, 0.0f, 0.0f, 0.0f, 1.0f,
		0.5f, -0.5f, -0.5f, 1.0f, 0.0f, 0.0f, 0.0f, 1.0f,
		0.5f, -0.5f, 0.5f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f,
		0.5f, 0.5f, 0.5f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f,

		-0.5f, -0.5f, -0.5f, 0.0f, -1.0f, 0.0f, 0.0f, 1.0f,
		0.5f, -0.5f, -0.5f, 0.0f, -1.0f, 0.0f, 1.0f, 1.0f,
		0.5f, -0.5f, 0.5f, 0.0f, -1.0f, 0.0f, 1.0f, 0.0f,
		0.5f, -0.5f, 0.5f, 0.0f, -1.0f, 0.0f, 1.0f, 0.0f,
		-0.5f, -0.5f, 0.5f, 0.0f, -1.0f, 0.0f, 0.0f, 0.0f,
		-0.5f, -0.5f, -0.5f, 0.0f, -1.0f, 0.0f, 0.0f, 1.0f,

		-0.5f, 0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f,
		0.5f, 0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 1.0f, 1.0f,
		0.5f, 0.5f, 0.5f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f,
		0.5f, 0.5f, 0.5f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f,
		-0.5f, 0.5f, 0.5f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f,
		-0.5f, 0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f};

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

	glm::vec3 cameraPos = glm::vec3(0.0f, 0.0f, 3.0f);
	glm::vec3 cameraFront = glm::vec3(0.0f, 0.0f, -1.0f);
	glm::vec3 cameraUp = glm::vec3(0.0f, 1.0f, 0.0f);

	double mouseX = 0.0f;
	double mouseY = 0.0f;

	unsigned int diffuseTex;
	unsigned int specularTex;

} // namespace

void Lesson23::prefix()
{
	glEnable(GL_DEPTH_TEST);

	lightSourceShader.read("1.light_cube.vs", "1.light_cube.fs");
	lightShader.read("6.3.multiple_lights.vs", "6.3.multiple_lights.fs");

	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);

	glBindVertexArray(VAO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	// position attribute
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void *)0);
	glEnableVertexAttribArray(0);

	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void *)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);

	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void *)(6 * sizeof(float)));
	glEnableVertexAttribArray(2);

	glActiveTexture(GL_TEXTURE0);
	diffuseTex = util::loadTexture("res/container2.png");
	glActiveTexture(GL_TEXTURE1);
	specularTex = util::loadTexture("res/container2_specular.png");

	m_arrProcessInput_MouseBtn.push_back([](int key, int isPressed, int bit) {
		if (isPressedScreen != isPressed)
		{
			isPressedScreen = isPressed;
			lastX = mouseX;
			lastY = mouseY;
		}
	});

	glGenVertexArrays(1, &lightVAO);
	glGenBuffers(1, &lightVBO);

	glBindVertexArray(lightVAO);

	glBindBuffer(GL_ARRAY_BUFFER, lightVBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void *)0);
	glEnableVertexAttribArray(0);

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
}
void Lesson23::show()
{
	float currentFrame = glfwGetTime();
	deltaTime = currentFrame - lastFrame;
	lastFrame = currentFrame;

	lightShader.use();
	lightShader.setVec3("viewPos", cameraPos);
	projection = glm::perspective(glm::radians(fov), 800.0f / 600.0f, 0.1f, 100.0f);
	glm::mat4 view = glm::lookAt(cameraPos, cameraPos + cameraFront, cameraUp);
	lightShader.setMat4("projection", projection);
	lightShader.setMat4("view", view);

	// material properties
	lightShader.setInt("material.diffuse", 0);
	lightShader.setInt("material.specular", 1);
	lightShader.setFloat("material.shininess", 32.0f);

	// directional light
	lightShader.setVec3("dirLight.direction", -0.2f, -1.0f, -0.3f);
	lightShader.setVec3("dirLight.ambient", 0.05f, 0.05f, 0.05f);
	lightShader.setVec3("dirLight.diffuse", 0.4f, 0.4f, 0.4f);
	lightShader.setVec3("dirLight.specular", 0.5f, 0.5f, 0.5f);
	// point light 1
	lightShader.setVec3("pointLights[0].position", pointLightPositions[0]);
	lightShader.setVec3("pointLights[0].ambient", 0.05f, 0.05f, 0.05f);
	lightShader.setVec3("pointLights[0].diffuse", 0.8f, 0.8f, 0.8f);
	lightShader.setVec3("pointLights[0].specular", 1.0f, 1.0f, 1.0f);
	lightShader.setFloat("pointLights[0].constant", 1.0f);
	lightShader.setFloat("pointLights[0].linear", 0.09f);
	lightShader.setFloat("pointLights[0].quadratic", 0.032f);
	// point light 2
	lightShader.setVec3("pointLights[1].position", pointLightPositions[1]);
	lightShader.setVec3("pointLights[1].ambient", 0.05f, 0.05f, 0.05f);
	lightShader.setVec3("pointLights[1].diffuse", 0.8f, 0.8f, 0.8f);
	lightShader.setVec3("pointLights[1].specular", 1.0f, 1.0f, 1.0f);
	lightShader.setFloat("pointLights[1].constant", 1.0f);
	lightShader.setFloat("pointLights[1].linear", 0.09f);
	lightShader.setFloat("pointLights[1].quadratic", 0.032f);
	// point light 3
	lightShader.setVec3("pointLights[2].position", pointLightPositions[2]);
	lightShader.setVec3("pointLights[2].ambient", 0.05f, 0.05f, 0.05f);
	lightShader.setVec3("pointLights[2].diffuse", 0.8f, 0.8f, 0.8f);
	lightShader.setVec3("pointLights[2].specular", 1.0f, 1.0f, 1.0f);
	lightShader.setFloat("pointLights[2].constant", 1.0f);
	lightShader.setFloat("pointLights[2].linear", 0.09f);
	lightShader.setFloat("pointLights[2].quadratic", 0.032f);
	// point light 4
	lightShader.setVec3("pointLights[3].position", pointLightPositions[3]);
	lightShader.setVec3("pointLights[3].ambient", 0.05f, 0.05f, 0.05f);
	lightShader.setVec3("pointLights[3].diffuse", 0.8f, 0.8f, 0.8f);
	lightShader.setVec3("pointLights[3].specular", 1.0f, 1.0f, 1.0f);
	lightShader.setFloat("pointLights[3].constant", 1.0f);
	lightShader.setFloat("pointLights[3].linear", 0.09f);
	lightShader.setFloat("pointLights[3].quadratic", 0.032f);
	// spotLight
	lightShader.setVec3("spotLight.position", cameraPos);
	lightShader.setVec3("spotLight.direction", cameraFront);
	lightShader.setVec3("spotLight.ambient", 0.0f, 0.0f, 0.0f);
	lightShader.setVec3("spotLight.diffuse", 1.0f, 1.0f, 1.0f);
	lightShader.setVec3("spotLight.specular", 1.0f, 1.0f, 1.0f);
	lightShader.setFloat("spotLight.constant", 1.0f);
	lightShader.setFloat("spotLight.linear", 0.09f);
	lightShader.setFloat("spotLight.quadratic", 0.032f);
	lightShader.setFloat("spotLight.cutOff", glm::cos(glm::radians(12.5f)));
	lightShader.setFloat("spotLight.outerCutOff", glm::cos(glm::radians(15.0f)));

	glBindVertexArray(VAO);

	glm::mat4 model = glm::mat4(1.0f);
	for (int i = 0; i < 10; ++i)
	{
		model = glm::translate(model, cubePositions[i]);
		float angle = 20.0f * i;
		model = glm::rotate(model, glm::radians(angle), glm::vec3(1.0f, 0.3f, 0.5f));
		lightShader.setMat4("model", model);
		glDrawArrays(GL_TRIANGLES, 0, 36);
	}

	lightSourceShader.use();
	lightSourceShader.setMat4("projection", projection);
	lightSourceShader.setMat4("view", view);
	for (int i = 0; i < 4; i++)
	{
		model = glm::mat4(1.0f);
		model = glm::translate(model, pointLightPositions[i]);
		model = glm::scale(model, glm::vec3(0.2f));
		lightSourceShader.setMat4("model", model);
		glBindVertexArray(lightVAO);
		glDrawArrays(GL_TRIANGLES, 0, 36);
	}
}
void Lesson23::over()
{
}