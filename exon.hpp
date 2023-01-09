#ifndef _EXON_HPP_
#define _EXON_HPP_

#include "window.hpp"
#include "config.hpp"
#include <functional>
#include <SFML/Graphics.hpp>

namespace exon {

    #define MACRO_TO_STR_HELPER(x) #x
    /** Macro to convert INT macro value into string value */
    #define MACRO_TO_STR(x) MACRO_TO_STR_HELPER(x)

    #define EXON_VERSION_MAJOR 0  ///< Exon's major version
    #define EXON_VERSION_MINOR 1  ///< Exon's minor version
    #define EXON_VERSION_PATCH 0  ///< Exon's patch

    /** Exon version as a string */
    #define EXON_VERSION MACRO_TO_STR(EXON_VERSION_MAJOR) "." MACRO_TO_STR(EXON_VERSION_MINOR) "." MACRO_TO_STR(EXON_VERSION_PATCH)

    class Exon {
    public:
        Window *window;
        
        Exon(conf::Conf *cnf);
        ~Exon();

        void run(std::function<void()> fupdate, std::function<void(sf::RenderWindow*)> frender);

        int get_ticks() { return this->ticks; }
        int get_frames() { return this->frames; }
    private:
        conf::Conf *cnf;
        int ticks;
        int frames;
        
        void update();
    };

}

#endif//_EXON_HPP_