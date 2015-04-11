#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <cstdlib>

#include "frases.hpp"

using namespace std;


float Frases::computaEscala(float h,float despobjeto)
{
    return h/despobjeto;
}

void Frases::dibujafrase(int centropantalla,int hobservador,int despobservador,
                         int numfrase,int desp,int hcaracter,string &frase,sf::RenderWindow &window)
{
  float factor=3.0;

  float despobjeto=desp-(hcaracter+10)*numfrase;
  if (despobjeto<despobservador/2.0) return;
  hobservador-=despobjeto*factor;
  float escala=computaEscala(float(hobservador),despobjeto-despobservador);
  float escalacaracter=computaEscala(float(hobservador),40+despobjeto-despobservador);
  sf::Text text;
  text.setString(frase);
  text.setFont(font);
  
  
  float hfrase=escala*despobjeto;
  float midahfrase=escalacaracter*hcaracter;
  text.setOrigin(sf::Vector2f(text.getLocalBounds().width/2.0,text.getLocalBounds().height/2.0));
  text.setScale(sf::Vector2f(midahfrase/(1.7*text.getLocalBounds().height),midahfrase/text.getLocalBounds().height));
  text.setPosition(sf::Vector2f(float(centropantalla),hobservador-hfrase));

  //text.setPosition(sf::Vector2f(float(centropantalla),0));
  
  window.draw(text);
}


Frases::Frases()
{
    tiempo=0;
    velocidad=24;
    if (!font.loadFromFile("res/font.otf")) {
        cout<<"no carrega la font"<<endl;
        exit(0);
    }
    ifstream fci("res/frases.txt");
    if (not fci.is_open()) {
        cout<<"ERROR opening frases.txt"<<endl;
        exit(0);
    }
    string linea;
    while (getline(fci,linea))
        frases.push_back(linea);
}

void Frases::dibujafrases(int centropantalla,int hobservador,int despobservador,int hcaracter,
                          sf::RenderWindow &window,float delta)
{
    tiempo+=delta;
    int desp=50+tiempo*velocidad;
    for (int i=0;i<int(frases.size());i++)
        dibujafrase(centropantalla,hobservador,despobservador,i,desp,hcaracter,frases[i],window);
}

void Frases::run(sf::RenderWindow & window)
{
    sf::Clock c;
    while(window.isOpen() && tiempo < 15) {
        float deltaTime = c.restart().asSeconds();
        sf::Event event;
        while(window.pollEvent(event)) {
            if (event.type == sf::Event::Closed ||
                    ((event.type == sf::Event::KeyPressed) &&
                     (event.key.code == sf::Keyboard::Escape)))
            {
                return;
            }
        }
        window.clear();
        dibujafrases(window.getSize().x/2.0,window.getSize().y+100,-100,20,window,deltaTime);
        window.display();
    }
}
