#include "assets.hpp"

namespace cmt {
    void AssetManager::LoadTexture(std::string filename, std::string name) {
        sf::Texture buf;
        buf.loadFromFile(filename);
        m_textures[name] = buf;
    }

    sf::Texture& AssetManager::GetTexture(std::string name) {
        return (sf::Texture&)m_textures.at(name);
    }

     void AssetManager::LoadFont(std::string filename, std::string name) {
        sf::Font buf;
        buf.loadFromFile(filename);
        m_fonts[name] = buf;
    }

    sf::Font& AssetManager::GetFont(std::string name) {
        return (sf::Font&)m_fonts.at(name);
    }
}