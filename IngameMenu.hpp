#ifndef INGAMEMENU_HPP
#define INGAMEMENU_HPP

#include "utils.hpp"
#include "Button.hpp"

class IngameMenu {
public:
    IngameMenu();
    IngameMenu(sf::Vector2f center);

    void draw(sf::RenderWindow &window);
    void handleEvent(sf::Event event);

    bool wantToResume();
    bool wantToMenu();
private:
    Button resume;
    Button menu;
    sf::RectangleShape background;
};

#endif // INGAMEMENU_HPP
