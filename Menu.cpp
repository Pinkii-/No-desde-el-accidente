#include "Menu.hpp"

int Menu::run(sf::RenderWindow* w) {

    window = w;

    std::string actual;

    std::ifstream myfile;
    myfile.open("res/lastlevel.txt");
    getline(myfile,actual);
    myfile.close();


    running = true;

    //Buttons initialization
    buttonL.setPosition(window->getSize().x - buttonL.getSize().x -10, window->getSize().y/2);
    buttonL.setSize(window->getSize().x/20, window->getSize().x/40);
    buttonL.setText("<");

    buttonR.setPosition(0 +10, window->getSize().y/2);
    buttonR.setSize(window->getSize().x/20, window->getSize().x/40);
    buttonR.setText(">");

    while(running){

        sf::Event event;
        while(window->pollEvent(event)){
            buttonL.handleEvent(event);
            buttonR.handleEvent(event);
            switch (event.type){
                case sf::Event::Closed:
                    window->close();
                    break;
                default:
                    break;
            }
            if (event.type == sf::Event::Closed) { window->close(); exit(0);}
            if (event.type == sf::Event::KeyPressed){ if (event.key.code == sf::Keyboard::Escape) { window->close(); exit(0); } }
        }

        if (buttonL.hasBeenClicked()) {

        }
        if (buttonR.hasBeenClicked()) {

        }
    }
}

Menu::Menu(){

    //Variable initialization
    level = 0;
    running = false;

    buttonL.setTexture("res/button.png");
    buttonR.setTexture("res/button.png");
    buttonL.setPressedTexture("res/pressedButton.png");
    buttonR.setPressedTexture("res/pressedButton.png");

}

int Menu::getLevel() const {
    return level;
}

void Menu::setLevel(int value) {
    level = value;
}

