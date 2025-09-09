#pragma once
#include "spaceship.hpp"
#include "obstacle.hpp"
#include "alien.hpp"

class game{
private:
  Spaceship spaceship;
  std::vector<Obstacle> createObstacle();
  std::vector<Alien> createAliens();
  void deleteInacticeLasers();
  void moveSideAliens();
  void moveDownAliens(int distance);
  void alienShootLaser();
  std::vector<Obstacle> obstacles;
  std::vector<Alien> aliens;
  std::vector<Laser> alienLasers;
  int aliensDirection;
  constexpr static float alienShootInterval = 0.35;
  float timeLastShootAlien;

public:
  game();
  ~game();
  void draw();
  void update();
  void inputHandle();
};