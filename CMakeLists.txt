cmake_minimum_required(VERSION 3.10)
project(Engine)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp GLAD/src/glad.c)
set(HEADER_FILES shader.h)

set(dir ${CMAKE_CURRENT_SOURCE_DIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${dir}/build)

include_directories(include)

#Static Lib
set(GCC_COVERAGE_COMPILE_FLAGS "-static")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}" )


#Include library files
include_directories(GLAD/include)
include_directories(glm/include)

#file(COPY resources DESTINATION ${dir}/build)
#file(COPY shaders DESTINATION ${dir}/build)

#Add deps
add_subdirectory(dependencies)

add_executable(Engine main.cpp stb_image.h src/Window/Window.cpp src/Window/Window.hpp src/Core/Render/VBO.cpp src/Core/Render/VBO.hpp src/Core/Render/VAO.cpp src/Core/Render/VAO.hpp src/Core/Render/Shader/Shader.cpp src/Core/Render/Shader/Shader.hpp GLAD/src/glad.c src/Core/Core.hpp src/Core/Render/Block/Block.cpp src/Core/Render/Block/Block.hpp src/Core/Render/Texture/Texture.cpp src/Core/Render/Texture/Texture.hpp src/Core/Render/Chunk/Chunk.cpp src/Core/Render/Chunk/Chunk.hpp src/Core/Camera/Camera.cpp src/Core/Camera/Camera.hpp)
target_link_libraries(Engine glfw)