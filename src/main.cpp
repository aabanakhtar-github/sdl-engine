#include "SDL3/SDL.h"
#include "SDL3/SDL_main.h"
#include "engine.h"
#include "event_handler.h"
#include "video.h"


int main(int argc, char *argv[]) {
    core::init();
    video::Window window;
    bool shouldexit = false;
    EventScheduler::get().bind(SDL_EVENT_QUIT, [&](SDL_Event& e) {
        shouldexit = true;
    });
    window.init(500, 500, "test.");
    while (!shouldexit) {
        EventScheduler::get().poll();
    }
    core::quit();
    return 0;
}