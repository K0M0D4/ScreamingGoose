#pragma once

#include <vector>

#include "scene.hpp"
#include "../../assets.hpp"
#include "../../button.hpp"

namespace cmt {
    class DeathScene : public Scene {
    public:
        DeathScene(AssetManager& assets, sf::RenderWindow& window, sf::Packet data);
        sf::Packet Process(sf::RenderWindow& window);

    private:
        AssetManager* m_assets;

        sf::RectangleShape m_bg[3];
        sf::Text m_texts[2];

        sf::Clock deltaClock;

        std::vector<Button> m_buttons;
    };
}