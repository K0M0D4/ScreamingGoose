#pragma once

#include <vector>

#include "scene.hpp"
#include "assets.hpp"

namespace cmt {
    class MenuScene : public Scene {
    public:
        MenuScene(AssetManager& assets, sf::RenderWindow& window);

    private:
        AssetManager* m_assets;

        sf::RectangleShape m_bg;

        std::string Process(sf::RenderWindow& window);
    };
}