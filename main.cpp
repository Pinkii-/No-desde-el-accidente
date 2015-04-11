#include <Resources.hpp>
#include <Scene.hpp>
#include "Portada.hpp"

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

    // Aqui tendrá que ir el menú {
    int currentLvl = 0;
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

