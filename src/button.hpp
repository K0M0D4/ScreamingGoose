#pragma once

#include <SFML/Graphics.hpp>

#include "assets.hpp"

namespace cmt {
    class Button {
    public:
        Button(sf::Vector2f size, AssetManager& assets);

        void SetTexture(std::string name);

        sf::RectangleShape& GetRect();

        void CalcOrigin();

        void EnableTexture(bool enable = true);

        bool IsTouch(sf::RenderWindow& window);
        bool IsClick(sf::RenderWindow& window);

        void Render(sf::RenderWindow& target);

    private:
        AssetManager* m_assets;

        sf::RectangleShape m_rect;

        sf::Texture* m_texture;

        bool m_enableTexture = false, m_enableText = false;
    };
}