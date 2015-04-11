#ifndef MENU_HPP
#define MENU_HPP
#include "utils.hpp"
#include "Button.hpp"

class Menu {

public:


    Menu();

    int getLevel() const;

    void setLevel(int value);

    int run(sf::RenderWindow *w);

private:

    int level;
    bool running;
    Button buttonL;
    Button buttonR;
    sf::RenderWindow* window;
    std::vector<Button> levels;


};

#endif // MENU_HPP
