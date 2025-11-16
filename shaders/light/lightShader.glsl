#version 330 core

in vec3 vlightColor;

out vec4 FragColor;

void main()
{
    FragColor = vec4(1.0);
	FragColor = vec4(vlightColor , 1.0);

}