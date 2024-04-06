#version 330 core

out vec4 FragColor;

uniform vec4 modelColor;


uniform vec3 cameraPos;

in vec3 fragPos;

 void main ()
 {	

	FragColor = modelColor;
 }