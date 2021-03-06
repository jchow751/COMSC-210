//LAB 8b: Perform A Timing Study On Nested For-Loop Sorting
//Programmer: Jacky Chow 
//Editor(s) used: Notepad++ 
//Compiler(s) used: Visual C++

#include <iostream> // for cout and endl
#include <string> // for string
#include <algorithm>
using namespace std;

#include <cassert> // for assert
#include <cmath> // for log and pow
#include <ctime> // for clock() and clock_t
#include <cstdlib>

int main()
{
  // print my name and this assignment's title 
  cout << "LAB 8b: Perform A Timing Study On Nested For-Loop Sorting\n"; 
  cout << "Programmer: Jacky Chow\n"; 
  cout << "Editor(s) used: Notepad++\n"; 
  cout << "Compiler(s) used: Visual C++\n"; 
  cout << "File: " << __FILE__ << endl; 
  cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl;
  
  // problem setup goes here

  // programmer customizations go here
  int n = 2000; // THE STARTING PROBLEM SIZE (MAX 250 MILLION)
  //BigOh calculation = 1 + n + n + n + 1/2n*n + 1/2n*n + 1/2n*n + 1/4n*n = 1 + 3n + 7/4n^2 = O(n^2) 
  string bigOh = "O(n squared)"; // YOUR PREDICTION: O(1), O(log n), O(n), O(n log n), or O(n squared)
  //const int REPS = 1; // for timing fast operations, use REPS up to 100th of the starting n

  int elapsedTimeTicksNorm = 0;
  double expectedTimeTicks = 0;
  for (int cycle = 0; cycle < 4; cycle++, n*= 2)
  {
    // more problem setup goes here -- the stuff not timed
    // open the input file
    double *array = new double[n];
    srand(time(0));
    for(int i = 0; i < n; i++)
    {
      array[i] = rand();
    }
    
    // assert that n is the size of the data structure
    //assert(a.size() == n); // or something like that...

    // start the timer, do something, and stop the timer
    clock_t startTime = clock();
    
    // do something where n is the "size" of the problem
    for (int i = 0; i < n; i++)
      for (int j = i + 1; j < n; j++)
        if (array[j] < array[i])
           swap(array[j], array[i]);
    
    clock_t endTime = clock(); 

    // validation block -- assure that process worked
    for (int i = 1; i < n; i++) assert (array[i - 1] <= array[i]);

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
    delete[] array;
} }