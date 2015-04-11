#include "Menu.hpp"
#include <Scene.hpp>
#include "Portada.hpp"
#include <Resources.hpp>

std::string levels[] = {
    "level1",
    "END"
};

int main() {
    sf::RenderWindow window(sf::VideoMode(sf::VideoMode::getFullscreenModes()[0].width,sf::VideoMode::getFullscreenModes()[0].height) // Size of the window <width,height>
            ,"Space Tongue" // Title of the window
            ,sf::Style::Default);
    Resources::load();
    Portada portada;
    portada.display(&window, "res/portada.png");

    Menu menu;
    // Aqui tendrá que ir el menú {
    int currentLvl = menu.run(&window);
    bool playing = true;
    while (playing) {
        Scene mygame(&window,levels[currentLvl]+".txt"); // Style of the window
        playing = mygame.run();
        if (mygame.getSuccess()) {
            currentLvl += 1;
            if (levels[currentLvl] == "END") break;
        }
    }
    // }
    return 0;
}

