add_executable(app app.cpp)

target_link_libraries(app PRIVATE glad_gl_core_33 glfw renderer)
