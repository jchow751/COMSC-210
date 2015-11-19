//LAB 3b: Write A Static Array Application
//Programmer: Jacky Chow 
//Editor(s) used: Notepad++ 
//Compiler(s) used: Visual C++

#include <iostream>
#include <vector>
using namespace std;

#include <cstdlib>

#include "StaticArray.h"

int main()
{
  // print my name and this assignment's title 
  cout << "LAB 3b: Write A Static Array Application\n"; 
  cout << "Programmer: Jacky Chow\n"; 
  cout << "Editor(s) used: Notepad++\n"; 
  cout << "Compiler(s) used: Visual C++\n"; 
  cout << "File: " << __FILE__ << endl; 
  cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl;

  char buf[100];
  StaticArray<int, 100> a;
  int index;
  int value;
  int n;
  vector<int> k;
  
  while(true)
  {
    cout << "Input an index and a value [Q to quit]: ";
    cin >> buf;
    if(buf[0] == 'q' || buf[0] == 'Q') break;
    index = atoi(buf);
    cin >> buf;
    value = atoi(buf);
    a[index] = value;
    cout << endl;
  }
  
  cout << "\nI stored this many values: " << a.size() << endl;
  cout << "The values are: \n";
  k = a.keys();
  n = a.size();
  for(int i = 0; i < n; i++)
  {
    cout << k[i] << " " << a[k[i]] << endl;
  }
  cout << endl;
  
  while(true)
  {
    cout << "Input an index for me to look up [Q to quit]: ";
    cin >> buf;
    if(buf[0] == 'q' || buf[0] == 'Q') break;
    index = atoi(buf);
    if(a.containsKey(index))
      cout << "Found it -- the value stored at " << index << " is " << a[index] << endl;
    else
      cout << "I didn't find it\n";
  }
}