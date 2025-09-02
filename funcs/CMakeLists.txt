# 收集所有cpp文件
file(GLOB_RECURSE FUNCS_SRCS "*.cpp")
message(STATUS "Funcs source files: ${FUNCS_SRCS}")

# 将FUNCS中所有的cpp编译为 funcs 这个 lib库
add_library(funcs ${FUNCS_SRCS} "stb_image.h" "camera.h" "texture.h" "shader.h" "resource_manager.h")

# 添加必要的包含目录
target_include_directories(funcs PUBLIC 
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_SOURCE_DIR}/libs/glad/include
    ${CMAKE_SOURCE_DIR}/libs/glm
    ${CMAKE_SOURCE_DIR}/libs/glfw-3.4.bin.WIN64/include
    ${CMAKE_SOURCE_DIR}/libs/glew-2.2.0/include
)

# 链接库文件
target_link_libraries(funcs PRIVATE
    ${CMAKE_SOURCE_DIR}/libs/glfw-3.4.bin.WIN64/lib-vc2022/glfw3.lib
    ${CMAKE_SOURCE_DIR}/libs/glew-2.2.0/lib/Release/x64/glew32s.lib
    opengl32.lib
)