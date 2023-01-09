#ifndef _WINDOW_HPP_
#define _WINDOW_HPP_

#include <string>
#include <SFML/Graphics.hpp>
#include "config.hpp"

namespace exon {

class Window {
public:
    Window(conf::WindowConf &wcnf);
    ~Window();

    void update();

    sf::RenderWindow *window;
};

}

#endif//_WINDOW_HPP_