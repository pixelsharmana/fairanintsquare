#ifndef NPC_H
#define NPC_H

#include "tiles.hpp"

struct npc: public tile{
private:
  std::string name="";
  unsigned int speed=1;
  int maxSpeed=6;
  unsigned int runningSpeed=6;
public:
  unsigned int getSpeed(){
    return speed;
  }

  void setSpeed(unsigned int input){
    speed=input;
  }

  unsigned int getRunningSpeed(){
    return runningSpeed;
  }

  void setRunningSpeed(unsigned int input){
    runningSpeed=input;
  }

  void setName(std::string input){
    name=input;
  }

  //Put movement in private
  sf::Vector2f movement={0, 0};
  bool running=0;

  virtual void up(){
    movement.y-=speed+(runningSpeed*running+1);
    if(movement.y<-maxSpeed){
      movement.y=-maxSpeed;
    }
    base.setTextureRect(sf::IntRect(17+16, 0, 16, 16));
  }

  virtual void down(){
    movement.y+=speed+(runningSpeed*running+1);
    if(movement.y>maxSpeed){
      movement.y=maxSpeed;
    }
    base.setTextureRect(sf::IntRect(0, 0, 16, 16));
  }

  virtual void left(){
    movement.x-=speed+(runningSpeed*running+1);
    if(movement.x<-maxSpeed){
      movement.x=-maxSpeed;
    }
    base.setTextureRect(sf::IntRect(17, 0, 16, 16));
    scale(1, 1);
  }

  void right(){
    movement.x+=getSpeed()+(getRunningSpeed()*running+1);
    if(movement.x>maxSpeed){
      movement.x=maxSpeed;
    }
    base.setTextureRect(sf::IntRect(17, 0, 16, 16));
    scale(-1, 1);
  }

  void stop(){
    movement.x=0;
    movement.y=0;
  }

  //Scaling is only ever used to flip the texture
  void scale(int t_x, int t_y){
    base.setScale(t_x, t_y);
  }

  // void say(std::string &input, sf::RenderWindow &window, const sf::Texture &font){
  //   writing output(input, getXPos()+15, getYPos()-20);
  //   output.show(window, font);
  // }

  npc(){
    base.setSize(sf::Vector2f(16, 16));
    //Origin to center to facilitate texture flipping
    base.setOrigin(8, 8);
  }

  npc(int t_x, int t_y){
    base.setSize(sf::Vector2f(16, 16));
    base.move(sf::Vector2f(t_x, t_y));
    //Origin to center to facilitate texture flipping
    base.setOrigin(8, 8);
  }

  npc(int t_x, int t_y, std::string input){
    base.setSize(sf::Vector2f(16, 16));
    base.move(sf::Vector2f(t_x, t_y));
    //Origin to center to facilitate texture flipping
    base.setOrigin(8, 8);
    name=input;
  }

  npc(std::string input){
    base.setSize(sf::Vector2f(16, 16));
    base.setOrigin(8, 8);
    name=input;
  }
};

#endif
