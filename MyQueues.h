#include <iostream>

template <class T>
class ArrayQueue {
 public:
  explicit ArrayQueue(int size = 10);
  ~ArrayQueue();
  bool IsEmpty();
  bool IsFull();
  bool EnQueue(const T &new_data);
  bool DeQueue(T *popped_data);
  T get_front() { return queue[front]; }
  T get_rear() { return queue[(rear - 1 + max_size) % max_size]; }
  void Show();

 private:
  T* queue;
  int front;
  int rear;
  int max_size;
};

template <class T>
ArrayQueue<T>::ArrayQueue(int size) //Is it ok without 'explicit'??
{
  queue = new T[size];
  front = rear = 0;
  max_size = size;

}

template <class T>
ArrayQueue<T>::~ArrayQueue()
{
  delete queue;
}

template <class T>
bool ArrayQueue<T>::IsEmpty()
{
  return (front == rear);
}

template <class T>
bool ArrayQueue<T>::IsFull()
{
  return ((rear + 1 - front) % max_size == 0);
}

template <class T>
bool ArrayQueue<T>::EnQueue(const T &new_data)
{
  if (IsFull())
    return false;

  queue[rear] = new_data;
  rear = (rear + 1) % max_size;
  return true;
}

template <class T>
bool ArrayQueue<T>::DeQueue(T *popped_data)
{
  if (IsEmpty())
    return false;

  *popped_data = queue[front];
  front = (front + 1) % max_size;
  return true;
}

template <class T>
void ArrayQueue<T>::Show()
{
  for (int i = front; i < rear; i = (i + 1) % max_size)
  {
    std:: cout << queue[i] << " ";
  }
 std::cout << std::endl;
}

template <class T>
class ListQueue {
  
}
