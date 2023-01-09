#include "exon.hpp"
#include "config.hpp"
#include "logging.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>

void update() {

}

void render(sf::RenderWindow *window) {
    
}

int main(int argc, char *argv[]) {
    Logger::get().set_disable(false);
    Logger::get().set_log_everything(true);
    Logger::get().set_logging_level(MAX_LOGGING_LEVEL);

    exon::conf::Conf *cnf = new exon::conf::Conf();
    cnf->window_conf.width = 900;
    cnf->window_conf.height = 600;
    cnf->window_conf.title = "Game window";
    exon::Exon *engine = new exon::Exon(cnf);

    engine->run(&update, &render);

    delete engine;
    
    return 0;
}