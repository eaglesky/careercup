#include <iostream>

template<class T> class CLinkedList;

template<class T>
class CLinkedNode {
 public:
  CLinkedNode(T new_data):data(new_data) {; }

 private:
  friend class CLinkedList<T>; //Attention! Friend class must have been declared
  CLinkedNode<T> *next;
  T data;
};

template<class T>
class CLinkedList {
 public:
  CLinkedList();
  CLinkedList(const CLinkedList<T> &list);
  ~CLinkedList();
  void PushNode(T new_data);
  void Delete(CLinkedNode<T> *pnode);
  void Show();
  int get_length();
  T get_data(CLinkedNode<T> *pnode);
  void Clear();
  CLinkedList<T> &operator=(const CLinkedList<T> &list);
  void CreateCList(int s_len, int l_len);
  CLinkedNode<T> *GetLoopStart();
 //  T FindToLast(int pos);
  CLinkedNode<T> *head;
  CLinkedNode<T> *tail;

 private:
  int length;
};

template<class T>
CLinkedList<T>::CLinkedList()
{
  head = tail = NULL;
  length = 0;
}

template<class T>
CLinkedList<T>::CLinkedList(const CLinkedList<T> &list)
{
  length = 0;
  head = tail = NULL;
  CLinkedNode<T> *pnode = list.head;
  while(pnode)
  {
    PushNode(pnode->data);
    pnode = pnode->next;
  }
}

template<class T>
CLinkedList<T>::~CLinkedList()
{
  CLinkedNode<T> *ptr = head;
  for (int i = 0; i < length; i++)
  {
    CLinkedNode<T> *ptr_del = ptr;
    ptr = ptr->next;
    ptr_del->next = NULL;
    delete(ptr_del); 
  }
}

template<class T>
void CLinkedList<T>::PushNode(T new_data)
{
  CLinkedNode<T> *pnew_node = new CLinkedNode<T>(new_data);
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
void CLinkedList<T>::Delete(CLinkedNode<T> *pnode)
{
  CLinkedNode<T> *ptr = head;
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
void CLinkedList<T>::Show()
{
  CLinkedNode<T> *pnode = head;
  for (int i = 0; i < length+1; i++)
  {
    std::cout << pnode->data << " ";
    pnode = pnode->next;
  }
  std::cout << " (" << length << ")" << std::endl;  
}

template <class T>
int CLinkedList<T>::get_length()
{
  return length;
}

template <class T>
void CLinkedList<T>::Clear()
{
  CLinkedNode<T> *ptr = head;
  while (ptr)
  {
    CLinkedNode<T> *ptr_del = ptr;
    ptr = ptr->next;
    Delete(ptr_del);
  }
}

template <class T>
CLinkedList<T>& CLinkedList<T>::operator=(const CLinkedList<T> &list)
{ // The argument must be const in order to bind temporary variable!!
  if (&list != this) {
    Clear();
    CLinkedNode<T> *pnode = list.head;
    while(pnode)
    {
      PushNode(pnode->data);
      pnode = pnode->next;
    }
  }
  return *this;
}

template <class T>
void CLinkedList<T>::CreateCList(int s_len, int l_len)
{
  int cur_data;

  for (int i = 0; i < s_len; i++)
  {
    cur_data = i+1;
    PushNode(cur_data);
  }
  
  cur_data = s_len + 1;
  PushNode(cur_data);
  CLinkedNode<int> *ploop_start = tail;
  for (int i = 2; i <= l_len; i++)
  {
    cur_data = i + s_len ;
    PushNode(cur_data);
  }
  tail->next = ploop_start;

}

template <class T>
CLinkedNode<T> *CLinkedList<T>::GetLoopStart()
{
  CLinkedNode<T> *slow = head;
  CLinkedNode<T> *fast = head;
  slow = slow->next;
  fast = fast->next->next;
  while (slow && fast)
  {
    if (slow == fast) {
      break;
    } else {
      slow = slow->next;
      fast = fast->next->next;
    }
  }
  if (!slow || !fast)
    return NULL;
  fast = head;
  while (slow && fast)
  {
    if (slow == fast) {
      break;
    } else {
      slow = slow->next;
      fast = fast->next;
    }
  }
  return (slow == fast)?slow:NULL;
}

template <class T>
T CLinkedList<T>::get_data(CLinkedNode<T> *pnode)
{
  if(pnode)
    return pnode->data;
}
