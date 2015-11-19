//LAB 4a: Write A Dynamic Array Class Template
//Programmer: Jacky Chow 
//Editor(s) used: Notepad++ 
//Compiler(s) used: Visual C++

#ifndef DynamicArray_h
#define DynamicArray_h

#include <vector>
using namespace std;
  
template <class T>
class DynamicArray
{
  static const int INIT_CAP = 10;
  T* data;
  bool* inUse;
  T dummy;
  int cap;
  
  public:
  DynamicArray(int = INIT_CAP);
  DynamicArray(const DynamicArray<T>&);  
  ~DynamicArray();
  DynamicArray<T>& operator=(const DynamicArray<T>&);
  T& operator[](int);
  T operator[](int) const;
  int capacity() const {return cap;}
  int size() const; // #of keys "in use", initially zero 
  bool containsKey(int) const; 
  void deleteKey(int); // set "in use" to false 
  vector<int> keys() const; // all "in use" keys 
  void clear();
};

template <class T>
DynamicArray<T>::DynamicArray(int init_cap)
{
  cap = init_cap;
  data = new T[cap];
  inUse = new bool[cap];
  for(int i = 0; i < cap; i++)
    inUse[i] = false;
}

template <class T>
DynamicArray<T>::DynamicArray(const DynamicArray<T>& a)
{
  cap = a.cap;
  data = new T[cap];
  inUse = new bool[cap];
  for(int i = 0; i < cap; i++)
  {
    data[i] = a.data[i];
    inUse[i] = a.inUse[i];
  }
}

template <class T>
DynamicArray<T>::~DynamicArray()
{
  delete [] data;
  delete [] inUse;
}

template <class T>
DynamicArray<T>& DynamicArray<T>::operator=(const DynamicArray<T>& a)
{
  if(this == &a) return *this;
  
  delete [] data;
  delete [] inUse;
  
  cap = a.cap;
  data = new T[cap];
  inUse = new bool[cap];
  for(int i = 0; i < cap; i++)
  {
    data[i] = a.data[i];
    inUse[i] = a.inUse[i];
  }
  return *this;
}

template <class T>
T& DynamicArray<T>::operator[](int index)
{
  if(index < 0) return dummy;
  if(index >= cap)
  { 
    T* tempData = new T[index + 1];
    for(int i = 0; i < cap; i++)
      tempData[i] = data[i];
    delete [] data;
    data = tempData;
    
    bool* tempInUse = new bool[index + 1];
    for(int i = 0; i < cap; i++)
      tempInUse[i] = inUse[i];
    for(int i = cap; i <= index; i++)
      tempInUse[i] = false;
    delete [] inUse;
    inUse = tempInUse;
    cap = index + 1;
  }
  inUse[index] = true;
  return data[index];
}

template <class T>
T DynamicArray<T>::operator[](int index) const
{
  if(index < 0) return dummy;
  if(index >= cap) return dummy;
  return data[index];
}

template <class T>
int DynamicArray<T>::size() const
{
  int result = 0;
  for(int i = 0; i < cap; i++)
    if(inUse[i]) result++;
  return result;
}

template <class T>
bool DynamicArray<T>::containsKey(int index) const 
{
  if(index < 0) return false;
  if(index >= cap) return false;
  return inUse[index];
}

template <class T>
void DynamicArray<T>::deleteKey(int index)
{
  if(index < 0) return;
  if(index >= cap) return;
  inUse[index] = false;
}

template <class T>
vector<int> DynamicArray<T>::keys() const
{
  vector<int> result;
  for(int i = 0; i < cap; i++)
    if(inUse[i]) result.push_back(i);
  return result;
}

template <class T>
void DynamicArray<T>::clear()
{
  for(int i = 0; i < cap; i++)
    inUse[i] = false;
}

#endif 
