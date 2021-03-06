//LAB 3a: Write A Static Array Class Template
//Programmer: Jacky Chow 
//Editor(s) used: Notepad++ 
//Compiler(s) used: Visual C++

#ifndef StaticArray_h
#define StaticArray_h

#include <vector>
using namespace std;
  
template <class T, int CAPACITY>
class StaticArray
{
  T data[CAPACITY];
  bool inUse[CAPACITY];
  T dummy;
  
  public:
  StaticArray();
  T& operator[](int);
  T operator[](int) const;
  int capacity() const {return CAPACITY;}
  int size() const; // #of keys "in use", initially zero 
  bool containsKey(int) const; 
  void deleteKey(int); // set "in use" to false 
  vector<int> keys() const; // all "in use" keys 
  void clear();
};

template <class T, int CAPACITY>
StaticArray<T, CAPACITY>::StaticArray()
{
  for(int i = 0; i < CAPACITY; i++)
    inUse[i] = false;
}

template <class T, int CAPACITY>
T& StaticArray<T, CAPACITY>::operator[](int index)
{
  if(index < 0) return dummy;
  if(index >= CAPACITY) return dummy;
  inUse[index] = true;
  return data[index];
}

template <class T, int CAPACITY>
T StaticArray<T, CAPACITY>::operator[](int index) const
{
  if(index < 0) return dummy;
  if(index >= CAPACITY) return dummy;
  return data[index];
}

template <class T, int CAPACITY>
int StaticArray<T, CAPACITY>::size() const
{
  int result = 0;
  for(int i = 0; i < CAPACITY; i++)
    if(inUse[i]) result++;
  return result;
}

template <class T, int CAPACITY>
bool StaticArray<T, CAPACITY>::containsKey(int index) const 
{
  if(index < 0) return false;
  if(index >= CAPACITY) return false;
  return inUse[index];
}

template <class T, int CAPACITY>
void StaticArray<T, CAPACITY>::deleteKey(int index)
{
  if(index < 0) return;
  if(index >= CAPACITY) return;
  inUse[index] = false;
}

template <class T, int CAPACITY>
vector<int> StaticArray<T, CAPACITY>::keys() const
{
  vector<int> result;
  for(int i = 0; i < CAPACITY; i++)
    if(inUse[i]) result.push_back(i);
  return result;
}

template <class T, int CAPACITY>
void StaticArray<T, CAPACITY>::clear()
{
  for(int i = 0; i < CAPACITY; i++)
    inUse[i] = false;
}

#endif //StaticArray_h
