#version 330 core
// ���룺�Ӷ�����ɫ����������ɫ��������ֵ��
in vec3 ourColor;
// ���������Ƭ����ɫ
out vec4 FragColor;

void main()
{
    FragColor = vec4(ourColor, 1.0);
}