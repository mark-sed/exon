#include "exon.hpp"
#include "logging.hpp"
#include <iostream>
#include <functional>

using namespace exon;

Exon::Exon(conf::Conf *cnf) {
    LOGMAX("Exon started");
    this->window = new Window(cnf->window_conf);
}

Exon::~Exon() {
    delete this->window;
}

void Exon::run(std::function<void()> fupdate, std::function<void(sf::RenderWindow*)> frender) {
    while(this->window->window->isOpen()) {
        this->update();
        fupdate();
        window->window->clear();
        frender(window->window);
        window->window->display();
    }
}

void Exon::update() {
    window->update();
}