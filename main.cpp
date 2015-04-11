#include <Resources.hpp>
#include <Scene.hpp>

int main() {
    sf::RenderWindow window(sf::VideoMode(sf::VideoMode::getFullscreenModes()[0].width,sf::VideoMode::getFullscreenModes()[0].height) // Size of the window <width,height>
            ,"Space Tongue" // Title of the window
            ,sf::Style::Default);
    Resources::load();
    Scene mygame(&window); // Style of the window
    mygame.run();
    return 0;
}

