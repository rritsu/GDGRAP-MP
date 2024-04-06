#include "Light.h"

Light::Light() {
	//this->lightPos = glm::vec3(-10.0f, 1.0f, 10.0f);
	this->lightColor = glm::vec3(1.0f, 1.0f, 1.0f);
	this->ambientColor = this->lightColor;
	this->ambientStr = 0.3f;
	this->specStr = 0.5f;
	this->specPhong = 12.0f;
	this->brightness = 1.0f;
}

void Light::bindLighting(GLuint shaderProg) {
	glUseProgram(shaderProg);
	GLuint lightColorAddress = glGetUniformLocation(shaderProg, "lightColor");
	glUniform3fv(lightColorAddress, 1, glm::value_ptr(this->lightColor));

	GLuint ambientStrAddress = glGetUniformLocation(shaderProg, "ambientStr");
	glUniform1f(ambientStrAddress, this->ambientStr);

	GLuint ambientColorAddress = glGetUniformLocation(shaderProg, "ambientColor");
	glUniform3fv(ambientColorAddress, 1, glm::value_ptr(this->ambientColor));

	GLuint specStrAddress = glGetUniformLocation(shaderProg, "specStr");
	glUniform1f(specStrAddress, this->specStr);

	GLuint brightnessAddress = glGetUniformLocation(shaderProg, "brightness");
	glUniform1f(brightnessAddress, this->brightness);

	GLuint specPhongAddress = glGetUniformLocation(shaderProg, "specPhong");
	glUniform1f(specPhongAddress, this->specPhong);
}

//glm::vec3 Light::getLightPos() {
//	return this->lightPos;
//}

/*
void Light::setLightPos_X(float pos_x) {
	this->lightPos.x = pos_x;
}

void Light::setLightPos_Y(float pos_y) {
	this->lightPos.y = pos_y;
}

void Light::setLightPos_Z(float pos_z) {
	this->lightPos.z = pos_z;
}

*/
glm::vec3 Light::getLightColor() {
	return this->lightColor;
}

void Light::setLightColor(glm::vec3 lightColor) {
	this->lightColor = lightColor;
}

glm::vec3 Light::getAmbientColor() {
	return this->ambientColor;
}

void Light::setAmbientColor(glm::vec3 ambientColor) {
	this->ambientColor = ambientColor;
}

float Light::getAmbientStr() {
	return this->ambientStr;
}

void Light::setAmbientStr(float ambientStr) {
	this->ambientStr = ambientStr;
}

float Light::getSpecStr() {
	return this->specStr = specStr;
}

void Light::setSpecStr(float specStr) {
	this->specStr = specStr;
}

float Light::getSpecPhong() {
	return this->specPhong;
}

void Light::setSpecPhong(float specPhong) {
	this->specPhong = specPhong;
}

float Light::getBrightness() {
	return this->brightness;
}

void Light::setBrightness(float brightness) {
	this->brightness = brightness;
}