#include "Editor.hpp"

Editor::Editor(sf::RenderWindow&w)
  :
    levels("../res/levelsfile.txt"),
    background(w)
{
  currentLvl = 0;
}

void Editor::run(sf::RenderWindow &window) {
  while (window.isOpen()) {
    sf::Event event;
    while (window.pollEvent(event)) {
      switch (event.type) {
        case sf::Event::Closed:
          window.close();
          exit(0);
          break;
        case sf::Event::MouseButtonPressed:
          break;
        default:
          break;
      }
    }
    window.clear();
    background.draw(window);
    window.display();
  }
}
