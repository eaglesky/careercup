#include "MyStacks.h"

template <class T>
class ArrayStackMin : public ArrayStack<T> {
 public:
  ArrayStackMin(int size = 10);
  ~ArrayStackMin(){ delete min_stack; }
  bool Push(const T &data);
  bool Pop(T &data);
  bool GetMin(T *pmin);
  void ShowMin();

 private:
  T *min_stack;
  int min_top;
};

template <class T>
ArrayStackMin<T>::ArrayStackMin(int size) : ArrayStack<T>(size)
{
  min_stack = new T[size];
  min_top = -1;
}

template <class T>
bool ArrayStackMin<T>::Push(const T &data)
{
  if (!ArrayStack<T>::Push(data))
    return false;

  if (min_top > -1) {
    if (data <= min_stack[min_top]) {
      min_top++;
      min_stack[min_top] = data;
    }
  } else {
    min_top++;
    min_stack[min_top] = data;
  }
  return true;
}

template <class T>
bool ArrayStackMin<T>::Pop(T &data)
{
  if (!ArrayStack<T>::Pop(data))
    return false;
  
  if (data == min_stack[min_top])
    min_top--;

  return true;
}

template <class T>
bool ArrayStackMin<T>::GetMin(T *pmin)
{
  if (ArrayStack<T>::IsEmpty())
    return false;

  *pmin = min_stack[min_top];
  return true;
}

template <class T>
void ArrayStackMin<T>::ShowMin()
{
  std::cout << "Min Stack:" << std::endl;
  for (int i = 0; i <= min_top; i++)
    std::cout << min_stack[i] << " ";

  std::cout << std::endl;
}

