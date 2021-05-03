#pragma once

#include <vector>

#include "scene.hpp"
#include "assets.hpp"
#include "button.hpp"

namespace cmt {
    class DeathScene : public Scene {
    public:
        DeathScene(AssetManager& assets, sf::RenderWindow& window);
        std::string Process(sf::RenderWindow& window);

    private:
        AssetManager* m_assets;

        sf::RectangleShape m_bg;
        sf::Text m_text;

        std::vector<Button> m_buttons;
    };
}