#include <iostream>
#include "../utils.hpp"
#include "../Resources.hpp"
#include "Editor.hpp"

int main() {
  sf::RenderWindow window(sf::VideoMode(sf::VideoMode::getFullscreenModes()[0].width,sf::VideoMode::getFullscreenModes()[0].height) // Size of the window <width,height>
          ,"Space Tongue" // Title of the window
          ,sf::Style::Default);
  Resources::load();

  Editor editor(window);
  editor.run(window);

  return 0;
}

