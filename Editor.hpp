#ifndef EDITOR_HPP
#define EDITOR_HPP

#include "Chameleon.hpp"
#include "Goal.hpp"
#include "Obstacle.hpp"
#include "Player.hpp"
#include "readlevels.hpp"
#include "Background.hpp"


class Editor {
public:
  Editor(sf::RenderWindow &w, LevelManager *lm);
  int run();
  Level getCurrentLvl();
private:
  // Current lvl info
  int currentLvl;
  sf::Text tCurrentLvl;
  bool saved;
  sf::CircleShape sSave;
  // Pincel info
  int pincel;

  // Mover la pantalla
  bool control;
  bool mousePressed;
  sf::Vector2f moveCamera;

  // Dibujar
  sf::RenderWindow* window;
  sf::View view;
  Background background;

  // Elementos para poner en el nivel
  Chameleon camaleon1;
  Chameleon camaleon2;
  Goal goal;
  Obstacle obstacle;
  Player player;

  // Elementos en el nivel
  LevelManager* levels;

  // Elementos en el current level
  std::vector<Chameleon> camaleones;
  std::vector<Obstacle> obstaculos;
  Goal go;
  Player pl;

  void setLevel(int lvl);
  void mousePressedAt(sf::Vector2f pos);
  void saveLvl();
};

#endif // EDITOR_HPP
