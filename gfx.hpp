#ifndef _GFX_HPP_
#define _GFX_HPP_

#include "exon.hpp"
#include <SFML/Graphics.hpp>
#include <string>
#include <vector>

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


    class Animation {
    public:
        Animation(std::string path, std::string name);
        ~Animation();

        void update();
        void reset();
    };


}


#endif//_GFX_HPP_