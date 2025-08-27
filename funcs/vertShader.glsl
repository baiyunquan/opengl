#version 330 core
// 输入：位置属性，来自VAO配置的 location 0
layout (location = 0) in vec3 aPos;
// 输入：颜色属性，来自VAO配置的 location 1
layout (location = 1) in vec3 aColor;

// 输出：将颜色传递给片段着色器
out vec3 ourColor;

void main()
{
    gl_Position = vec4(aPos, 1.0);
    ourColor = aColor; // 直接将顶点颜色数据传递出去
}