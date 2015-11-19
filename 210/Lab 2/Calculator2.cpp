//LAB 2c: Using Templated Classes
//Programmer: Jacky Chow 
//Editor(s) used: Notepad++ 
//Compiler(s) used: Visual C++

#include <iostream>
#include <string>
#include <stack>
using namespace std;
#include <cstdlib>


int main()
{
  // print my name and this assignment's title 
  cout << "LAB 2c: Using Templated Classes\n"; 
  cout << "Programmer: Jacky Chow\n"; 
  cout << "Editor(s) used: Notepad++\n"; 
  cout << "Compiler(s) used: Visual C++\n"; 
  cout << "File: " << __FILE__ << endl; 
  cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl;
  
  stack<double> s;
  string buf;
  while(true)
  {
    cout << "Enter: ";
    for(stack<double> copy = s; !copy.empty(); copy.pop())
    {
	  cout << copy.top() << ' ';
    }
    cin >> buf;
    cin.ignore(1000, 10);
	
    if(buf == "q" || buf == "Q") break;
	
    if(s.size() >=2)
    {
      if(buf == "+")
      {
	double a, b;
	a = s.top();
	s.pop();
        b = s.top();
        s.pop();
        s.push(a+b);
      }

      else if(buf == "-")
      {
        double a, b;
	a = s.top();
	s.pop();
	b = s.top();
	s.pop();
	s.push(b-a);
      }

      else if(buf == "/")
      {
	double a, b;
	a = s.top();
	s.pop();
	b = s.top();
	s.pop();
	s.push(b/a);
      }

      else if(buf == "*")
      {
	double a, b;
	a = s.top();
	s.pop();
	b = s.top();
        s.pop();
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