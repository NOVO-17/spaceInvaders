#include "game.hpp"


game::game()
{
}

game::~game(){

}

void game::draw(){
  spaceship.Draw();

  for(auto& Laser: spaceship.lasers){
    Laser.draw();
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