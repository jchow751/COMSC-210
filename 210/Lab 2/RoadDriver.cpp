//LAB 2b: Writing Templates And Overloading Operators
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
  cout << "LAB 2b: Writing Templates And Overloading Operators\n"; 
  cout << "Programmer: Jacky Chow\n"; 
  cout << "Editor(s) used: Notepad++\n"; 
  cout << "Compiler(s) used: Visual C++\n"; 
  cout << "File: " << __FILE__ << endl; 
  cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl;
  
  cout << "First and second roads use int as their data type.\n\n";
  Road<int> road;
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
    const Road<int> copy = road; // a read-only copy
    cout << "Getter for width of the road's first copy returns " << copy.getWidth() << " feet.\n";
    assert(10 == copy.getWidth());
    cout << "Getter for length of the road's first copy returns " << copy.getLength() << " miles.\n";
    assert(50 == copy.getLength());

    if(road == copy)
      cout << "First copy is the same as the original road. Operator== working.\n\n";
    else
      cout << "Error with the first copy. Operator== not working.\n\n";
  }

  // object assignment testing
  {
    Road<int> copy; 
    copy = road;
    cout << "Getter for width of the road's second copy returns " << copy.getWidth() << " feet.\n";
    assert(10 == copy.getWidth());
    cout << "Getter for length of the road's second copy returns " << copy.getLength() << " miles.\n";
    assert(50 == copy.getLength());

    if(road == copy)
      cout << "Second copy is the same as the original road. Operator== working.\n\n";
    else
      cout << "Error with the second copy. Operator== not working.\n\n";
  }

  Road<int> road2;
  road2.setWidth(12);
  road2.setLength(60);
  cout << "Second road width should be 12 feet.\n";
  cout << "Getter for width of the second road returns " << road2.getWidth() << " feet\n";
  assert(12 == road2.getWidth());
  cout << "Second road length should be 60 miles.\n";
  cout << "Getter for length of the second road returns " << road2.getLength() << " miles\n\n";
  assert(60 == road2.getLength());

  if(road < road2)
    cout << "First road is less than second road. Operator< working.\n\n";
  else
    cout << "Error with the < operator. First road is not longer than second.\n\n";
  assert(road < road2);
  if(road2 < road)
    cout << "Error with the < operator. The second road is not less than the first road.\n\n";
  else
    cout << "The second road is not less than the first road. Operator< working.\n\n";
  assert(!(road2 < road));	

  cout << "Third, fourth and fifth roads use float as their data type.\n\n";
  Road<float> road3;
  road3.setWidth(10.5);
  road3.setLength(45.75);
  cout << "Third road width should be 10.5 feet.\n";
  cout << "Getter for width of the third road returns " << road3.getWidth() << " feet\n";
  assert(10.5 == road3.getWidth());
  cout << "Third road length should be 45.75 miles.\n";
  cout << "Getter for length of the third road returns " << road3.getLength() << " miles\n\n";
  assert(45.75 == road3.getLength());
  
  Road<float> road4;
  road4.setWidth(10.5);
  road4.setLength(52.25);
  cout << "Fourth road width should be 10.5 feet.\n";
  cout << "Getter for width of the fourth road returns " << road4.getWidth() << " feet\n";
  assert(10.5 == road4.getWidth());
  cout << "Fourth road length should be 52.25 miles.\n";
  cout << "Getter for length of the fourth road returns " << road4.getLength() << " miles\n\n";
  assert(52.25 == road4.getLength());
  
  if(road3 < road4)
    cout << "Third road is less than fourth road. Operator< working.\n\n";
  else
    cout << "Error with the < operator. Third road is not longer than fourth.\n\n";
  assert(road3 < road4);
  if(road4 < road3)
    cout << "Error! The fourth road is not less than the third road. Operator< not working.\n\n";
  else
    cout << "The fourth road is not less than the third road. Operator< working.\n\n";  
  assert(!(road4 < road3));
  if(road3 == road4)
    cout << "Error, third and fourth roads have different lengths. Operator== not working.\n\n";
  else
    cout << "Third and fourth roads are not equal. Operator== working.\n\n";
  assert(!(road3 == road4));

  Road<float> road5;
  road5.setWidth(10.5);
  road5.setLength(45.75);
  cout << "Fifth road width should be 10.5 feet.\n";
  cout << "Getter for width of the fifth road returns " << road5.getWidth() << " feet\n";
  assert(10.5 == road5.getWidth());
  cout << "Fifth road length should be 45.75 miles.\n";
  cout << "Getter for length of the fifth road returns " << road5.getLength() << " miles\n\n";
  assert(45.75 == road5.getLength());
  
  if(road3 < road5)
    cout << "Error, third road is not less than fifth road. Operator< not working.\n\n";
  else
    cout << "Third road is not less than fifth. Operator< working.\n\n";
  assert(!(road3 < road5));
  if(road5 < road3)
    cout << "Error! The fifth road is not less than the third road. Operator< not working.\n\n";
  else
    cout << "Fifth road is not less than third. Operator< working.\n\n";  
  assert(!(road5 < road3));
  if(road3 == road5)
    cout << "Third road is equal to fifth. Operator== is working.\n";
  else
    cout << "Error, third and fifth roads are equal. Operator== not working.\n";
  assert(road3 == road5);

  cout << "\nCubic feet of the fifth road with an asphalt thickness of 2 inches is: \n" << road5.asphalt(2) << " cubic feet\n";
  cout << "\nCubic feet of the fourth road with an asphalt thickness of 3 inches is: \n" << road4.asphalt(3) << " cubic feet\n";
} 