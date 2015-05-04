#include "Editor.hpp"

Editor::Editor(sf::RenderWindow&w)
  :
    levels("res/levelsfile.txt"),
    background(w)
{
  window = &w;
  currentLvl = 0;
  setLevel(currentLvl);
  pincel = 0;
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
        case sf::Event::MouseButtonPressed: {
          sf::Vector2i pos = sf::Vector2i(event.mouseButton.x,event.mouseButton.y);
          sf::Vector2f newPos = window.mapPixelToCoords(pos,view);
          mousePressedAt(newPos);
          break;
        }
        case sf::Event::MouseWheelMoved:
          view.zoom(1+0.1*event.mouseWheel.delta);
          break;
        case sf::Event::KeyPressed:
          if (event.key.code >= sf::Keyboard::Num0 && event.key.code <= sf::Keyboard::Num5) {
            pincel = event.key.code - sf::Keyboard::Num0;
          }
          else if (event.key.code == sf::Keyboard::Escape) pincel = 0;
          break;
        default:
          break;
      }
    }
    window.clear();
    background.draw(window);
    window.setView(view);
    for (Chameleon &c : camaleones) c.draw(window);
    for (Obstacle &o : obstaculos) o.draw(window);
    pl.draw(window);
    go.draw(window);
    window.setView(window.getDefaultView());
    window.display();
  }
}

void Editor::setLevel(int lvl) {
  // ini lvl
  Level level = levels.getLevel(lvl);

  sf::Vector2f p;
  float maxX = window->getSize().x;
  float maxY = window->getSize().y-50;
  float minX, minY; minX = minY = 0;
  camaleones = std::vector<Chameleon>();
  for (uint i = 0; i < level.camaleon.size(); ++i) {
    p = level.camaleon[i];
    camaleones.push_back(Chameleon(p,level.tipocamaleon[i]));
    if (p.x < minX) minX = p.x;
    else if (p.x > maxX) maxX = p.x;
    if (p.y < minY) minY = p.y;
    else if (p.y > maxY) maxY = p.y;
  }
  obstaculos = std::vector<Obstacle>();
  for (uint i = 0; i < level.obstaculo.size(); ++i) {
    p = level.obstaculo[i];
    obstaculos.push_back(Obstacle(p));
    if (p.x < minX) minX = p.x;
    else if (p.x > maxX) maxX = p.x;
    if (p.y < minY) minY = p.y;
    else if (p.y > maxY) maxY = p.y;
  }
  p = level.final;
  go.setPosition(p);
  if (p.x < minX) minX = p.x;
  else if (p.x > maxX) maxX = p.x;
  if (p.y < minY) minY = p.y;
  else if (p.y > maxY) maxY = p.y;

  p = level.inicio;
  pl.setPosition(p);
  pl.setSpeed(level.velocidad);
  if (p.x < minX) minX = p.x;
  else if (p.x > maxX) maxX = p.x;
  if (p.y < minY) minY = p.y;
  else if (p.y > maxY) maxY = p.y;

  view.setCenter(minX+(maxX-minX)/2,minY+(maxY-minY)/2);
  view.setSize(window->getSize().x,window->getSize().y);
  window->setView(view);
}

void Editor::mousePressedAt(sf::Vector2f pos) {
  switch (pincel) {
    case 0: // Nada seleccionado para ponerlo en el mapa. Se puede seleccionar cosas del mapa.

      break;
    case 1: // Principio
      pl.setPosition(pos);
      break;
    case 2: // Final
      go.setPosition(pos);
      break;
    case 3: // Camaleon 1
      camaleones.push_back(Chameleon(pos,0));
      break;
    case 4: // Camaleon 2
      camaleones.push_back(Chameleon(pos,1));
      break;
    case 5: // Obstaculo
      obstaculos.push_back(Obstacle(pos));
      break;
    default:
      break;
  }
}
