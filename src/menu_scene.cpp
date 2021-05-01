#include "menu_scene.hpp"

namespace cmt {
    MenuScene::MenuScene(AssetManager& assets, sf::RenderWindow& window) {
        m_assets = &assets;

        m_assets->LoadTexture("res/splash.png", "splash");

        m_bg.setSize(sf::Vector2f(1280, 720));
        m_bg.setFillColor(sf::Color::Green);

        Process(window);
    }

    std::string MenuScene::Process(sf::RenderWindow& window) {
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
            return "game";
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
            return "exit";
        }

        window.draw(m_bg);

        return "";
    }
}