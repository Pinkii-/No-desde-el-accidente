#ifndef EDITOR_HPP
#define EDITOR_HPP

#include "../Chameleon.hpp"
#include "../Goal.hpp"
#include "../Obstacle.hpp"
#include "../Player.hpp"
#include "../readlevels.hpp"
#include "../Background.hpp"


class Editor {
public:
  Editor(sf::RenderWindow &w);
  void run(sf::RenderWindow& window);
private:
  sf::RenderWindow* window;
  sf::View view;
  Background background;
  int currentLvl;
  // Elementos para poner en el nivel
  Chameleon camaleon1;
  Chameleon camaleon2;
  Goal goal;
  Obstacle obstacle;
  Player player;

  // Elementos en el nivel
  LevelManager levels;

  // Elementos en el current level
  std::vector<Chameleon> camaleones;
  std::vector<Obstacle> obstaculos;
  Goal go;
  Player pl;

  void setLevel(int lvl);
};

#endif // EDITOR_HPP
