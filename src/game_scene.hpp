#pragma once

#include <vector>

#include "player.hpp"
#include "scene.hpp"
#include "assets.hpp"
#include "pipe.hpp"

namespace cmt {
    class GameScene : public Scene {
    public:
        GameScene(AssetManager& assets, sf::RenderWindow& window);

    private:
        AssetManager* m_assets;

        sf::RectangleShape m_bg;

        sf::Clock deltaClock;

        Player* m_player;
        bool m_prevJump = false;

        std::vector<Pipe> m_pipes;
        std::vector<sf::RectangleShape> m_pointRects;

        uint32_t m_points = 0;
        sf::Text m_pointsT;

        std::string Process(sf::RenderWindow& window);

        void ReSummonPipe(int i, int x = 2000);
    };
}