#ifndef _GFX_HPP_
#define _GFX_HPP_

#include "exon.hpp"
#include <SFML/Graphics.hpp>
#include <string>

namespace exon {

    class SpriteSheet {
    public:
        SpriteSheet(std::string path, unsigned int width, unsigned int height, conf::SpriteConf &cnf);

        sf::Sprite get_sprite(unsigned int col, unsigned int row);
    private:
        std::string path;
        unsigned int width;
        unsigned int height;
        sf::Texture sheet;
        conf::SpriteConf cnf;
    };


}


#endif//_GFX_HPP_