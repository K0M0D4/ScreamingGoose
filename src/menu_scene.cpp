#include "menu_scene.hpp"

namespace cmt {
    MenuScene::MenuScene(AssetManager& assets, sf::RenderWindow& window) {
        m_assets = &assets;

        m_bg.setSize(sf::Vector2f(1280, 720));
        m_bg.setFillColor(sf::Color::Green);

        for(int i = 0; i < 3; i++) {
            m_buttons.emplace_back(Button(sf::Vector2f(300, 70), *m_assets));
            m_buttons.at(i).GetRect().setPosition(sf::Vector2f(640, i * 100 + 360));
            m_buttons.at(i).EnableTexture();
        }
    }

    std::string MenuScene::Process(sf::RenderWindow& window) {
        window.draw(m_bg);
        
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

            if(m_buttons.at(i).IsClick(window)) {
                if(i == 0)
                    return "game";
                if(i == 2)
                    return "exit";
            }

            m_buttons.at(i).Render(window);
        }

        return "";
    }
}