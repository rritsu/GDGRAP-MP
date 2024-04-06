#ifndef POINTLIGHT_H
#define POINTLIGHT_H

#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>

class PointLight {
public:
    PointLight();
    void bindLightPoint(GLuint shaderProg);
    void setLightPoint(glm::vec3 lightPoint);
    void setLightPoint_X(float point_x);
    void setLightPoint_Y(float point_y);
    void setLightPoint_Z(float point_z);
    glm::vec3 getLightPosition() const;
    void setLightColor(glm::vec3 color);

private:
    glm::vec3 lightPoint;
    glm::vec3 lightColor;
};

#endif 