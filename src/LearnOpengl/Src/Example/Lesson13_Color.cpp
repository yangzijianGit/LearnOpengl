/*** 
 * @Author       : yangzijian
 * @Description  : 
 * @Date         : 2021-01-06 16:25:11
 */
#include "Lesson13_Color.h"
#include <glad/glad.h>
#include "Util.h"
#include <iostream>
#include "Shader.h"
#include "glfw3.h"

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
	// world space positions of our cubes
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

	float vertices[] = {
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

	glm::vec3 lightPos(1.2f, 1.0f, 2.0f);

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

} // namespace

void Lesson13::prefix()
{
	glEnable(GL_DEPTH_TEST);

	lightSourceShader.read("1.light_cube.vs", "1.light_cube.fs");
	lightShader.read("1.colors.vs", "1.colors.fs");

	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);

	glBindVertexArray(VAO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	// position attribute
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void *)0);
	glEnableVertexAttribArray(0);

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

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void *)0);
	glEnableVertexAttribArray(0);

	m_arrProcessInput_MouseMove.push_back([](double x, double y) {
		printf("mouse move:%f, %f\n", x, y);
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
		printf("mouse scroll:%f,%f\n", x, y);
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
void Lesson13::show()
{

	float currentFrame = glfwGetTime();
	deltaTime = currentFrame - lastFrame;
	lastFrame = currentFrame;

	projection = glm::perspective(glm::radians(fov), 800.0f / 600.0f, 0.1f, 100.0f);
	glm::mat4 view = glm::lookAt(cameraPos, cameraPos + cameraFront, cameraUp);
	lightShader.use();
	lightShader.setMat4("projection", projection);
	lightShader.setMat4("view", view);
	lightShader.setVec3("objectColor", glm::vec3(1.0f, 0.5f, 0.31f));
	lightShader.setVec3("lightColor", glm::vec3(1.0f, 1.0f, 1.0f));

	glm::mat4 model = glm::mat4(1.0f);
	lightShader.setMat4("model", model);
	glBindVertexArray(VAO);
	glDrawArrays(GL_TRIANGLES, 0, 36);

	lightSourceShader.use();
	lightSourceShader.setMat4("projection", projection);
	lightSourceShader.setMat4("view", view);
	model = glm::mat4(1.0f);
	model = glm::translate(model, lightPos);
	model = glm::scale(model, glm::vec3(0.2f));
	lightSourceShader.setMat4("model", model);
	glBindVertexArray(lightVAO);
	glDrawArrays(GL_TRIANGLES, 0, 36);
}
void Lesson13::over()
{
}