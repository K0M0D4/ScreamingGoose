#pragma once

#include <vector>

#include "scene.hpp"
#include "assets.hpp"
#include "button.hpp"

namespace cmt {
    class MenuScene : public Scene {
    public:
        MenuScene(AssetManager& assets, sf::RenderWindow& window);
        std::string Process(sf::RenderWindow& window);

    private:
        AssetManager* m_assets;

        sf::RectangleShape m_bg;

        std::vector<Button> m_buttons;
    };
}