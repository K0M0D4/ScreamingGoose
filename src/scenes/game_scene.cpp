#include "include/game_scene.hpp"

namespace cmt {
    GameScene::GameScene(AssetManager& assets, sf::RenderWindow& window, sf::Packet data) {
        m_assets = &assets;

        m_player = new Player(*m_assets);

        float bg_data[3];
        data >> bg_data[0] >> bg_data[1] >> bg_data[2];

        for(int i = 0; i < 3; i++) {
            m_bg[i].setSize(sf::Vector2f(1280, 720));
            m_bg[i].setTexture(&m_assets->GetTexture("bg"));
            m_bg[i].setPosition(bg_data[i], 0);
        }

        m_pointsT.setFont(m_assets->GetFont("font"));
        m_pointsT.setCharacterSize(100);
        m_pointsT.setOutlineThickness(3);
        m_pointsT.setOutlineColor(sf::Color::Black);

        Pipe buf(&m_assets->GetTexture("pipe"));

        for(int i = 0; i < 4; i++) {
            buf.ReSummon((i + 1) * 500 + 900);
            m_pipes.push_back(buf);
        }
    }

    sf::Packet GameScene::Process(sf::RenderWindow& window) {
        sf::Packet packet;

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && !m_prevJump) {
            m_prevJump = true;
            m_player->Jump();
        } else if(!sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
            m_prevJump = false;
        }

        for(int i = 0; i < 3; i++){
            m_bg[i].move(-deltaClock.getElapsedTime().asMilliseconds() / 4, 0);
            if(m_bg[i].getPosition().x < -1280)
                m_bg[i].move(1280 * 2, 0);
            window.draw(m_bg[i]);
        }

        for(auto& pipe : m_pipes) {
            if(pipe.CheckPoint(m_player->GetRect())) {
                m_points++;
                pipe.GetPointRect().move(0, 1000);
            }
            if(pipe.CheckCollision(m_player->GetCollider())) {
                packet << "death" << m_points << m_bg[0].getPosition().x << m_bg[1].getPosition().x << m_bg[2].getPosition().x;
                return packet;
            }

            pipe.Move(sf::Vector2f(-deltaClock.getElapsedTime().asMilliseconds() / 3, 0));

            if(pipe.GetRectD().getPosition().x < -100) {
                pipe.ReSummon();
            }

            pipe.Render(window);
        }

        m_player->Render(window, deltaClock.getElapsedTime());

        m_pointsT.setString(std::to_string(m_points));
        m_pointsT.setOrigin(m_pointsT.getGlobalBounds().width / 2, m_pointsT.getGlobalBounds().height / 2);
        m_pointsT.setPosition(640, 100);
        window.draw(m_pointsT);

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
            packet << "menu" << m_bg[0].getPosition().x << m_bg[1].getPosition().x << m_bg[2].getPosition().x;
            return packet;
        }

        deltaClock.restart();

        packet << "";
        return packet;
    }
}