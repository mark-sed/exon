#include "exon.hpp"
#include <iostream>

using namespace exon;

Exon::Exon() {
    // TODO: Read settings from config struct
    this->window = new Window(600, 400, "Exon window");
}

Exon::~Exon() {
    delete this->window;
}

void Exon::run() {
    while(this->window->window->isOpen()) {
        this->update();
        window->window->clear();
        window->window->display();
    }
}

void Exon::update() {
    window->update();
}