#include <Resources.hpp>
#include <Scene.hpp>
#include "Portada.hpp"

int main() {
    Resources::load();
    Portada portada;
    portada.display(window, "res/portada.png");
    Scene mygame(sf::VideoMode::getFullscreenModes()[0].width,sf::VideoMode::getFullscreenModes()[0].height // Size of the window <width,height>
            ,"Space Tongue" // Title of the window
            ,sf::Style::Default); // Style of the window
    mygame.run();
    return 0;
}

