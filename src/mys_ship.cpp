#include "mys_ship.hpp"

mys_ship::mys_ship()
{
  image = LoadTexture("Graphics/mys.png");
  alive = false;
}

mys_ship::~mys_ship()
{
  UnloadTexture(image);
}

void mys_ship::Update()
{
  if(alive){
    position.x += speed;
    if(position.x > GetScreenWidth() - image.width - 25 || position.x < 25){
      alive = false;
    }
  }
}

void mys_ship::Draw()
{
  DrawTextureV(image, position, WHITE); 
}

void mys_ship::Spawn()
{
  position.y = 90;
  int side = GetRandomValue(0,1);
  if(side == 0){
    position.x = 25;
    speed = 3;
  }else{
    position.x = GetScreenWidth() - image.width - 25;  
    speed = -3;
  }
  alive = true;
}
