/*** 
 * @Author       : yangzijian
 * @Description  : 
 * @Date         : 2021-01-29 11:03:25
 */

#include "Camera.h"

const float Camera::YAW = -90.0f;
const float Camera::PITCH = 0.0f;
const float Camera::SPEED = 2.5;
const float Camera::SENSITIVITY = 0.1f;
const float Camera::ZOOM = 45.0f;

// constructor
Camera::Camera(glm::vec3 position,
               glm::vec3 up,
               float yaw, float pitch)
    : m_vUp(0.0f, 1.0f, 0.0f),
      m_fMovementSpeed(SPEED), m_fMouseSensitity(SENSITIVITY), m_fZoom(ZOOM)
{
    m_vPosition = position;
    m_vWorldUp = up;
    m_fYaw = yaw;
    m_fPitch = pitch;
    ComputeCameraVecters();
}

Camera::~Camera()
{
}

glm::mat4 Camera::GetViewMatrix()
{
    return glm::lookAt(m_vPosition, m_vPosition + m_vFront, m_vUp);
}

void Camera::Input_keyBoard(Camera_Movement moveType, float deltaTime)
{
    float velocity = m_fMovementSpeed * deltaTime;
    switch (moveType)
    {
    case Camera::Camera_Movement::FORWARD:
    {
        m_vPosition += m_vFront * velocity;
    }
    break;
    case Camera::Camera_Movement::BACKWARD:
    {
        m_vPosition += -m_vFront * velocity;
    }
    break;
    case Camera::Camera_Movement::LEFT:
    {
        m_vPosition += -m_vRight * velocity;
    }
    break;
    case Camera::Camera_Movement::RIGHT:
    {
        m_vPosition += m_vRight * velocity;
    }
    break;
    default:
        break;
    }
}
void Camera::Input_MouseMovement(double xoffect, double yoffect, GLboolean constrainPitch)
{
    xoffect *= m_fMouseSensitity;
    yoffect *= m_fMouseSensitity;

    m_fYaw += xoffect;
    m_fPitch += yoffect;

    if (constrainPitch)
    {
        if (m_fPitch > 89.0f)
            m_fPitch = 89.0f;
        if (m_fPitch < -89.0f)
            m_fPitch = -89.0f;
    }
    ComputeCameraVecters();
}
void Camera::Input_MouseScroll(double xoffect, double yoffect)
{
    m_fZoom -= (float)yoffect;
    if (m_fZoom < 1.0f)
        m_fZoom = 1.0f;
    if (m_fZoom > 45.0f)
        m_fZoom = 45.0f;
}

void Camera::ComputeCameraVecters()
{
    glm::vec3 front;
    front.x = cos(glm::radians(m_fYaw)) * cos(glm::radians(m_fPitch));
    front.y = sin(glm::radians(m_fPitch));
    front.z = sin(glm::radians(m_fYaw)) * cos(glm::radians(m_fPitch));
    m_vFront = glm::normalize(front);
    m_vRight = glm::normalize(glm::cross(m_vFront, m_vWorldUp));
    m_vUp = glm::normalize(glm::cross(m_vRight, m_vFront));
}