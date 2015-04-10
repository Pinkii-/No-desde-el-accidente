#ifndef MYGAME_H
#define MYGAME_H
#include "Game.hpp"

class MyGame : public Game {
public:
    MyGame(int scrwidth, int scrheight, std::string title, int style);
    ~MyGame();
    void update(float deltaTime);
    void draw();
    void processEvents();
private:
    //The components of the game
};

#endif // MYGAME_H
