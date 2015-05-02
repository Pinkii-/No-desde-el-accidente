#include "Scene.hpp"

Scene::Scene(sf::RenderWindow* w, Level lvl)
    : Game(w),
      background(*w),
      iMenu(sf::Vector2f(w->getSize().x/2,w->getSize().y/2))
{
    sound.setBuffer(Resources::buffer);

    finishLvl = false;
    success = false;
    menuIsActive = false;

    goal.setPosition(lvl.final);

    player.setSpeed(lvl.velocidad);
    player.setPosition(lvl.inicio);

    currentChameleon = nullptr;

    chameleons = std::vector<Chameleon>();
    for (uint i = 0; i < lvl.camaleon.size(); ++i) chameleons.push_back(Chameleon(lvl.camaleon[i]));

    //    chameleons.push_back(Chameleon(sf::Vector2f(200,200)));
    //    chameleons.push_back(Chameleon(sf::Vector2f(400,20)));
    //    chameleons.push_back(Chameleon(sf::Vector2f(100,600)));
    //    chameleons.push_back(Chameleon(sf::Vector2f(1000,800)));

}

Scene::~Scene() {}

bool Scene::update(float deltaTime){
    background.update(deltaTime);
    if (menuIsActive) return false;
    if (!player.isAlive()) {
        timeFromDeath += deltaTime;
        if (timeFromDeath > 0.5) {
            finishLvl = true;
            success = false;
        }
    }
    player.update(deltaTime);
    for (Chameleon &c : chameleons) c.update(deltaTime, player.getPosition());
    goal.update(deltaTime,player.getPosition());

    lookCollisions();
    return finishLvl;
}

void Scene::draw(){
    background.draw(*window);
    goal.draw(*window);
    player.draw(*window);
    for (Chameleon &c : chameleons) c.draw(*window);
    if (menuIsActive) iMenu.draw(*window);
}

void Scene::processEvents(){
    sf::Event event;
    while (window->pollEvent(event)) {
        if (menuIsActive) iMenu.handleEvent(event);
        switch (event.type) {
            case sf::Event::Closed:
                window->close();
                break;
            case  sf::Event::KeyPressed:
                //Close key
                if (event.key.code == sf::Keyboard::Escape) {
                    menuIsActive = !menuIsActive;
                }
                break;
            default:
                break;
        }
    }
    if (menuIsActive) {
        if (iMenu.wantToResume()) menuIsActive = false;
        else if (iMenu.wantToMenu()) goToMenu = true;
    }
    else {
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) activeChameleon(sf::Vector2f(sf::Mouse::getPosition(*window).x,sf::Mouse::getPosition(*window).y));
        else releaseChameleon();
    }
}

bool Scene::getSuccess() const {
    return success;
}

void Scene::releaseChameleon() {
    if (currentChameleon == nullptr) return;

    currentChameleon->release();
    currentChameleon = nullptr;
    player.setLicked(false,sf::Vector2f(0,0));
}

void Scene::activeChameleon(sf::Vector2f pos) {
    // TODO: elegir que chamaleon hay que elegir
    if (currentChameleon != nullptr) return;
    for (Chameleon &c : chameleons) {
        if (getModule(pos,c.getPosition()) < c.getRadius()) {
            currentChameleon = &c;
            sound.play();
            sound.setVolume(100);
            break;
        }
    }
    if (currentChameleon == nullptr) return;


    currentChameleon->lick();
    player.setLicked(true,currentChameleon->getPosition());
}

void Scene::lookCollisions() {
    sf::CircleShape playerBounds = player.getBox();
    for (Chameleon& c : chameleons) {
        if (isCollisioning(playerBounds.getPosition(),playerBounds.getRadius(),c.getPosition(),c.getRadius())) {
            //WOPS HA CHOCADO. DO THINGS
            if (player.isAlive()) {
                player.setAlive(false);
                timeFromDeath = 0;
                c.eating();
                return;
            }
        }
    }
    if (isCollisioning(playerBounds.getPosition(),playerBounds.getRadius(),goal.getPosition(),goal.getSize()/2)) {
        finishLvl = true;
        success = true;
    }
}


