set(HEADER_LIST "${antrock_SOURCE_DIR}/include/antrock/renderer/renderer.hpp")

# Make an automatic library - will be static or dynamic based on user setting
add_library(renderer renderer.cpp ${HEADER_LIST})

# We need this directory, and users of our library will need it too
target_include_directories(renderer PUBLIC ../../include)

# add here all opengl stuff later target_link_libraries(modern_library PRIVATE
# glm glfw)
