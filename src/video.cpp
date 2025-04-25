#include "video.h"
#include "SDL3_image/SDL_image.h"

namespace video
{
    Texture::Texture(const Texture& texture)
        : Texture(texture.clone().value())
    {
    }

    Texture& Texture::operator=(Texture texture)
    {
        swap(*this, texture);
        return *this;
    }

    Texture::Texture(Texture&& texture) noexcept
        : renderer(texture.renderer)
    {
        swap(*this, texture);
    }

    Texture& Texture::operator=(Texture&& texture) noexcept
    {
        swap(*this, texture);
        return *this;
    }

    bool Texture::init(Renderer& renderer, const std::string& filename)
    {
        auto surface = IMG_Load(filename.c_str());
        if (surface == nullptr)
        {
            return false;
        }

        auto texture = SDL_CreateTextureFromSurface(renderer.renderer, surface);
        if (texture == nullptr)
        {
            SDL_DestroySurface(surface);
            return false;
        }

        width = surface->w;
        height = surface->h;
        this->texture = texture;

        SDL_DestroySurface(surface);
        return true;
    }

    std::optional<Texture> Texture::clone() const
    {
        float w, h;
        SDL_GetTextureSize(texture, &w, &h);

        auto texture = SDL_CreateTexture(renderer.renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, w, h);
        if (texture == nullptr)
        {
            return std::nullopt;
        }
        // clear the renderer
        renderer.clear({0, 0, 0, 0});
        SDL_SetRenderTarget(renderer.renderer, texture);
        // upload
        Rect frame(0, 0, w, h);
        renderer.drawTexture(*this, frame, frame);
        // reset
        renderer.clear({0, 0, 0, 0});
        SDL_SetRenderTarget(renderer.renderer, nullptr);
        // return
        auto ret = Texture(renderer);
        ret.texture = texture;
        ret.width = w;
        ret.height = h;
        return ret;
    }


    Texture::~Texture()
    {
        SDL_DestroyTexture(texture);
        texture = nullptr;
    }

    bool Window::init(std::uint32_t w, std::uint32_t h, const std::string& name)
    {
        this->w = w; 
        this->h = h;
        window = SDL_CreateWindow(name.data(), w, h, 0);
        return window != nullptr;
    }

    Window::~Window()
    {
        SDL_DestroyWindow(window);
        window = nullptr;
    }

    Renderer::Renderer(Window& window)
        : surface(window)
    {
    }

    Renderer::~Renderer()
    {
        SDL_DestroyRenderer(renderer);
        renderer = nullptr;
    }

    bool Renderer::init()
    {
        renderer = SDL_CreateRenderer(surface.window, nullptr);
        if (renderer == nullptr)
        {
            return false;
        }

        return true;
    }

    void Renderer::drawTexture(const Texture& texture, const Rect& source, const Rect& target, double angle) const
    {
        SDL_RenderTextureRotated(
            renderer,
            texture.texture,
            &source,
            &target,
            angle,
            nullptr,
            SDL_FLIP_NONE
        );
    }

    void Renderer::clear(const Color& color) const
    {
        auto bytes = color.toBytes();
        SDL_SetRenderDrawColor(renderer, bytes[0], bytes[1], bytes[2], bytes[3]);
        SDL_RenderClear(renderer);
    }
}
