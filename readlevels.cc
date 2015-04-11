#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <cstdlib>

using namespace std;

int stoi(string s) {
  int x=0;
  for (int i=0;i<int(s.size());i++)
    x=10*x+s[i]-'0';
  return x;
}

struct Level {
  Vector2f inicio,velocidad,final;
  vector<Vector2f> camaleon;
  bool iniciodefined,velocidaddefined,finaldefined;
  Level() {
    iniciodefined=velocidaddefined=finaldefined=false;
  }
};


class LevelManager {
Private:

  vector<Level> vl;

  bool isint(string s)
  {
    for (int i=0;i<int(s.size());i++)
      if (not (s[i]>='0' and s[i]<='9'))
	return false;
    return true;
  }

  float stof(string s) {
    int x=0;
    for (int i=0;i<int(s.size());i++)
      x=10*x+s[i]-'0';
    return float(x);
  }

  void checkwelldefined(int numlevel,Level level)
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

Public:
  LevelManager() {
    ifstream fci("levelsfile.txt");
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
	  for (int i=0;i<linea-1;i++) {
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
	checkwelldefined(int(vl.size()),vl.back());
	vl.push_back();
	continue;
      }
      Level &level=vl.back();
      if (comando!="inicio" and comando!="final" and
	  comando!="velocidad" and comando!="camaleon") {
	cout<<"Error line "<<numlinea<<": wrong instruction "<<comando<<"."<<endl;
	exit(0);
      }
      if (i+2>=int(vs.size()) or not isint(vs[i+1].second) or not isint(vs[i+2].second)) {
	cout<<"Error line "<<numlinea<<": two integers are needed for "<<comando<<"."<<endl;
	exit(0);
      }
      int x=vs[i+1].second;
      if (comando=="inicio") {
	if (level.iniciodefined) {
	  cout<<"Error line "<<numlinea<<": inicio already defined."<<endl;
	  exit(0);
	}
	level.iniciodefined=true;
	level.inicio=Vector2f(stof(vs[i+1],stof(vs[i+2])));
      } else if (comando=="final") {
	if (level.finaldefined) {
	  cout<<"Error line "<<numlinea<<": final already defined."<<endl;
	  exit(0);
	}
	level.finaldefined=true;
	level.final=Vector2f(stof(vs[i+1],stof(vs[i+2])));
      } else if (comando=="velocidad") {
	if (level.velocidaddefined) {
	  cout<<"Error line "<<numlinea<<": velocidad already defined."<<endl;
	  exit(0);
	}
	level.velocidaddefined=true;
	level.velocidad=Vector2f(stof(vs[i+1],stof(vs[i+2])));
      } else if (comando=="camaleon") {
	level.camaleon.push_back(Vector2f(stof(vs[i+1],stof(vs[i+2]))));
      }
      i++;i++;
    }
    checkwelldefined(int(vl.size()),vl.back());
  }

  int getNumLevels()
  {
    return int(vl.size());
  }

  Level getLevel(int i)
  {
    return vl[i];
  }

  void escribe()
  {
    for (int i=0;i<int(vl.size());i++) {
      cout<<
    }
  }
};

int main()
{
}
