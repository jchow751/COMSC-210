//LAB 11b: Perform A Simple Timing Study
//Programmer: Jacky Chow 
//Editor(s) used: Notepad++ 
//Compiler(s) used: Visual C++

#include <iostream> // for cout and endl
#include <string>
using namespace std;

#include <cassert> // for assert
#include <cmath> // for log and pow
#include <ctime> // for clock() and clock_t
#include <cstdlib>

#include "PriorityQueue.h"

int main()
{
  // print my name and this assignment's title 
  cout << "LAB 11b: Perform A Simple Timing Study\n"; 
  cout << "Programmer: Jacky Chow\n"; 
  cout << "Editor(s) used: Notepad++\n"; 
  cout << "Compiler(s) used: Visual C++\n"; 
  cout << "File: " << __FILE__ << endl; 
  cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl;
  
  // problem setup goes here

  // programmer customizations go here
  int n = 10000000; // THE STARTING PROBLEM SIZE (MAX 250 MILLION)
  //BigOh calculation = n * 5 = 5n = O(n)
  string bigOh = "O(log n)"; // YOUR PREDICTION: O(1), O(log n), O(n), O(n log n), or O(n squared)
  const int REPS = n/100; // for timing fast operations, use REPS up to 100th of the starting n

  int elapsedTimeTicksNorm = 0;
  double expectedTimeTicks = 0;
  cout << "Enqueue\n";
  for (int cycle = 0; cycle < 4; cycle++, n*= 2)
  {
    // more problem setup goes here -- the stuff not timed
    int counter = n;
    PriorityQueue<int> a(85000000);
    // do something where n is the "size" of the problem

    while (counter)
    {
      //progress bar
      a.enqueue(counter);
      counter--;
    }

    // assert that n is the size of the data structure
    assert(a.size() == n);
    
    // start the timer, do something, and stop the timer
    int reps = 0;
    clock_t startTime = clock();
    for(reps = 0; reps < REPS; reps++)
      a.enqueue(reps + n);
    clock_t endTime = clock(); 
    assert(a.size() == n + REPS);  
    
    // validation block -- assure that process worked
    //check that all values in queue ordered properly
    int tempCheck = a.dequeue();
    while(a.size())
    {
      assert(a.front() <= tempCheck);
      tempCheck = a.dequeue();
    }
    
    // compute timing results
    long elapsedTimeTicks = (long)(endTime - startTime);
    double factor = pow(2.0, cycle);
    if (cycle == 0)
      elapsedTimeTicksNorm = elapsedTimeTicks;
    else if (bigOh == "O(1)")
      expectedTimeTicks = elapsedTimeTicksNorm;
    else if (bigOh == "O(log n)")
      expectedTimeTicks = log(double(n)) / log(n / factor) * elapsedTimeTicksNorm;
    else if (bigOh == "O(n)")
      expectedTimeTicks = factor * elapsedTimeTicksNorm;
    else if (bigOh == "O(n log n)")
      expectedTimeTicks = factor * log(double(n)) / log(n / factor) * elapsedTimeTicksNorm;
    else if (bigOh == "O(n squared)")
      expectedTimeTicks = factor * factor * elapsedTimeTicksNorm;

    // reporting block
    cout << elapsedTimeTicks;;
    if (cycle == 0) cout << " (expected " << bigOh << ')';
    else cout << " (expected " << expectedTimeTicks << ')';
    cout << " for n=" << n << endl;
  } 
  
  cout << "\nDequeue\n";
  // programmer customizations go here
  n = 10000000; // THE STARTING PROBLEM SIZE (MAX 250 MILLION)
  //BigOh calculation = n * 5 = 5n = O(n)
  bigOh = "O(log n)"; // YOUR PREDICTION: O(1), O(log n), O(n), O(n log n), or O(n squared)
  const int REPS2 = n/100; // for timing fast operations, use REPS up to 100th of the starting n

  elapsedTimeTicksNorm = 0;
  expectedTimeTicks = 0;
  for(int cycle = 0; cycle < 4; cycle++, n*= 2)
  {
    // more problem setup goes here -- the stuff not timed
    int counter = n;
    PriorityQueue<int> a(85000000);
    // do something where n is the "size" of the problem
    while(counter)
    {
      //progress bar
      a.enqueue(counter);
      counter--;
    }
    
    // assert that n is the size of the data structure
    assert(a.size() == n);
    
    // start the timer, do something, and stop the timer
    int reps = 0;
    clock_t startTime = clock();
    for(reps = 0; reps < REPS2; reps++)
      a.dequeue();
    clock_t endTime = clock(); 
    assert(a.size() == n - REPS2); 
    // validation block -- assure that process worked
    //check that all values in queue ordered properly
    int tempCheck = a.dequeue();
    while(a.size())
    {
      assert(a.front() <= tempCheck);
      tempCheck = a.dequeue();
    }

    // compute timing results
    long elapsedTimeTicks = (long)(endTime - startTime);
    double factor = pow(2.0, cycle);
    if (cycle == 0)
      elapsedTimeTicksNorm = elapsedTimeTicks;
    else if (bigOh == "O(1)")
      expectedTimeTicks = elapsedTimeTicksNorm;
    else if (bigOh == "O(log n)")
      expectedTimeTicks = log(double(n)) / log(n / factor) * elapsedTimeTicksNorm;
    else if (bigOh == "O(n)")
      expectedTimeTicks = factor * elapsedTimeTicksNorm;
    else if (bigOh == "O(n log n)")
      expectedTimeTicks = factor * log(double(n)) / log(n / factor) * elapsedTimeTicksNorm;
    else if (bigOh == "O(n squared)")
      expectedTimeTicks = factor * factor * elapsedTimeTicksNorm;

    // reporting block
    cout << elapsedTimeTicks;;
    if (cycle == 0) cout << " (expected " << bigOh << ')';
    else cout << " (expected " << expectedTimeTicks << ')';
    cout << " for n=" << n << endl;
  }
}