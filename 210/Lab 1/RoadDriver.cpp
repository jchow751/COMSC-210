//Lab 1a, Class Programming And Testing
//Programmer: Jacky Chow 
//Editor(s) used: Notepad++ 
//Compiler(s) used: Visual C++

#include <iostream>
using namespace std;
#include <cassert>

#include "Road.h"
#include "Road.h" // testing ifndef

int main()
{
  // print my name and this assignment's title 
  cout << "LAB 1a: Class Programming And Testing\n"; 
  cout << "Programmer: Jacky Chow\n"; 
  cout << "Editor(s) used: Notepad++\n"; 
  cout << "Compiler(s) used: Visual C++\n"; 
  cout << "File: " << __FILE__ << endl; 
  cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl;
  
  Road road;
  road.setWidth(10);
  road.setLength(50);
  cout << "First road width should be 10 feet.\n";
  cout << "Getter for width of the first road returns " << road.getWidth() << " feet\n";
  assert(10 == road.getWidth());
  cout << "First road length should be 50 miles.\n";
  cout << "Getter for length of the first road returns " << road.getLength() << " miles\n";
  assert(50 == road.getLength());
  cout << "\nCubic feet of the road with an asphalt thickness of 2 inches is: \n" << road.asphalt(2) << " cubic feet\n";
  cout << "\nCubic feet of the road with an asphalt thickness of 4 inches is: \n" << road.asphalt(4) << " cubic feet\n\n";

  // object copy testing
  {
    const Road copy = road; // a read-only copy
    cout << "Getter for width of the road's first copy returns " << copy.getWidth() << " feet.\n";
    assert(10 == copy.getWidth());
    cout << "Getter for length of the road's first copy returns " << copy.getLength() << " miles.\n\n";
    assert(50 == copy.getLength());
  }

  // object assignment testing
  {
    Road copy; 
    copy = road;
    cout << "Getter for width of the road's second copy returns " << copy.getWidth() << " feet.\n";
    assert(10 == copy.getWidth());
    cout << "Getter for length of the road's second copy returns " << copy.getLength() << " miles.\n";
    assert(50 == copy.getLength());
  }
} 