#include "PointLight.h"

    PointLight::PointLight() {
    this->lightPoint = glm::vec3(1.0f, 1.0f, 2.0f);
}

void PointLight::bindLightPoint(GLuint shaderProg) {
    glUseProgram(shaderProg);
    GLuint lightAddress = glGetUniformLocation(shaderProg, "lightPoint");
    glUniform3fv(lightAddress, 1, glm::value_ptr(this->lightPoint));

    GLuint lightColorAddress = glGetUniformLocation(shaderProg, "lightColor");
    glUniform3fv(lightColorAddress, 1, glm::value_ptr(this->lightColor));
}

void PointLight::setLightPoint(glm::vec3 lightPoint) {
    this->lightPoint = lightPoint;
}

void PointLight::setLightPoint_X(float point_x) {
    this->lightPoint.x = point_x;
}

void PointLight::setLightPoint_Y(float point_y) {
    this->lightPoint.y = point_y;
}

void PointLight::setLightPoint_Z(float point_z) {
    this->lightPoint.z = point_z;
}

void PointLight::setLightColor(glm::vec3 lightColor) {
    this->lightColor = lightColor;
}

glm::vec3 PointLight::getLightPosition() const {
    return this->lightPoint;
}
