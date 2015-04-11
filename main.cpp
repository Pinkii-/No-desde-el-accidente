#include "Menu.hpp"
#include <Scene.hpp>
#include "Portada.hpp"
#include "readlevels.hpp"
#include <Resources.hpp>

int main() {
    sf::RenderWindow window(sf::VideoMode(sf::VideoMode::getFullscreenModes()[0].width,sf::VideoMode::getFullscreenModes()[0].height) // Size of the window <width,height>
            ,"Space Tongue" // Title of the window
            ,sf::Style::Fullscreen);
    Resources::load();
    Portada portada;
    portada.display(&window, "res/portada.png");

    LevelManager lvlMng;

    Menu menu;

    // Aqui tendrá que ir el menú {
    while (true) {
        int currentLvl = menu.run(&window);
        bool playing = true;
        while (playing) {
            Scene mygame(&window, lvlMng.getLevel(currentLvl)); // Style of the window
            playing = mygame.run();
            if (mygame.getSuccess()) {
                currentLvl += 1;
                if (currentLvl >= lvlMng.getNumLevels()) break;
            }
        }
    }
    return 0;
}

