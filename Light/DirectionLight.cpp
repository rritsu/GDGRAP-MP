#include "DirectionLight.h"

DirectionLight::DirectionLight() {
	this->lightDirection = glm::vec3(4.0f, -5.0f, 0.0f); // TEMPORARY VALUES, change if needed
}

void DirectionLight::bindLightDirection(GLuint shaderProg) {
	glUseProgram(shaderProg);
	GLuint lightDirectionAddress = glGetUniformLocation(shaderProg, "lightDirection");
	glUniform3fv(lightDirectionAddress, 1, glm::value_ptr(this->lightDirection));
}

glm::vec3 DirectionLight::getLightDirection() {
	return this->lightDirection;
}

void DirectionLight::setLightDirection(glm::vec3 lightDirection) {
	this->lightDirection = lightDirection;
}

void DirectionLight::setLightDir_X(float dir_x) {
	this->lightDirection.x = dir_x;
}

void DirectionLight::setLightDir_Y(float dir_y) {
	this->lightDirection.y = dir_y;
}

void DirectionLight::setLightDir_Z(float dir_z) {
	this->lightDirection.z = dir_z;
}