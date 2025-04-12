#include "SDL3/SDL.h"
#include "SDL3/SDL_main.h"
#include "engine.h"
#include "scheduler.h"
#include "video.h"
#include "iostream"


int main(int argc, char *argv[]) {
    core::init();
    std::cout << "hello world!" << std::endl;
    video::Window window;
    video::Renderer renderer(window); 
    video::Texture texture; 
    bool shouldexit = false;

    Scheduler::get().bind(SDL_EVENT_QUIT, [&](SDL_Event& e) {
        shouldexit = true;
    });

    Scheduler::get().bindUpdateFunction([&](float _) {
        renderer.clear();
        renderer.drawTexture(texture, video::Rect{0.0, 0.0, 32.0, 32.0}, video::Rect{0, 0, 32, 32});
        SDL_RenderPresent(renderer.renderer);
    });

    window.init(500, 500, "test.");
    renderer.init();
    if (!texture.init(renderer, "data/testsprite.png")) {
        std::cout << SDL_GetError() << std::endl;
    }
    
    while (!shouldexit) {
       Scheduler::get().poll(); 
    }

    core::quit();
    return 0;
}