#version 330 core

uniform vec3 lightColor;

out vec4 FragColor;

void main()
{
    //FragColor = vec4(lightColor , 1.0); // ���������ĸ�����ȫ������Ϊ1.0
    FragColor = vec4(1.0);
}