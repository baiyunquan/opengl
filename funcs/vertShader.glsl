#version 330 core
// ���룺λ�����ԣ�����VAO���õ� location 0
layout (location = 0) in vec3 aPos;
// ���룺��ɫ���ԣ�����VAO���õ� location 1
layout (location = 1) in vec3 aColor;

// ���������ɫ���ݸ�Ƭ����ɫ��
out vec3 ourColor;

void main()
{
    gl_Position = vec4(aPos, 1.0);
    ourColor = aColor; // ֱ�ӽ�������ɫ���ݴ��ݳ�ȥ
}