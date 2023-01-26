#include "exon.hpp"
#include "config.hpp"
#include "logging.hpp"
#include "gfx.hpp"
#include "input.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

void main_update();
void main_render(sf::RenderWindow *window);

class Game {
public:
    exon::conf::Conf *cnf;
    exon::Exon *engine;
    exon::Animation *anim;
    int x, y;

    Game() {
        cnf = new exon::conf::Conf();
        cnf->window_conf.width = 900;
        cnf->window_conf.height = 600;
        cnf->window_conf.title = "Game window";

        cnf->sprite_conf.basepath = "res/";
        cnf->sprite_conf.scale = 4.f;

        exon::Fonts::get().set_basepath("res/");
        
        engine = new exon::Exon(cnf);

        anim = new exon::Animation("anim.json", "joker", "idle", cnf->sprite_conf);

        x = y = 200;
    }

    ~Game() {
        delete engine;
        delete cnf;
    }

    void run() {
        engine->run(&main_update, &main_render);
    }

    void update() {
        anim->update();

        y += 2 * (exon::input::get_axis_move(0, exon::input::JOYAXES.at("LSY")) / 100.f);
        x += 2 * (exon::input::get_axis_move(0, exon::input::JOYAXES.at("LSX")) / 100.f);

        if(exon::input::is_key_pressed(sf::Keyboard::Key::W)) {
            y -= 2;
        }
        else if(exon::input::is_key_pressed(sf::Keyboard::Key::S)) {
            y += 2;
        }
        if(exon::input::is_key_pressed(sf::Keyboard::Key::A)) {
            x -= 2;
        }
        else if(exon::input::is_key_pressed(sf::Keyboard::Key::D)) {
            x += 2;
        }

        if(exon::input::is_joy_changed()) {
            if(exon::input::get_joy_connected(0)) {
                std::cout << "CONNECTED!\n";
            }
            else if(exon::input::get_joy_disconnected(0)){
                std::cout << "DISCONNECTED!\n";
            }
        }
    }

    void render(sf::RenderWindow *window) {
        anim->render(window, x, y);

        sf::Font dorFont01 = exon::Fonts::get_font("DorFont01.ttf");
        sf::Text tfps;
        tfps.setFont(dorFont01);
        tfps.setString(std::to_string(engine->get_frames())+std::string("/")+std::to_string(engine->get_ticks()));
        tfps.setCharacterSize(16);
        tfps.setFillColor(sf::Color::White);
        tfps.setPosition(cnf->window_conf.width-tfps.getLocalBounds().width-5, 0);
        window->draw(tfps);
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