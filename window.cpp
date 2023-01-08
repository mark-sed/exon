#include "window.hpp"

using namespace exon;

Window::Window(unsigned int width, unsigned int height, const std::string& title) {
    this->window = new sf::RenderWindow(sf::VideoMode(width, height), title);
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