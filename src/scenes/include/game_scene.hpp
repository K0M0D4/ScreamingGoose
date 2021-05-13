#pragma once

#include <vector>
#include <string>

#include "scene.hpp"
#include "../../player.hpp"
#include "../../assets.hpp"
#include "../../pipe.hpp"

namespace cmt {
    class GameScene : public Scene {
    public:
        GameScene(AssetManager& assets, sf::RenderWindow& window, sf::Packet data);

    private:
        AssetManager* m_assets;

        sf::RectangleShape m_bg[3];

        sf::Clock deltaClock;

        Player* m_player;
        bool m_prevJump = false;

        std::vector<Pipe> m_pipes;

        uint32_t m_points = 0;
        sf::Text m_pointsT;

        sf::Packet Process(sf::RenderWindow& window);
    };
}