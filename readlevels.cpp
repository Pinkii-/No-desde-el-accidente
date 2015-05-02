#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <cstdlib>

#include "readlevels.hpp"

using namespace std;

/*
git add -A
git commit -m "cogiendo datos"
git pull
git push origin master 

 */

bool my_isint(string s)
{
  for (int i=0;i<int(s.size());i++)
    if (not (s[i]>='0' and s[i]<='9'))
      return false;
  return true;
}

float my_stof(string s) {
  int x=0;
  for (int i=0;i<int(s.size());i++)
    x=10*x+s[i]-'0';
  return float(x);
}

void LevelManager::checkwelldefined(int numlevel,Level level)
{
  if (not level.iniciodefined) {
    cout<<"Level "<<numlevel<<" with no inicio defined."<<endl;
    exit(0);
  } else if (not level.finaldefined) {
    cout<<"Level "<<numlevel<<" with no final defined."<<endl;
    exit(0);
  } else if (not level.velocidaddefined) {
    cout<<"Level "<<numlevel<<" with no velocidad defined."<<endl;
    exit(0);
  } else if (int(level.camaleon.size())==0) {
    cout<<"Level "<<numlevel<<" with no camaleon."<<endl;
    exit(0);
  }
}

LevelManager::LevelManager(std::string path)
{
  ifstream fci(path);
  if (not fci.is_open()) {
    cout<<"ERROR opening levelsfile.txt"<<endl;
    exit(0);
  }
  vector<pair<int,string> > vs;
  {
    int numlinea=0;
    string linea;
    while (getline(fci,linea)) {
      numlinea++;
      {
        for (int i=0;i<int(linea.size())-1;i++) {
          if (linea[i]=='/' and linea[i+1]=='/') {
            linea=linea.substr(0,i);
            break;
          }
        }
      }
      istringstream ci(linea);
      {
        string s;
        while(ci>>s)
          vs.push_back(pair<int,string> (numlinea,s));
      }
    }
  }
  vl.push_back(Level());
  for (int i=0;i<int(vs.size());i++) {
    int numlinea=vs[i].first;
    string comando=vs[i].second;
    if (comando=="nuevonivel") {
      checkwelldefined(int(vl.size())-1,vl.back());
      vl.push_back(Level());
      continue;
    }
    Level &level=vl.back();
    if (comando!="inicio" and comando!="final" and
        comando!="velocidad" and comando!="camaleon" and comando!="obstaculo") {
      cout<<"Error line "<<numlinea<<": wrong instruction "<<comando<<"."<<endl;
      exit(0);
    }
    /*
    if (comando=="camaleon" and (i+3>=int(vs.size()) or not my_isint(vs[i+1].second) or not my_isint(vs[i+2].second) or not my_isint(vs[i+3].second))) {
      cout<<"Error line "<<numlinea<<": three integers are needed for "<<comando<<"."<<endl;
      exit(0);
    }
    */
    if (i+2>=int(vs.size()) or not my_isint(vs[i+1].second) or not my_isint(vs[i+2].second)) {
      cout<<"Error line "<<numlinea<<": two integers are needed for "<<comando<<"."<<endl;
      exit(0);
    }
    sf::Vector2f p(my_stof(vs[i+1].second),my_stof(vs[i+2].second));
    if (comando=="inicio") {
      if (level.iniciodefined) {
        cout<<"Error line "<<numlinea<<": inicio already defined."<<endl;
        exit(0);
      }
      level.iniciodefined=true;
      level.inicio=p;
      i+=2;
    } else if (comando=="final") {
      if (level.finaldefined) {
        cout<<"Error line "<<numlinea<<": final already defined."<<endl;
        exit(0);
      }
      level.finaldefined=true;
      level.final=p;
      i+=2;
    } else if (comando=="velocidad") {
      if (level.velocidaddefined) {
        cout<<"Error line "<<numlinea<<": velocidad already defined."<<endl;
        exit(0);
      }
      level.velocidaddefined=true;
      level.velocidad=p;
      i+=2;
    } else if (comando=="camaleon") {
      level.camaleon.push_back(p);
      if (i+3<int(vs.size()) and my_isint(vs[i+3].second)) {
        level.tipocamaleon.push_back(my_stoi(vs[i+3].second));
        i+=3;
      } else {
        level.tipocamaleon.push_back(0);
        i+=2;
      }
      //i++;
    } else if (comando=="obstaculo") {
      level.obstaculo.push_back(p);
      i+=2;
    }
  }
  checkwelldefined(int(vl.size()),vl.back());
}

int LevelManager::getNumLevels()
{
  return int(vl.size());
}

Level LevelManager::getLevel(int i)
{
  return vl[i];
}

void LevelManager::escribe(sf::Vector2f &v)
{
  cout<<v.x<<" "<<v.y<<endl;
}

void LevelManager::escribe()
{
  for (int i=0;i<int(vl.size());i++) {
    cout<<"Level "<<i<<endl;
    Level &level=vl[i];
    cout<<"inicio ";escribe(level.inicio);
    cout<<"final ";escribe(level.final);
    cout<<"velocidad ";escribe(level.velocidad);
    for (int j=0;j<int(level.camaleon.size());j++) {
      cout<<"camaleon ";
      escribe(level.camaleon[j]);
    }
    cout<<endl;
  }
}

//LevelManager levelManager;

//int main()
//{
//  levelManager.escribe();
//}
