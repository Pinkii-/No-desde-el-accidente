#ifndef MENU_HPP
#define MENU_HPP
#include "utils.hpp"
#include "Button.hpp"

class Menu {

public:


    Menu(sf::RenderWindow *w);

    void setLevel(int value);

    int run();

private:

    int level;
    bool running;
    Button buttonL;
    Button buttonR;
    sf::RenderWindow* window;
    std::vector<Button> levels;

    int readMaxLvl();
};

#endif // MENU_HPP
