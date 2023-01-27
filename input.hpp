#ifndef _INPUT_HPP_
#define _INPUT_HPP_

#include <SFML/Window/Mouse.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/Joystick.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Graphics.hpp>
#include <map>
#include <array>

namespace exon {
    namespace input {

        extern std::array<bool, sf::Keyboard::Key::KeyCount> keypressed;
        extern sf::Keyboard::Key keyreleased;

        extern std::array<bool, sf::Mouse::Button::ButtonCount> mousepressed;
        extern sf::Mouse::Button mousereleased;
        extern int mousescroll;
        extern int hmousescroll;
        extern bool mousemoved;

        extern std::array<std::array<bool, sf::Joystick::ButtonCount>, sf::Joystick::Count> joypressed;
        extern std::array<std::array<int, sf::Joystick::AxisCount>, sf::Joystick::Count> joymoved;
        extern std::array<unsigned int, sf::Joystick::Count> joyreleased;
        extern std::array<bool, sf::Joystick::Count> joyconnected;
        extern std::array<bool, sf::Joystick::Count> joydisconnected;
        extern bool joychanged;

        void init_input(sf::RenderWindow *window);
        void update_input(sf::Event event);
        
        bool is_key_pressed(sf::Keyboard::Key k);
        bool is_key_released(sf::Keyboard::Key k);
        bool is_key_clicked(sf::Keyboard::Key k);

        bool is_joy_pressed(unsigned id, unsigned b);
        bool is_joy_released(unsigned id, unsigned b);
        bool is_joy_clicked(unsigned id, unsigned b);
        int get_axis_move(unsigned id, unsigned b);
        inline bool is_joy_connected(unsigned id);
        bool get_joy_connected(unsigned id);
        bool get_joy_disconnected(unsigned id);
        bool is_joy_changed();

        bool is_mouse_pressed(sf::Mouse::Button b);
        bool is_mouse_released(sf::Mouse::Button b);
        bool is_mouse_clicked(sf::Mouse::Button b);
        int get_scroll();
        int get_hscroll();
        bool is_mouse_in_window();
        int get_mouse_x();
        int get_mouse_y();
        sf::Vector2i get_mouse_xy();
        int get_mouse_desktop_x();
        int get_mouse_desktop_y();
        sf::Vector2i get_mouse_desktop_xy();

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

        const std::map<std::string, sf::Mouse::Button> MOUSECODE {
            {"LEFT", sf::Mouse::Button::Left},
            {"RIGHT", sf::Mouse::Button::Right},
            {"MIDDLE", sf::Mouse::Button::Middle},
            {"B1", sf::Mouse::Button::XButton1},
            {"B2", sf::Mouse::Button::XButton2},
        };
        
        // XBOX
        const std::map<std::string, unsigned int> JOYCODES {
            {"A", 0},
            {"B", 1},
            {"X", 2},
            {"Y", 3},
            {"LB", 4},
            {"RB", 5},
            {"VIEW", 6},
            {"MENU", 7},
            {"GUIDE", 8},
            {"LSB", 9},
            {"RSB", 10},
        };
        const std::map<std::string, unsigned int> JOYAXES {
            {"LSX", 0},
            {"LSY", 1},
            {"LT", 2},
            {"RT", 3},
            {"RSX", 4},
            {"RSY", 5},
            {"DPADX", 6},
            {"DPADY", 7},
        };
    }
}

#endif//_INPUT_HPP_