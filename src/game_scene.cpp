#include "game_scene.hpp"

#include <string>

namespace cmt {
    GameScene::GameScene(AssetManager& assets, sf::RenderWindow& window) {
        m_assets = &assets;

        m_player = new Player(*m_assets);

        m_bg.setSize(sf::Vector2f(1280, 720));
        m_bg.setTexture(&m_assets->GetTexture("bg"));

        m_pointsT.setFont(m_assets->GetFont("font"));
        m_pointsT.setCharacterSize(100);
        m_pointsT.setOutlineThickness(3);
        m_pointsT.setOutlineColor(sf::Color::Black);

        Pipe buf(&m_assets->GetTexture("pipe"));

        for(int i = 0; i < 4; i++) {
            buf.ReSummon((i + 1) * 500 + 800);
            m_pipes.push_back(buf);
        }
    }

    std::string GameScene::Process(sf::RenderWindow& window) {
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && !m_prevJump) {
            m_prevJump = true;
            m_player->Jump();
        } else if(!sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
            m_prevJump = false;
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
            return "menu";

        window.draw(m_bg);

        for(auto& pipe : m_pipes) {
            if(pipe.CheckCollision(m_player->GetCollider()))
                return "death";
            if(pipe.CheckPoint(m_player->GetRect())) {
                m_points++;
                pipe.GetPointRect().move(0, 1000);
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

        deltaClock.restart();

        return "";
    }
}