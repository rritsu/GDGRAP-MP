#pragma once

#include "Light.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class DirectionLight : public Light
{
	private:
		glm::vec3 lightDirection;

	public:
		DirectionLight();

	public:
		void bindLightDirection(GLuint shaderProg);

	public:
		glm::vec3 getLightDirection();
		void setLightDirection(glm::vec3 lightDirection);
		void setLightDir_X(float dir_x);
		void setLightDir_Y(float dir_y);
		void setLightDir_Z(float dir_z);
};

