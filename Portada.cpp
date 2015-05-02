#include "Portada.hpp"
#include "utils.hpp"


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

    width = 5;
    height = 2;
    actualAnimation = 0;
    timeBetweenAnimations = 0.25;
    timeSinceLastAnimation = -1.0;

    animationWidth = s.getGlobalBounds().width/width;
    animationHeight = s.getGlobalBounds().height/height;

    if(window->getSize().y/animationHeight < window->getSize().x/animationWidth)
        s.scale(window->getSize().y/animationHeight,window->getSize().y/animationHeight);
    else
        s.scale(window->getSize().x/animationWidth,window->getSize().x/animationWidth);

    s.setOrigin(sf::Vector2f(animationWidth/2, animationHeight/2));
    s.setPosition(window->getSize().x/2, window->getSize().y/2.0);

    sf::Clock c;

    while(open){
        float deltaTime = c.restart().asSeconds();
        sf::Event event;
        while (window->pollEvent(event)) {
            switch (event.type) {
                case sf::Event::KeyPressed:
                case sf::Event::MouseButtonPressed:
                     open = false;
                default:
                    break;
            }
        }

        timeSinceLastAnimation += deltaTime;
        if(timeSinceLastAnimation >= timeBetweenAnimations){
            if (actualAnimation+2  >= width*height) timeSinceLastAnimation = -2;
            if (actualAnimation+1  >= width*height) break;

            actualAnimation = (actualAnimation + 1);
            if (actualAnimation == 1) timeSinceLastAnimation = -0.5;
            else timeSinceLastAnimation = 0.0;
        }



        window->clear();
        if (actualAnimation+2  < width*height)
            s.setTextureRect(sf::IntRect((actualAnimation%width)*animationWidth, (actualAnimation/width)*animationHeight, animationWidth, animationHeight));
        window->draw(s);
        window->display();
    }

}
