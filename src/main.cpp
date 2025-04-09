#include "SDL3/SDL.h"
#include "SDL3/SDL_main.h"
#include "engine.h"
#include "video.h"

int main(int argc, char *argv[]) {
    core::init();
    video::Window window;
    window.init(500, 500, "test.");
    while (true) {

    }
    core::quit();
    return 0;
}