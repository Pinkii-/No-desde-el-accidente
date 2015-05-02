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
    obstacles = std::vector<Obstacle>();
    for (uint i = 0; i < lvl.obstacle.size(); ++i) obstacles.push_back(Obstacle(lvl.obstacle[i]));

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

    float offset = 50;
    std::vector<sf::Vector2f> positions;
    positions.push_back(goal.getPosition());
    for(Chameleon &c : chameleons) positions.push_back(c.getPosition());
    float maxX, minX, maxY, minY;
    maxX = player.getPosition().x+offset;
    minX = player.getPosition().x-offset;
    maxY = player.getPosition().y+offset;
    minY = player.getPosition().y-offset;
    for(int i = 0; i < positions.size(); ++i){
        //maxX = max(maxX, positions[i].x + offset);
        if(positions[i].x+offset > maxX) maxX = positions[i].x+offset;
        if(positions[i].x-offset < minX) minX = positions[i].x-offset;
        if(positions[i].y+offset > maxY) maxY = positions[i].y+offset;
        if(positions[i].y-offset < minY) minY = positions[i].y-offset;
    }

    float escalatX, escalatY;
    escalatX = window->getSize().x/(maxX-minX);
    escalatY = window->getSize().y/(maxY-minY);
    viewScale = std::min(escalatX, escalatY);
    view.setCenter((maxX+minX)/2, (maxY+minY)/2);
    view.setSize(window->getSize().x/viewScale, window->getSize().y/viewScale);

    return finishLvl;

}

void Scene::draw(){
    window->setView(view);
    background.draw(*window);
    goal.draw(*window);
    player.draw(*window);
    for (Chameleon &c : chameleons) c.draw(*window);
    for (Obstacle &o : obstacles) o.draw(*window);
    window->setView(window->getDefaultView());
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
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {

            sf::Vector2f mouse;
            mouse.x = view.getCenter().x + (sf::Mouse::getPosition(*window).x - window->getSize().x/2.0) / viewScale;
            mouse.y = view.getCenter().y + (sf::Mouse::getPosition(*window).y - window->getSize().y/2.0) / viewScale;

            activeChameleon(sf::Vector2f( mouse.x, mouse.y));
        }
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


