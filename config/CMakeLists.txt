# -c 只编译,不链接,输出.o文件
# -pipe用管道代替临时文件
# -O 相当于-O1 1级优化
# -W 输出所有警告信息
# -Wall 打开gcc所有警告
# -Werror 将所有警告当做错误处理,停止编译
# -g 生成调试信息
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -c -pipe  -O -W -Wall -Wpointer-arith -Wno-unused-parameter -Werror -g ")
add_library(Config ngx_modules.c)