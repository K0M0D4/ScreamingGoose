#pragma once

#include <SFML/Graphics.hpp>

namespace cmt {
    class Scene {
    public:
        virtual std::string Process(sf::RenderWindow& window) = 0;
    };
}