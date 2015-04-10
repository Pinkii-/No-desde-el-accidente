#include "Scene.hpp"

Scene::Scene(int scrwidth, int scrheight, std::string title, int style)
    : Game(scrwidth,scrheight,title,style),
      player(sf::Vector2f(200,200),sf::Vector2f(50,50))
{
    chameleons = std::vector<Chameleon>();
    chameleons.push_back(Chameleon(sf::Vector2f(400,400)));
}

Scene::~Scene() {}

void Scene::update(float deltaTime){
    player.update(deltaTime);
    for (Chameleon c : chameleons) c.update(deltaTime, player.getPosition());
}

void Scene::draw(){
    player.draw(window);
    for (Chameleon c : chameleons) c.draw(window);
}

void Scene::processEvents(){
    sf::Event event;
    while (window.pollEvent(event)) {
        switch (event.type) {
        case sf::Event::Closed:
            window.close();
            break;
            // Add more events to handle them.
        default:
            break;
        }
    }
}
