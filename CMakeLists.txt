
cmake_minimum_required(VERSION 3.5)
project(opengl-engine)

include(FetchContent)
FetchContent_Declare(
    SDL3
    GIT_REPOSITORY https://github.com/libsdl-org/SDL.git
    GIT_TAG origin/main
)

FetchContent_MakeAvailable(SDL3)


add_executable(opengl-engine WIN32 
src/main.cpp src/engine.cpp src/engine.h src/video.h src/video.cpp src/event_handler.cpp src/event_handler.h src/texture.h src/texture.cpp)
target_link_libraries(opengl-engine PRIVATE SDL3::SDL3)