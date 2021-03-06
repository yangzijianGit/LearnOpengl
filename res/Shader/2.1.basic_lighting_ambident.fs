#version 330 core 

out vec4 fragColor;

uniform vec3 objectColor;
uniform vec3 lightColor;

void main()
{
	float ambientStrength = 0.5;
	vec3 ambient = ambientStrength * lightColor;

	vec3 result = ambient * objectColor;
	fragColor = vec4(result, 1.0);
}

