#include "exon.hpp"

int main(int argc, char *argv[]) {

    exon::Exon *engine = new exon::Exon();

    engine->run();

    delete engine;
    
    return 0;
}