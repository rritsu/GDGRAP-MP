#pragma once

#include "iostream"

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class MyCamera
{
	private:
	//	glm::vec3 cameraPos;
		//glm::vec3 cameraFront;
	//	glm::vec3 cameraUp;
		float yaw;
		float pitch;
		float last_x;
		float last_y;

	protected:
		glm::vec3 cameraPos;
		glm::vec3 cameraFront;
		glm::vec3 cameraUp;
		glm::mat4 projection;
		float fov;
		float z_far;
		float z_near;

	public:
		MyCamera();

	public:
		void initialize(bool* firstMouse, double xpos, double ypos);
		void updateMouse(double xpos, double ypos);
		void bindView(GLuint shaderProg);
		void bindProjection(GLuint shaderProg, glm::mat4 projection);

	public:
		glm::vec3 getCameraPos();
		void setCameraPos(glm::vec3 cameraPos);
		glm::vec3 getCameraFront();
		void setCameraFront(glm::vec3 cameraFront);
		glm::vec3 getCameraUp();

		glm::mat4 getProjection();
		void setProjection(glm::mat4 projection);
		float getZ_Far();
		void setZ_Far(float z_far);
		float getZ_Near();
		void setZ_Near(float z_near);
};

/*
//camera variables
glm::vec3 cameraPos = glm::vec3(0.0f, 0.0f, 3.0f);
glm::vec3 cameraFront = glm::vec3(0.0f, 0.0f, -1.0f);
glm::vec3 cameraUp = glm::vec3(0.0f, 1.0f, 0.0f);


//mouse position/stateS
float yaw = -90.0f;
float pitch = 0.0f;
float fov = 45.0f;
bool firstMouse = true;
float lastX = 800.0f / 2.0;
float lastY = 600.0 / 2.0;
*/