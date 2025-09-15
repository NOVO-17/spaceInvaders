#pragma once
#include <raylib.h>
#include "laser.hpp"
#include <vector>

class Spaceship{
  public:
    Spaceship();
    ~Spaceship();
    void Draw();
    void moveLeft();
    void moveRight();
    void shoot();
    Rectangle getRect();
    std::vector<Laser> lasers;

  private:
    Texture2D image;
    Vector2 position;
    double lastFireTime;
};