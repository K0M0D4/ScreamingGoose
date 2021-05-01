#pragma once

#include <SFML/Graphics.hpp>

#include "assets.hpp"

namespace cmt {
    class Player {
    public:
        Player(AssetManager& assets);

        void Jump();

        sf::RectangleShape& GetRect();

        void Render(sf::RenderWindow& target, sf::Time deltaTime);

    private:
        sf::RectangleShape m_rect;
    };
}