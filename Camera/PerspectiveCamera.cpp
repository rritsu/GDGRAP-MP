#include "PerspectiveCamera.h"

PerspectiveCamera::PerspectiveCamera() {
}

void PerspectiveCamera::bindView(GLuint shaderProg) {
    //camera
    glUseProgram(shaderProg);
    glm::mat4 viewMatrix = glm::lookAt(this->cameraPos, this->cameraPos + this->cameraFront, this->cameraUp);
    unsigned int viewLoc = glGetUniformLocation(shaderProg, "view");
    glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(viewMatrix));
}

glm::mat4 PerspectiveCamera::giveProjection(float width, float height) {
	//this->z_near = -1.0f;
	//this->z_far = 1.0f;
	return glm::perspective(glm::radians(this->fov), height / width, this->z_near, this->z_far);
}