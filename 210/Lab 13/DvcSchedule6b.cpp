//LAB 6b: Big Data Solutions
//Programmer: Jacky Chow 
//Editor(s) used: Notepad++ 
//Compiler(s) used: Visual C++

#include <fstream>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

#include <cstring>
#include <ctime>
#include <cctype>
#include <cstdlib>
#include "LinkedArray.h"
#include "SortableStaticArray.h"

struct Subject
{
  string subjectCode;
  int count;
};

struct Record
{
  string subject;
  int season;
  int termYear;
};

struct List
{
  LinkedArray<Record> list;
};

int main()
{
  // print my name and this assignment's title 
  cout << "LAB 6b: Big Data Solutions\n"; 
  cout << "Programmer: Jacky Chow\n"; 
  cout << "Editor(s) used: Notepad++\n"; 
  cout << "Compiler(s) used: Visual C++\n"; 
  cout << "File: " << __FILE__ << endl; 
  cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl;
  
  SortableStaticArray<Subject> a(109);
  SortableStaticArray<List, 10000> seenBefore;
  int duplicates = 0;
  int n = 0;
  // for parsing the inputfile
  char* token;
  char buf[1000];
  const char* const tab = "\t";

  clock_t startTime = clock();
  // open the input file
  ifstream fin;
  fin.open("dvc-schedule.txt");
  if (!fin.good()) throw "I/O error";  

  // read the input file
  while (fin.good())
  {
    //progress bar
    if(++n % 1000 == 0)
    {
      cout << '.';
      cout.flush();
    }
    
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

    //check for duplicate
    int ter;
    int terYear;
    int sect;
    int dupSize;
  
    //convert term to an int
    if(toupper(term[0]) == 'S')
    {
      if(toupper(term[1]) == 'P')
        ter = 1;
      if(toupper(term[1]) == 'U')
        ter = 2;
    }
    else if(toupper(term[0]) == 'F')
      ter = 3;
    else
      continue;
    
    //convert Year and section to int
    terYear = atoi(term.substr(term.length() - 4).c_str());    
    sect = atoi(section.c_str());
	
    bool foundIt = false;
    
    //check large array by section
    if(seenBefore.containsKey(sect))
    {
      dupSize = seenBefore[sect].list.size();
      int i = 0;
      for(; i < dupSize; i++)
      {
        if(seenBefore[sect].list[i].season == ter && seenBefore[sect].list[i].termYear ==  terYear)
          if(seenBefore[sect].list[i].subject == subjectCode)
          {
            foundIt = true;
            duplicates++;
            break;
          }          
      }
      if(foundIt) continue;
    }
    if(!foundIt)
    {
      Record dup;
      dup.subject = subjectCode;
      dup.season = ter;
      dup.termYear = terYear;
      seenBefore[sect].list[seenBefore[sect].list.size()] = dup;
    }
   
    // if I get this far, then it's a valid record
    int asize = a.size();
    foundIt = true;
    for(int i = 0; i < asize; i++)
    {
      if(a[i].subjectCode == subjectCode) 
      {
        a[i].count++;
        foundIt = false;
        break;
      }
    }
    if(foundIt)
    {
      Subject subject;
      subject.subjectCode = subjectCode;
      subject.count = 1; 
      a[a.size()] = subject;
    }    
  }
  fin.close();
  
  //sort array
  int asize = a.size();
  for (int i = 0; i < asize; i++)
    for (int j = i + 1; j < asize; j++)
      if (a[j].subjectCode < a[i].subjectCode)
         swap(a[j], a[i]);
        
  double elapsedSeconds = (double)(clock() - startTime) / CLOCKS_PER_SEC;
  //output subject count array
  cout << endl;
  
  for(int i = 0; i < asize; i++)
  {
    cout << a[i].subjectCode << ", " << a[i].count << " sections\n";
  }

  cout << "Duplicates: " << duplicates << endl;
  cout << "Time elapsed: " << elapsedSeconds << endl;
}