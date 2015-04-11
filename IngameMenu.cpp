#include "IngameMenu.hpp"
#include "Resources.hpp"

IngameMenu::IngameMenu() {}

IngameMenu::IngameMenu(sf::Vector2f center) :
    resume("", "res/boton_01.png", center.x/8,center.y/6),
    menu("", "res/boton_02.png", center.x/8,center.y/6)
{

    resume.setSize(center.x/4,center.y/3);
    resume.setPosition(center.x-resume.getSize().x,center.y + 10);

    menu.setSize(center.x/4,center.y/3);
    menu.setPosition(center.x-menu.getSize().x,center.y - center.y/3);

    background = sf::RectangleShape(
                sf::Vector2f(
                    std::max(resume.getSize().x, menu.getSize().x) + 20,
                    resume.getSize().y + menu.getSize().y +30));
    background.setOrigin(background.getSize().x/2, background.getSize().y/2);
    background.setPosition(center);
    background.setFillColor(sf::Color::Black);

    resume.setPosition(resume.getPosition().x+background.getSize().x/2-10, resume.getPosition().y);
    menu.setPosition(menu.getPosition().x+background.getSize().x/2-10, menu.getPosition().y);
}

void IngameMenu::draw(sf::RenderWindow &window) {
    //window.draw(background);
    resume.draw(window);
    menu.draw(window);
}

void IngameMenu::handleEvent(sf::Event event) {
    menu.handleEvent(event);
    resume.handleEvent(event);
}

bool IngameMenu::wantToResume() {
    return resume.hasBeenClicked();
}

bool IngameMenu::wantToMenu() {
    return menu.hasBeenClicked();
}

