//LAB 7c: Use A Stack
//Programmer: Jacky Chow 
//Editor(s) used: Notepad++ 
//Compiler(s) used: Visual C++

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#include <cstring>
#include "Stack.h"

struct Hugs
{
  char symbol;
  int lineN;
};

int main()
{
  // print my name and this assignment's title 
  cout << "LAB 7c: Use A Stack\n"; 
  cout << "Programmer: Jacky Chow\n"; 
  cout << "Editor(s) used: Notepad++\n"; 
  cout << "Compiler(s) used: Visual C++\n"; 
  cout << "File: " << __FILE__ << endl; 
  cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl;
  
  Stack<Hugs> a;
  string fileName;
  char buf[1000];
  int lineCount;
  Hugs temp;
  int n;
  bool comboBreaker = false;  //closing brace tracker
  bool ign = false;           // quote tracker
  bool ign2 = false;          // /* tracker
  
  cout << "Enter filename (H, CPP, JAVA, HTML, or JS): ";
  cin >> fileName;
  
  ifstream fin;
  fin.open(fileName.c_str());
  if(!fin.good()) throw "I/O error";  //get out if file doesn't exist
  lineCount = 0;
  while (fin.good())
  {
    string line;    
    getline(fin, line);
    lineCount++;
    strcpy(buf, line.c_str());
    for(int i = 0; buf[i] != '\0'; i++)
    {
      if(buf[i] == '\"')  //if PreProcessor.cpp used, should be first error due to ' ' not being accounted for
      {
        if(a.peek().symbol == '\"') 
        {
          a.pop(temp);
          ign = !ign;
        }
        else
        {
          Hugs h;
          h.symbol = '\"';
          h.lineN = lineCount;
          a.push(h);
          ign = !ign;
        }
      }
      if(ign) continue; //ignore all til end of the line or matching " found
      if(buf[i] == '/')
      {
        n = strlen(buf);
        if(i + 1 < n && buf[i + 1] == '*')
        {
          Hugs h;
          h.symbol = '/';
          h.lineN = lineCount;
          a.push(h);
          ign2 = !ign2;          
        }
      }
      if(buf[i] == '*')
      {
        n = strlen(buf);
        if(i + 1 < n && buf[i + 1] == '/')
        {        
          if(a.peek().symbol == '/') 
          {
            a.pop(temp);
            ign2 = !ign2;
          }
          else
          {
            Hugs h;
            h.symbol = '/';
            h.lineN = lineCount;
            a.push(h);
            comboBreaker = true;
            break;
          }
        }
      }
      if(ign2) continue;
      if(buf[i] == '(')
      {
        Hugs h;
        h.symbol = '(';
        h.lineN = lineCount;
        a.push(h);
      }
      if(buf[i] == ')')
      {
        if(a.peek().symbol == '(')
          a.pop(temp);
        else
        {
          Hugs h;
          h.symbol = ')';
          h.lineN = lineCount;
          a.push(h);
          comboBreaker = true;
          break;
        }
      }
      if(buf[i] == '{')
      {
        Hugs h;
        h.symbol = '{';
        h.lineN = lineCount;
        a.push(h);
      }
      if(buf[i] == '}')
      {
        if(a.peek().symbol == '{')
          a.pop(temp);
        else
        {
          Hugs h;
          h.symbol = '}';
          h.lineN = lineCount;
          a.push(h);
          comboBreaker = true;
          break;
        }
      }
      if(buf[i] == '[')
      {
        Hugs h;
        h.symbol = '[';
        h.lineN = lineCount;
        a.push(h);
      }
      if(buf[i] == ']')
      {
        if(a.peek().symbol == '[')
          a.pop(temp);
        else
        {
          Hugs h;
          h.symbol = ']';
          h.lineN = lineCount;
          a.push(h);
          comboBreaker = true;
          break;
        }
      }
      if(buf[i] == '/')
      {
        n = strlen(buf);
        if(i +1 < n && buf[i + 1] == '/') break;
      }        
    }
    if(comboBreaker) break; //break out if closing brace found with no match
    if(ign)                 //break out in end of line comes up with no closing "
    {
      comboBreaker = true;
      break;
    }
  }
  if(comboBreaker || a.peek().symbol == '/') //for closing brace mismatch and /* not being closed
  {
    char match;
    if(a.peek().symbol == ')') match = '(';  //state the missing symbol 
    else if(a.peek().symbol == '}') match = '{';
    else if(a.peek().symbol == ']') match = '[';
    else if(a.peek().symbol == '/') match = '/';
    else if(a.peek().symbol == '\"') match = '\"';
    cout << "Error, the " << a.peek().symbol << " on line " << a.peek().lineN 
      << " does not have a matching " << match << " for it in file: " << fileName << endl;     
  }
  else if(!a.empty()) 
  {    
    for(int i = a.size(); i > 1; i--) //to output first opening brace mismatch found
    {     
      a.pop(temp);
    }
    char match;
    if(a.peek().symbol == '(') match = ')';
    else if(a.peek().symbol == '{') match = '}';
    else if(a.peek().symbol == '[') match = ']';
    else if(a.peek().symbol == '/') match = '/';
    cout << "Error, the " << a.peek().symbol << " on line " << a.peek().lineN 
      << " does not have a matching " << match << " for it in file: " << fileName << endl;  
  }
  else
    cout << "No mismatches were found in file: " << fileName << endl;
}