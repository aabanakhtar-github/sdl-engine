
cmake_minimum_required(VERSION 3.5)
project(opengl-engine)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include(FetchContent)
FetchContent_Declare(
    SDL3
    GIT_REPOSITORY https://github.com/libsdl-org/SDL.git
    GIT_TAG origin/main
)

FetchContent_Declare(
        SDL3_image
        GIT_REPOSITORY https://github.com/libsdl-org/SDL_image.git
        GIT_TAG release-3.2.4
        GIT_SHALLOW TRUE
        GIT_PROGRESS TRUE
)

FetchContent_Declare(
        EnTT
        GIT_REPOSITORY https://github.com/skypjack/entt.git
        GIT_PROGRESS TRUE
)

set(SDL3IMAGE_AVIF OFF CACHE BOOL "Disable AVIF support in SDL3_image" FORCE)
set(SDL3IMAGE_AVIF OFF CACHE BOOL "" FORCE)
set(SDL3IMAGE_IMAGEIO_AVIF OFF CACHE BOOL "" FORCE)
set(SDL3IMAGE_LIBAVIF OFF CACHE BOOL "" FORCE)
set(SDL3IMAGE_VENDORED OFF CACHE BOOL "" FORCE)

FetchContent_MakeAvailable(SDL3)
FetchContent_MakeAvailable(SDL3_image)
FetchContent_MakeAvailable(EnTT)

add_executable(opengl-engine WIN32 
    src/main.cpp
    src/engine.cpp 
    src/engine.h 
    src/video.h 
    src/video.cpp 
    src/scheduler.cpp 
    src/scheduler.h
        src/components.h
        src/texture_registry.h
        src/systems.h
        src/systems.cpp
        src/GameLoop.cpp
        src/GameLoop.h
        src/camera.h
        src/keyboard.h
)
target_link_libraries(opengl-engine PRIVATE SDL3::SDL3 SDL3_image::SDL3_image EnTT::EnTT)