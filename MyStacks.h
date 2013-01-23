#include <iostream>
template <class T>
class ArrayStack {
 public:
  ArrayStack():top(-1),max_size(0),stack(NULL){std::cout << "Constructor without argument!" << std::endl;}
  ArrayStack(int size);      
  ~ArrayStack();
  ArrayStack<T> &operator=(const ArrayStack<T> &stack);
  bool Push(const T &data);
  bool Pop(T *data);
  bool get_top(T &data);
  bool IsEmpty() { return (top == -1);}
  bool IsFull() { return (top == (max_size - 1));}
  void Show();
  int get_size() const { return max_size; }
  int get_topptr() { return top; }
 private:
  T *stack;
  int top;
  int max_size;
};

template <class T>
ArrayStack<T>::ArrayStack(int size)
{
  std::cout << "Constructor with argument!" << std::endl;
  stack = new T[size];
  top = -1;
  max_size = size;
}

template <class T>
ArrayStack<T>::~ArrayStack()
{
//  std::cout << "Deconstructor called!" << std::endl;
  delete stack;
  stack = NULL;
}

template <class T>
ArrayStack<T> &ArrayStack<T>::operator=(const ArrayStack<T> &newstack)
{
  top = newstack.top;
  max_size = newstack.max_size;
  delete stack;
  stack = new T[max_size];
}

template <class T>
bool ArrayStack<T>::Push(const T &data)
{
  if (IsFull()) {
    return false;
  } else {
    top++;
    stack[top] = data;
    return true;
  }
}

template <class T>
bool ArrayStack<T>::Pop(T *data)
{
  if (IsEmpty()) {
    return false;
  } else {
    *data = stack[top];
    top--;
    return true;
  }
}

template <class T>
bool ArrayStack<T>::get_top(T &top_data)
{
  if (IsEmpty()) {
    return false;
  } else {
    top_data = stack[top];
    return true;
  }
}

template <class T>
void ArrayStack<T>::Show()
{
  //std::cout << "Stack Content: " << std::endl;
  for (int i = top; i >= 0; i--)
    std::cout << stack[i] << std::endl;
  std::cout << std::endl;
}

template <class T> class ListStack;
template <class T>
class Node {
 public:
  Node(){}
  Node(const T &new_data):data(new_data),next(NULL) {}
 private:
  friend class ListStack<T>;
  T data;
  Node<T> *next;
};

template <class T>
class ListStack {
 public:
  ListStack();
  ~ListStack();
  bool Push(const T &data);
  bool Pop(T *pdata);
  bool get_top(T *ptop_data);
  bool IsEmpty();
  bool IsFull();
  void Show();
 private:
  Node<T> *top;
};

template <class T>
ListStack<T>::ListStack()
{
  top = NULL;  
}

template <class T>
ListStack<T>::~ListStack()
{
  Node<T> *pnode = top;
  Node<T> *pcur_node;
  while (pnode)
  {
    pcur_node = pnode;
    pnode = pnode->next;
    pcur_node->next = NULL;
    delete pcur_node;
  }
}

template <class T>
bool ListStack<T>::Push(const T &data)
{
  if(IsFull())
    return false;
  Node<T> *pnode = new Node<T>(data); 
  pnode->next = top;
  top = pnode;
  return true;
}

template <class T>
bool ListStack<T>::Pop(T *pdata)
{
  if(IsEmpty())
    return false;

  Node<T> *old_top = top;
  top = top->next;
  old_top->next = NULL;
  *pdata = old_top->data;
  delete old_top;
  return true;
}

template <class T>
bool ListStack<T>::get_top(T *ptop_data)
{
  if(IsEmpty())
    return false;

  *ptop_data = top->data;
  return true;
}

template <class T>
bool ListStack<T>::IsEmpty()
{
  return (top == NULL);
}

template <class T>
bool ListStack<T>::IsFull()
{
  try {
    Node<T> *pnode = new Node<T>;
    delete pnode;
    return false;
  } catch (std::bad_alloc &memmoryAllocationException) {
    return true;
  }
}

template <class T>
void ListStack<T>::Show()
{
  Node<T> *pnode = top;
  while (pnode)
  {
    std::cout << pnode->data << " ";
    pnode = pnode->next;
  }
  std::cout <<std::endl;
}
