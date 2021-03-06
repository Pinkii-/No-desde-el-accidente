#ifndef LEVELMANAGER_HPP
#define LEVELMANAGER_HPP

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <cstdlib>
#include "utils.hpp"

using namespace std;

struct Level {
  sf::Vector2f inicio,velocidad,final;
  vector<sf::Vector2f> camaleon;
  vector<sf::Vector2f> obstaculo;
  vector<int> tipocamaleon;
  bool iniciodefined,velocidaddefined,finaldefined;
  Level() {
    iniciodefined=velocidaddefined=finaldefined=false;
  }
};


class LevelManager {
private:
  string path;
  vector<Level> vl;

  bool isint(string s);
  float stof(string s);
  void checkwelldefined(int numlevel,Level level);
  void escribe(sf::Vector2f &v);

public:
  LevelManager();
  LevelManager(string path);
  int getNumLevels();
  Level getLevel(int i);
  void setLevel(int i, Level l);
  void escribe();
  void escribeAFichero();
};

#endif
