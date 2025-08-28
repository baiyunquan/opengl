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

// 窗口设置常量
const unsigned int SCR_WIDTH = 800;   // 窗口宽度
const unsigned int SCR_HEIGHT = 600;  // 窗口高度

// 外部全局变量声明（鼠标与相机相关）
extern bool firstMouse;               // 首次鼠标输入标记
extern float yaw;                     // 偏航角（水平旋转）
extern float pitch;                   // 俯仰角（垂直旋转）
extern float lastX;                   // 上一帧鼠标X坐标
extern float lastY;                   // 上一帧鼠标Y坐标
extern float fov;                     // 视野角度
extern glm::vec3 cameraFront;         // 相机前向向量

// 测试功能相关函数
void testEBO();                       // 测试元素缓冲对象（EBO）功能
void test();                          // 通用测试函数
void testGLM();                       // 测试GLM数学库功能
void testMove();                      // 测试相机/物体移动功能
void testCamera();                    // 测试相机视角控制功能
void testBox();                       // 测试立方体渲染功能
void test3D();                        // 测试3D场景渲染基础功能
void testMAT();                       // 测试矩阵变换功能
void testImage();                     // 测试纹理图像加载与渲染

// 初始化与窗口管理
void init();                          // 初始化GLFW、GLAD等环境
GLFWwindow* createWindow();           // 创建基础窗口（无鼠标特殊配置）
GLFWwindow* createWindowMouse();      // 创建支持鼠标交互的窗口（绑定鼠标回调）

// 事件回调函数
void framebuffer_size_callback(GLFWwindow* window, int width, int height);  // 窗口大小变化回调
void mouse_callback(GLFWwindow* window, double xpos, double ypos);          // 鼠标移动回调
void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);   // 鼠标滚轮回调

// 输入处理函数（重载版本）
void processInput(GLFWwindow* window);                                      // 基础输入处理
void processInput(GLFWwindow* window, glm::vec3& cameraPos, glm::vec3& cameraFront,
    glm::vec3& cameraUp, float& deltaTime);                   // 相机移动输入处理
void processInput(GLFWwindow* window, float& opacity);                      // 透明度调整输入处理

// 缓冲管理函数
void initBuffer(unsigned int& VBO, unsigned int& VAO, float vertices[], size_t arraySize);  // 初始化基础顶点缓冲
void initBufferColor(unsigned int& VBO, unsigned int& VAO, float vertices[], size_t arraySize);  // 初始化带颜色的顶点缓冲
void removeBuffer(unsigned int& VBO, unsigned int& VAO);  // 释放VBO和VAO资源

// 着色器工具函数
std::string readShaderSource(const char* filePath);  // 读取着色器源代码文件
unsigned int loadShader(int type, std::string file);  // 加载并编译单个着色器（顶点/片段）

// 相机观察矩阵工具函数
glm::mat4 lookAt(const glm::vec3& cameraPos, const glm::vec3& cameraTarget, const glm::vec3& up);  // 生成观察矩阵

#endif // MAIN_H