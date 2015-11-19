//LAB 10: Write, Test, and Apply The HashTable Class Template
//Programmer: Jacky Chow 
//Editor(s) used: Notepad++ 
//Compiler(s) used: Visual C++

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;
#include <cassert>
#include <cstring>

#include "HashTable.h"
#include "HashTable.h"

struct TermSection
{
  string term;
  string section;
};

bool operator==(const TermSection& x, const TermSection& y)
{
  if(x.term != y.term) return false;
  if(x.section != y.section) return false;
  return true;
}

int hashCode(const TermSection& x)
{
  int result;
  result = (int(x.term[0]) * int(x.term[3])) + (int(x.section[0]) * int(x.section[1]) * int(x.section[2])) + int(x.section[3]);
  return result;
}

int main()
{
  // print my name and this assignment's title 
  cout << "LAB 10: Write, Test, and Apply The HashTable Class Template\n"; 
  cout << "Programmer: Jacky Chow\n"; 
  cout << "Editor(s) used: Notepad++\n"; 
  cout << "Compiler(s) used: Visual C++\n"; 
  cout << "File: " << __FILE__ << endl; 
  cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl;
  
  int n = 100;
  int arraySize;
  HashTable<string, TermSection, 1009> a(hashCode);
  
  cout << "Created HashTable<string, TermSection, 1009> a(hashCode)\n";
  cout << "a.capacity returns: " << a.capacity() << endl;
  assert(807 == a.capacity());
  cout << "Size should be 0. a.size returns: " << a.size() << endl << endl;
  assert(0 == a.size());
  char* token;
  char buf[1000];
  const char* const tab = "\t";
  int counter = 0;
  ifstream fin;
  fin.open("dvc-schedule.txt");
  if (!fin.good()) throw "I/O error";  
  
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
    TermSection x = {term, section};
    a[x] = course;
  }
  fin.close();

  vector<TermSection> k = a.keys();  
  cout << "Capacity of a should now be 807. a.capacity returns: " << a.capacity() << endl;
  assert(807 == a.capacity());
  cout << "Size should also be 99. a.size returns: " << a.size() << endl;
  assert(99 == a.size());
  cout << "keys vector size should be equal to a.size: " << k.size() << endl;
  arraySize = k.size();
  assert(arraySize == a.size());
  counter = 0;

  // object copy testing
  {
    const HashTable<string, TermSection, 1009> copy = a;
    cout << endl;

    k = copy.keys();  
    cout << "Capacity of copy1 should be 807. copy.capacity returns: " << copy.capacity() << endl;
    assert(807 == copy.capacity());
    cout << "Size of copy1 should also be 99. copy.size returns: " << copy.size() << endl;
    assert(99 == copy.size());
    cout << "keys vector size of copy1 should be equal to copy.size: " << k.size() << endl;
    arraySize = k.size();
    assert(arraySize == copy.size());
    cout << "Printing out course from copy1 using element 4 in vector k: " << copy[k[4]] << endl;
    cout << "Now testing that copy.containsKey() will return true with that parameter.\n";
    if(copy.containsKey(k[4])) cout << "copy.containsKey(k[4]) returned True.\n";
    else cout << "Error! a.containsKey(k[4]) returned False.\n";
    assert(copy.containsKey(k[4]));
    TermSection y = {"Horch 2036", "9999"};
    cout << "Printing out course with fake y parameter(should be a dummy): " << copy[y] << endl;
    cout << "Now testing that copy.containsKey() will return false with fake y parameter.\n";
    if(!copy.containsKey(y)) cout << "copy.containsKey(y) returned False.\n";
    else cout << "Error! copy.containsKey(y) returned True.\n";  
    assert(!copy.containsKey(y));    
  }
  
  // object assignment testing
  {
    cout << endl;
    HashTable<string, TermSection, 1009> copy(hashCode); 
    cout << "Created copy 2 with a capacity 807.\nIt returns " << copy.capacity() << endl;
    assert(807 == copy.capacity());
    cout << "Copy 2 should have a size of 0. It returns: " << copy.size() << endl;
    cout << "Assigning copy 2 to equal a.\n";
    copy = a;
    k = copy.keys();  
    cout << "Capacity of copy2 should now be 160. copy.capacity returns: " << copy.capacity() << endl;
    assert(807 == copy.capacity());
    cout << "Size of copy2 should now be 99. copy.size returns: " << copy.size() << endl;
    assert(99 == copy.size());
    cout << "keys vector size of copy2 should be equal to copy.size: " << k.size() << endl;
    arraySize = k.size();
    assert(arraySize == copy.size());
    cout << "Using the clear function on copy 2.\n";
    copy.clear();
    cout << "Capacity of copy2 should still be 160. copy.capacity returns: " << copy.capacity() << endl;
    assert(807 == copy.capacity());
    cout << "Size of copy2 should now be 0. copy.size returns: " << copy.size() << endl;
    assert(0 == copy.size());
    k = copy.keys();
    cout << "keys vector size of copy2 should be equal to copy.size: " << k.size() << endl;
    arraySize = k.size();
    assert(arraySize == copy.size());
  }

  fin.open("dvc-schedule.txt");
  if (!fin.good()) throw "I/O error";  

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
    
    TermSection x = {term, section};      
    a.deleteKey(x);                     
    counter++;    
  } 
  fin.close();
  
  cout << "\nReopened the file to check and delete entries in array a.\n";
  k = a.keys();
  cout << "Capacity of a should still be 807. a.capacity returns: " << a.capacity() << endl;
  assert(807 == a.capacity());
  cout << "Size should also be 0. a.size returns: " << a.size() << endl;
  assert(0 == a.size());
  cout << "keys vector size should be equal to a.size: " << k.size() << endl;
  arraySize = k.size();
  assert(arraySize == a.size());
}