#pragma once

#include <vector>

#include "scene.hpp"
#include "assets.hpp"

namespace cmt {
    class SplashScene : public Scene {
    public:
        SplashScene(AssetManager& assets, sf::RenderWindow& window);

    private:
        AssetManager* m_assets;

        sf::RectangleShape m_bg;

        sf::Clock m_clock;

        std::string Process(sf::RenderWindow& window);
    };
}