
project(GLAD VERSION 0.1.0)

set(gladSourceDir "src/glad.c")
set(gladIncludeDir "include/glad/glad.h" "include/KHR/khrplatform.h")

message(STATUS "This is CMAKE_CURRENT_SOURCE_DIR/include"  "${CMAKE_CURRENT_SOURCE_DIR}/include")
include_directories("${CMAKE_CURRENT_SOURCE_DIR}/include")
add_library(glad ${gladSourceDir} ${gladIncludeDir})

