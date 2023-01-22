#ifndef _GFX_HPP_
#define _GFX_HPP_

#include "exon.hpp"
#include "libs/json.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/System/Time.hpp>
#include <string>
#include <vector>

using json = nlohmann::json;

namespace exon {

    class SpriteSheet {
    public:
        SpriteSheet(std::string path, unsigned int width, unsigned int height, conf::SpriteConf &cnf);

        sf::Sprite get_sprite(unsigned int col, unsigned int row);
        sf::Sprite get_sprite(unsigned int col, unsigned int row, int w, int h);
    private:
        std::string path;
        unsigned int width;
        unsigned int height;
        sf::Texture sheet;
        conf::SpriteConf cnf;
    };


    class Animation {
    public:
        Animation(std::string path, const std::string name, const std::string key, conf::SpriteConf &cnf);
        ~Animation();

        void render(sf::RenderWindow *window, int x, int y);
        void update();
        void reset();
    private:
        json json_data;
        SpriteSheet *ss;
        const std::string name;
        const std::string key;
        conf::SpriteConf cnf;
        sf::Sprite curr_img;
        
        std::vector<int> cols, rows, heights, widths;

        int index;
        int length;
        int delay;

        sf::Clock clock;
        sf::Time last_time;
    };


}


#endif//_GFX_HPP_