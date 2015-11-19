//LAB 7b: Write And Test A Queue Template
//Programmer: Jacky Chow 
//Editor(s) used: Notepad++ 
//Compiler(s) used: Visual C++

#ifndef Queue_h
#define Queue_h

template <class T>
class Queue
{
  struct Node
  {
    T data;
    Node* next;
  };

  Node* start;
  Node* end;
  int siz;
  T dummy;
  
  public:
  Queue();
  Queue(const Queue<T>&);  
  ~Queue();
  Queue<T>& operator=(const Queue<T>&);
  int size() const{return siz;} 
  bool empty() const {return siz == 0 ? true: false;}
  T& front() {return siz != 0 ? start->data: dummy;}
  void push(const T&);
  bool pop(T&);
  void clear();
};

template <class T>
Queue<T>::Queue()
{
  start = 0;
  end = 0;
  siz = 0;
}

template <class T>
Queue<T>::Queue(const Queue<T>& a)
{
  siz = a.siz;
  end = 0;
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
Queue<T>::~Queue()
{
  while(start)
  {
    Node* p = start->next;
    delete start;
    start = p;
  }
}

template <class T>
Queue<T>& Queue<T>::operator=(const Queue<T>& a)
{
  if(this == &a) return *this;
  
  while(start)
  {
    Node* p = start->next;
    delete start;
    start = p;
  }
  
  end = 0;
  
  for(Node* p = a.start; p; p = p->next)
  {
    Node* node = new Node;
    node->data = p->data;
    node->next = 0;
    if(end) end->next = node;
    else start = node;
    end = node;
  }
  siz = a.siz;
  return *this;
}

template <class T>
void Queue<T>::push(const T& a)
{
  Node* node = new Node;
  node->data = a;
  node->next = 0;
  if(end) end->next = node;
  else start = node;
  end = node;
  ++siz;
}

template <class T>
bool Queue<T>::pop(T& a)
{
  if (!start) return false; // failed
  a = start->data;
  Node* p = start->next;
  delete start;
  start = p;
  if (!start) end = 0;
  --siz;
  return true; // success
}


template <class T>
void Queue<T>::clear()
{
  while(start)
  {
    Node* p = start->next;
    delete start;
    start = p;
  }
  siz = 0;
  end = 0;
}

#endif 