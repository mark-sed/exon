#include "input.hpp"
#include <SFML/Window/Mouse.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/Joystick.hpp>
#include <iostream>

using namespace exon::input;

std::array<bool, sf::Keyboard::Key::KeyCount> exon::input::keypressed{false, };
sf::Keyboard::Key exon::input::keyreleased = sf::Keyboard::Key::Unknown;

void exon::input::update_input(sf::Event event) {
    if(event.type == sf::Event::KeyPressed) {
        keypressed[event.key.code] = true;
        keyreleased = sf::Keyboard::Key::Unknown;
    }
    else if(event.type == sf::Event::KeyReleased) {
        keypressed[event.key.code] = false;
        keyreleased = event.key.code;
    }
}

bool exon::input::is_key_pressed(sf::Keyboard::Key k) { 
    return keypressed[k];
}

bool exon::input::is_key_released(sf::Keyboard::Key k) {
    if(keyreleased == k) {
        keyreleased = sf::Keyboard::Key::Unknown;
        return true;
    }
    return false;
}

bool exon::input::is_key_clicked(sf::Keyboard::Key k) { 
    auto status = keypressed[k];
    keypressed[k] = false;
    return status;
}
