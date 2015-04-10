#include <Resources.hpp>
#include <Scene.hpp>

int main() {
    Resources::load();
    Scene mygame(sf::VideoMode::getFullscreenModes()[0].width,sf::VideoMode::getFullscreenModes()[0].height // Size of the window <width,height>
            ,"Scene" // Title of the window
            ,sf::Style::Default); // Style of the window
    mygame.run();
    return 0;
}

