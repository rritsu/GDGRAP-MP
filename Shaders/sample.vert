#version 330 core

layout (location=0) in vec3 aPos;
layout(location=1) in vec3 vertexNormal;
layout (location=2) in vec2 aTex;

//pass the tex coord to the fragment shader
out vec3 normCoord;
out vec3 fragPos;
out vec2 texCoord;


uniform mat4 transform;
uniform mat4 projection;
uniform mat4 view;

void main ()
{
	gl_Position = projection *  //multiply the Projection Matrix with the View
				  view *		//multiply the View with the Position
				  transform *	//Multiply the matrix with the Position
				  vec4(aPos, 1.0); //Turns our 3x1 matrix into 1 4x1

	texCoord = aTex;

	normCoord = mat3(
		transpose(inverse(transform))
		) * vertexNormal;

	fragPos = vec3(transform * vec4(aPos, 1.0));
	
}


//commented out ones are related to texture and normals, uncomment them if texture and normals are implemented in main