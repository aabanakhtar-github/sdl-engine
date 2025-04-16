#pragma once

#include "util.h"
#include "video.h"
#include "entt/entt.hpp"

namespace systems
{
    void draw(const video::Renderer& renderer, entt::registry& registry);
}