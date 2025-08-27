cmake_minimum_required(VERSION 3.12)

# 本工程的名字
project(OpenGLTEST1)

# 本工程支持的C++版本
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 定义库文件所在的根目录
set(LIB_DIR ${CMAKE_SOURCE_DIR}/libs)

# 将funcs文件夹纳入到编译系统
add_subdirectory(funcs)

# 搜索所有cpp文件并加入到变量中
file(GLOB SRCS "*.cpp")
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
    VERBATIM
)

# 保证在构建 main 前复制着色器
add_dependencies(main copy_shaders)

# 使用现代 CMake 方式添加包含目录
target_include_directories(main PRIVATE
    ${LIB_DIR}/glfw-3.4.bin.WIN64/include
    ${LIB_DIR}/glew-2.2.0/include
    ${LIB_DIR}/glad/include
)

# 定义 GLEW_STATIC
target_compile_definitions(main PRIVATE GLEW_STATIC)

# 将 glad 的源文件添加到编译
target_sources(main PRIVATE ${LIB_DIR}/glad/src/glad.c)

# 链接库文件
target_link_libraries(main PRIVATE
    funcs
    ${LIB_DIR}/glfw-3.4.bin.WIN64/lib-vc2022/glfw3.lib
    ${LIB_DIR}/glew-2.2.0/lib/Release/x64/glew32s.lib
    opengl32.lib
)