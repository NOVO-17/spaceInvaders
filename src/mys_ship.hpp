#pragma once
#include <raylib.h>

class mys_ship{
  public:
    mys_ship();
    ~mys_ship();
    void Draw();
    void Update();
    void spawn();
    bool alive;
    Rectangle getRect();
  private:
    int speed;
    Vector2 position;
    Texture2D image;
};