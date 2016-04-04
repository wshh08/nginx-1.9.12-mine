set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -c -pipe  -O0 -W -Wall -Wpointer-arith -Wno-unused-parameter -Werror -g ")
add_library(EventModules ngx_epoll_module.c)
