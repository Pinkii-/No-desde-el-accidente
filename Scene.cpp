#include "Scene.hpp"

Scene::Scene(int scrwidth, int scrheight, std::string title, int style)
    : Game(scrwidth,scrheight,title,style) {
    //Create the components of the game and init them
}

Scene::~Scene() {}

void Scene::update(float deltaTime){
    // Update the game
}

void Scene::draw(){
    // Draw the game
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
