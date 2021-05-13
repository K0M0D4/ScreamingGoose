#include "include/death_scene.hpp"

namespace cmt {
    DeathScene::DeathScene(AssetManager& assets, sf::RenderWindow& window, sf::Packet data) {
        m_assets = &assets;

        int points;
        data >> points;

        float bg_data[3];
        data >> bg_data[0] >> bg_data[1] >> bg_data[2];

        for(int i = 0; i < 3; i++) {
            m_bg[i].setSize(sf::Vector2f(1280, 720));
            m_bg[i].setTexture(&m_assets->GetTexture("bg"));
            m_bg[i].setPosition(bg_data[i], 0);
        }

        for(int i = 0; i < 2; i++) {
            m_buttons.emplace_back(Button(sf::Vector2f(300, 70), *m_assets));
            m_buttons.at(i).GetRect().setPosition(sf::Vector2f(640, i * 100 + 360));
            m_buttons.at(i).EnableTexture();
        }

        for(int i = 0; i < 2; i++) {
            m_texts[i].setFont(m_assets->GetFont("font"));
            if(i == 0)
                m_texts[i].setString("You lost!");
            else
                m_texts[i].setString("Points: " + std::to_string(points));
            m_texts[i].setCharacterSize(50);
            m_texts[i].setOrigin(m_texts[i].getGlobalBounds().width / 2, m_texts[i].getGlobalBounds().height / 2);
            m_texts[i].setOutlineThickness(5);
            m_texts[i].setOutlineColor(sf::Color::Black);
            m_texts[i].setPosition(640, 100 + 100 * i);
        }
    }

    sf::Packet DeathScene::Process(sf::RenderWindow& window) {
        sf::Packet packet;
        for(int i = 0; i < 3; i++){
            m_bg[i].move(-deltaClock.getElapsedTime().asMilliseconds() / 4, 0);
            if(m_bg[i].getPosition().x < -1280)
                m_bg[i].move(1280 * 2, 0);
            window.draw(m_bg[i]);
        }

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
                if(i == 0) {
                    packet << "game" << m_bg[0].getPosition().x << m_bg[1].getPosition().x << m_bg[2].getPosition().x;
                    return packet;
                }
                if(i == 1) {
                    packet << "menu" << m_bg[0].getPosition().x << m_bg[1].getPosition().x << m_bg[2].getPosition().x;
                    return packet;
                }
            }

            m_buttons.at(i).Render(window);
        }

        window.draw(m_texts[0]);
        window.draw(m_texts[1]);

        deltaClock.restart();

        packet << "";
        return packet;
    }
}