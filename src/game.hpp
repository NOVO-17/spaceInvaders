#pragma once
#include "spaceship.hpp"
#include "obstacle.hpp"

class game{
private:
  void deleteInacticeLasers();
  std::vector<Obstacle> createObstacle();
  Spaceship spaceship;
  std::vector<Obstacle> obstacles;
public:
  game();
  ~game();
  void draw();
  void update();
  void inputHandle();
};