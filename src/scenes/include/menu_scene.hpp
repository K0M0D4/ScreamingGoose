#pragma once

#include <vector>

#include "scene.hpp"
#include "../../assets.hpp"
#include "../../button.hpp"
#include "../../pipe.hpp"

namespace cmt {
    class MenuScene : public Scene {
    public:
        MenuScene(AssetManager& assets, sf::RenderWindow& window, sf::Packet data);
        sf::Packet Process(sf::RenderWindow& window);

    private:
        AssetManager* m_assets;

        sf::RectangleShape m_bg[3];

        sf::Clock deltaClock;

        std::vector<Pipe> m_pipes;

        std::vector<Button> m_buttons;
    };
}