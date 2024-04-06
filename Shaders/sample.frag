#version 330 core

out vec4 FragColor;

uniform sampler2D tex0;

uniform vec3 lightPos;  //might remove soon, idk


uniform vec3 lightPoint;
uniform vec3 lightDirection;
uniform vec3 lightColor;
uniform float ambientStr;
uniform vec3 ambientColor;
uniform float specStr;
uniform float specPhong;
uniform float brightness;
uniform vec3 objectColor;

uniform vec3 cameraPos;

in vec3 normCoord;
in vec3 fragPos;
in vec2 texCoord;

 void main ()
 {	
	//NOTE: code related to lighting are commented out, uncomment them when lighting is implemented in main then comment out line 62
	
	float constant = 1.0f;      
	float linear = 0.02f;
	float quadratic = 0.001f;
	float distance = length(lightPos - fragPos);
	float attenuation = 1.0 / (constant + linear * distance + quadratic * (distance * distance));

	vec3 normal = normalize(normCoord);
	
	//vec light = normalize(lightPoint + lightDirection - fragPos);  //COMBINED DIRECTION LIGHT AND POINT LIGHT (not sure if correct)

	vec3 lightDir = normalize(lightPos - fragPos);


	//DIFFUSE
	float diff = max(dot(normal, lightDir), 0.0);			
	vec3 diffuse = diff * lightColor * brightness;

	//AMBIENT
	vec3 ambientCol = ambientColor * ambientStr * brightness;

	//SPECULAR
	vec3 viewDir = normalize(cameraPos - fragPos);
	vec3 reflectDir = reflect(-lightDir, normal);
	float spec = pow(max(dot(reflectDir, viewDir), 0.1), specPhong);
	vec3 specColor = spec * specStr * lightColor * brightness;

	ambientCol *= attenuation;
	diffuse *= attenuation;
	specColor *= attenuation;

	FragColor = vec4(diffuse + ambientCol + specColor, 1.0) * texture(tex0, texCoord);
	

	/*FragColor = vec4 (126.0f/254.0f, 194.0f/254.0f, 254.0f/254.0f, 1.0f)*/;
 }