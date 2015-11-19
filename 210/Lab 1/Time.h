//LAB 1b: More Class Programming And Testing
//Programmer: Jacky Chow 
//Editor(s) used: Notepad++ 
//Compiler(s) used: Visual C++

#ifndef TIME_H
#define TIME_H

class Time
{
  int hours;
  int minutes;
  int seconds;

  public:
  void setHours(int h) {hours = h;}
  void setMinutes(int m) {minutes = m;}
  void setSeconds(int s) {seconds = s;}
  double timeInHours() const;
  double timeInMinutes() const;
  int timeInSeconds() const;
};

#endif