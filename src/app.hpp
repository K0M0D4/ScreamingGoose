#pragma once

#include <SFML/Graphics.hpp>

#include "scenes/include/splash_scene.hpp"
#include "scenes/include/menu_scene.hpp"
#include "scenes/include/game_scene.hpp"
#include "scenes/include/death_scene.hpp"

#include "pipe.hpp"
#include "assets.hpp"

namespace cmt {
    class App {
    public:
        App(std::string name = "window", sf::Vector2f windowSize = sf::Vector2f(1280, 720));

        void Start();

    private:
        sf::RenderWindow m_window;
        AssetManager m_assets;

        sf::Clock delta;

        Scene* m_actualScene;

    };
}