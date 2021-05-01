#include "pipe.hpp"

namespace cmt {
    Pipe::Pipe(sf::Texture* texture, sf::Vector2f pos) {
        m_rect.setSize(sf::Vector2f(100, 700));
        m_rect.setOrigin(sf::Vector2f(m_rect.getGlobalBounds().width / 2, m_rect.getGlobalBounds().height / 2));

        m_rect.setTexture(texture);
        m_rect.setPosition(pos);
    }

    sf::RectangleShape& Pipe::GetRect() {
        return (sf::RectangleShape&)m_rect;
    }

    void Pipe::SetUp(bool val) {
        if(val) {
            m_rect.setScale(sf::Vector2f(1, -1));
        } else {
            m_rect.setScale(sf::Vector2f(1, 1));
        }
    }

    void Pipe::Render(sf::RenderWindow& target) {
        target.draw(m_rect);
    }
}