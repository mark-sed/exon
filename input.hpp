#ifndef _INPUT_HPP_
#define _INPUT_HPP_

#include <SFML/Window/Mouse.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/Joystick.hpp>
#include <SFML/Window/Event.hpp>
#include <map>
#include <array>

namespace exon {
    namespace input {

        const std::map<std::string, sf::Keyboard::Key> KEYCODES {
            {"A", sf::Keyboard::Key::A},
            {"B", sf::Keyboard::Key::B},
            {"C", sf::Keyboard::Key::C},
            {"D", sf::Keyboard::Key::D},
            {"E", sf::Keyboard::Key::E},
            {"F", sf::Keyboard::Key::F},
            {"G", sf::Keyboard::Key::G},
            {"H", sf::Keyboard::Key::H},
            {"I", sf::Keyboard::Key::I},
            {"J", sf::Keyboard::Key::J},
            {"K", sf::Keyboard::Key::K},
            {"L", sf::Keyboard::Key::L},
            {"M", sf::Keyboard::Key::M},
            {"N", sf::Keyboard::Key::N},
            {"O", sf::Keyboard::Key::O},
            {"P", sf::Keyboard::Key::P},
            {"Q", sf::Keyboard::Key::Q},
            {"R", sf::Keyboard::Key::R},
            {"S", sf::Keyboard::Key::S},
            {"T", sf::Keyboard::Key::T},
            {"U", sf::Keyboard::Key::U},
            {"V", sf::Keyboard::Key::V},
            {"W", sf::Keyboard::Key::W},
            {"X", sf::Keyboard::Key::X},
            {"Y", sf::Keyboard::Key::Y},
            {"Z", sf::Keyboard::Key::Z},
        };

        extern std::array<bool, sf::Keyboard::Key::KeyCount> keypressed;
        extern sf::Keyboard::Key keyreleased;

        void update_input(sf::Event event);
        bool is_key_pressed(sf::Keyboard::Key k);
        bool is_key_released(sf::Keyboard::Key k);
        bool is_key_clicked(sf::Keyboard::Key k);
    }
}

#endif//_INPUT_HPP_