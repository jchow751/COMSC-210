//Lab 1a, Class Programming And Testing
//Programmer: Jacky Chow 
//Editor(s) used: Notepad++ 
//Compiler(s) used: Visual C++

#ifndef ROAD_H
#define ROAD_H

class Road
{
  int width;
  int length;

  public:
  void setWidth(int);
  void setLength(int);
  int getWidth() const {return width;}
  int getLength() const {return length;}
  double asphalt(int) const;
};

#endif
