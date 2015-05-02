#include "Editor.hpp"

Editor::Editor(sf::RenderWindow&w)
  :
    levels("res/levelsfile.txt"),
    background(w)
{
  window = &w;
  currentLvl = 0;
  setLevel(currentLvl);
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
    for (Chameleon &c : camaleones) c.draw(window);
    for (Obstacle &o : obstaculos) o.draw(window);
    pl.draw(window);
    go.draw(window);
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
  for (int i = 0; i < level.camaleon.size(); ++i) {
    p = level.camaleon[i];
    camaleones.push_back(Chameleon(p,level.tipocamaleon[i]));
    if (p.x < minX) minX = p.x;
    else if (p.x > maxX) maxX = p.x;
    if (p.y < minY) minY = p.y;
    else if (p.y > maxY) maxY = p.y;
  }
  obstaculos = std::vector<Obstacle>();
  for (int i = 0; i < level.obstaculo.size(); ++i) {
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
