# 收集所有cpp文件
file(GLOB_RECURSE FUNCS_SRCS "*.cpp")
message(STATUS "Funcs source files: ${FUNCS_SRCS}")

# 将FUNCS中所有的cpp编译为 funcs 这个 lib库
add_library(funcs ${FUNCS_SRCS} "stb_image.h")

# 添加必要的包含目录
target_include_directories(funcs PUBLIC 
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_SOURCE_DIR}/libs/glad/include
)