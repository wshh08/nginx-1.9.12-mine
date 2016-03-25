cmake_minimum_required(VERSION 2.8.4)
project(Nginx)
set(CMAKE_C_COMPILER clang)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -pipe  -O -W -Wall -Wpointer-arith -Wno-unused-parameter -Werror -g ")

#Core Includes:
include_directories(src/core)
include_directories(src/event)
include_directories(src/http)
include_directories(src/http/modules)
include_directories(src/os/unix)
include_directories(objs)

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

# 用于自动执行子目录objs等
add_subdirectory(config)
add_subdirectory(src/event)
add_subdirectory(src/event/modules)
add_subdirectory(src/http)
add_subdirectory(src/http/modules)
add_subdirectory(src/os/unix)

#增加生成nginx的任务
aux_source_directory(src/core DIR_SRCS)
add_executable(nginx ${DIR_SRCS})

#nginx依赖以下库
target_link_libraries(nginx Config)
target_link_libraries(nginx Event)
target_link_libraries(nginx EventModules)
target_link_libraries(nginx Http)
target_link_libraries(nginx HttpModules)
target_link_libraries(nginx OsUnix)
target_link_libraries(nginx dl pthread crypt pcre crypto z)
