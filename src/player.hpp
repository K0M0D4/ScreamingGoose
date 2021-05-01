#pragma once

#include <SFML/Graphics.hpp>

#include "assets.hpp"

namespace cmt {
    class Player {
    public:
        Player(AssetManager& assets);

        void Jump();

        bool CheckCollision(sf::RectangleShape& rect);

        void Render(sf::RenderWindow& target, sf::Time deltaTime);

    private:
        sf::RectangleShape m_rect;
    };
}