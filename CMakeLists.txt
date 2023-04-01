cmake_minimum_required(VERSION 3.22)
project(Z-Engine)

set(CMAKE_CXX_STANDARD 17)

include_directories(${CMAKE_SOURCE_DIR}/src)

include(FindGLEW)
include(FindOpenGL)
include(FindPNG)

find_package(Threads)
find_package(glfw3 3.3 REQUIRED)

add_executable(Z-Engine
    src/Z-Engine.cpp
    src/window/Events.cpp
    src/window/Events.h
    src/window/Window.cpp
    src/window/Window.h
    src/window/Camera.cpp
    src/window/Camera.h
    src/graphics/Shader.cpp
    src/graphics/Shader.h
    src/graphics/Texture.cpp
    src/graphics/Texture.h
    src/graphics/Primitives.cpp
    src/graphics/Primitives.h
    src/graphics/Mesh.cpp
    src/graphics/Mesh.h
    src/loaders/Png-Loader.cpp
    src/loaders/Png-Loader.h
    src/objects/Object.h
    src/objects/Object.cpp
    src/objects/Draw-Object.h
    src/objects/Draw-Object.cpp
    src/objects/Objects.h
    src/objects/Objects.cpp
    )

target_link_libraries(Z-Engine GLEW::glew OpenGL::GL stdc++fs Threads::Threads PNG::PNG GLEW::glew glfw)