//LAB 9: Write, Test, and Apply The AssociativeArray Template
//Programmer: Jacky Chow 
//Editor(s) used: Notepad++ 
//Compiler(s) used: Visual C++

#ifndef AssociativeArray_h
#define AssociativeArray_h

#include <vector>
using namespace std;
  
template <class T, class U>
class AssociativeArray
{
  T* value;
  U* key;
  bool* inUse;
  static const int INIT_CAP = 10;
  int siz;
  int cap;
  T dummy;
  
  public:
  AssociativeArray(int = INIT_CAP);
  AssociativeArray(const AssociativeArray<T, U>&);
  ~AssociativeArray();
  AssociativeArray<T, U>& operator=(const AssociativeArray<T, U>&);
  int capacity() const {return cap;}
  int size() const {return siz;}
  void clear();
  bool containsKey(const U&) const;
  void deleteKey(const U&);
  vector<U> keys() const;
  T& operator[](const U&);
  T operator[](const U&) const; 
};

template <class T, class U>
AssociativeArray<T, U>::AssociativeArray(int init_cap)
{
  cap = init_cap;
  value = new T[cap];
  key = new U[cap];
  inUse = new bool[cap];
  siz = 0;
  for(int i = 0; i < cap; i++)
    inUse[i] = false;
}

template <class T, class U>
AssociativeArray<T, U>::AssociativeArray(const AssociativeArray<T, U>& a)
{
  cap = a.cap;
  siz = a.siz;
  value = new T[cap];
  key = new U[cap];
  inUse = new bool[cap];
  for(int i = 0; i < cap; i++)
  {
    value[i] = a.value[i];
    key[i] = a.key[i];
    inUse[i] = a.inUse[i];
  }
}

template <class T, class U>
AssociativeArray<T, U>::~AssociativeArray()
{
  delete [] value;
  delete [] key;
  delete [] inUse;
}

template <class T, class U>
AssociativeArray<T, U>& AssociativeArray<T, U>::operator=(const AssociativeArray<T, U>& a)
{
  if(this == &a) return *this;
  
  delete [] value;
  delete [] key;
  delete [] inUse;

  cap = a.cap;
  siz = a.siz;
  value = new T[cap];
  key = new U[cap];
  inUse = new bool[cap];
  for(int i = 0; i < cap; i++)
  {
    value[i] = a.value[i];
    key[i] = a.key[i];
    inUse[i] = a.inUse[i];
  }
  return *this;  
}

template <class T, class U>
void AssociativeArray<T, U>::clear()
{
  for(int i = 0; i < cap; i++)
    inUse[i] = false;
  siz = 0;  
}

template <class T, class U>
bool AssociativeArray<T, U>::containsKey(const U& index) const
{
  for(int i = 0; i < cap; i++)
    if(key[i] == index)
      return inUse[i];
  return false;      
}

template <class T, class U>
void AssociativeArray<T, U>::deleteKey(const U& index)
{
  for(int i = 0; i < cap; i++)
    if(inUse[i] == true && key[i] == index)
    {
      inUse[i] = false;
      siz--;
      return;
    }
}

template <class T, class U> 
vector<U> AssociativeArray<T, U>::keys() const
{
  vector<U> result;
  for(int i = 0; i < cap; i++)
    if(inUse[i]) result.push_back(key[i]);
  return result;
}

template <class T, class U> 
T& AssociativeArray<T, U>::operator[](const U& para)
{
  int i, j;
  for(i = 0; i < cap; i++)  
    if(inUse[i] == true && key[i] == para) return value[i];    
  
  for(i = 0; i < cap; i++)
    if(!inUse[i])
    {
      key[i] = para;
      inUse[i] = true;
      siz++;
      return value[i];
    }
  
  i = cap;
  //new array with double capacity
  int newCap = 2 * cap;
  T* tempV = new T[newCap];
  U* tempK = new U[newCap];
  bool* tempUse = new bool[newCap];
  for(j = 0; j < i; j++)
  {
    tempV[j] = value[j];
    tempK[j] = key[j];
    tempUse[j] = inUse[j];
  }
  for(; j < newCap; j++)
    tempUse[j] = false;
  
  delete [] value;
  delete [] key;
  delete [] inUse;
  
  value = tempV;
  key = tempK;
  inUse = tempUse;
  cap = newCap;
  
  key[i] = para;
  inUse[i] = true;
  siz++;
  
  return value[i];
}

template <class T, class U> 
T AssociativeArray<T, U>::operator[](const U& para) const 
{ 
  for(int i = 0; i < cap; i++)
    if(inUse[i] == true && key[i] == para) 
      return value[i]; 
  return dummy; 
}

#endif 
