//LAB 10: Write, Test, and Apply The HashTable Class Template
//Programmer: Jacky Chow 
//Editor(s) used: Notepad++ 
//Compiler(s) used: Visual C++

#ifndef HashTable_h
#define HashTable_h

#include <list>
#include <vector>
#include <algorithm>
using namespace std;

template <class T, class U, int CAPACITY>
class HashTable
{       
  struct Node
  {
    T value;
    U key;
    
    void operator=(const T& v){value = v;}
    bool operator==(const Node& n) const {return key == n.key;}    
  };
  list<Node> data[CAPACITY];
  T dummy;
  int siz;
  int(*hashCode)(const U&);
  int getWrappedIndex(const U&) const;
  
  public:
  HashTable(int(*)(const U&));
  int capacity() const {return 0.8 * CAPACITY;}
  int size() const {return siz;}  
  T& operator[](const U&);
  T operator[](const U&) const; 
  void clear();
  bool containsKey(const U&) const;
  void deleteKey(const U&);
  vector<U> keys() const;
};

template <class T, class U, int CAPACITY>
HashTable<T, U, CAPACITY>::HashTable(int(*x)(const U&))
{
  siz = 0;
  hashCode = x;
}

template <class T, class U, int CAPACITY>
int HashTable<T, U, CAPACITY>::getWrappedIndex(const U& key) const
{
  int wi = hashCode(key) % CAPACITY;
  if(wi < 0) wi += CAPACITY;
  return wi;
}

template <class T, class U, int CAPACITY>
T& HashTable<T, U, CAPACITY>::operator[](const U& key)
{
  int wi = getWrappedIndex(key);
  
  typename list<Node>::iterator it; 
  Node temp;
  temp.key = key; // key is parameter 
  it = find(data[wi].begin(), data[wi].end(), temp); 

  if (it == data[wi].end()) // no matching key 
  { 
    data[wi].push_back(temp); 
    ++siz; 
    return data[wi].back().value; 
  } 
  else
    return it->value;
}

template <class T, class U, int CAPACITY>
T HashTable<T, U, CAPACITY>::operator[](const U& key) const
{
  int wi = getWrappedIndex(key);
  
  typename list<Node>::const_iterator it; 
  Node temp;
  temp.key = key; // key is parameter 
  it = find(data[wi].begin(), data[wi].end(), temp); 

  if (it == data[wi].end()) // no matching key 
  { 
    return dummy;
  } 
  else return it->value;
}

template <class T, class U, int CAPACITY>
void HashTable<T, U, CAPACITY>::clear()
{
  for(int i = 0; i < CAPACITY; i++)
    data[i].clear();
  siz = 0;
}

template <class T, class U, int CAPACITY>
bool HashTable<T, U, CAPACITY>::containsKey(const U& key) const
{
  int wi = getWrappedIndex(key);
  
  typename list<Node>::const_iterator it; 
  Node temp;
  temp.key = key; // key is parameter 
  it = find(data[wi].begin(), data[wi].end(), temp); 

  if (it == data[wi].end()) // no matching key 
  { 
    return false; 
  } 
  else
    return true;
}

template <class T, class U, int CAPACITY>
void HashTable<T, U, CAPACITY>::deleteKey(const U& key)
{
  int wi = getWrappedIndex(key);
  
  typename list<Node>::iterator it; 
  Node temp;
  temp.key = key; // key is parameter 
  it = find(data[wi].begin(), data[wi].end(), temp); 

  if (it != data[wi].end())
  {  
    data[wi].erase(it);
    siz--;
  }
}

template <class T, class U, int CAPACITY>
vector<U> HashTable<T, U, CAPACITY>::keys() const
{
  vector<U> result;
  typename list<Node>::const_iterator it; 
  for(int i = 0; i < CAPACITY; i++)
  {
    for(it = data[i].begin(); it != data[i].end(); ++it)
    {
      result.push_back(it->key);
    }      
  }
  return result;
}

#endif 