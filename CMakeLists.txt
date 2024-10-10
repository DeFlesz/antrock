cmake_minimum_required(VERSION 3.15)

project(
  antrock
  VERSION 0.0.1
  DESCRIPTION "antrock simple engine for my games"
  LANGUAGES C CXX)

# for clangd lsp or whatever
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# external libraries

# glfw & its options
set(GLFW_BUILD_DOCS
    OFF
    CACHE BOOL "GLFW lib only")
set(GLFW_INSTALL
    OFF
    CACHE BOOL "GLFW lib only")
add_subdirectory(extern/glfw)

# glad
set(GLAD_SOURCES_DIR "${PROJECT_SOURCE_DIR}/extern/glad/")
# Path to glad cmake files
add_subdirectory("${GLAD_SOURCES_DIR}/cmake" glad_cmake)

# glm
add_subdirectory(extern/glm)

# Specify glad settings
glad_add_library(glad_gl_core_33 REPRODUCIBLE API gl:core=3.3)

# internal libraries
add_subdirectory(src/renderer)

# executable code
add_subdirectory(apps)
