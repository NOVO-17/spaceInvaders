#include "game.hpp"


game::game(){
  obstacles = createObstacle();
  aliens = createAliens();
  // mys_Ship.spawn();
  aliensDirection = 1;
  timeLastShootAlien = 0.0;
  lastSpawnTime = 0.0;
  mys_shipSpawnInterval = GetRandomValue(10, 20);
}

game::~game(){
  Alien::unloadImages();
}

void game::draw(){
  spaceship.Draw();
  mys_Ship.Draw();

  for(auto& Laser: spaceship.lasers){
    Laser.draw();
  }

  for(auto& obstacle: obstacles){
    obstacle.Draw();
  }

  for(auto& alien: aliens){
    alien.Draw();
  }

  for (auto& laser: alienLasers){
    laser.draw();
  }
}

void game::update(){

  deleteInacticeLasers();
  moveSideAliens();
  mys_Ship.Update();
  CheckForCollision();

  double GetCurrentTime = GetTime();
  if(GetCurrentTime - lastSpawnTime > mys_shipSpawnInterval){
    mys_Ship.spawn();
    lastSpawnTime = GetTime();
    mys_shipSpawnInterval = GetRandomValue(10,20);
  }
  for(auto& Laser: spaceship.lasers){
    Laser.update();
  }

  for (auto& laser: alienLasers){
    laser.update();
  }

}

void game::inputHandle(){
  if (IsKeyDown(KEY_LEFT)){
    spaceship.moveLeft();
  } else if (IsKeyDown(KEY_RIGHT)){
    spaceship.moveRight();
  } else if (IsKeyDown(KEY_SPACE)){
    spaceship.shoot();
  }
  
}

void game::deleteInacticeLasers(){
  for(auto it = spaceship.lasers.begin(); it != spaceship.lasers.end();){
    if(!it -> active){
      it = spaceship.lasers.erase(it);
    }else{
      ++it;
    }
  }

  for(auto it = alienLasers.begin(); it != alienLasers.end();){
    if(!it -> active){
      it = alienLasers.erase(it);
    }else{
      ++it;
    }
  }
}

std::vector<Obstacle> game::createObstacle()
{
  int obstacleWidth = Obstacle::grid[0].size() *3;
  float gap = (GetScreenWidth() - (4* obstacleWidth))/5;

  for (int i = 0; i < 4; i++){
    float offsetX = (i + 1)* gap + i *obstacleWidth;
    obstacles.push_back(Obstacle({offsetX, float(GetScreenHeight() - 200)}));
  }
  return obstacles ;
}

std::vector<Alien> game::createAliens()
{
  std::vector<Alien>aliens;
  for (int row = 0; row < 5; row++){
    for (int column = 0; column < 11; column++){
      int alienType;
      if(row == 0){
        alienType = 3;
      } else if (row == 1 || row == 2){
        alienType = 2;
      }else{
        alienType = 1;
      }
      
      float x = 75 + column * 55; // x = offset + column * cellsize 
      float y = 110 + row * 55;
      aliens.push_back(Alien(alienType,{x,y}));
    }
  }
  return aliens;
}

void game::moveSideAliens()
{
  for(auto& alien: aliens){
    if(alien.position.x + alien.alienImages[alien.type - 1].width > GetScreenWidth()){
      aliensDirection = -1;
      moveDownAliens(4);
    }
    if(alien.position.x < 0 ){
      aliensDirection = 1;
      moveDownAliens(4);
    }
    alien.Update(aliensDirection);
  }
}

void game::moveDownAliens(int distance)
{
  for(auto& alien: aliens){
    alien.position.y += distance;
  }
}

void game::alienShootLaser()
{
  double currentTime = GetTime();
  if(currentTime - timeLastShootAlien >= alienShootInterval && !aliens.empty()){
    int randomIndex = GetRandomValue(0,aliens.size() - 1);
    Alien& alien = aliens[randomIndex];
    alienLasers.push_back(Laser({alien.position.x + alien.alienImages[alien.type - 1].width/2,
                                alien.position.y + alien.alienImages[alien.type - 1].height},6));
    timeLastShootAlien = GetTime();
  }
}

void game::CheckForCollision()
{
  for(auto& laser: spaceship.lasers){
    auto it = aliens.begin();
    while (it != aliens.end()){
      if(CheckCollisionRecs(it -> getRect(), laser.getRect())){
        it = aliens.erase(it);
        laser.active = false;
      }else{
        ++it;
      }
    }
    
  }
}
