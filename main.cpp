#include "Menu.hpp"
#include <Scene.hpp>
#include "Portada.hpp"
#include "readlevels.hpp"
#include <Resources.hpp>
#include "frases.hpp"

int main() {
    sf::RenderWindow window(sf::VideoMode::getDesktopMode() // Size of the window <width,height>
            ,"Space Tongue" // Title of the window
            ,sf::Style::Fullscreen);
    Resources::load();

    sf::Music music;
    if (!music.openFromFile("res/starwars.ogg")) std::cout << "fail on music load" << std::endl; // error
    music.play();
    sf::Time t1 = sf::seconds(21);
    music.setPlayingOffset(t1);

    Portada portada;
    portada.display(&window, "res/portada.png");

    Frases frases(window);
    frases.run(window);

    LevelManager lvlMng;

    Menu menu(&window);

    music.stop();

    if (!music.openFromFile("res/music.ogg")) std::cout << "fail on music2 load" << std::endl; // error
    music.play();
    music.setLoop(true);

    // Aqui tendrá que ir el menú {
    while (true) {
        int currentLvl = menu.run();
        bool playing = true;
        while (playing) {
            Scene mygame(&window, lvlMng.getLevel(currentLvl)); // Style of the window
            playing = mygame.run();
            if (mygame.getSuccess()) {
                system("echo > res/lastlevel.txt");
                currentLvl += 1;
                if (currentLvl >= lvlMng.getNumLevels()) break;
                else menu.setLevel(currentLvl);
            }
        }
    }
    music.stop();
    return 0;
}

