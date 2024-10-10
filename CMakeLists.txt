cmake_minimum_required(VERSION 3.15)

project(
  antrock
  VERSION 0.0.1
  DESCRIPTION "antrock simple engine for my games"
  LANGUAGES CXX)

# for clangd lsp or whatever
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# external libraries glfw & its options
set(GLFW_BUILD_DOCS
    OFF
    CACHE BOOL "GLFW lib only")
set(GLFW_INSTALL
    OFF
    CACHE BOOL "GLFW lib only")
add_subdirectory(extern/glfw)

# internal libraries
add_subdirectory(src/renderer)

# executable code
add_subdirectory(apps)
