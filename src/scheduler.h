#pragma once

#include "SDL3/SDL.h"

#include <cstdint>
#include <unordered_map>
#include <functional>
#include <vector>

#include "util.h"

class Scheduler
{
    MAKE_SINGLETON(Scheduler);

public:
    using EventCallback = std::function<void(SDL_Event&)>;
    using UpdateCallback = std::function<void(float)>;

    void poll();
    void bind(SDL_EventType e, const EventCallback& callback);
    void bindUpdateFunction(const UpdateCallback& callback);

private:
    std::unordered_map<SDL_EventType, std::vector<EventCallback>>
    bindings = {};
    std::vector<UpdateCallback> update_functions = {};
};
