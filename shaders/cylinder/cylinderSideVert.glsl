#version 330 core
layout (location = 0) in vec3 aPos;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

out vec3 FragPos;
out vec3 Normal;

void main()
{
    vec4 worldPos = model * vec4(aPos, 1.0);
    FragPos = worldPos.xyz;

    // 侧面法线：径向 (x, y, 0)
    vec3 localNormal = normalize(vec3(aPos.x, aPos.y, 0.0));

    mat3 normalMatrix = transpose(inverse(mat3(model)));
    Normal = normalMatrix * localNormal;

    gl_Position = projection * view * worldPos;
}