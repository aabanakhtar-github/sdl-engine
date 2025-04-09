#include "SDL3/SDL.h"
#include <cstdint>
#include <unordered_map>
#include <functional> 
#include <vector>
#include "util.h" 

class EventScheduler {
        MAKE_SINGLETON(EventScheduler)
    public:
        using EventCallback = std::function<void(SDL_Event&)>;
        
        void poll(); 
        void bind(SDL_EventType e, const EventCallback& callback); 

    private:
        std::unordered_map<SDL_EventType, std::vector<EventCallback>>
            bindings;
};