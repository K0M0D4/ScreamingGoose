#include "death_scene.hpp"

namespace cmt {
    DeathScene::DeathScene(AssetManager& assets, sf::RenderWindow& window) {
        m_assets = &assets;

        m_bg.setSize(sf::Vector2f(1280, 720));
        m_bg.setFillColor(sf::Color::Green);

        for(int i = 0; i < 2; i++) {
            m_buttons.emplace_back(Button(sf::Vector2f(300, 70), *m_assets));
            m_buttons.at(i).GetRect().setPosition(sf::Vector2f(640, i * 100 + 360));
            m_buttons.at(i).EnableTexture();
        }

        m_text.setFont(m_assets->GetFont("font"));
        m_text.setString("You lost!");
        m_text.setCharacterSize(50);
        m_text.setOrigin(m_text.getGlobalBounds().width / 2, m_text.getGlobalBounds().height / 2);
        m_text.setOutlineThickness(5);
        m_text.setOutlineColor(sf::Color::Black);
        m_text.setPosition(640, 200);
    }

    std::string DeathScene::Process(sf::RenderWindow& window) {
        window.draw(m_bg);

        for(int i = 0; i < 2; i++) {
            if(m_buttons.at(i).IsTouch(window))
                if(i == 0)
                    m_buttons.at(i).SetTexture("start2");
                else
                    m_buttons.at(i).SetTexture("exit2");
            else
                if(i == 0)
                    m_buttons.at(i).SetTexture("start");
                else
                    m_buttons.at(i).SetTexture("exit");

            if(m_buttons.at(i).IsClick(window)) {
                if(i == 0)
                    return "game";
                if(i == 1)
                    return "menu";
            }

            m_buttons.at(i).Render(window);
        }

        window.draw(m_text);

        return "";
    }
}