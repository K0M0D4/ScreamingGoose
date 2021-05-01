#pragma once

#include <SFML/Graphics.hpp>

#include <map>

namespace cmt {
    class AssetManager {
    public:
        AssetManager() {}

        void LoadTexture(std::string filename, std::string name);
        sf::Texture& GetTexture(std::string name);

        void LoadFont(std::string filename, std::string name);
        sf::Font& GetFont(std::string name);

    private:
        std::map<std::string, sf::Texture> m_textures;
        std::map<std::string, sf::Font> m_fonts;

    };
}