#pragma once

#include <SFML/Graphics.hpp>

namespace cmt {
    class Pipe {
    public:
        Pipe(sf::Texture* texture, sf::Vector2f pos = sf::Vector2f(0, 0));

        sf::RectangleShape& GetRect();

        void SetUp(bool val = true);

        void Render(sf::RenderWindow& target);
        
    private:
        sf::RectangleShape m_rect;

    };
}