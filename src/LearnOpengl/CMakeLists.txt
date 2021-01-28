

project(LearnOpengl VERSION 1.00.00)

aux_source_directory("./Src/App" Source_App)
aux_source_directory("./Src/Example" Source_Example)
aux_source_directory("./Src/OGL" Source_OGL)
include_directories(".")
include_directories("./Src/App")
include_directories("./Src/Example")
include_directories("./Src/OGL")
include_directories("../glad/include")
include_directories("../glfw-3.3/include")
include_directories("../glfw-3.3/include/GLFW")
include_directories("../glm-0.9.8.5/glm/")
link_directories("../../build/src/glad")
link_directories("../../build/src/glfw-3.3/src")
link_libraries(glad)
link_libraries(glfw)
source_group(App FILES ${Source_App})
source_group(Example FILES ${Source_Example})
source_group(OGL FILES ${Source_OGL})
add_executable(LearnOpengl ${Source_App} ${Source_Example} ${Source_OGL})


