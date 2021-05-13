#include "app.hpp"

namespace cmt {
    App::App(std::string name, sf::Vector2f windowSize) {
        m_window.create(sf::VideoMode(windowSize.x, windowSize.y), name, sf::Style::Titlebar | sf::Style::Close);
        m_window.setFramerateLimit(60);
        m_window.setVerticalSyncEnabled(true);

        m_actualScene = new SplashScene(m_assets, m_window);
    }

    void App::Start() {
        while(m_window.isOpen()) {
            sf::Event event;
            while(m_window.pollEvent(event)) {
                if(event.type == sf::Event::Closed) m_window.close();
            }

            m_window.clear(sf::Color(0, 200, 250));

            sf::Packet state = m_actualScene->Process(m_window);
            std::string retStr;
            state >> retStr;
            if(retStr == "menu") {
                float bgData[3];
                state >> bgData[0] >> bgData[1] >> bgData[2];
                sf::Packet packet;
                packet << bgData[0] << bgData[1] << bgData[2];
                m_actualScene = new MenuScene(m_assets, m_window, packet);
            } else if(retStr == "game") {
                float bgData[3];
                state >> bgData[0] >> bgData[1] >> bgData[2];
                sf::Packet packet;
                packet << bgData[0] << bgData[1] << bgData[2];
                m_actualScene = new GameScene(m_assets, m_window, packet);
            } else if(retStr == "death") {
                int points;
                float bgData[3];
                state >> points >> bgData[0] >> bgData[1] >> bgData[2];
                sf::Packet packet;
                packet << points << bgData[0] << bgData[1] << bgData[2];
                m_actualScene = new DeathScene(m_assets, m_window, packet);
            } else if(retStr == "exit") {
                m_window.close();
            }

            m_window.display();

            delta.restart();
        }
    }
}