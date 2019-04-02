#include <SFML/Graphics.hpp>
#include <iostream>
#include <sstream>
#include <math.h>
#include "text.hpp"
#include "utilities.hpp"

int main(){
  sf::RenderWindow window(sf::VideoMode(1366, 768), "Finneon", sf::Style::Default);
  window.setFramerateLimit(60);

  //Make the font self-constructing in the future
  sf::Texture text;
  text.loadFromFile("fontT.png");

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
	writing myText("This is a test", 50, 50);
	myText.show(window, text);

    window.clear();

    window.display();
  }

  return 0;
}
