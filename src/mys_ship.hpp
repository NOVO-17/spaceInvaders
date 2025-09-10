#pragma once 
#include <raylib.h>

class mys_ship{
  public:
  mys_ship();
  ~mys_ship();
  void Update();
  void Draw();
  void Spawn();
  bool alive;
private:
  Vector2 position;
  int speed;
  Texture2D image;
};