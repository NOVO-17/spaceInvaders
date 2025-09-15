#pragma once
#include <raylib.h>

class Alien
{
private:
public:
  Alien(int type, Vector2 position);
  void Update(int direction);
  void Draw();
  int GetType();
  int type;
  static void unloadImages();
  static Texture2D alienImages[3];
  Vector2 position;
  Rectangle getRect();
};