//LAB 1b: More Class Programming And Testing
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
  return (hours*60*60) + (minutes*60) + seconds;
}