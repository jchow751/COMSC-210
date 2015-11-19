//LAB 11a: Write And Test A Priority Queue Template
//Programmer: Jacky Chow 
//Editor(s) used: Notepad++ 
//Compiler(s) used: Visual C++

#ifndef PriorityQueue_h
#define PriorityQueue_h

#include <algorithm>
using namespace std;

template <class T>
class PriorityQueue
{       
  T* value;
  int siz;
  int cap;
  
  public:
  PriorityQueue(int = 2);
  PriorityQueue(const PriorityQueue<T>&);
  ~PriorityQueue();
  PriorityQueue<T>& operator=(const PriorityQueue<T>&);
  int size() const {return siz;}  
  void enqueue(const T&);
  T& front() {return value[0];}
  T& back() {return value[siz-1];}
  T dequeue();
  bool empty() const {return !siz ? true: false;}
  void clear();
};

template <class T>
PriorityQueue<T>::PriorityQueue(int x)
{
  cap = x;
  value = new T[cap];
  siz = 0;
}

template <class T>
PriorityQueue<T>::PriorityQueue(const PriorityQueue<T>& a)
{
  cap = a.cap;
  siz = a.siz;
  value = new T[cap];
  for(int i = 0; i < cap; i++)
    value[i] = a.value[i];
}

template <class T>
PriorityQueue<T>::~PriorityQueue()
{
  delete [] value;
}

template <class T>
PriorityQueue<T>& PriorityQueue<T>::operator=(const PriorityQueue<T>& a)
{
  if(this == &a) return *this;
  
  delete [] value;
  
  cap = a.cap;
  siz = a.siz;
  value = new T[cap];
  for(int i = 0; i < cap; i++)
    value[i] = a.value[i];  
  
  return *this;
}
  
template <class T>
void PriorityQueue<T>::enqueue(const T& para)
{
  int index = siz;
  if(index >= cap)  //double the capacity
  {
    T* temp = new T[2*cap];
    for(int i = 0; i < cap; i++)
      temp[i] = value[i];
    delete [] value;
    value = temp;
    cap = 2*cap;     
  }
  value[index] = para;
  while(true)
  {
    int parentIndex = (index+1)/2 - 1;
    if(parentIndex < 0) break;
    if(value[index] <= value[parentIndex]) break;
    swap(value[parentIndex], value[index]);
    index = parentIndex;
  }
  ++siz;
}

template <class T>
T PriorityQueue<T>::dequeue()
{
  T result = value[0];
  int index = 0;
  while(true)
  {
    int indexL = 2*index+1;
    int indexR = 2*index+2;
    if(indexL >= siz) break;
    if(indexL == siz-1 || value[indexR] <= value[indexL]) 
    {
      value[index] = value[indexL];
      index = indexL;
    }
    else
    {
      value[index] = value[indexR];
      index = indexR;
    }
  }
  --siz;
  value[index] = value[siz];
  while(true)
  {
    int parentIndex = (index+1)/2 - 1;
    if(parentIndex < 0) break;
    if(value[index] <= value[parentIndex]) break;
    swap(value[parentIndex], value[index]);
    index = parentIndex;
  }
  return result;
}

template <class T>
void PriorityQueue<T>::clear()
{
  siz = 0;
}
#endif 