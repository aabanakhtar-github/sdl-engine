#pragma once

#include "util.h"
#include "video.h"

#include <unordered_map>

class TextureRegistry
{
    MAKE_SINGLETON(TextureRegistry)

public:
    [[nodiscard]] bool addTexture(video::Renderer& renderer, const std::string& key, const std::string& path)
    {
        video::Texture t(renderer);
        const bool success = t.init(renderer, path);

        if (success)
        {
            textures.emplace(key, std::move(t));
        }

        return success;
    }

    const video::Texture& getTexture(const std::string& key) const
    {
        return textures.at(key);
    }

private:
    std::unordered_map<std::string, video::Texture> textures = {};
};
