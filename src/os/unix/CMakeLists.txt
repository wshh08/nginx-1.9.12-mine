set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -c -pipe  -O0 -W -Wall -Wpointer-arith -Wno-unused-parameter -Werror -g ")
aux_source_directory(. DIR_SRCS_OS_UNIX)
add_library(OsUnix ${DIR_SRCS_OS_UNIX})
