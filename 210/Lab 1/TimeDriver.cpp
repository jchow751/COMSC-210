//LAB 1b: More Class Programming And Testing
//Programmer: Jacky Chow 
//Editor(s) used: Notepad++ 
//Compiler(s) used: Visual C++

#include <iostream>
using namespace std;
#include <cassert>
#include "Time.h"
#include "Time.h"

int main()
{
  // print my name and this assignment's title 
  cout << "LAB 1b: More Class Programming And Testing\n"; 
  cout << "Programmer: Jacky Chow\n"; 
  cout << "Editor(s) used: Notepad++\n"; 
  cout << "Compiler(s) used: Visual C++\n"; 
  cout << "File: " << __FILE__ << endl; 
  cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl;

  Time time;
  cout << "Hours is being set to 1 hour.\n";
  time.setHours(1);
  cout << "Minutes is being set to 40 minutes.\n";
  time.setMinutes(40);
  cout << "Seconds is being set to 30 seconds.\n\n";
  time.setSeconds(30);

  cout << "Time in hours is " << time.timeInHours() << " hours\n";
  assert(1.67499 < time.timeInHours() && time.timeInHours() < 1.67501);
  cout << "Time in minutes is " << time.timeInMinutes() << " minutes\n";
  assert(100.499 < time.timeInMinutes() && time.timeInMinutes() < 100.501);
  cout << "Time in seconds is " << time.timeInSeconds() << " seconds\n";
  assert(6030 == time.timeInSeconds());

  // object copy testing
  {
    const Time copy = time; // a read-only copy
    cout << "\nTime in hours in copy1 is " << copy.timeInHours() << " hours\n";
    assert(1.67499 < copy.timeInHours() && copy.timeInHours() < 1.67501);
    cout << "Time in minutes in copy1 is " << copy.timeInMinutes() << " minutes\n";
    assert(100.499 < copy.timeInMinutes() && copy.timeInMinutes() < 100.501);
    cout << "Time in seconds in copy1 is " << copy.timeInSeconds() << " seconds\n";
    assert(6030 == copy.timeInSeconds());
  }

  // object assignment testing
  {
    Time copy; 
    copy = time;
    cout << "\nTime in hours in copy2 is " << copy.timeInHours() << " hours\n";
    assert(1.67499 < copy.timeInHours() && copy.timeInHours() < 1.67501);
    cout << "Time in minutes in copy2 is " << copy.timeInMinutes() << " minutes\n";
    assert(100.499 < copy.timeInMinutes() && copy.timeInMinutes() < 100.501);
    cout << "Time in seconds in copy2 is " << copy.timeInSeconds() << " seconds\n";
    assert(6030 == copy.timeInSeconds());
  }
  
  cout << "\nHours is being set to 2 hours.\n";
  time.setHours(2);
  cout << "Minutes is being set to 10 minutes.\n";
  time.setMinutes(10);
  cout << "Seconds is being set to 15 seconds.\n\n";
  time.setSeconds(15);

  cout << "\nNew time in hours is " << time.timeInHours() << " hours\n";
  assert(2.170832 < time.timeInHours() && time.timeInHours() < 2.17834);
  cout << "New time in minutes is " << time.timeInMinutes() << " minutes\n";
  assert(130.2499 < time.timeInMinutes() && time.timeInMinutes() < 130.2501);
  cout << "New time in seconds is " << time.timeInSeconds() << " seconds\n";
  assert(7815 == time.timeInSeconds());
}