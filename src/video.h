#include "SDL3/SDL.h"
#include "texture.h"
#include <string>
#include <cstdint>

namespace video {
    using Rect = SDL_FRect;

    struct Window {
        SDL_Window *window = nullptr;

        bool init(std::uint32_t w, std::uint32_t h, const std::string& name);
        ~Window();
    };


    class Renderer { 
        public:
            Renderer(Window& window);
            ~Renderer(); 

            bool init();
            void drawTexture(class ::Texture& t, Rect& source, Rect& destination, double angle = 0);
            void clear();
        private:
            Window& surface;
            SDL_Renderer* renderer = nullptr;
    };

}

