//Lab 1a, Class Programming And Testing
//Programmer: Jacky Chow 
//Editor(s) used: Notepad++ 
//Compiler(s) used: Visual C++

#include "Road.h"

void Road::setWidth(int w)
{
  width = w;
}

void Road::setLength(int l)
{
  length = l;
}

double Road::asphalt(int thickness) const
{
  return (thickness/12.0) * (length * 5280) * width;
}
