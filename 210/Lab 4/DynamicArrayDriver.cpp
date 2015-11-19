//LAB 4a: Write A Dynamic Array Class Template
//Programmer: Jacky Chow 
//Editor(s) used: Notepad++ 
//Compiler(s) used: Visual C++

#include <iostream>
#include <vector>
using namespace std;
#include <cassert>

#include "DynamicArray.h"
#include "DynamicArray.h"

int main()
{
  // print my name and this assignment's title 
  cout << "LAB 4a: Write A Dynamic Array Class Template\n"; 
  cout << "Programmer: Jacky Chow\n"; 
  cout << "Editor(s) used: Notepad++\n"; 
  cout << "Compiler(s) used: Visual C++\n"; 
  cout << "File: " << __FILE__ << endl; 
  cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl;
  
  vector<int> k;
  DynamicArray<int> a;

  //Test capacity() and size()
  cout << "Capacity of a should be 10\nCapacity returns " << a.capacity() << endl;
  assert(10 == a.capacity());
  cout << "Size should be 0\nSize returns " << a.size() << endl; 
  assert(0 == a.size());

  //Test kes()  
  k = a.keys();
  cout << "Keys of a in use: ";
  for(int i = 0; i < k.size(); i++)
    cout << k[i] << " ";
  cout << endl << endl;  

  //Test operator[] setter and getter
  a[3] = 7;
  cout << "a[3] was set to 7\na[3] is returns " << a[3] << endl;
  assert(7 == a[3]);
  cout << "Size should be 1\nSize returns " << a.size() << endl; 
  assert(1 == a.size());  
  k = a.keys();
  cout << "Keys of a in use: ";
  for(int i = 0; i < k.size(); i++)
    cout << k[i] << " ";
  cout << endl << endl; 

  a[5] = 20;
  cout << "a[5] was set to 20\na[5] is returns " << a[5] << endl;
  assert(20 == a[5]);
  a[7] = 15;
  cout << "a[7] was set to 15\na[7] is returns " << a[7] << endl;
  assert(15 == a[7]);
  a[9] = 3;
  cout << "a[9] was set to 3\na[9] is returns " << a[9] << endl;
  assert(3 == a[9]);  
  k = a.keys();
  cout << "Keys of a in use: ";
  for(int i = 0; i < k.size(); i++)
    cout << k[i] << " ";
  cout << endl << endl; 

  //Test containsKey()
  cout << "\nKey 1 is currently not in use.\n";
  if(a.containsKey(1)) cout << "Error, a[1] is not is use\n";
  else 
    cout << "containsKey() on a[1] returned a false\n";
  assert(!(a.containsKey(1)));

  a[1] = 8;
  cout << "a[1] was set to 8\na[1] is returns " << a[1] << endl;
  assert(8 == a[1]);
  cout << "Key 1 is now in use.\n";

  if(a.containsKey(1)) cout << "containsKey() on a[1] now returns true\n";
  else 
    cout << "Error! a[1] did not return a true\n";
  assert(a.containsKey(1));
  k = a.keys();
  cout << "Keys of a in use: ";
  for(int i = 0; i < k.size(); i++)
    cout << k[i] << " ";
  cout << endl << endl; 

  //Test deleteKey()
  a.deleteKey(1);
  cout << "a[1] was deleted\n";
  cout << "Key 1 is again not in use.\n";
  if(a.containsKey(1)) cout << "Error, a[1] is not is use\n";
  else 
    cout << "a[1] returned a false\n";
  k = a.keys();
  cout << "Keys of a in use: ";
  for(int i = 0; i < k.size(); i++)
    cout << k[i] << " ";
  cout << endl << endl; 

  //Cout values in current inUse keys    
  for(int i = 0; i < k.size(); i++)
  {
    cout << "a[" << k[i] << "] = " << a[k[i]] << endl;
  }
  
  cout << "Testing incresing capacity of dynamic array\n";
  cout << "Adding value 13 to index position 14 in a\n\n";
  a[14] = 13;  
  k = a.keys();
  cout << "Keys of a in use: ";
  for(int i = 0; i < k.size(); i++)
    cout << k[i] << " ";
  cout << endl << endl; 

  //Cout values in current inUse keys    
  for(int i = 0; i < k.size(); i++)
  {
    cout << "a[" << k[i] << "] = " << a[k[i]] << endl;
  }
  cout << "Size of a should now be 5.\nIt returns " << a.size() << endl;
  assert(5 == a.size());
  cout << "Capacity of a should now be 15.\nIt returns " << a.capacity() << endl;
  assert(15 == a.capacity());

  // object copy testing
  {
    const DynamicArray<int> copy = a; // a read-only copy
    cout << endl;

    k = copy.keys();
    for(int i = 0; i < k.size(); i++)
    {
      cout << "copy1[" << k[i] << "] = " << copy[k[i]] << endl;
    }
    cout << endl;
    for (int i = 0; i < copy.capacity(); i++)
      cout << "copy1[" << i << "] = " << copy[i] << endl;
    cout << "Keys of a in use: ";
    for(int i = 0; i < k.size(); i++)
      cout << k[i] << " ";
    cout << endl << endl; 
  }

  // object assignment testing
  {
    cout << endl;
    DynamicArray<int> copy(20); 
    cout << "Copy 2 should be capacity 20.\nIt returns " << copy.capacity() << endl;
    assert(20 == copy.capacity());
    cout << "Copying a to copy 2 should set capacity to 15\n";
    copy = a;
    cout << "It returns " << copy.capacity() << endl;
    assert(15 == copy.capacity());
    k = copy.keys();
    for(int i = 0; i < k.size(); i++)
    {
      cout << "copy2[" << k[i] << "] = " << copy[k[i]] << endl;
    }
    cout << endl;
    for (int i = 0; i < copy.capacity(); i++)
      cout << "copy2[" << i << "] = " << copy[i] << endl;
    cout << "Keys of a in use: ";
    for(int i = 0; i < k.size(); i++)
      cout << k[i] << " ";
    cout << endl << endl; 
  }  
  
  //Test clear()
  cout << "\nTestting clear() on a." << endl;
  a.clear();
  k = a.keys();
  cout << "Keys of a in use: ";
  for(int i = 0; i < k.size(); i++)
    cout << k[i] << " ";
  cout << endl;   
  cout << "Size should be 0\nSize returns " << a.size() << endl; 
  assert(0 == a.size());
}
