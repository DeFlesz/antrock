set(renderer_include_path "${antrock_SOURCE_DIR}/include/antrock/renderer")
set(HEADER_LIST "${renderer_include_path}/renderer.hpp"
                "${renderer_include_path}/GL/Shader.hpp")

set(SOURCE_LIST renderer.cpp GL/Shader.cpp)

# Make an automatic library - will be static or dynamic based on user setting
add_library(renderer ${SOURCE_LIST} ${HEADER_LIST})

# We need this directory, and users of our library will need it too
target_include_directories(renderer PUBLIC ../../include)

# add here all opengl stuff later
target_link_libraries(renderer PRIVATE glad_gl_core_33 glm glfw)
