#pragma once

#include <SFML/Graphics.hpp>

#include "assets.hpp"

namespace cmt {
    class Player {
    public:
        Player(AssetManager& assets);

        void Jump();

        sf::RectangleShape& GetRect();
        sf::RectangleShape& GetCollider();

        void Render(sf::RenderWindow& target, sf::Time deltaTime);

    private:
        sf::RectangleShape m_rect, m_collider;

        sf::Vector2f m_velocity = sf::Vector2f(0, 0);
    };
}