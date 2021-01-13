

project(LearnOpengl VERSION 1.00.00)

aux_source_directory("." SourceCodeDir)
include_directories(".")
include_directories("../glad/include")
include_directories("../glfw-3.3/include")
include_directories("../glfw-3.3/include/GLFW")
include_directories("../glm-0.9.8.5/glm/")
link_directories("../../build/src/glad")
link_directories("../../build/src/glfw-3.3/src")
link_libraries(glad)
link_libraries(glfw3)
add_executable(LearnOpengl ${SourceCodeDir})