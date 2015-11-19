//LAB 2a: Writing Overloading Operators
//Programmer: Jacky Chow 
//Editor(s) used: Notepad++ 
//Compiler(s) used: Visual C++

#include "Time.h"

double Time::timeInHours() const
{
  return hours + (minutes/60.0) + (seconds/3600.0);
}

double Time::timeInMinutes() const
{
  return (hours*60) + minutes + (seconds/60.0);
}

int Time::timeInSeconds() const
{
  return (hours*3600) + (minutes*60) + seconds;
}

bool operator<(const Time& a, const Time& b)
{
  if(a.timeInSeconds() < b.timeInSeconds()) return true;
  return false;
}

bool operator==(const Time& a, const Time& b)
{
  if(a.timeInSeconds() == b.timeInSeconds()) return true;
  return false;
}