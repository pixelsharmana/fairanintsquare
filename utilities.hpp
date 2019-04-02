#ifndef UTILITIES_H
#define UTILITIES_H

//Transforms a lot of things into a string
template<typename T> std::string toString(const T &input){
  std::ostringstream os;
  os << input;
  return os.str();
}

#endif
