#ifndef TEXT_H
#define TEXT_H

const extern std::map <char, int> letters={
  {'a', 0}, {'b', 3}, {'c', 6}, {'d', 9}, {'e', 12}, {'f', 15}, {'g', 18},
  {'h', 21}, {'i', 24}, {'j', 27}, {'k', 30}, {'l', 33}, {'m', 36}, {'n', 39},
  {'o', 42}, {'p', 45}, {'q', 48}, {'r', 51}, {'s', 54}, {'t', 57}, {'u', 60},
  {'v', 63}, {'w', 66}, {'x', 69}, {'y', 72}, {'z', 75}, {'1', 78}, {'2', 81},
  {'3', 84}, {'4', 87}, {'5', 90}, {'6', 93}, {'7', 96}, {'8', 99}, {'9', 102},
  {'!', 105}, {'?', 108}, {'+', 111}, {'-', 114}, {'>', 117}, {':', 120}, {' ', 123}
};

class writing{
private:
  std::string text="";
  int posX=0;
  int posY=0;
  unsigned int sizeX=0;
  unsigned int sizeY=0;

  std::vector<sf::Sprite> writeCharacters(const sf::Texture &font){
    int originalX=posX;
    std::vector<sf::Sprite> container;
    for(auto &it:text){
      if(it=='\n'){
	posX=originalX;
	posY+=6;
      }
      else{
	sf::Sprite temp;
	temp.setTexture(font);
	temp.setTextureRect(sf::IntRect(letters.at(it), 0, 3, 5));
	temp.setPosition(sf::Vector2f(posX, posY));
	posX+=4;
	container.push_back(temp);
      }
    }
    return container;
  }

public:
  void setString(const std::string &input){
    text=input;
    for(auto &it:text){
      it=std::tolower(it);
    }
    unsigned int counter=0;
    for(auto &it:text){
      //Breaks reset the lenght counter
      if(it=='\n'){
	counter=0;
	//Each character is 5 pixels high plus 1 pixel accounting for the space between letters
	sizeY+=6;
      }
      else{
	counter++;
	if(counter>sizeX){
	  sizeX++;
	}
      }
    }
    //Each character is 3 pixels long plus 1 pixel accounting for the space between letters
    sizeX*=4;
  }

  std::string getString(){
    return text;
  }

  //Maybe add stuff to move or squish when on the screen's edge
  void setPos(int x, int y){
    posX=x;
    posY=y;
  }

  void show(sf::RenderWindow &window, const sf::Texture &font){
    //Make a pretty rectangle around the text
    auto base=std::make_unique<sf::RectangleShape>();
    //SizeX's offset is 5 instead of 6 because remember that the last
    //letter still has that space after it
    //Same kind of deal for sizeY
    base->setSize(sf::Vector2f(sizeX+5, sizeY+11));
    base->setPosition(sf::Vector2f(posX-3, posY-3));
    base->setFillColor(sf::Color(0, 128, 255));
    base->setOutlineThickness(-1);
    base->setOutlineColor(sf::Color(255, 255, 255));

    //Write the text itself
    auto characters=std::make_unique<std::vector<sf::Sprite>>();
    *characters=writeCharacters(font);
    window.draw(*base);
    for(auto &it:*characters){
      window.draw(it);
    }
  }

  writing(){

  }

  writing(const std::string &&input, int x, int y){
    setString(input);
    posX=x;
    posY=y;
  }
};

#endif
