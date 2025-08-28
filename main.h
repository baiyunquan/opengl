#ifndef MAIN_H
#define MAIN_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <shader.cpp>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

// �������ó���
const unsigned int SCR_WIDTH = 800;   // ���ڿ��
const unsigned int SCR_HEIGHT = 600;  // ���ڸ߶�

// �ⲿȫ�ֱ�������������������أ�
extern bool firstMouse;               // �״����������
extern float yaw;                     // ƫ���ǣ�ˮƽ��ת��
extern float pitch;                   // �����ǣ���ֱ��ת��
extern float lastX;                   // ��һ֡���X����
extern float lastY;                   // ��һ֡���Y����
extern float fov;                     // ��Ұ�Ƕ�
extern glm::vec3 cameraFront;         // ���ǰ������

// ���Թ�����غ���
void testEBO();                       // ����Ԫ�ػ������EBO������
void test();                          // ͨ�ò��Ժ���
void testGLM();                       // ����GLM��ѧ�⹦��
void testMove();                      // �������/�����ƶ�����
void testCamera();                    // ��������ӽǿ��ƹ���
void testBox();                       // ������������Ⱦ����
void test3D();                        // ����3D������Ⱦ��������
void testMAT();                       // ���Ծ���任����
void testImage();                     // ��������ͼ���������Ⱦ

// ��ʼ���봰�ڹ���
void init();                          // ��ʼ��GLFW��GLAD�Ȼ���
GLFWwindow* createWindow();           // �����������ڣ�������������ã�
GLFWwindow* createWindowMouse();      // ����֧����꽻���Ĵ��ڣ������ص���

// �¼��ص�����
void framebuffer_size_callback(GLFWwindow* window, int width, int height);  // ���ڴ�С�仯�ص�
void mouse_callback(GLFWwindow* window, double xpos, double ypos);          // ����ƶ��ص�
void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);   // �����ֻص�

// ���봦���������ذ汾��
void processInput(GLFWwindow* window);                                      // �������봦��
void processInput(GLFWwindow* window, glm::vec3& cameraPos, glm::vec3& cameraFront,
    glm::vec3& cameraUp, float& deltaTime);                   // ����ƶ����봦��
void processInput(GLFWwindow* window, float& opacity);                      // ͸���ȵ������봦��

// ���������
void initBuffer(unsigned int& VBO, unsigned int& VAO, float vertices[], size_t arraySize);  // ��ʼ���������㻺��
void initBufferColor(unsigned int& VBO, unsigned int& VAO, float vertices[], size_t arraySize);  // ��ʼ������ɫ�Ķ��㻺��
void removeBuffer(unsigned int& VBO, unsigned int& VAO);  // �ͷ�VBO��VAO��Դ

// ��ɫ�����ߺ���
std::string readShaderSource(const char* filePath);  // ��ȡ��ɫ��Դ�����ļ�
unsigned int loadShader(int type, std::string file);  // ���ز����뵥����ɫ��������/Ƭ�Σ�

// ����۲���󹤾ߺ���
glm::mat4 lookAt(const glm::vec3& cameraPos, const glm::vec3& cameraTarget, const glm::vec3& up);  // ���ɹ۲����

#endif // MAIN_H