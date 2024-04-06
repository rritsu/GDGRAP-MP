#include "MyCamera.h"

MyCamera::MyCamera() {
    this->cameraPos = glm::vec3(0.0f, 0.0f, 3.0f);
    this->cameraFront = glm::vec3(0.0f, 0.0f, -1.0f);
    this->cameraUp = glm::vec3(0.0f, 1.0f, 0.0f);

    //mouse position/stateS
    this->yaw = -90.0f;
    this->pitch = 0.0f;
    this->fov = 45.0f;
    this->last_x = 800.0f / 2.0;
    this->last_y = 600.0 / 2.0;

	this->projection = glm::mat4(0.0f);
	this->z_far = 1.0f;
	this->z_near = -1.0f;
}

void MyCamera::initialize(bool* firstMouse, double xpos, double ypos) {
    if (*firstMouse)
    {
        //MyCamera camera;
        this->last_x = xpos;
        this->last_y = ypos;
        *firstMouse = false;
    }
}

void MyCamera::updateMouse(double xpos, double ypos) {
    float xoffset = xpos - this->last_x;
    float yoffset = this->last_y - ypos;
    this->last_x = xpos;
    this->last_y = ypos;

    //this logic shows if the higher the sensitivity the larger the mouse movements
    float sensitivity = 0.1f;
    xoffset *= sensitivity;
    yoffset *= sensitivity;

    this->yaw += xoffset;
    this->pitch += yoffset;

    //capped to 90 in order to avoid flipping the perspective
    if (this->pitch > 89.0f)
        this->pitch = 89.0f;
    if (this->pitch < -89.0f)
        this->pitch = -89.0f;

    //camera vector to update camera front 
    glm::vec3 front = glm::vec3(1.0f);
    front.x = cos(glm::radians(this->yaw)) * cos(glm::radians(this->pitch));
    front.y = sin(glm::radians(this->pitch));
    front.z = sin(glm::radians(this->yaw)) * cos(glm::radians(this->pitch));
    this->cameraFront = glm::normalize(front);
}


void MyCamera::bindView(GLuint shaderProg) {
    //camera
    glUseProgram(shaderProg);
    glm::mat4 viewMatrix = glm::lookAt(this->cameraPos, this->cameraPos + this->cameraFront, this->cameraUp);
    unsigned int viewLoc = glGetUniformLocation(shaderProg, "view");
    glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(viewMatrix));
}

void MyCamera::bindProjection(GLuint shaderProg, glm::mat4 projection) {
    glUseProgram(shaderProg);
    this->setProjection(projection);
    unsigned int projLoc = glGetUniformLocation(shaderProg, "projection");
    glUniformMatrix4fv(projLoc, 1, GL_FALSE, glm::value_ptr(projection));
}

glm::vec3 MyCamera::getCameraPos() {
    return this->cameraPos;
}

void MyCamera::setCameraPos(glm::vec3 cameraPos) {
    this->cameraPos = cameraPos;
}

glm::vec3 MyCamera::getCameraFront() {
    return this->cameraFront;
}

void MyCamera::setCameraFront(glm::vec3 cameraFront) {
    this->cameraFront = cameraFront;
}

glm::vec3 MyCamera::getCameraUp() {
    return this->cameraUp;
}




/*
might not be needed
void MyCamera::switchToOrtho() {
	this->z_far = 1.0f;
	this->z_near = -1.0f;
}

void MyCamera::switchToPerspective() {
	this->z_far = 100.0f;
	this->z_near = 0.1f;
}
*/




glm::mat4 MyCamera::getProjection() {
	return this->projection;
}

void MyCamera::setProjection(glm::mat4 projection) {
	this->projection = projection;
}

float MyCamera::getZ_Far() {
	return this->z_far;
}

void MyCamera::setZ_Far(float z_far) {
	this->z_far = z_far;
}

float MyCamera::getZ_Near() {
	return this->z_near;
}

void MyCamera::setZ_Near(float z_near) {
	this->z_near = z_near;
}