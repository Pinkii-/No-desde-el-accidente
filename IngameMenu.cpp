#include "IngameMenu.hpp"

IngameMenu::IngameMenu() {}

IngameMenu::IngameMenu(sf::Vector2f center) :
    resume("Resume", "res/button.png", center.x/8,center.y/6),
    menu("Menu", "res/button.png", center.x/8,center.y/6)
{
//    resume.setTexture("res/button.png");
//    resume.setText("Resume");
//    resume.setSize(center.x/8,center.y/6);
    resume.setFont("res/font.otf");
    resume.setPosition(center.x-resume.getSize().x,center.y + 10);


//    menu.setTexture("res/button.png");
//    menu.setText("Menu");
//    menu.setSize(center.x/8,center.y/6);
    menu.setFont("res/font.otf");
    menu.setPosition(center.x-menu.getSize().x,center.y - center.y/6);

    background = sf::RectangleShape(
                sf::Vector2f(
                    std::max(resume.getSize().x, menu.getSize().x),
                    std::max(resume.getSize().y, menu.getSize().y)));
    background.setOrigin(background.getSize().x, background.getSize().y);
    background.setPosition(center);
    background.setFillColor(sf::Color::White);
}

void IngameMenu::draw(sf::RenderWindow &window) {
    window.draw(background);
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

