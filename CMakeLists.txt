cmake_minimum_required(VERSION 2.8.4)
project(Nginx C)
set(CMAKE_C_COMPILER gcc)

# -Wl,E 给链接命令ld传递-E参数,使生成的可执行程序的dynamic symbol table中包含程序的all symbols,
# 以方便'dlopen载入的动态链接库'反向调用程序中标识符. 若无此参数则dynamic symbol table中将仅包含
# 被'-l调用的动态链接库'所引用symbols(默认情况),此时将无法满足dlopen载入的链接库的反向调用要求.
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wl,-E")

#Core Includes:
include_directories(src/core)
include_directories(src/event)
include_directories(src/http)
include_directories(src/http/modules)
include_directories(src/os/unix)
include_directories(config)

#link_directories(objs)
#link_directories(src/core)
#link_directories()

#set(SRC objs/ngx_modules.c src/core/nginx.c)
#aux_source_directory(src/core DIR_SRCS)
#set(DIR_SRCS src/core/nginx.c src/core/ngx_array.c src/core)
#aux_source_directory(src/stream DIR_SRCS)
#aux_source_directory(src/event DIR_SRCS)
#aux_source_directory(src/event/modules DIR_SRCS)
#aux_source_directory(objs DIR_SRCS)
#aux_source_directory(src/http DIR_SRCS)
#aux_source_directory(src/os/unix DIR_SRCS)
#aux_source_directory(src/http/modules DIR_SRCS)

# 用于自动执行子目录config等,用于生成各模块的静态链接库.a文件供nginx任务引用
add_subdirectory(config)
add_subdirectory(src/event)
add_subdirectory(src/event/modules)
add_subdirectory(src/http)
add_subdirectory(src/http/modules)
add_subdirectory(src/os/unix)

#LearnC子任务用于测试学习代码,与Nginx项目无关
add_subdirectory(LearnC)

#增加生成可执行nginx的任务
aux_source_directory(src/core DIR_SRCS)
add_executable(nginx ${DIR_SRCS})

#nginx依赖以下链接库
target_link_libraries(nginx Config Event EventModules Http HttpModules OsUnix)
target_link_libraries(nginx dl pthread crypt pcre crypto z)
