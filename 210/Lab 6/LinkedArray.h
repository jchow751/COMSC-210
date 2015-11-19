//LAB 6a: Write A Linked Array Class Template
//Programmer: Jacky Chow 
//Editor(s) used: Notepad++ 
//Compiler(s) used: Visual C++

#ifndef LinkedArray_h
#define LinkedArray_h

#include <vector>
using namespace std;
  
template <class T>
class LinkedArray
{
  struct Node
  {
    T data;
    bool inUse;
    Node* next;
  };
  Node* start;
  Node* end;
  int cap;
  int siz;
  mutable Node* lastP;
  mutable int lastIndex;
  static const int INIT_CAP = 10;
  T dummy;
  
  public:
  LinkedArray(int = INIT_CAP);
  LinkedArray(const LinkedArray<T>&);  
  ~LinkedArray();
  LinkedArray<T>& operator=(const LinkedArray<T>&);
  T& operator[](int);
  T operator[](int) const;
  int capacity() const {return cap;}
  int size() const{return siz;} // #of keys "in use", initially zero 
  bool containsKey(int) const; 
  void deleteKey(int); // set "in use" to false 
  vector<int> keys() const; // all "in use" keys 
  void clear();
};

template <class T>
LinkedArray<T>::LinkedArray(int init_cap)
{
  start = 0;
  end = 0;
  lastP = NULL;
  lastIndex = -1;
  cap = init_cap;
  siz = 0;
  for(int i = 0; i < cap; i++)
  {
    Node* node = new Node;
    node->inUse = false;
    node->next = 0;
    if(end) end->next = node;
    else start = node;
    end = node;
  }
}

template <class T>
LinkedArray<T>::LinkedArray(const LinkedArray<T>& a)
{
  cap = a.cap;
  Node* p = a.start;
  start = 0;
  end = 0;
  lastP = NULL;
  lastIndex = -1;
  for(int i = 0; i < cap; i++, p = p->next)
  {
    Node* node = new Node;
    node->data = p->data;
    node->inUse = p->inUse;
    node->next = 0;
    if(end) end->next = node;
    else start = node;
    end = node;
  }
  siz = a.siz;
}

template <class T>
LinkedArray<T>::~LinkedArray()
{
  while(start)
  {
    Node* p = start->next;
    delete start;
    start = p;
  }
}

template <class T>
LinkedArray<T>& LinkedArray<T>::operator=(const LinkedArray<T>& a)
{
  if(this == &a) return *this;
  
  while(start)
  {
    Node* p = start->next;
    delete start;
    start = p;
  }
  
  cap = a.cap;
  start = 0;
  end = 0;
  lastP = NULL;
  lastIndex = -1;
  Node* p = a.start;
  for(int i = 0; i < cap; i++, p = p->next)
  {
    Node* node = new Node;
    node->data = p->data;
    node->inUse = p->inUse;
    node->next = 0;
    if(end) end->next = node;
    else start = node;
    end = node;
  }
  siz = a.siz;
  return *this;
}

template <class T>
T& LinkedArray<T>::operator[](int index)
{
  if(index < 0) return dummy;
  if(index >= cap)
  { 
    int newCap = index - cap + 1;
    for(int i = 0; i < newCap; i++)
    {
      Node* node = new Node;
      node->inUse = false;
      node->next = 0;
      if(end) end->next = node;
      else start = node;
      end = node;
    }
    cap = index + 1;
  } 
  Node* p = start;
  int count = 0;
  if(lastIndex != -1 && lastIndex <= index)
  {
    p = lastP;
    count = lastIndex;
  }
  for(; p; count++, p = p->next)
  {
    if(count == index) break; 
  }
  if(!(p->inUse)) siz++; 
  p->inUse = true;
  lastP = p;
  lastIndex = index;
  return p->data;
}

template <class T>
T LinkedArray<T>::operator[](int index) const
{
  if(index < 0) return dummy;
  if(index >= cap) return dummy;
  const Node* p = start;
  int count = 0;
  if(lastIndex != -1 && lastIndex <= index)
  {
    p = lastP;
    count = lastIndex;
  } 
  for(; p; count++, p = p->next)
  {
    if(index == count) break; 
  }
  lastP = (Node*)p;
  lastIndex = index;
  return p->data;
}

template <class T>
bool LinkedArray<T>::containsKey(int index) const 
{
  if(index < 0) return false;
  if(index >= cap) return false;
  Node* p;
  int count = 0;
  for(p = start; p; count++, p = p->next)
  {
    if(index == count) break; 
  }
  return p->inUse;
}

template <class T>
void LinkedArray<T>::deleteKey(int index)
{
  if(index < 0) return;
  if(index >= cap) return;
  Node* p;
  int count = 0;
  for(p = start; p; count++, p = p->next)
  {
    if(index == count) break; 
  }
  if(p->inUse) siz--;
  p->inUse = false;
}

template <class T>
vector<int> LinkedArray<T>::keys() const
{
  vector<int> result;
  int count = 0;
  for(Node* p = start; p; count++, p = p->next)
    if(p->inUse) result.push_back(count);
  return result;
}

template <class T>
void LinkedArray<T>::clear()
{
  for(Node* p = start; p; p = p->next)
    p->inUse = false;
  siz = 0;
}

#endif 
