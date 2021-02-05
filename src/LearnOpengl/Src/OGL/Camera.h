/*** 
 * @Author       : yangzijian
 * @Description  : 
 * @Date         : 2021-01-29 11:03:25
 */
#pragma once

#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <vector>

class Camera
{
public:
    enum class Camera_Movement
    {
        FORWARD,
        BACKWARD,
        LEFT,
        RIGHT
    };

    static const float YAW;
    static const float PITCH;
    static const float SPEED;
    static const float SENSITIVITY;
    static const float ZOOM;

public:
    // camera Attributes
    glm::vec3 m_vPosition;
    glm::vec3 m_vFront;
    glm::vec3 m_vUp;
    glm::vec3 m_vRight;
    glm::vec3 m_vWorldUp;
    // euler Angles
    float m_fYaw;
    float m_fPitch;
    // camera options
    float m_fMovementSpeed;
    float m_fMouseSensitity;
    float m_fZoom;

    // constructor
    Camera(glm::vec3 position = glm::vec3(0.0f, 0.0f, 0.0f),
           glm::vec3 up = glm::vec3(0.0f, 1.0f, 0.0f),
           float yaw = YAW, float pitch = PITCH);

    ~Camera();

    glm::mat4 GetViewMatrix();

    void Input_keyBoard(Camera_Movement moveType, float deltaTime);
    void Input_MouseMovement(double xoffect, double yoffect, GLboolean constrainPitch = true);
    void Input_MouseScroll(double xoffect, double yoffect);

private:
    void ComputeCameraVecters();
};
