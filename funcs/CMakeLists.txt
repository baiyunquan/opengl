# 递归将本文件夹下所有的cpp，放到 FUNCS这个变量中
file(GLOB_RECURSE FUNCS ./ *.cpp)

# 将FUNCS中所有的cpp编译为 funcs这个 lib库
add_library(funcs ${FUNCS} "func.h")