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

#include <unistd.h>

typedef std::complex<double> point;

int my_stoi(std::string s);
float radToAngle(float rad);
float angleToRad(float angle);
float speedToRad(sf::Vector2f speed);

double prodesc(point p1,point p2);
double prodvec(point p1,point p2);

point vector2point(sf::Vector2f p);
sf::Vector2f point2vector(point p);

float getAngle(const sf::Vector2f &orig, const sf::Vector2f &des);
float getModule(const sf::Vector2f &orig, const sf::Vector2f &des);

bool isCollisioning(sf::Vector2f point1, float radius1, sf::Vector2f point2, float radius2);

const float animationTime = 0.2; //HARDCODED ALERT 2 the time needed to reach full length
const float scalePlayer = 0.5;

#endif // UTILS_HPP
