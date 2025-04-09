#include "SDL_events.h"
#include <cstdint>
#include <unordered_map>
#include "util.h" 

struct UserEvent {
    bool isValidEvent;
    const std::uint32_t ID;
    
    UserEvent(bool valid, std::uint32_t ID) 
        : isValidEvent(valid), ID(ID) {}
};

class EventScheduler {
        MAKE_SINGLETON(EventScheduler)
    public:

        
    private:

}