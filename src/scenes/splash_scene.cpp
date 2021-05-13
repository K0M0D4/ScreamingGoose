#include "include/splash_scene.hpp"

namespace cmt {
    SplashScene::SplashScene(AssetManager& assets, sf::RenderWindow& window) {
        m_assets = &assets;

        m_assets->LoadTexture("res/splash.png", "splash");
        m_bg.setSize(sf::Vector2f(1280, 720));
        m_bg.setTexture(&m_assets->GetTexture("splash"));
        window.draw(m_bg);
        window.display();

        m_assets->LoadTexture("res/bg.png", "bg");
        m_assets->LoadTexture("res/pipe.png", "pipe");

        m_assets->LoadTexture("res/start.png", "start");
        m_assets->LoadTexture("res/options.png", "options");
        m_assets->LoadTexture("res/exit.png", "exit");

        m_assets->LoadTexture("res/start2.png", "start2");
        m_assets->LoadTexture("res/options2.png", "options2");
        m_assets->LoadTexture("res/exit2.png", "exit2");

        m_assets->LoadFont("res/font.otf", "font");
    }

    sf::Packet SplashScene::Process(sf::RenderWindow& window) {
        sf::Packet packet;
        window.draw(m_bg);

        if(m_clock.getElapsedTime().asSeconds() >= sf::seconds(2).asSeconds()) {
            packet << "menu" << 0.f << 1280.f << 1280.f * 2.f;
            return packet;
        }

        packet << "";
        return packet;
    }
}