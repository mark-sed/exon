#ifndef _EXON_HPP_
#define _EXON_HPP_

#include "window.hpp"
#include "config.hpp"
#include <functional>
#include <SFML/Graphics.hpp>

namespace exon {

    class Exon {
    public:
        Window *window;
        
        Exon(conf::Conf *cnf);
        ~Exon();

        void run(std::function<void()> fupdate, std::function<void(sf::RenderWindow*)> frender);
    private:
        conf::Conf *cnf;
        
        void update();
    };

}

#endif//_EXON_HPP_