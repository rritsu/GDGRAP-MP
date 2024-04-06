#pragma once

#include "MyCamera.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>


class OrthoCamera : public MyCamera
{
	private:
		float leftMost;
		float rightMost;
		float bottomMost;
		float topMost;

	public:
		OrthoCamera();

	public:
		glm::mat4 giveProjection();
		void bindView(GLuint shaderProg);

	public:
		float getLeftMost();
		void setLeftMost(float leftmost);
		float getRightMost();
		void setRightMost(float rightMos);
		float getBottomMost();
		void setBottomMost(float bottomMost);
		float getTopMost();
		void setTopMost(float topmost);

};

