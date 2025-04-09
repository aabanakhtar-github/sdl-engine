#include "event_handler.h"

void EventScheduler::bind(SDL_EventType e, const EventCallback& callback) {
    bindings[e].push_back(callback);
}

void EventScheduler::poll() {
    SDL_Event current_event; 

    while (SDL_PollEvent(&current_event)) {
        auto search = bindings.find(SDL_EventType(current_event.type));
        if (search != bindings.end()) {
            auto &functions = search->second; 
            for (auto &f : functions) {
                f(current_event);
            } 
        }
    }
}