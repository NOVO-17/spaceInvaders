#pragma once
#include "spaceship.hpp"

class game{
private:
  void deleteInacticeLasers();
  Spaceship spaceship;
public:
  game();
  ~game();
  void draw();
  void update();
  void inputHandle();
};