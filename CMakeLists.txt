cmake_minimum_required(VERSION 3.15)

project(
	antrock
	VERSION 0.0.1
	DESCRIPTION "antrock simple engine for my games"
	LANGUAGES CXX)

#for clangd lsp or whatever
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

#internal compiled libraries
add_subdirectory(src/renderer)

#executable code
add_subdirectory(apps)
