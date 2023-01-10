#include "exon.hpp"
#include "logging.hpp"
#include <SFML/System/Clock.hpp>
#include <SFML/System/Time.hpp>
#include <iostream>
#include <functional>

using namespace exon;

Exon::Exon(conf::Conf *cnf) : cnf{cnf} {
    LOGMAX("Exon " EXON_VERSION " started.");
    this->window = new Window(cnf->window_conf);
}

Exon::~Exon() {
    delete this->window;
}

void Exon::run(std::function<void()> fupdate, std::function<void(sf::RenderWindow*)> frender) {
    double ns = 1000000 / this->cnf->fps;
    double delta = 0;
    sf::Clock clock;
    int ticks;
    int frames;
    
    auto lastTime = clock.getElapsedTime().asMicroseconds();
    
    long timer = 0;

    while(this->window->window->isOpen()) {
        auto now = clock.getElapsedTime().asMicroseconds();
        delta += (now - lastTime) / ns;
        timer += now - lastTime;
        lastTime = now;
        
        if(delta >= 1){
            update();
            fupdate();
            frames++;
            delta--;
        }
        
        window->window->clear(sf::Color::Black);
        frender(this->window->window);
        window->window->display();
        ticks++;
        
        if(timer >= 1000000){
            //std::cout << ticks << "   " << frames << "\n";
            this->fps = frames;
            this->gticks = ticks;
            ticks = 0;
            frames = 0;
            timer = 0;
        }
    }
}

void Exon::update() {
    window->update();
}