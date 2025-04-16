#include "scheduler.h"

void Scheduler::bind(SDL_EventType e, const EventCallback& callback)
{
    bindings[e].push_back(callback);
}

void Scheduler::poll()
{
    SDL_Event current_event;

    while (SDL_PollEvent(&current_event))
    {
        auto search = bindings.find(SDL_EventType(current_event.type));
        if (search != bindings.end())
        {
            auto& functions = search->second;
            for (auto& f : functions)
            {
                f(current_event);
            }
        }
    }

    for (auto& func : update_functions)
    {
        func(0);
    }
}

void Scheduler::bindUpdateFunction(const UpdateCallback& callback)
{
    update_functions.push_back(callback);
}
