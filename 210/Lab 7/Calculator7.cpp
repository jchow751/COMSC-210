//LAB 7a: Write And Apply A Stack Template
//Programmer: Jacky Chow 
//Editor(s) used: Notepad++ 
//Compiler(s) used: Visual C++

#include <iostream>
#include <string>
using namespace std;
#include <cstdlib>

#include "Stack.h"

int main()
{
  // print my name and this assignment's title 
  cout << "LAB 7a: Write And Apply A Stack Template\n"; 
  cout << "Programmer: Jacky Chow\n"; 
  cout << "Editor(s) used: Notepad++\n"; 
  cout << "Compiler(s) used: Visual C++\n"; 
  cout << "File: " << __FILE__ << endl; 
  cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl;

  Stack<double> s;
  double temp;
  string buf;
  while(true)
  {
    cout << "Enter: ";
    for(Stack<double> copy = s; !copy.empty(); copy.pop(temp))
    {
      cout << copy.peek() << ' ';
    }
    cin >> buf;
    cin.ignore(1000, 10);
	
    if(buf == "q" || buf == "Q") break;
	
    if(s.size() >=2)
    {
      if(buf == "+")
      {
        double a, b;
	a = s.peek();
	s.pop(temp);
        b = s.peek();
        s.pop(temp);
        s.push(a+b);
      }

      else if(buf == "-")
      {
        double a, b;
	a = s.peek();
	s.pop(temp);
        b = s.peek();
      	s.pop(temp);
	s.push(b-a);
      }

      else if(buf == "/")
      {
	double a, b;
	a = s.peek();
	s.pop(temp);
        b = s.peek();
      	s.pop(temp);
      	s.push(b/a);
      }

      else if(buf == "*")
      {
        double a, b;
        a = s.peek();
        s.pop(temp);
        b = s.peek();
        s.pop(temp);
        s.push(b*a);
      }

      else
      {
        s.push(atof(buf.c_str()));
      }
    }

    else
      s.push(atof(buf.c_str()));
  }
}