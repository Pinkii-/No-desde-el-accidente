#include "Menu.hpp"
#include "Scene.hpp"
#include "Portada.hpp"
#include "readlevels.hpp"
#include "Resources.hpp"
#include "frases.hpp"
#include "Editor.hpp"

int main() {

    sf::RenderWindow window(sf::VideoMode::getDesktopMode() // Size of the window <width,height>
                            //  sf::RenderWindow window(sf::VideoMode(sf::VideoMode::getFullscreenModes()[0].width,sf::VideoMode::getFullscreenModes()[0].height) // Size of the window <width,height>

                            ,"Space Tongue" // Title of the window
                            ,sf::Style::Default);
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

    LevelManager lvlMng("res/levelsfile.txt");
    Editor editor(window, &lvlMng);
    Menu menu(&window);

    music.stop();

    if (!music.openFromFile("res/music.ogg")) std::cout << "fail on music2 load" << std::endl; // error
    music.play();
    music.setLoop(true);

    // Aqui tendrá que ir el menú {
    while (true) {
        int currentLvl = menu.run();
        if (currentLvl >= 0) {
            bool playing = true;
            while (playing) {
                Scene mygame(&window, lvlMng.getLevel(currentLvl)); // Style of the window
                playing = mygame.run();
                if (mygame.getSuccess()) {
                    currentLvl += 1;
                    if (currentLvl >= lvlMng.getNumLevels()) break;
                    else menu.setLevel(currentLvl);
                }
            }
        }
        else if (currentLvl == -1) { // Editor de niveles
            while (int status = editor.run()) {
                if (status == 1) {
                    Scene mygame(&window, lvlMng.getLevel(editor.getCurrentLvl()));
                    (void) mygame.run();
                }
            }
        }
    }
    music.stop();
    return 0;
}

