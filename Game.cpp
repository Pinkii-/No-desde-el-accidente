#include "Game.hpp"

Game::Game(sf::RenderWindow *w) {
    window = w;
}

Game::~Game() {}

void Game::run() {
    sf::Clock c;
    srand(time(0));
    while(window->isOpen()) {
        float deltaTime = c.restart().asSeconds();
        processEvents();
        update(deltaTime);
        render();
    }
}

void Game::render() {
    window->clear();
    draw();
    window->display();
}
