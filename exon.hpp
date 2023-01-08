#ifndef _EXON_HPP_
#define _EXON_HPP_

#include "window.hpp"

namespace exon {

class Exon {
public:
    Exon();
    ~Exon();

    void run();

    Window *window;
private:
    void update();
};

}

#endif//_EXON_HPP_