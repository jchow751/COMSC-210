//LAB 7a: Write And Apply A Stack Template
//Programmer: Jacky Chow 
//Editor(s) used: Notepad++ 
//Compiler(s) used: Visual C++

#ifndef Stack_h
#define Stack_h
  
template <class T>
class Stack
{
  struct Node
  {
    T data;
    Node* next;
  };
  Node* start;
  int siz;
  T dummy;
  
  public:
  Stack();
  Stack(const Stack<T>&);  
  ~Stack();
  Stack<T>& operator=(const Stack<T>&);
  int size() const{return siz;} 
  bool empty() const {return siz == 0 ? true: false;}
  T& peek(){return siz != 0 ? start->data: dummy;}
  void push(const T&);
  bool pop(T&);
  void clear();
};

template <class T>
Stack<T>::Stack()
{
  start = 0;
  siz = 0;
}

template <class T>
Stack<T>::Stack(const Stack<T>& a)
{
  siz = a.siz;
  Node* end = 0;
  start = 0;
  for(Node* p = a.start; p; p = p->next)
  {
    Node* node = new Node;
    node->data = p->data;
    node->next = 0;
    if(end) end->next = node;
    else start = node;
    end = node;
  }
}

template <class T>
Stack<T>::~Stack()
{
  while(start)
  {
    Node* p = start->next;
    delete start;
    start = p;
  }
}

template <class T>
Stack<T>& Stack<T>::operator=(const Stack<T>& a)
{
  if(this == &a) return *this;
  
  while(start)
  {
    Node* p = start->next;
    delete start;
    start = p;
  }
  
  siz = a.siz;
  start = 0;
  Node* end = 0;
  for(Node* p = a.start; p; p = p->next)
  {
    Node* node = new Node;
    node->data = p->data;
    node->next = 0;
    if(end) end->next = node;
    else start = node;
    end = node;
  }
  return *this;
}

template <class T>
void Stack<T>::push(const T& a)
{
  Node* node = new Node;
  node->data = a;
  node->next = start;
  start = node;
  siz++;
}

template <class T>
bool Stack<T>::pop(T& a)
{
  if (0 == siz) return false; // failed
  a = start->data;
  Node* p = start->next;
  delete start;
  start = p;
  --siz;
  return true; // success
}


template <class T>
void Stack<T>::clear()
{
  while(start)
  {
    Node* p = start->next;
    delete start;
    start = p;
  }
  siz = 0;
}

#endif 
