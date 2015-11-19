//LAB 7a: Write And Apply A Stack Template 
//Programmer: Jacky Chow 
//Editor(s) used: Notepad++ 
//Compiler(s) used: Visual C++

#include <iostream>
using namespace std;
#include <cassert>

#include "Stack.h"
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
  
  cout << "Creating stack a\n";
  Stack<int> a;
  
  if(a.empty()) cout << "Stack a.empty() returns true that it is empty\n\n";
  else cout << "Error with a.empty()\n\n";
  assert(a.empty());
  
  int b = 5;
  a.push(10);
  cout << "Pushed 10 into stack a\n";
  if(!a.empty()) cout << "Stack a.empty() returned false and is not empty\n";
  assert(!a.empty());
  if(!a.empty()) cout << "a.peek() should be 10 and returns: " << a.peek();
  assert(10 == a.peek());
  a.push(b);
  cout << "\nPushed b, which equals 5 into a stack\n";
  if(!a.empty()) cout << "a.peek() should be 5 and returns: " << a.peek();
  assert(5 == a.peek());
  cout << "\na.size() should be 2 and it returns: " << a.size();
  assert(2 == a.size());
  if(a.pop(b)) cout << "\na.pop() should pop b\n";
  cout << "a.size() should now be 1 and it returns: " << a.size();
  assert(1 == a.size());
  a.push(15);
  a.push(4);
  a.push(20);
  cout << "\nPushing 15, 4, and 20 into stack a";
  cout << "\na.size() should now be 4 and it returns: " << a.size();
  assert(4 == a.size());
  if(!a.empty()) cout << "\na.peek() should be 20 and returns: " << a.peek(); 
  assert(20 == a.peek());

  // object copy testing
  {
    cout << "\n\nCreating 1st copy stack with copy constructor\n";
    const Stack<int> copy = a; // a read-only copy
    if(!copy.empty()) cout << "1st copy stack copy.empty() returned false and is not empty\n";
    assert(!copy.empty());
    if(!copy.empty()) cout << "copy.peek() should be 20 and returns: " << a.peek(); 
    assert(20 == a.peek());
    cout << "\ncopy.size() should now be 4 and it returns: " << copy.size();
    assert(4 == copy.size());
  }

  // object assignment testing
  {
    cout << endl << endl << "Creating 2nd copy stack\n";
    Stack<int> copy; 
    if(copy.empty()) cout << "2nd copy stack copy.empty() returns true that it is empty\n";
    else cout << "Error with copy.empty()\n\n";
    assert(copy.empty());
    copy = a;
    cout << "Assigning a stack to 2nd copy stack\n";
    if(!copy.empty()) cout << "2nd copy stack copy.empty() returned false and is not empty\n";
    assert(!copy.empty());
    if(!copy.empty()) cout << "copy.peek() should be 20 and returns: " << a.peek(); 
    assert(20 == a.peek());
    cout << "\ncopy.size() should now be 4 and it returns: " << copy.size();
    assert(4 == copy.size());
    copy.pop(b);
    cout << "\nPoping next value which is: " << b;
    cout << "\ncopy.size() should now be 3 and it returns: " << copy.size();
    assert(3 == copy.size());
    copy.pop(b);
    cout << "\nPoping next value which is: " << b;
    cout << "\ncopy.size() should now be 2 and it returns: " << copy.size();
    assert(2 == copy.size());
    copy.pop(b);
    cout << "\nPoping next value which is: " << b;
    cout << "\ncopy.size() should now be 1 and it returns: " << copy.size();
    assert(1 == copy.size());
    copy.pop(b);
    cout << "\nPoping next value which is: " << b;
    cout << "\ncopy.size() should now be 0 and it returns: " << copy.size();
    assert(0 == copy.size());
    if(!copy.pop(b)) cout << "\nTried poping again and copy.pop(int) returned false because stack is empty\n";
    else cout << "\nError, copy.pop(int) returned a true when copy.size is 0\n";
  }

  cout << "\n\nNow testing a.clear()\n";
  a.clear();
  if(a.empty()) cout << "Stack a.empty() returns true that it is empty\n";
  else cout << "Error with a.empty()\n";
  assert(a.empty());
  cout << "a.size() should be 0 and it returns: " << a.size();
  assert(0 == a.size());
  cout << "\na.peek() should return dummy and returns: " << a.peek();  
}