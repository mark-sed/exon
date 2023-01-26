#include "window.hpp"
#include "input.hpp"
#include <iostream>

using namespace exon;

Window::Window(conf::WindowConf &wcnf) {
    this->window = new sf::RenderWindow(sf::VideoMode(wcnf.width, wcnf.height), wcnf.title);
}

Window::~Window() {
    delete this->window;
}

void Window::update() {
    // Check if window is being closed
    sf::Event event;
    while(window->pollEvent(event)) {
        if(event.type == sf::Event::Closed) {
            window->close();
        }
        exon::input::update_input(event);
        /*if (event.type == sf::Event::TextEntered) {
            if (event.text.unicode < 128)
                std::cout << "ASCII character typed: " << static_cast<char>(event.text.unicode) << std::endl;
        }*/
    }
}