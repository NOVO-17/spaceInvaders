#include "game.hpp"


game::game(){
  obstacles = createObstacle();
}

game::~game(){

}

void game::draw(){
  spaceship.Draw();

  for(auto& Laser: spaceship.lasers){
    Laser.draw();
  }

  for(auto& obstacle: obstacles){
    obstacle.Draw();
  }
}

void game::update(){
  for(auto& Laser: spaceship.lasers){
    Laser.update();
  }
  deleteInacticeLasers();
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
}

std::vector<Obstacle> game::createObstacle()
{
  int obstacleWidth = Obstacle::grid[0].size() *3;
  float gap = (GetScreenWidth() - (4* obstacleWidth))/5;

  for (int i = 0; i < 4; i++){
    float offsetX = (i + 1)* gap + i *obstacleWidth;
    obstacles.push_back(Obstacle({offsetX, float(GetScreenHeight() - 100)}));
  }
}
