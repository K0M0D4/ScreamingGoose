#include "button.hpp"

namespace cmt {
    Button::Button(sf::Vector2f size, AssetManager& assets) {
        m_assets = &assets;
        m_rect.setSize(size);
        CalcOrigin();
    }

    void Button::SetTexture(std::string name) {
        m_texture = &m_assets->GetTexture(name);
    }

    sf::RectangleShape& Button::GetRect() {
        return (sf::RectangleShape&)m_rect;
    }

    void Button::CalcOrigin() {
        m_rect.setOrigin(m_rect.getGlobalBounds().width / 2, m_rect.getGlobalBounds().height / 2);
    }

    void Button::EnableTexture(bool enable) {
        m_enableTexture = enable;
    }

    bool Button::IsTouch(sf::RenderWindow& window) {
        sf::IntRect buf(m_rect.getPosition().x - m_rect.getGlobalBounds().width / 2,
                        m_rect.getPosition().y - m_rect.getGlobalBounds().height / 2,
                        m_rect.getGlobalBounds().width, m_rect.getGlobalBounds().height);

        if(buf.contains(sf::Mouse::getPosition(window)))
            return true;
        return false;
    }

    bool Button::IsClick(sf::RenderWindow& window) {
        if(sf::Mouse::isButtonPressed(sf::Mouse::Left) && IsTouch(window))
            return true;
        return false;
    }

    void Button::Render(sf::RenderWindow& target) {
        if(!m_enableTexture)
            m_rect.setTexture(0);
        else
            m_rect.setTexture(m_texture);

        target.draw(m_rect);
    }
}