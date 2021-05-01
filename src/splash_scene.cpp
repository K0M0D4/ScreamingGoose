#include "splash_scene.hpp"

namespace cmt {
    SplashScene::SplashScene(AssetManager& assets, sf::RenderWindow& window) {
        m_assets = &assets;

        m_assets->LoadTexture("res/splash.png", "splash");
        m_assets->LoadTexture("res/bg.png", "bg");
        m_assets->LoadTexture("res/pipe.png", "pipe");

        m_assets->LoadFont("res/font.otf", "font");

        m_bg.setSize(sf::Vector2f(1280, 720));
        m_bg.setTexture(&m_assets->GetTexture("splash"));

        Process(window);
    }

    std::string SplashScene::Process(sf::RenderWindow& window) {
        window.draw(m_bg);

        if(m_clock.getElapsedTime().asSeconds() >= sf::seconds(2).asSeconds())
            return "menu";

        return "";
    }
}