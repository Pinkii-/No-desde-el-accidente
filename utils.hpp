#ifndef UTILS_HPP
#define UTILS_HPP

//SFML (Simple Fast Media Library)
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

//STL (Standard Toolkit Library)
#include <map>
#include <list>
#include <cmath>
#include <stack>
#include <queue>
#include <string>
#include <vector>
#include <complex>
#include <cstring>
#include <fstream>
#include <sstream>
#include <iostream>

typedef std::complex<double> point;

float radToAngle(float rad);
float angleToRad(float angle);
float speedToAngle(sf::Vector2f speed);

double prodesc(point p1,point p2);
double prodvec(point p1,point p2);

point vector2point(sf::Vector2f p);
sf::Vector2f point2vector(point p);

float getAngle(const sf::Vector2f &orig, const sf::Vector2f &des);
float getModule(const sf::Vector2f &orig, const sf::Vector2f &des);

#endif // UTILS_HPP
