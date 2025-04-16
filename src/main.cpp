#include <entt/entity/registry.hpp>

#include "components.h"
#include "SDL3/SDL.h"
#include "SDL3/SDL_main.h"
#include "engine.h"
#include "scheduler.h"
#include "video.h"
#include "iostream"
#include "systems.h"
#include "texture_registry.h"


int main(int argc, char* argv[])
{
    if (!core::init())
    {
        std::cerr << "Failed to init!" << std::endl;
        return -1;
    }

    video::Window window;
    video::Renderer renderer(window);
    entt::registry registry;
    bool shouldexit = false;

    window.init(500, 500, "Archer Demo");
    renderer.init();

    if (!TextureRegistry::get().addTexture(renderer, "0", "data/testsprite.png"))
    {
        return 1;
    }

    const auto test = registry.create();
    registry.emplace<SpriteComponent>(test, "0", video::Rect{0.0, 0.0, 32.0, 32.0}, video::Rect{0.0, 0.0, 32.0, 32.0});

    Scheduler::get().bind(SDL_EVENT_QUIT, [&](SDL_Event& e)
    {
        shouldexit = true;
    });

    Scheduler::get().bindUpdateFunction([&](float _)
    {
        systems::draw(renderer, registry);
    });


    while (!shouldexit)
    {
        Scheduler::get().poll();
    }

    core::quit();
    return 0;
}
