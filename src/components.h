#pragma once

#include <string>
#include "video.h"

struct SpriteComponent
{
    std::string registry_key;
    video::Rect src;
    video::Rect dest;
};

