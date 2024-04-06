#include "Model3D.h"

Model3D::Model3D() {
    this->pos_x = 0.0f;
    this->pos_y = 0.0f;
    this->pos_z = 0.0f;
    this->scale_x = 0.003f;
    this->scale_y = 0.003f;
    this->scale_z = 0.003f;
    this->axis_x = 0.0f;
    this->axis_y = 1.0f;
    this->axis_z = 0.0f;
    this->theta_x= 0.0f;
    this->theta_y= 0.0f;
    this->theta_z= 0.0f;
    this->modelColor = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);
}

//this behavior is for applying transformation and drawing the model
void Model3D::drawModel(std::vector<GLfloat> fullVertexData, GLuint texture, GLuint shaderProg, GLuint* VAO, int numVertices) {
    glm::mat4 transformation_matrix;

    //translate
    transformation_matrix = glm::translate(glm::mat4(1.0f),
        glm::vec3(this->pos_x, this->pos_y, this->pos_x)
    );

    //scale
    transformation_matrix = glm::scale(transformation_matrix,
        glm::vec3(this->scale_x, this->scale_y, this->scale_z)
    );

    //rotate
    //X-AXIS
    transformation_matrix = glm::rotate(transformation_matrix,
        glm::radians(this->theta_x),
        glm::normalize(glm::vec3(1, 0, 0))
    );

    //Y-AXIS
    transformation_matrix = glm::rotate(transformation_matrix,
        glm::radians(this->theta_y),
        glm::normalize(glm::vec3(0, 1, 0))
    );

    //Z-AXIS
    transformation_matrix = glm::rotate(transformation_matrix,
        glm::radians(this->theta_z),
        glm::normalize(glm::vec3(0, 0, 1))
    );

  //  std::cout << "loob: " << this->getAxis_Y() << std::endl;
   
    glUseProgram(shaderProg);

    //transform
    unsigned int transformloc = glGetUniformLocation(shaderProg, "transform");
    glUniformMatrix4fv(transformloc, 1, GL_FALSE, glm::value_ptr(transformation_matrix));

   // GLuint tex0Address = glGetUniformLocation(shaderProg, "tex0");
   // glBindTexture(GL_TEXTURE_2D, texture);
   // glUniform1i(tex0Address, 0);

    //draw
    glBindVertexArray(*VAO);
   // glDrawElements(GL_TRIANGLES, mesh_indices.size(), GL_UNSIGNED_INT, 0);
    glDrawArrays(GL_TRIANGLES, 0, fullVertexData.size() / numVertices);
}

void Model3D::drawLightPoint(std::vector<GLuint> mesh_indices, GLuint shaderProg, GLuint* sphereVAO) {
    glm::mat4 transformation_matrix;

    //translate
    transformation_matrix = glm::translate(glm::mat4(1.0f),
        glm::vec3(this->pos_x, this->pos_y, this->pos_x)
    );

    //scale
    transformation_matrix = glm::scale(transformation_matrix,
        glm::vec3(this->scale_x, this->scale_y, this->scale_z)
    );

    //rotate
    transformation_matrix = glm::rotate(transformation_matrix,
        glm::radians(this->theta_x),
        glm::normalize(glm::vec3(2, 0, 0))
    );

    //Y-AXIS
    transformation_matrix = glm::rotate(transformation_matrix,
        glm::radians(this->theta_y),
        glm::normalize(glm::vec3(0, 2, 0))
    );

    //Z-AXIS
    transformation_matrix = glm::rotate(transformation_matrix,
        glm::radians(this->theta_z),
        glm::normalize(glm::vec3(0, 0, 2))
    );

    glUseProgram(shaderProg);

   // this->bindModelColor(shaderProg, this->modelColor);
    GLuint modelColorAddress = glGetUniformLocation(shaderProg, "modelColor");
    glUniform4fv(modelColorAddress, 1, glm::value_ptr(modelColor));

    //transform
    unsigned int transformloc = glGetUniformLocation(shaderProg, "transform");
    glUniformMatrix4fv(transformloc, 1, GL_FALSE, glm::value_ptr(transformation_matrix));

    //draw
    glBindVertexArray(*sphereVAO);
    glDrawElements(GL_TRIANGLES, mesh_indices.size(), GL_UNSIGNED_INT, 0);
}

void Model3D::bindModelColor(GLuint shaderProg, glm::vec4 modelColor) {
    glUseProgram(shaderProg);
    GLuint modelColorAddress = glGetUniformLocation(shaderProg, "modelColor");
    glUniform4fv(modelColorAddress, 1, glm::value_ptr(modelColor));
}

void Model3D::setPosition(glm::vec3 newPos) {
    pos_x = newPos.x;
    pos_y = newPos.y;
    pos_z = newPos.z;
}

glm::vec3 Model3D::getPosition() const {
    return glm::vec3(pos_x, pos_y, pos_z);
}

void Model3D::setScale(glm::vec3 scale) {
    scale_x = scale.x;
    scale_y = scale.y;
    scale_z = scale.z;
}

glm::vec3 Model3D::getScale() const {
    return glm::vec3(scale_x, scale_y, scale_z);
}

//GETTERS
//position
float Model3D::getPos_X() {
    return this->pos_x;
}

float Model3D::getPos_Y() {
    return this->pos_x;
}

float Model3D::getPos_Z() {
    return this->pos_z;
}

void Model3D::setPos_X(float pos_x) {
    this->pos_x = pos_x;
}

void Model3D::setPos_Y(float pos_y) {
    this->pos_y = pos_y;
}

void Model3D::setPos_Z(float pos_z) {
    this->pos_z = pos_z;
}
//SCALE
float Model3D::getScale_X() {
    return this->scale_x;
}

float Model3D::getScale_Y() {
    return this->scale_y;
}

float Model3D::getScale_Z() {
    return this->scale_z;
}

void Model3D::setScale_X(float scale_x)
{
    this->scale_x = scale_x;
}

void Model3D::setScale_Y(float scale_y)
{
    this->scale_y = scale_y;
}

void Model3D::setScale_Z(float scale_z)
{
    this->scale_z = scale_z;
}

//AXIS
float Model3D::getAxis_X() {
    return this->axis_x;
}

float Model3D::getAxis_Y() {
    return this->axis_y;
}

float Model3D::getAxis_Z() {
    return this->axis_z;
}

void Model3D::setAxis_X(float axis_x) {
    this->axis_x = axis_x;
}

void Model3D::setAxis_Y(float axis_y) {
    this->axis_y = axis_y;
}

void Model3D::setAxis_Z(float axis_z) {
    this->axis_z = axis_z;
}

//THETA
float Model3D::getTheta_X() {
    return this->theta_x;
}

float Model3D::getTheta_Y() {
    return this->theta_y;
}

float Model3D::getTheta_Z() {
    return this->theta_z;
}

void Model3D::setTheta_X(float theta_x) {
    this->theta_x = theta_x;
}

void Model3D::setTheta_Y(float theta_y) {
    this->theta_y = theta_y;
}

void Model3D::setTheta_Z(float theta_z) {
    this->theta_z = theta_z;
}

float Model3D::getTheta() {
    return this->theta;
}

void Model3D::setModelColor(glm::vec4 modelColor) {
    this->modelColor = modelColor;
}