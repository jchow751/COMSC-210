//LAB 2a: Writing Overloading Operators
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
  cout << "LAB 2a: Writing Overloading Operators\n"; 
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

  Time time2;
  cout << "\nTime 2 hours is being set to 2 hour.\n";
  time2.setHours(2);
  cout << "Time 2 minutes is being set to 20 minutes.\n";
  time2.setMinutes(20);
  cout << "Time 2 seconds is being set to 45 seconds.\n\n";
  time2.setSeconds(45);

  cout << "Time 2 in seconds is " << time2.timeInSeconds() << " seconds\n";
  assert(8445 == time2.timeInSeconds());

  if(time < time2)
    cout << "Time 1 is less than time 2\n\n";
  else
    cout << "Error with overloaded < operator\n\n";
  assert(time < time2);
  assert(!(time2 < time));

  Time time3;
  cout << "Time 3 hours is being set to 1 hour.\n";
  time3.setHours(1);
  cout << "Time 3 minutes is being set to 40 minutes.\n";
  time3.setMinutes(40);
  cout << "Time 3 seconds is being set to 30 seconds.\n\n";
  time3.setSeconds(30);

  cout << "Time 3 in seconds is " << time3.timeInSeconds() << " seconds\n";
  assert(6030 == time3.timeInSeconds());

  if(time == time3)
    cout << "Time 3 is equal to the original time\n";
  else
    cout << "Error with overloaded == operator\n";
  assert(time == time3);
  assert(!(time < time3));


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
  cout << "Seconds is being set to 15 seconds.\n";
  time.setSeconds(15);

  cout << "\nNew time in hours is " << time.timeInHours() << " hours\n";
  assert(2.170832 < time.timeInHours() && time.timeInHours() < 2.17834);
  cout << "New time in minutes is " << time.timeInMinutes() << " minutes\n";
  assert(130.2499 < time.timeInMinutes() && time.timeInMinutes() < 130.2501);
  cout << "New time in seconds is " << time.timeInSeconds() << " seconds\n";
  assert(7815 == time.timeInSeconds());
}