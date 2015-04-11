#include "IngameMenu.hpp"
#include "Resources.hpp"

IngameMenu::IngameMenu() {}

IngameMenu::IngameMenu(sf::Vector2f center) :
    resume("Resume", "res/button.png", center.x/8,center.y/6),
    menu("Menu", "res/button.png", center.x/8,center.y/6)
{
//    resume.setTexture("res/button.png");
//    resume.setText("Resume");
    resume.setFont(Resources::font);
    resume.setSize(center.x/8,center.y/6);
    resume.setPosition(center.x-resume.getSize().x,center.y + 10);


//    menu.setTexture("res/button.png");
//    menu.setText("Menu");
    menu.setFont(Resources::font);
    menu.setSize(center.x/8,center.y/6);
    menu.setPosition(center.x-menu.getSize().x,center.y - center.y/6);

    background = sf::RectangleShape(
                sf::Vector2f(
                    std::max(resume.getSize().x, menu.getSize().x) + 20,
                    resume.getSize().y + menu.getSize().y +30));
    background.setOrigin(background.getSize().x/2, background.getSize().y/2);
    background.setPosition(center);
    background.setFillColor(sf::Color::Blue);

    resume.setPosition(resume.getPosition().x+background.getSize().x/2-10, resume.getPosition().y);
    menu.setPosition(menu.getPosition().x+background.getSize().x/2-10, menu.getPosition().y);
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

