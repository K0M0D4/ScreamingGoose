#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>

namespace cmt {
    class Scene {
    public:
        virtual sf::Packet Process(sf::RenderWindow& window) = 0;
    };
}