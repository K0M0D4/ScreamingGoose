#include "game_scene.hpp"

#include <iostream>
#include <string>

namespace cmt {
    GameScene::GameScene(AssetManager& assets, sf::RenderWindow& window) {
        m_assets = &assets;

        m_player = new Player(*m_assets);

        m_bg.setSize(sf::Vector2f(1280, 720));
        m_bg.setTexture(&m_assets->GetTexture("bg"));

        m_pointsT.setFont(m_assets->GetFont("font"));
        m_pointsT.setCharacterSize(100);

        Pipe buf(&m_assets->GetTexture("pipe"));

        sf::RectangleShape pointBuf;
        pointBuf.setSize(sf::Vector2f(10, 720));
        pointBuf.setFillColor(sf::Color::Green);
        pointBuf.setOrigin(pointBuf.getGlobalBounds().width / 2, pointBuf.getGlobalBounds().height / 2);

        for(int i = 0; i < 4; i++) {
            buf.SetUp(false);
            m_pipes.push_back(buf);
            buf.SetUp();
            m_pipes.push_back(buf);

            m_pointRects.push_back(pointBuf);

            ReSummonPipe(i * 2, (i + 1) * 500 + 800);
        }

        Process(window);
    }

    std::string GameScene::Process(sf::RenderWindow& window) {
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && !m_prevJump) {
            m_prevJump = true;
            m_player->Jump();
        } else if(!sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
            m_prevJump = false;
        }

        for(auto& pipe : m_pipes) {
            if(m_player->CheckCollision(pipe.GetRect()))
                return "death";
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
            return "exit";

        window.draw(m_bg);

        for(int i = 0; i < 8; i++) {
            m_pipes[i].GetRect().move(-deltaClock.getElapsedTime().asMilliseconds() / 3, 0);
            if(m_pipes[i].GetRect().getPosition().x < -100) {
                ReSummonPipe(i);
                i++;
            }
            m_pipes[i].Render(window);
        }

        m_player->Render(window, deltaClock.getElapsedTime());

        m_pointsT.setString(std::to_string(m_points));
        m_pointsT.setOrigin(m_pointsT.getGlobalBounds().width / 2, m_pointsT.getGlobalBounds().height / 2);
        m_pointsT.setPosition(640, 100);
        window.draw(m_pointsT);

        for(auto& rect : m_pointRects) {
            rect.move(-deltaClock.getElapsedTime().asMilliseconds() / 3, 0);

            if(m_player->CheckCollision(rect)) {
                m_points++;
                rect.move(0, 1000);
            }

            window.draw(rect);
        }

        deltaClock.restart();

        return "";
    }

    void GameScene::ReSummonPipe(int i, int x) {
        int y = std::rand() % 300 + 700;
        m_pipes[i].GetRect().setPosition(x, y);
        i++;
        m_pipes[i].GetRect().setPosition(x, y - 1000);
        m_pointRects[(i + 1) / 2 - 1].setPosition(x + 100, 360);
    }
}