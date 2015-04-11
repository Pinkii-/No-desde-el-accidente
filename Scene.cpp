#include "Scene.hpp"

Scene::Scene(sf::RenderWindow* w)
      : Game(w)
{
    goal.setPosition(900,150);

    player.setSpeed(sf::Vector2f(200,200));
    player.setPosition(sf::Vector2f(200,200));

    currentChameleon = nullptr;
    chameleons = std::vector<Chameleon>();
    chameleons.push_back(Chameleon(sf::Vector2f(600,200)));
    chameleons.push_back(Chameleon(sf::Vector2f(200,200)));
    chameleons.push_back(Chameleon(sf::Vector2f(400,20)));
    chameleons.push_back(Chameleon(sf::Vector2f(100,600)));


}

Scene::~Scene() {}

void Scene::update(float deltaTime){
    player.update(deltaTime);
    for (Chameleon &c : chameleons) c.update(deltaTime, player.getPosition());
    goal.update(deltaTime);
}

void Scene::draw(){
    goal.draw(*window);
    player.draw(*window);
    for (Chameleon &c : chameleons) c.draw(*window);
}

void Scene::processEvents(){
    sf::Event event;
    while (window->pollEvent(event)) {
        switch (event.type) {
            case sf::Event::Closed:
                window->close();
                break;
            case  sf::Event::KeyPressed:
                //Close key
                if (event.key.code == sf::Keyboard::Escape) {
                    window->close();
                }
                break;
            default:
                break;
        }
    }
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) activeChameleon(sf::Vector2f(sf::Mouse::getPosition(*window).x,sf::Mouse::getPosition(*window).y));
    else releaseChameleon();
}

void Scene::activeChameleon(sf::Vector2f pos) {
    // TODO: elegir que chamaleon hay que elegir
    if (currentChameleon != nullptr) return;
    for (Chameleon &c : chameleons) {
        if (getModule(pos,c.getPosition()) < c.getRadius()) {
            currentChameleon = &c;
            break;
        }
    }
    if (currentChameleon == nullptr) return;


    currentChameleon->lick();
    player.setLicked(true,currentChameleon->getPosition());
}

void Scene::releaseChameleon() {
    if (currentChameleon == nullptr) return;

    currentChameleon->release();
    currentChameleon = nullptr;
    player.setLicked(false,sf::Vector2f(0,0));
}

