#include "Menu.hpp"

int Menu::run() {
    running = true;

    std::string actual;
    std::ifstream myfile;

    float maxLvl;

    myfile.open("res/lastlevel.txt");
    getline(myfile,actual);
    myfile.close();
    maxLvl = my_stoi(actual);


    Button b;
    b.disableClickEffect();
  //  sf::Font f;
    //f.loadFromFile("res/font.otf");
    //b.setFont(f);
    b.setTexture("res/empty.png");
    b.setText(actual);
    b.setPosition(window->getSize().x/2, window->getSize().y/2);
    b.setSize(window->getSize().x/20, window->getSize().x/10);


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

Menu::Menu(sf::RenderWindow* w){

    //Variable initialization
    window = w;
    level = 0;
    running = false;

    buttonL.setTexture("res/empty.png");
    buttonR.setTexture("res/empty.png");
    buttonL.setPressedTexture("res/empty.png");
    buttonR.setPressedTexture("res/empty.png");
    buttonL.setText("<");
    buttonR.setText(">");

    //Buttons initialization
    buttonL.setSize(window->getSize().x/20, window->getSize().x/10);
    buttonL.setPosition(0 +10, window->getSize().y/2);

    buttonR.setSize(window->getSize().x/20, window->getSize().x/10);
    buttonR.setPosition(window->getSize().x - buttonR.getSize().x -10, window->getSize().y/2);
}

void Menu::setLevel(int value) {
    if (value > level) {
      level = value;
      char command[256];
      snprintf(command, 256, "echo -n %d > res/lastlevel.txt", value);
      system(command);
    }
}

