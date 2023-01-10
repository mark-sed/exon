#include "gfx.hpp"

using namespace exon;

SpriteSheet::SpriteSheet(std::string path, 
                         unsigned int width,
                         unsigned int height,
                         conf::SpriteConf &cnf) : path{path},
                                                  width{width},
                                                  height{height},
                                                  cnf{cnf} {
    if(!this->sheet.loadFromFile(path)){
        // TODO:
    }
}

sf::Sprite SpriteSheet::get_sprite(unsigned int col, unsigned int row) {
    sf::Sprite s;
    s.setTexture(this->sheet);
    s.setTextureRect(sf::IntRect(col*width, row*height, width, height));
    s.setScale(cnf.scale, cnf.scale);
    return s;
}