#include <iostream>

template<class T> class LinkedList;

template<class T>
class LinkedNode {
 public:
  LinkedNode(T new_data):data(new_data) {; }

 private:
  friend class LinkedList<T>; //Attention! Friend class must have been declared
  LinkedNode<T> *next;
  T data;
};

template<class T>
class LinkedList {
 public:
  LinkedList();
  LinkedList(const LinkedList<T> &list);
  ~LinkedList();
  void PushNode(T new_data);
  void Delete(LinkedNode<T> *pnode);
  bool CopyDelete(LinkedNode<T> *pnode);
  bool CopyDeleteMiddle(); 
  void Show();
  int get_length();
  void Clear();
  LinkedList<T> operator+(LinkedList<T> &list);
  LinkedList<T> &operator=(const LinkedList<T> &list);
 //  T FindToLast(int pos);
  LinkedNode<T> *head;
  LinkedNode<T> *tail;

 private:
  int length;
};

template<class T>
LinkedList<T>::LinkedList()
{
  head = tail = NULL;
  length = 0;
}

template<class T>
LinkedList<T>::LinkedList(const LinkedList<T> &list)
{
  length = 0;
  head = tail = NULL;
  LinkedNode<T> *pnode = list.head;
  while(pnode)
  {
    PushNode(pnode->data);
    pnode = pnode->next;
  }
}

template<class T>
LinkedList<T>::~LinkedList()
{
  LinkedNode<T> *ptr = head;
  while (ptr)
  {
    LinkedNode<T> *ptr_del = ptr;
    ptr = ptr->next;
    Delete(ptr_del);
  }
}

template<class T>
void LinkedList<T>::PushNode(T new_data)
{
  LinkedNode<T> *pnew_node = new LinkedNode<T>(new_data);
  pnew_node->next = NULL;
  if (!length) {
    head = tail = pnew_node;
    length++;
  } else {
    tail->next = pnew_node;
    tail = pnew_node;
    length++;
  }
}

template<class T>
void LinkedList<T>::Delete(LinkedNode<T> *pnode)
{
  LinkedNode<T> *ptr = head;
  if (pnode==head) {
    head = pnode->next;
    ptr = head;
  } else {
    while(ptr->next != pnode)
    {
      ptr = ptr->next;
    }    
    ptr->next = pnode->next;
  }
  if(pnode == tail)
     tail = ptr;

  delete pnode;
  length--;
}

template<class T>
void LinkedList<T>::Show()
{
  LinkedNode<T> *pnode = head;
  while(pnode)
  {
    std::cout << pnode->data << " ";
    pnode = pnode->next;
  }
  std::cout << " (" << length << ")" << std::endl;  
}

template <class T>
int LinkedList<T>::get_length()
{
  return length;
}

template <class T>
bool LinkedList<T>::CopyDelete(LinkedNode<T> *pnode)
{
  if (length == 1) {
    delete pnode;
    length--;
    head = tail = NULL;
    return true;
  } else if (!pnode || !(pnode->next)) {
    return false;
  }
  
  pnode->data = pnode->next->data;
  LinkedNode<T> *pnext_node = pnode->next;
  pnode->next = pnext_node->next;
  length--;
  if (!pnext_node->next)
    tail = pnode;
  delete pnext_node;
  return true;    
}

template <class T>
bool LinkedList<T>::CopyDeleteMiddle()
{
  LinkedNode<T> *pnode = head;
  for (int i = 1; i < (length + 1) / 2; i++)
  {
    pnode = pnode->next;
  }
  return CopyDelete(pnode);
}

template <class T>
void LinkedList<T>::Clear()
{
  LinkedNode<T> *ptr = head;
  while (ptr)
  {
    LinkedNode<T> *ptr_del = ptr;
    ptr = ptr->next;
    Delete(ptr_del);
  }
}

template <class T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList<T> &list)
{ // The argument must be const in order to bind temporary variable!!
  if (&list != this) {
    Clear();
    LinkedNode<T> *pnode = list.head;
    while(pnode)
    {
      PushNode(pnode->data);
      pnode = pnode->next;
    }
  }
  return *this;
}

template <class T>
LinkedList<T> LinkedList<T>::operator+(LinkedList<T> &list)
{
  int carry = 0;
  LinkedList<T> sum_list;
  LinkedNode<T> *pnode = list.head;
  LinkedNode<T> *pnode_this = head;
  if (!pnode || !pnode_this)
    throw("Invalid list!");
  
  T digit, digit_this, digit_sum;
  while(pnode || pnode_this)
  {
    if (!pnode) {
      digit = 0;
      digit_this = pnode_this->data;
      pnode_this = pnode_this->next;
    } else if (!pnode_this) {
      digit = pnode->data;
      digit_this = 0;
      pnode = pnode->next;
    } else {
      digit = pnode->data;
      digit_this = pnode_this->data;
      pnode = pnode->next;
      pnode_this = pnode_this->next;
    }
    digit_sum = digit + digit_this + carry;
    if (digit_sum >=10) {
      digit_sum-=10;
      carry = 1;
    } else {
      carry = 0;
    }
    sum_list.PushNode(digit_sum);
    
  }
  if (carry == 1)
    sum_list.PushNode(1);

  return sum_list;
}
