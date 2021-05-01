#include "pipe.hpp"

#include <iostream>

namespace cmt {
    Pipe::Pipe(sf::Texture* texture, float posX) {
        m_rectD.setSize(sf::Vector2f(100, 700));
        m_rectD.setOrigin(sf::Vector2f(m_rectD.getGlobalBounds().width / 2, m_rectD.getGlobalBounds().height / 2));
        m_rectD.setTexture(texture);

        m_rectU.setSize(sf::Vector2f(100, 700));
        m_rectU.setOrigin(sf::Vector2f(m_rectU.getGlobalBounds().width / 2, m_rectU.getGlobalBounds().height / 2));
        m_rectU.setTexture(texture);

        m_rectU.setScale(sf::Vector2f(1, -1));

        ReSummon(posX);

        m_pointRect.setSize(sf::Vector2f(10, 720));
        m_pointRect.setFillColor(sf::Color::Green);
        m_pointRect.setOrigin(m_pointRect.getGlobalBounds().width / 2, m_pointRect.getGlobalBounds().height / 2);
    }

    sf::RectangleShape& Pipe::GetRectD() {
        return (sf::RectangleShape&)m_rectD;
    }

    sf::RectangleShape& Pipe::GetRectU() {
        return (sf::RectangleShape&)m_rectU;
    }

    sf::RectangleShape& Pipe::GetPointRect() {
        return (sf::RectangleShape&)m_pointRect;
    }

    bool Pipe::CheckCollision(sf::RectangleShape& rect) {
        if(m_rectD.getPosition().x - m_rectD.getGlobalBounds().width / 2 < rect.getPosition().x + rect.getGlobalBounds().width / 2 &&
            m_rectD.getPosition().x + m_rectD.getGlobalBounds().width / 2 > rect.getPosition().x - rect.getGlobalBounds().width / 2 &&
            m_rectD.getPosition().y - m_rectD.getGlobalBounds().height / 2 < rect.getPosition().y + rect.getGlobalBounds().height / 2 &&
            m_rectD.getPosition().y + m_rectD.getGlobalBounds().height / 2 > rect.getPosition().y - rect.getGlobalBounds().height / 2)
            return true;
        if(m_rectU.getPosition().x - m_rectU.getGlobalBounds().width / 2 < rect.getPosition().x + rect.getGlobalBounds().width / 2 &&
            m_rectU.getPosition().x + m_rectU.getGlobalBounds().width / 2 > rect.getPosition().x - rect.getGlobalBounds().width / 2 &&
            m_rectU.getPosition().y - m_rectU.getGlobalBounds().height / 2 < rect.getPosition().y + rect.getGlobalBounds().height / 2 &&
            m_rectU.getPosition().y + m_rectU.getGlobalBounds().height / 2 > rect.getPosition().y - rect.getGlobalBounds().height / 2)
            return true;
        return false;
    }

    bool Pipe::CheckPoint(sf::RectangleShape& rect) {
        if(m_pointRect.getPosition().x - m_pointRect.getGlobalBounds().width / 2 < rect.getPosition().x + rect.getGlobalBounds().width / 2 &&
            m_pointRect.getPosition().x + m_pointRect.getGlobalBounds().width / 2 > rect.getPosition().x - rect.getGlobalBounds().width / 2 &&
            m_pointRect.getPosition().y - m_pointRect.getGlobalBounds().height / 2 < rect.getPosition().y + rect.getGlobalBounds().height / 2 &&
            m_pointRect.getPosition().y + m_pointRect.getGlobalBounds().height / 2 > rect.getPosition().y - rect.getGlobalBounds().height / 2)
            return true;
        return false;
    }

    void Pipe::Move(sf::Vector2f move) {
        m_rectD.move(move);
        m_rectU.move(move);
        m_pointRect.move(move);        
    }

    void Pipe::ReSummon(int x) {
        int y = std::rand() % 300 + 700;
        m_rectD.setPosition(x, y);
        m_rectU.setPosition(x, y - 1000);

        m_pointRect.setPosition(m_rectD.getPosition().x + 100, 360);
    }

    void Pipe::Render(sf::RenderWindow& target) {
        target.draw(m_rectD);
        target.draw(m_rectU);

        target.draw(m_pointRect);
    }
}