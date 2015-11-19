//LAB 7b: Write And Test A Queue Template
//Programmer: Jacky Chow 
//Editor(s) used: Notepad++ 
//Compiler(s) used: Visual C++

#include <iostream>
using namespace std;
#include <cassert>

#include "Queue.h"
#include "Queue.h"

int main()
{
  // print my name and this assignment's title 
  cout << "LAB 7b: Write And Test A Queue Template\n"; 
  cout << "Programmer: Jacky Chow\n"; 
  cout << "Editor(s) used: Notepad++\n"; 
  cout << "Compiler(s) used: Visual C++\n"; 
  cout << "File: " << __FILE__ << endl; 
  cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl;
  
  cout << "Creating Queue a\n";
  Queue<int> a;
  
  if(a.empty()) cout << "Queue a.empty() returns true that it is empty\n\n";
  else cout << "Error with a.empty()\n\n";
  assert(a.empty());
  
  int b;
  a.push(10);
  cout << "Pushed 10 into Queue a\n";
  if(!a.empty()) cout << "Queue a.empty() returned false and is not empty\n";
  assert(!a.empty());
  if(!a.empty()) cout << "a.front() should be 10 and returns: " << a.front();
  assert(10 == a.front());
  a.push(5);
  cout << "\nPushed 5 into a Queue\n";
  cout << "a.front() should be 10 and returns: " << a.front();
  assert(10 == a.front());
  cout << "\na.size() should be 2 and it returns: " << a.size();
  assert(2 == a.size());
  a.pop(b);
  cout << "\na.pop() should pop the 10, poping: " << b;
  cout << "\na.front() should now be 5 and returns: " << a.front();
  assert(5 == a.front());
  cout << "\na.size() should now be 1 and it returns: " << a.size();
  assert(1 == a.size());
  a.push(15);
  cout << "\nPushing 15, a.size() should now be 2 and it returns: " << a.size();
  assert(2 == a.size());
  a.push(4);
  cout << "\nPushing 4, a.size() should now be 3 and it returns: " << a.size();
  assert(3 == a.size());
  a.push(20);
  cout << "\nPushing 20, a.size() should now be 4 and it returns: " << a.size();
  assert(4 == a.size());
  cout << "\na.front() should now be 5 and returns: " << a.front();

  // object copy testing
  {
    cout << "\n\nCreating 1st copy Queue with copy constructor\n";
    const Queue<int> copy = a; // a read-only copy
    if(!copy.empty()) cout << "1st copy Queue copy.empty() returned false and is not empty\n";
    assert(!copy.empty());
    cout << "copy.front() should be 5 and returns: " << copy.front(); 
    assert(5 == copy.front());
    cout << "\ncopy.size() should now be 4 and it returns: " << copy.size();
    assert(4 == copy.size());
  }

  // object assignment testing
  {
    cout << endl << endl << "Creating 2nd copy Queue\n";
    Queue<int> copy; 
    if(copy.empty()) cout << "2nd copy Queue copy.empty() returns true that it is empty\n";
    else cout << "Error with copy.empty()\n\n";
    assert(copy.empty());
    copy = a;
    cout << "Assigning a Queue to 2nd copy Queue\n";
    if(!copy.empty()) cout << "2nd copy Queue copy.empty() returned false and is not empty\n";
    assert(!copy.empty());
    cout << "copy.front() should be 5 and returns: " << copy.front(); 
    assert(5 == copy.front());
    cout << "\ncopy.size() should now be 4 and it returns: " << copy.size();
    assert(4 == copy.size());
    copy.pop(b);
    cout << "\nPoping next value which is: " << b;
    assert(5 == b);
    cout << "\ncopy.size() should now be 3 and it returns: " << copy.size();
    assert(3 == copy.size());
    copy.pop(b);
    cout << "\nPoping next value which is: " << b;
    assert(15 == b);
    cout << "\ncopy.size() should now be 2 and it returns: " << copy.size();
    assert(2 == copy.size());
    copy.pop(b);
    cout << "\nPoping next value which is: " << b;
    assert(4 == b);
    cout << "\ncopy.size() should now be 1 and it returns: " << copy.size();
    assert(1 == copy.size());
    copy.pop(b);
    cout << "\nPoping next value which is: " << b;
    assert(20 == b);
    cout << "\ncopy.size() should now be 0 and it returns: " << copy.size();
    assert(0 == copy.size());
    if(!copy.pop(b)) cout << "\nTried poping again and copy.pop(int) returned false because queue is empty\n";
    else cout << "\nError, copy.pop(int) returned a true when copy.size is 0\n";
  }
  
  cout << "\n\nNow testing a.clear()\n";
  a.clear();
  if(a.empty()) cout << "Queue a.empty() returns true that it is empty\n";
  else cout << "Error with a.empty()\n";
  assert(a.empty());
  cout << "a.size() should be 0 and it returns: " << a.size();
  assert(0 == a.size()); 
  cout << "\na.front() should return dummy and returns: " << a.front();
}