//LAB 11a: Write And Test A Priority Queue Template
//Programmer: Jacky Chow 
//Editor(s) used: Notepad++ 
//Compiler(s) used: Visual C++

#include <iostream>
using namespace std;

#include <cassert>

#include "PriorityQueue.h"
#include "PriorityQueue.h"

int main()
{
  // print my name and this assignment's title 
  cout << "LAB 11a: Write And Test A Priority Queue Template\n"; 
  cout << "Programmer: Jacky Chow\n"; 
  cout << "Editor(s) used: Notepad++\n"; 
  cout << "Compiler(s) used: Visual C++\n"; 
  cout << "File: " << __FILE__ << endl; 
  cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl;
  
  PriorityQueue<int> pq;
  int temp;
  cout << "Created a PriorityQueue<int> named pq\n";
  cout << "Its size should be 0. It is: " << pq.size() << endl; 
  assert(0 == pq.size());
  if(pq.empty()) cout << "pq.empty() returned true that it was empty\n";
  else cout << "Error: pq.empty() returned false for empty PQ\n";
  assert(pq.empty());
  cout << "\nEnqueuing the ints 13, 8, 4, 20, 10 into pq\n";
  pq.enqueue(13);
  pq.enqueue(8);
  pq.enqueue(4);
  pq.enqueue(20);
  pq.enqueue(10);
  
  if(!pq.empty()) cout << "pq.empty() returned false that it was empty\n";
  else cout << "Error: pq.empty() returned true for a non-empty PQ\n";
  assert(!pq.empty());  
  cout << "\nIts size should now be 5. It is: " << pq.size() << endl;
  assert(5 == pq.size());  
  cout << "The front should be 20. It is: " << pq.front() << endl;
  assert(20 == pq.front()); 
  cout << "The back should be 10. It is: " << pq.back() << endl;
  assert(10 == pq.back());  
  
  //const copy constructor test
  {
    cout << "\nCreating const copy with copy constructor\n";
    const PriorityQueue<int> copy = pq;
    if(!copy.empty()) cout << "copy.empty() returned false that it was empty\n";
    else cout << "Error: copy.empty() returned true for a non-empty PQ\n";
    assert(!copy.empty());  
    cout << "Copy size should now be 5. It is: " << copy.size() << endl;
    assert(5 == copy.size());  
  }
  
  //operator= copy test
  {
    cout << "\nCreating copy with with operator=\n";
    PriorityQueue<int> copy;
    cout << "Should initially have size 0. It is: " << copy.size() << endl;
    assert(copy.empty());
    cout << "Assigning copy to = pq\n";
    copy = pq;
    if(!copy.empty()) cout << "copy.empty() returned false that it was empty\n";
    else cout << "Error: copy.empty() returned true for a non-empty copy\n";
    assert(!copy.empty());  
    cout << "Copy 2's size should now be 5. It is: " << copy.size() << endl;
    assert(5 == copy.size());  
    cout << "The front should be 20. It is: " << copy.front() << endl;
    assert(20 == copy.front()); 
    cout << "The back should be 10. It is: " << copy.back() << endl;
    assert(10 == copy.back());  
    cout << "Dequeuing the entire copy of pq: \n";
    for(; copy.size();)
      cout << copy.dequeue() << ' '; 
    cout << "\nCopy should now be size 0. It is: " << copy.size() << endl;
    assert(copy.empty());    
    if(copy.empty()) cout << "copy.empty() returned true that it was empty\n";
    else cout << "Error: copy.empty() returned false for an empty copy\n";
    assert(copy.empty()); 
  }
  
  temp = pq.dequeue();
  cout << "\nDequeuing root of pq. It should return 20. It is: " << temp << endl;
  assert(20 == temp);  
  
  cout << "\nIts size should now be 4. It is: " << pq.size() << endl;
  assert(4 == pq.size());    
  cout << "The front should be 13. It is: " << pq.front() << endl;
  assert(13 == pq.front());    
  cout << "The back should be 8. It is: " << pq.back() << endl;
  assert(8 == pq.back());    
  cout << "\nNow using clear to clear pq\n";
  
  pq.clear();
  cout << "Size should now be 0. It is: " << pq.size() << endl;
  assert(0 == pq.size());  
  if(pq.empty()) cout << "pq.empty() returned true that it was empty\n";
  else cout << "Error: pq.empty() returned false for empty PQ\n";
  assert(pq.empty());  
}