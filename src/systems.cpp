#include "systems.h"

#include <iostream>

#include "components.h"
#include "texture_registry.h"

namespace systems
{

    void draw(const video::Renderer& renderer, entt::registry& registry)
    {
        renderer.clear(video::Color{0, 255.0, 0, 0});

        const auto view = registry.view<SpriteComponent>();
        view.each([&](auto entity, auto& sprite) {
            auto& tex = TextureRegistry::get().getTexture(sprite.registry_key);
            renderer.drawTexture(
                tex,
                sprite.src,
                sprite.dest
            );
        });

        renderer.present();
    }


}
