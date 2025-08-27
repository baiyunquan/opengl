cmake_minimum_required(VERSION 3.12)

# 本工程的名字
project(OpenGLTEST1)

# 本工程支持的C++版本
set(CMAKE_CXX_STANDARD 17)

# 定义库文件所在的根目录
set(LIB_DIR ${CMAKE_SOURCE_DIR}/libs)

# 指定 GLFW 和 GLEW 的头文件目录（使用相对路径）
include_directories(${LIB_DIR}/glfw-3.4.bin.WIN64/include)
include_directories(${LIB_DIR}/glew-2.2.0/include)

# 定义 GLEW_STATIC
add_definitions(-DGLEW_STATIC)

# 将funcs文件夹纳入到编译系统
add_subdirectory(funcs)

# 搜索所有cpp文件并加入到变量中
aux_source_directory(. SRCS)
message(STATUS "Source files: ${SRCS}")

# 生成可执行文件
add_executable(main ${SRCS})

# 获取 funcs 目录下所有 glsl 文件
file(GLOB SHADER_FILES "${CMAKE_SOURCE_DIR}/funcs/*.glsl")

# 目标输出目录
set(SHADER_OUTPUT_DIR "${CMAKE_BINARY_DIR}/funcs")

# 创建自定义目标用于复制着色器文件
add_custom_target(copy_shaders ALL
    COMMAND ${CMAKE_COMMAND} -E make_directory "${SHADER_OUTPUT_DIR}"
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
        ${SHADER_FILES}
        "${SHADER_OUTPUT_DIR}"
    COMMENT "Copying shader files to output directory"
)

# 保证在构建 main 前复制着色器
add_dependencies(main copy_shaders)

# 链接库文件（使用相对路径）
target_link_libraries(main funcs)
target_link_libraries(main ${LIB_DIR}/glfw-3.4.bin.WIN64/lib-vc2022/glfw3.lib)
target_link_libraries(main ${LIB_DIR}/glew-2.2.0/lib/Release/x64/glew32s.lib)
target_link_libraries(main opengl32.lib)

# --- 重点：配置 Glad ---
# 添加 Glad 的头文件目录 (包含 glad.h 和 KHR 文件夹的目录)
target_include_directories(main PRIVATE ${LIB_DIR}/glad/include)

# 将 glad 的源文件 (glad.c) 添加到你的可执行文件中
# 这样在编译时，glad 的实现会被直接编译进你的程序
target_sources(main PRIVATE ${LIB_DIR}/glad/src/glad.c)
