#pragma once
#include "spaceship.hpp"
#include "obstacle.hpp"
#include "alien.hpp"
#include "mys_ship.hpp"

class game{
private:
  Spaceship spaceship;
  mys_ship mys_Ship;
  std::vector<Obstacle> createObstacle();
  std::vector<Alien> createAliens();
  void deleteInacticeLasers();
  void moveSideAliens();
  void moveDownAliens(int distance);
  void alienShootLaser();
  void CheckForCollision();
  void GameOver();
  void Reset();
  void InitGame();
  void CheckHighScore();
  std::vector<Obstacle> obstacles;
  std::vector<Alien> aliens;
  std::vector<Laser> alienLasers;
  int aliensDirection;
  constexpr static float alienShootInterval = 0.35;
  float timeLastShootAlien;
  float mys_shipSpawnInterval;
  float lastSpawnTime;

public:
  game();
  ~game();
  void draw();
  void update();
  void inputHandle();
  bool run;
  int lives;
  int score;
  int HighScore;
};