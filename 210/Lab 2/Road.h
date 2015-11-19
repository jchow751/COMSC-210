//LAB 2b: Writing Templates And Overloading Operators
//Programmer: Jacky Chow 
//Editor(s) used: Notepad++ 
//Compiler(s) used: Visual C++

#ifndef ROAD_H
#define ROAD_H

template<class T>
class Road
{
  T width;
  T length;

  public:
  void setWidth(T);
  void setLength(T);
  T getWidth() const {return width;}
  T getLength() const {return length;}
  double asphalt(int) const;
  bool operator<(const Road&) const;
  bool operator==(const Road&) const;
};

template<class T>
void Road<T>::setWidth(T w)
{
  width = w;
}

template<class T>
void Road<T>::setLength(T l)
{
  length = l;
}

template<class T>
double Road<T>::asphalt(int thickness) const
{
  return (thickness/12.0) * (length * 5280) * width;
}

template<class T>
bool Road<T>::operator<(const Road& b) const
{
  if(length < b.length) return true;
  else
    return false;
}

template<class T>
bool Road<T>::operator==(const Road& b) const
{
  if(length == b.length && width == b.width) return true;
  else
    return false;
}

#endif
