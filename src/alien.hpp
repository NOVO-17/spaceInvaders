#pragma once
#include <raylib.h>

class Alien
{
private:
public:
  Alien(int type, Vector2 position);
  ~Alien();
  void Update(int direction);
  void Draw();
  int GetType();
  static void unloadImages();
  static Texture2D alienImages[3];
  int type;
  Vector2 position;
};