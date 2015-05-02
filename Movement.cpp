#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include <iostream>
#include <complex>

using namespace std;

typedef complex<double> point;

point vector2point(sf::Vector2f p)
{
  return point(double(p.x),double(p.y));
}

sf::Vector2f point2vector(point p)
{
  return sf::Vector2f(float(real(p)),float(imag(p)));
}

double prodesc(point p1,point p2)
{
  return real(conj(p1)*p2);
}

double prodvec(point p1,point p2)
{
  return imag(conj(p1)*p2);
}

//bool licked,tensioning;
//sf::Vector2f pos,speed,camaleonPos;

void evoluciona(float fdelta)
{
  double delta=fdelta;
  point p=vector2point(pos);
  point v=vector2point(speed);
  point c=vector2point(camaleonPos);
  if (not licked) {
    p+=v*delta;
    pos=point2vector(p);
    return;
  }
  if (not tensioning) {
    p+=v*delta;
    pos=point2vector(p);
    if (prodesc(v,p-c)>=0)
      tensioning=true;
    return;
  }
  p-=c;
  double modulov=abs(v);
  double desp=modulov*delta;
  double r=abs(p);
  double alfa=desp/r;
  int signo=prodvec(p,v)>0?1:-1;
  p*=polar(1.0,signo*alfa);
  v=p*polar(1.0,signo*M_PI/2.0);
  v=(modulov/abs(v))*v;
  p+=c;
  pos=point2vector(p);
  speed=point2vector(v);
}

int main()
{
}
