#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class Light
{
	protected:
	//	glm::vec3 lightPos;
		glm::vec3 lightColor;
		glm::vec3 ambientColor;
		float ambientStr;
		float specStr;
		float specPhong;
		float brightness;

	public:
		Light();

	public:
		void bindLighting(GLuint shaderProg);

	public:
		//glm::vec3 getLightPos();
	//	void setLightPos_X(float pos_x);
	//	void setLightPos_Y(float pos_y);
	//	void setLightPos_Z(float pos_z);


		glm::vec3 getLightColor();
		void setLightColor(glm::vec3 lightColor);
		glm::vec3 getAmbientColor();
		void setAmbientColor(glm::vec3 ambientColor);
		float getAmbientStr();
		void setAmbientStr(float ambientStr);
		float getSpecStr();
		void setSpecStr(float specStr);
		float getSpecPhong();
		void setSpecPhong(float specPhong);
		float getBrightness();
		void setBrightness(float brightness);

};