#include "exon.hpp"
#include "config.hpp"
#include "logging.hpp"
#include "gfx.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

void main_update();
void main_render(sf::RenderWindow *window);

class Game {
public:
    exon::conf::Conf *cnf;
    exon::Exon *engine;

    Game() {
        cnf = new exon::conf::Conf();
        cnf->window_conf.width = 900;
        cnf->window_conf.height = 600;
        cnf->window_conf.title = "Game window";
        cnf->sprite_conf.scale = 4.f;
        engine = new exon::Exon(cnf);
        
    }

    ~Game() {
        delete engine;
        delete cnf;
    }

    void run() {
        engine->run(&main_update, &main_render);
    }

    void update() {
    
    }

    void render(sf::RenderWindow *window) {
        exon::SpriteSheet ss("icons.png", 16, 16, cnf->sprite_conf);
        auto img = ss.get_sprite(0, 0);
        img.setPosition(200, 200);
        window->draw(img);

        sf::Font dorFont01;
        dorFont01.loadFromFile("res/DorFont01.ttf");

        sf::Text tfps;
        tfps.setFont(dorFont01);
        tfps.setString(std::to_string(engine->get_frames())+std::string("/")+std::to_string(engine->get_ticks()));
        tfps.setCharacterSize(16);
        tfps.setFillColor(sf::Color::White);
        tfps.setPosition(cnf->window_conf.width-tfps.getLocalBounds().width-5, 0);
        window->draw(tfps);

        exon::Animation anim("res/anim.json", "joker");
        
    }
};

Game *game;

void main_update() {
    game->update();
}

void main_render(sf::RenderWindow *window) {
    game->render(window);
}

int main(int argc, char *argv[]) {
    Logger::get().set_disable(false);
    Logger::get().set_log_everything(true);
    Logger::get().set_logging_level(MAX_LOGGING_LEVEL);

    game = new Game();
    game->run();
    delete game;

    return 0;
}