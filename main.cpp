#include <SFML/Graphics.hpp>
#include <iostream>
#include <sstream>
#include <math.h>
#include "text.hpp"
#include "utilities.hpp"
//#include "npc.hpp"

int main(){
  sf::RenderWindow window(sf::VideoMode(1366, 768), "Fair ain't square", sf::Style::Default);
  window.setFramerateLimit(60);

  //Make the font self-constructing in the future
  sf::Texture text;
  text.loadFromFile("./fontT.png");

  //Placeholder square, at least show something on screen
  sf::RectangleShape square(sf::Vector2f(150.0, 150.0));
  square.setSize(sf::Vector2f(100.0, 100.0));
  square.setFillColor(sf::Color(25, 255, 25));
  square.setPosition(sf::Vector2f(150.0, 150.0));

  while (window.isOpen()){
    sf::Event event;

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
      window.close();
    }

    while (window.pollEvent(event)){
      //If the window is resized, make sure our new view is still proportional
      if(event.type==sf::Event::Resized){
		sf::FloatRect visibleArea(0,0,event.size.width, event.size.height);
		window.setView(sf::View(visibleArea));
      }

      //If the window is closed, well, close the window
      if (event.type==sf::Event::Closed){
		window.close();
      }
    }
	window.clear();
	writing myText("This is a test", 50, 50);
	myText.show(window, text);
	window.draw(square);

    window.display();
  }

  return 0;
}
