#include "gfx.hpp"
#include "logging.hpp"
#include "libs/json.hpp"
#include <SFML/System/Clock.hpp>
#include <SFML/System/Time.hpp>
#include <iostream>
#include <streambuf>
#include <fstream>

using namespace exon;
using json = nlohmann::json;

SpriteSheet::SpriteSheet(std::string path, 
                         unsigned int width,
                         unsigned int height,
                         conf::SpriteConf &cnf) : path{path},
                                                  width{width},
                                                  height{height},
                                                  cnf{cnf} {
    if(!this->sheet.loadFromFile(cnf.basepath+path)){
        error(std::string("Could not load file '")+path+"'.");
    }
}

sf::Sprite SpriteSheet::get_sprite(unsigned int col, unsigned int row) {
    sf::Sprite s;
    s.setTexture(this->sheet);
    s.setTextureRect(sf::IntRect(col*width, row*height, width, height));
    s.setScale(cnf.scale, cnf.scale);
    return s;
}

sf::Sprite SpriteSheet::get_sprite(unsigned int col, unsigned int row, int w, int h) {
    sf::Sprite s;
    s.setTexture(this->sheet);
    s.setTextureRect(sf::IntRect(col*width, row*height, w, h));
    s.setScale(cnf.scale, cnf.scale);
    return s;
}

Animation::Animation(std::string path, 
                     const std::string name,
                     const std::string key,
                     conf::SpriteConf &cnf) : name{name}, key{key}, cnf{cnf} {
    std::ifstream f(path);
    std::string conf((std::istreambuf_iterator<char>(f)), std::istreambuf_iterator<char>());
    try{
        json_data = json::parse(conf);
    }catch(json::exception &e){
        // Error loading animation file, abort!
        std::string m = std::string("Animation '")+name+std::string("' (")+path+std::string(") could not be parsed.");
        error(m);
    }
    auto an_json = json_data[name][key];
    ss = new SpriteSheet(an_json["sprite"].get<std::string>(), 
                         an_json["tsw"].get<int>(),
                         an_json["tsh"].get<int>(),
                         cnf);

    index = 0;
    delay = an_json["delay"];
    
    auto frame_meta = an_json["frames"].get<std::vector<json> >();
    length = frame_meta.size();

    cols.reserve(length);
    rows.reserve(length);
    heights.reserve(length);
    widths.reserve(length);

    for(auto m: frame_meta) {
        cols.push_back(m["c"].get<int>());
        rows.push_back(m["r"].get<int>());
        widths.push_back(m["w"].get<int>());
        heights.push_back(m["h"].get<int>());
    }

    curr_img = ss->get_sprite(cols[0], rows[0], widths[0], heights[0]);
    last_time = clock.getElapsedTime();
}

Animation::~Animation() {

}

void Animation::reset() {

}

void Animation::update() {
    auto now = clock.getElapsedTime();
    if(now.asMilliseconds() - last_time.asMilliseconds() >= delay) {
        this->index++;
        if(this->index >= this->length) {
            this->index = 0;
        }
        this->curr_img = curr_img = ss->get_sprite(cols[index], rows[index], widths[index], heights[index]);
        last_time = now;
    }
}

void Animation::render(sf::RenderWindow *window, int x, int y) {
    curr_img.setPosition(x, y);
    window->draw(curr_img);
}