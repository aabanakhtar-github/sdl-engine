
cmake_minimum_required(VERSION 3.5)
project(opengl-engine)

include(FetchContent)
# Create an option to switch between a system sdl library and a vendored SDL library
FetchContent_Declare(
    SDL3
    GIT_REPOSITORY https://github.com/libsdl-org/SDL
    # This will be a tag once SDL3 is released
    GIT_TAG origin/main
    OVERRIDE_FIND_PACKAGE
)

FetchContent_MakeAvailable(SDL3)


# Create your game executable target as usual
add_executable(opengl-engine WIN32 
src/main.cpp src/engine.cpp src/engine.h src/video.h src/video.cpp)
target_link_libraries(opengl-engine PRIVATE SDL3::SDL3)