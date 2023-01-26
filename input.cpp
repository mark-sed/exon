#include "input.hpp"
#include <SFML/Window/Mouse.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/Joystick.hpp>
#include <iostream>

using namespace exon::input;

std::array<bool, sf::Keyboard::Key::KeyCount> exon::input::keypressed{false, };
sf::Keyboard::Key exon::input::keyreleased = sf::Keyboard::Key::Unknown;

int exon::input::mousescroll = 0;
int exon::input::hmousescroll = 0;
bool exon::input::mousemoved = false;

std::array<bool, sf::Mouse::Button::ButtonCount> exon::input::mousepressed{false, };
sf::Mouse::Button exon::input::mousereleased = sf::Mouse::Button::ButtonCount;

void exon::input::update_input(sf::Event event) {
    exon::input::mousemoved = false;

    switch(event.type) {
    case sf::Event::KeyPressed:
        keypressed[event.key.code] = true;
        keyreleased = sf::Keyboard::Key::Unknown;
    break;
    case sf::Event::KeyReleased:
        keypressed[event.key.code] = false;
        keyreleased = event.key.code;
    break;
    case sf::Event::MouseMoved:
        exon::input::mousemoved = true;
    break;
    case sf::Event::MouseButtonPressed:
        mousepressed[event.mouseButton.button] = true;
    break;
    case sf::Event::MouseButtonReleased:
        mousepressed[event.mouseButton.button] = false;
        mousereleased = event.mouseButton.button;
    break;
    case sf::Event::MouseWheelScrolled:
        if (event.mouseWheelScroll.wheel == sf::Mouse::VerticalWheel) {
            if((event.mouseWheelScroll.delta >= 0) ^ (mousescroll < 0)) {
                // Same sign
                mousescroll += event.mouseWheelScroll.delta;
            }
            else {
                mousescroll = event.mouseWheelScroll.delta;
            }
        }
        else if(event.mouseWheelScroll.wheel == sf::Mouse::HorizontalWheel) {
            if((event.mouseWheelScroll.delta >= 0) ^ (hmousescroll < 0)) {
                // Same sign
                hmousescroll += event.mouseWheelScroll.delta;
            }
            else {
                hmousescroll = event.mouseWheelScroll.delta;
            }
        }
    break;
    default:
    break;
    }
}

bool exon::input::is_mouse_pressed(sf::Mouse::Button b) {
    return mousepressed[b];
}

bool exon::input::is_mouse_released(sf::Mouse::Button b) {
    if(mousereleased == b) {
        mousereleased = sf::Mouse::Button::ButtonCount;
        return true;
    }
    return false;
}

bool exon::input::is_mouse_clicked(sf::Mouse::Button b) {
    auto status = mousepressed[b];
    mousepressed[b] = false;
    return status;
}

int exon::input::get_scroll() {
    auto v = mousescroll;
    mousescroll = 0;
    return v;
}

int exon::input::get_hscroll() {
    auto v = hmousescroll;
    hmousescroll = 0;
    return v;
}

bool exon::input::is_mouse_in_window() {
    return exon::input::mousemoved;
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
