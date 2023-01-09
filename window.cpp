#include "window.hpp"

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
    }
}