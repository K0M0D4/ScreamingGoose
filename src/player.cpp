#include "player.hpp"

namespace cmt {
    Player::Player(AssetManager& assets) {
        m_rect.setSize(sf::Vector2f(72, 72));
        m_rect.setOrigin(m_rect.getGlobalBounds().width / 2, m_rect.getGlobalBounds().height / 2);
        m_rect.setFillColor(sf::Color::Blue);
        m_rect.setPosition(sf::Vector2f(200, 300));
    }

    void Player::Jump() {
        m_rect.move(0, -130);
    }

    sf::RectangleShape& Player::GetRect() {
        return (sf::RectangleShape&)m_rect;
    }

    void Player::Render(sf::RenderWindow& target, sf::Time deltaTime) {
        m_rect.move(sf::Vector2f(0, deltaTime.asMilliseconds() / 3));

        if(m_rect.getPosition().y < 0)
            m_rect.setPosition(m_rect.getPosition().x, 0);

        target.draw(m_rect);
    }
}