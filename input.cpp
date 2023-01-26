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

std::array<std::array<bool, sf::Joystick::ButtonCount>, sf::Joystick::Count> exon::input::joypressed{{false, }, };
std::array<std::array<int, sf::Joystick::AxisCount>, sf::Joystick::Count> exon::input::joymoved{{0, }, };
std::array<unsigned int, sf::Joystick::Count> exon::input::joyreleased{sf::Joystick::ButtonCount, };
std::array<bool, sf::Joystick::Count> exon::input::joyconnected{false, };
std::array<bool, sf::Joystick::Count> exon::input::joydisconnected{false, };
bool exon::input::joychanged = false;

void exon::input::init_input() {
    for(unsigned i = 0; i < sf::Joystick::Count; ++i) {
        if(is_joy_connected(i)) {
            joychanged = true;
            joyconnected[i] = true;
        }
    }
}

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
        case sf::Event::JoystickButtonPressed:
            joypressed[event.joystickButton.joystickId][event.joystickButton.button] = true;
        break;
        case sf::Event::JoystickButtonReleased:
            joypressed[event.joystickButton.joystickId][event.joystickButton.button] = false;
            joyreleased[event.joystickButton.joystickId] = event.joystickButton.button;
        case sf::Event::JoystickMoved:
            joymoved[event.joystickButton.joystickId][event.joystickMove.axis] = event.joystickMove.position;
        break;
        case sf::Event::JoystickConnected:
            joyconnected[event.joystickConnect.joystickId] = true;
            joychanged = true;
        break;
        case sf::Event::JoystickDisconnected:
            joydisconnected[event.joystickConnect.joystickId] = true;
            joychanged = true;
        break;
        default: break;
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

bool exon::input::is_joy_pressed(unsigned id, unsigned b) {
    return joypressed[id][b];
}

bool exon::input::is_joy_released(unsigned id, unsigned b) {
    if(joyreleased[id] == b) {
        joyreleased[id] = sf::Joystick::ButtonCount;
        return true;
    }
    return false;
}

bool exon::input::is_joy_clicked(unsigned id, unsigned b) {
    auto status = joypressed[id][b];
    joypressed[id][b] = false;
    return status;
}

int exon::input::get_axis_move(unsigned id, unsigned b) {
    return joymoved[id][b];
}

bool exon::input::is_joy_connected(unsigned id) {
    return sf::Joystick::isConnected(id);
}

bool exon::input::get_joy_connected(unsigned id) {
    if(joyconnected[id]) {
        joyconnected[id] = false;
        joychanged = false;
        return true;
    }
    return false;
}

bool exon::input::get_joy_disconnected(unsigned id) {
    if(joydisconnected[id]) {
        joydisconnected[id] = false;
        joychanged = false;
        return true;
    }
    return false;
}

bool exon::input::is_joy_changed() {
    return joychanged;
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
