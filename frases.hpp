#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <cstdlib>

using namespace std;

class Frases {

private:

  sf::Font font;
  vector<string> frases;
  float tiempo;
  float velocidad;

  float computaEscala(float h,float despobjeto);

  void dibujafrase(int centropantalla,int hobservador,int despobservador,
		   int numfrase,int desp,int hcaracter,string &frase,sf::RenderWindow &window);

public:

  Frases();

  void dibujafrases(int centropantalla,int hobservador,int despobservador,int hcaracter,
		    sf::RenderWindow &window,float delta);

  void run(sf::RenderWindow & window);
};
