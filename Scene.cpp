#include "Scene.hpp"

Scene::Scene(int scrwidth, int scrheight, std::string title, int style)
    : Game(scrwidth,scrheight,title,style),
      player(sf::Vector2f(200,200),sf::Vector2f(500,500))
{
    currentChameleon = nullptr;
    chameleons = std::vector<Chameleon>();
    chameleons.push_back(Chameleon(sf::Vector2f(600,200)));
}

Scene::~Scene() {}

void Scene::update(float deltaTime){
    player.update(deltaTime);
    for (Chameleon &c : chameleons) c.update(deltaTime, player.getPosition());
}

void Scene::draw(){
    player.draw(window);
    for (Chameleon &c : chameleons) c.draw(window);
}

void Scene::processEvents(){
    sf::Event event;
    while (window.pollEvent(event)) {
        switch (event.type) {
            case sf::Event::Closed:
                window.close();
                break;
            default:
                break;
        }
    }
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) activeChameleon(sf::Vector2f(sf::Mouse::getPosition().x,sf::Mouse::getPosition().y));
    else releaseChameleon();
}

void Scene::activeChameleon(sf::Vector2f pos) {
    // TODO: elegir que chamaleon hay que elegir
    currentChameleon = &chameleons[0];


    currentChameleon->lick();
    player.setLicked(true,currentChameleon->getPosition());
}

void Scene::releaseChameleon() {
    if (currentChameleon == nullptr) return;

    currentChameleon->release();
    currentChameleon = nullptr;
    player.setLicked(false,sf::Vector2f(0,0));
}

