//
// Created by Aya on 11/30/2020.
//

#ifndef GFX_LAB_CAMERACOMPONENT_H
#define GFX_LAB_CAMERACOMPONENT_H
#include"ECS/Component.h"

#include <glm/glm.hpp>
#include <glm/gtc/constants.hpp>
#include <glm/trigonometric.hpp>
#include <glm/gtx/fast_trigonometry.hpp>
#include <../common/application.hpp>
#include "Transform.h"
class Camera;
///x=eye,up=y,z=direction
// Allows you to control the camera freely in world space
class CameraController: public Component{
private:
    our::Application* app;///////////////////////////////ask
    Camera *camera;/////////////////////////////////////ask
    float yaw, pitch;
    glm::vec3 position;
    glm::vec3 eye = {0, 0, 0}, direction = {0, 0, -1}, up = {0, 1, 0};
    float yaw_sensitivity, pitch_sensitivity, fov_sensitivity;
    glm::vec3 position_sensitivity;
    float speedup_factor = 5.0f; // A speed multiplier if "Left Shift" is held.
    Transform *T;
    bool mouse_locked = false;

public:
    CameraController(our::Application* application, Camera* camera,Transform* T);

    void release();

    void update(double delta_time);

    [[nodiscard]] float getYaw() const;
    [[nodiscard]] float getPitch() const;
    [[nodiscard]] glm::vec3 getPosition() const;

    [[nodiscard]] float getYawSensitivity() const;
    [[nodiscard]] float getPitchSensitivity() const;
    [[nodiscard]] float getFieldOfViewSensitivity() const;
    [[nodiscard]] glm::vec3 getPositionSensitivity()const;
    [[nodiscard]] float getSpeedUpFactor() const;

    void setYaw(float _yaw);
    void setPitch(float _pitch);
    void setPosition(glm::vec3 _pos);
    void setTransform(Transform* T);

    void setYawSensitivity(float sensitivity);
    void setPitchSensitivity(float sensitivity);
    void setFieldOfViewSensitivity(float sensitivity);
    void setPositionSensitivity(glm::vec3 sensitivity);
    void setEyeUpDirection(glm::mat4 mat);
    glm::vec3 getEye();
    glm::vec3 getUp();
    glm::vec3 getDirection();
    glm::mat4 getViewMatrix();
    ~CameraController(){}
};




#endif //GFX_LAB_CAMERACOMPONENT_H
