#include "player.hpp"

namespace cmt {
    Player::Player(AssetManager& assets) {
        m_rect.setSize(sf::Vector2f(72, 72));
        m_rect.setOrigin(m_rect.getGlobalBounds().width / 2, m_rect.getGlobalBounds().height / 2);
        m_rect.setFillColor(sf::Color::Blue);
        m_rect.setPosition(sf::Vector2f(300, 300));

        m_collider.setSize(sf::Vector2f(m_rect.getSize().x - 10, m_rect.getSize().y - 10));
        m_collider.setOrigin(m_collider.getGlobalBounds().width / 2, m_collider.getGlobalBounds().height / 2);
    }

    void Player::Jump() {
        m_velocity -= sf::Vector2f(0, 20);
    }

    sf::RectangleShape& Player::GetRect() {
        return (sf::RectangleShape&)m_rect;
    }

    sf::RectangleShape& Player::GetCollider() {
        return (sf::RectangleShape&)m_collider;
    }

    void Player::Render(sf::RenderWindow& target, sf::Time deltaTime) {
        m_velocity += sf::Vector2f(0, deltaTime.asMilliseconds() / 10);

        if(m_velocity.y > 7) {
            m_velocity.y = 7;
        }
        if(m_velocity.y < -20) {
            m_velocity.y = -20;
        } 

        m_rect.move(m_velocity);

        if(m_rect.getPosition().y < 0)
            m_rect.setPosition(m_rect.getPosition().x, 0);
        if(m_rect.getPosition().y > 635)
            m_rect.setPosition(m_rect.getPosition().x, 635);

        m_collider.setPosition(m_rect.getPosition());

        target.draw(m_rect);
        target.draw(m_collider); //debug
    }
}