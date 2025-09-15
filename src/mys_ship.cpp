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

void mys_ship::Draw()
{
  if(alive){
    DrawTextureV(image, position, WHITE);
  }
}

void mys_ship::Update()
{
  if(alive){
    position.x += speed;
    if(position.x > GetScreenWidth() - image.width || position.x < 0 ){
      alive = false;
    }
  }
}

void mys_ship::spawn()
{
  position.y = 90;
  int side = GetRandomValue(0,1);

  if(side == 0 ){
    position.x = 0;
    speed = 3;
  }else{
    position.x = GetScreenWidth() - image.width;
    speed = -3;
  }
  alive = true;
}

Rectangle mys_ship::getRect()
{
  if(alive){
    return{position.x, position.y, float(image.width), float(image.height)};
  }
}
