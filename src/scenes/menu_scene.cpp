#include "include/menu_scene.hpp"

namespace cmt {
    MenuScene::MenuScene(AssetManager& assets, sf::RenderWindow& window, sf::Packet data) {
        m_assets = &assets;

        float bg_data[3];
        data >> bg_data[0] >> bg_data[1] >> bg_data[2];

        for(int i = 0; i < 3; i++) {
            m_bg[i].setSize(sf::Vector2f(1280, 720));
            m_bg[i].setTexture(&m_assets->GetTexture("bg"));
            m_bg[i].setPosition(bg_data[i], 0);
        }

        for(int i = 0; i < 3; i++) {
            m_buttons.emplace_back(Button(sf::Vector2f(300, 70), *m_assets));
            m_buttons.at(i).GetRect().setPosition(sf::Vector2f(640, i * 100 + 360));
            m_buttons.at(i).EnableTexture();
        }

        Pipe buf(&m_assets->GetTexture("pipe"));

        for(int i = 0; i < 4; i++) {
            buf.ReSummon((i + 1) * 500 + 900);
            m_pipes.push_back(buf);
        }
    }

    sf::Packet MenuScene::Process(sf::RenderWindow& window) {
        sf::Packet packet;
        
        for(int i = 0; i < 3; i++){
            m_bg[i].move(-deltaClock.getElapsedTime().asMilliseconds() / 4, 0);
            if(m_bg[i].getPosition().x < -1280)
                m_bg[i].move(1280 * 2, 0);
            window.draw(m_bg[i]);
        }

        for(auto& pipe : m_pipes) {
            pipe.Move(sf::Vector2f(-deltaClock.getElapsedTime().asMilliseconds() / 3, 0));

            if(pipe.GetRectD().getPosition().x < -100) {
                pipe.ReSummon();
            }

            pipe.Render(window);
        }
        
        for(int i = 0; i < 3; i++) {
            if(m_buttons.at(i).IsTouch(window))
                if(i == 0)
                    m_buttons.at(i).SetTexture("start2");
                else if(i == 1)
                    m_buttons.at(i).SetTexture("options2");
                else
                    m_buttons.at(i).SetTexture("exit2");
            else
                if(i == 0)
                    m_buttons.at(i).SetTexture("start");
                else if(i == 1)
                    m_buttons.at(i).SetTexture("options");
                else
                    m_buttons.at(i).SetTexture("exit");

            m_buttons.at(i).Render(window);

            if(m_buttons.at(i).IsClick(window)) {
                if(i == 0) {
                    packet << "game" << m_bg[0].getPosition().x << m_bg[1].getPosition().x << m_bg[2].getPosition().x;
                    return packet;
                }
                if(i == 2) {
                    packet << "exit";
                    return packet;
                }
            }
        }

        deltaClock.restart();

        packet << "";
        return packet;
    }
}