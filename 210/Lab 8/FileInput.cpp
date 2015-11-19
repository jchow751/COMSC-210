//LAB 8a: Perform A Simple Timing Study
//Programmer: Jacky Chow 
//Editor(s) used: Notepad++ 
//Compiler(s) used: Visual C++

#include <iostream> // for cout and endl
#include <string> // for string
#include <fstream>
using namespace std;

#include <cassert> // for assert
#include <cstring>
#include <cmath> // for log and pow
#include <ctime> // for clock() and clock_t

int main()
{
  // print my name and this assignment's title 
  cout << "LAB 8a: Perform A Simple Timing Study\n"; 
  cout << "Programmer: Jacky Chow\n"; 
  cout << "Editor(s) used: Notepad++\n"; 
  cout << "Compiler(s) used: Visual C++\n"; 
  cout << "File: " << __FILE__ << endl; 
  cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl;
  
  // problem setup goes here

  // programmer customizations go here
  int n = 8000; // THE STARTING PROBLEM SIZE (MAX 250 MILLION)
  //BigOh calculation = n * 5 = 5n = O(n)
  string bigOh = "O(n)"; // YOUR PREDICTION: O(1), O(log n), O(n), O(n log n), or O(n squared)
  //const int REPS = 1; // for timing fast operations, use REPS up to 100th of the starting n

  int elapsedTimeTicksNorm = 0;
  double expectedTimeTicks = 0;
  for (int cycle = 0; cycle < 4; cycle++, n*= 2)
  {
    // more problem setup goes here -- the stuff not timed
    // open the input file
    char* token;
    char buf[1000];
    const char* const tab = "\t";
    int counter = 0;
    ifstream fin;
    fin.open("dvc-schedule.txt");
    if (!fin.good()) throw "I/O error";  
    
    // assert that n is the size of the data structure
    //assert(a.size() == n); // or something like that...

    // start the timer, do something, and stop the timer
    clock_t startTime = clock();
    
    // do something where n is the "size" of the problem
    while (fin.good())
    {
      //progress bar
      if(counter == n) break;
    
      // read the line
      string line;
      getline(fin, line);
      strcpy(buf, line.c_str());
      if (buf[0] == 0) continue;
    
      // parse the line
      const string term(token = strtok(buf, tab));
      const string section(token = strtok(0, tab));
      const string course((token = strtok(0, tab)) ? token : "");
      const string instructor((token = strtok(0, tab)) ? token : "");
      const string whenWhere((token = strtok(0, tab)) ? token : "");
      if (course.find('-') == string::npos) continue; // invalid line
      const string subjectCode(course.begin(), course.begin() + course.find('-'));
      counter++;
    }
    
    clock_t endTime = clock(); 

    // validation block -- assure that process worked

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
} }