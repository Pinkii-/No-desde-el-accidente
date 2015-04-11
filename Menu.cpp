#include "Menu.hpp"

int Menu::run(sf::RenderWindow* w) {

    window = w;
    running = true;

    float maxLvl;
    std::string actual;
    std::ifstream myfile;

    myfile.open("res/lastlevel.txt");
    getline(myfile,actual);
    myfile.close();
    maxLvl = my_stoi(actual);

    //Buttons initialization
    buttonL.setTextResizeText("<");
    buttonL.setSize(window->getSize().x/20, window->getSize().x/40);
    buttonL.setPosition(0 +10, window->getSize().y/2);

    buttonR.setTextResizeText(">");
    buttonR.setSize(window->getSize().x/20, window->getSize().x/40);
    buttonR.setPosition(window->getSize().x - buttonR.getSize().x -10, window->getSize().y/2);

    Button b;
    b.disableClickEffect();
    sf::Font f;
    f.loadFromFile("res/font.otf");
    b.setFont(f);
    b.setTexture("res/levelButton.png");
    b.setSize(window->getSize().x/20, window->getSize().x/40);
    b.setText(actual);
    b.setPosition(window->getSize().x/2, window->getSize().y/2);


    while(running){

        sf::Event event;
        while(window->pollEvent(event)){
            b.handleEvent(event);
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
            if(level > 0) level--;
        }

        if (buttonR.hasBeenClicked()) {
            if(level < maxLvl) ++level;
        }

        if(b.hasBeenClicked()){
            return level;
        }


        window->clear();

        buttonL.draw(*window);
        buttonR.draw(*window);
        std::stringstream ss;
        ss << level;
        std::string str = ss.str();
        b.setTextResizeText(str);
        b.draw(*window);

        window->display();
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

