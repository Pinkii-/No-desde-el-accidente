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


float speedToAngle(sf::Vector2f speed);
float radToAngle(float rad);
float angleToRad(float angle);

typedef std::complex<double> point;

point vector2point(sf::Vector2f p);
sf::Vector2f point2vector(point p);
double prodesc(point p1,point p2);
double prodvec(point p1,point p2);


#endif // UTILS_HPP
