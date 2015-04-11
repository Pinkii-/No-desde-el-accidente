#include "Game.hpp"

Game::Game(sf::RenderWindow *w) {
    window = w;
}

Game::~Game() {}

bool Game::run() {
    sf::Clock c;
    srand(time(0));
    while(window->isOpen()) {
        float deltaTime = c.restart().asSeconds();
        processEvents();
        if (update(deltaTime)) return true;
        render();
    }
    return false;
}

void Game::render() {
    window->clear();
    draw();
    window->display();
}
