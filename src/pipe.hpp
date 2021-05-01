#pragma once

#include <SFML/Graphics.hpp>

namespace cmt {
    class Pipe {
    public:
        Pipe(sf::Texture* texture, float posX = 0);

        sf::RectangleShape& GetRectU();
        sf::RectangleShape& GetRectD();
        sf::RectangleShape& GetPointRect();

        bool CheckCollision(sf::RectangleShape& rect);
        bool CheckPoint(sf::RectangleShape& rect);

        void Move(sf::Vector2f move);

        void ReSummon(int x = 2000);

        void Render(sf::RenderWindow& target);
        
    private:
        sf::RectangleShape m_rectU, m_rectD, m_pointRect;

    };
}