#pragma once

#include "util.h"
#include "video.h"
#include "entt/entt.hpp"
// commitment  is key.
namespace systems
{
    void draw(const video::Renderer& renderer, entt::registry& registry);
}