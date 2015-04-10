#ifndef UTILS_HPP
#define UTILS_HPP

//SFML (Simple Fast Media Library)
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

//STL (Standard Toolkit Library)
#include <cmath>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstring>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <map>
#include <complex>

typedef std::complex<double> point;

float radToAngle(float rad);
float angleToRad(float angle);
float speedToAngle(sf::Vector2f speed);

double prodesc(point p1,point p2);
double prodvec(point p1,point p2);

point vector2point(sf::Vector2f p);
sf::Vector2f point2vector(point p);

float getAngle(sf::Vector2f &orig, sf::Vector2f &des);
float getModule(sf::Vector2f &orig, sf::Vector2f &des);

#endif // UTILS_HPP
