#include "Portada.hpp"


Portada::Portada() {
    open = true;
}

Portada::~Portada(){}

void Portada::display(sf::RenderWindow* window){
    open = true;
    while(open){

        sf::Event event;
        while (window->pollEvent(event)) {
            switch (event.type) {
                case sf::Event::Closed:
                    window->close();
                    exit(0);
                    break;
                case sf::Event::KeyPressed:
                    if (event.key.code == sf::Keyboard::Escape) { window->close(); exit(0); }
                    break;
                case sf::Event::MouseButtonPressed:
                    if (event.mouseButton.button == sf::Mouse::Left) {
                        open = false;
                    }
                default:
                    break;
            }
        }


        t.loadFromFile("res/Portada.png");
        s.setTexture(t);
        if(window->getSize().y/s.getGlobalBounds().height < window->getSize().x/s.getGlobalBounds().width)
            s.scale(window->getSize().y/s.getGlobalBounds().height,window->getSize().y/s.getGlobalBounds().height);
        else
            s.scale(window->getSize().x/s.getGlobalBounds().width,window->getSize().x/s.getGlobalBounds().width);
        s.setPosition(window->getSize().x/2 - s.getGlobalBounds().width/2, 0);
        window->draw(s);
        window->display();
    }
}

void Portada::display(sf::RenderWindow* window, std::string pathImage){
    open = true;
    t.loadFromFile(pathImage);
    s = sf::Sprite();
    s.setTexture(t);

    qttyAnimations = 9;
    actualAnimation = 0;
    timeBetweenAnimations = 0.2;
    timeSinceLastAnimaiton = 0.0;

    animationSize = s.getGlobalBounds().width/qttyAnimations;

    if(window->getSize().y/s.getGlobalBounds().height < window->getSize().x/animationSize)
        s.scale(window->getSize().y/s.getGlobalBounds().height,window->getSize().y/s.getGlobalBounds().height);
    else
        s.scale(window->getSize().x/animationSize,window->getSize().x/animationSize);

    sf::Clock c;

    while(open){
        float deltaTime = c.restart().asSeconds();
        sf::Event event;
        while (window->pollEvent(event)) {
            switch (event.type) {
                case sf::Event::Closed:
                    window->close();
                    break;
                case sf::Event::KeyPressed:
                    if (event.key.code == sf::Keyboard::Escape) {
                        window->close();
                        exit(0);
                    }
                    break;
                case sf::Event::MouseButtonPressed:
                    if (event.mouseButton.button == sf::Mouse::Left) {
                        open = false;
                    }
                default:
                    break;
            }
        }

        timeSinceLastAnimaiton += deltaTime;
        if(timeSinceLastAnimaiton >= timeBetweenAnimations){
            if (actualAnimation > qttyAnimations) break;
            actualAnimation = (actualAnimation + 1);
            timeSinceLastAnimaiton = 0.0;
        }



        window->clear();
        s.setTextureRect(sf::IntRect(actualAnimation*animationSize, 0, animationSize, s.getGlobalBounds().height));
        window->draw(s);
        window->display();
    }

}
