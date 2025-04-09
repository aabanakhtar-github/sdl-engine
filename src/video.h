#include "SDL3/SDL.h"
#include <string>
#include <cstdint>

namespace video {
    struct Window {
        SDL_Window *window = nullptr;

        bool init(std::uint32_t w, std::uint32_t h, const std::string& name);
        ~Window();
    };


    class Renderer { 
        public:
            Renderer(Window& window);
            ~Renderer(); 

            void draw();
        private:
            Window& surface;
            SDL_Renderer* renderer = nullptr;
    };

}

