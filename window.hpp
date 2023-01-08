#ifndef _WINDOW_HPP_
#define _WINDOW_HPP_

#include <string>
#include <SFML/Graphics.hpp>

namespace exon {

class Window {
public:
    Window(unsigned int width, unsigned int height, const std::string& title);
    ~Window();

    void update();

    sf::RenderWindow *window;
};

}

#endif//_WINDOW_HPP_