#include "gfx.hpp"
#include "libs/json.hpp"
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

Animation::Animation(std::string path, std::string name) {
    std::ifstream f(path);
    std::string conf((std::istreambuf_iterator<char>(f)), std::istreambuf_iterator<char>());
    json json_data;
    try{
        json_data = json::parse(conf);
    }catch(json::exception &e){
        // Error loading config file, abort!
        // FIXME: change to error call
        std::cerr << "ERROR:" << e.what();
        exit(1);
    }
    std::cout << json_data << std::endl;
}

Animation::~Animation() {

}

void Animation::reset() {

}

void Animation::update() {

}