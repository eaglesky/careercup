#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;

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
  ~LinkedList();
  void PushNode(T new_data);
  void Delete(LinkedNode<T> *pnode);
  void Show();
  T FindToLast(int pos);
 private:
  LinkedNode<T> *head;
  LinkedNode<T> *tail;
  int length;
};

template<class T>
LinkedList<T>::LinkedList()
{
  head = tail = NULL;
  length = 0;
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
    cout << pnode->data << endl;
    pnode = pnode->next;
  }
  cout << "In total: " << length << endl;  
}

template<class T>
T LinkedList<T>::FindToLast(int pos)
{
  if(pos < 1 || pos > length) {
    throw("Invalid position!");
  } else {  
    LinkedNode<T> *pnode = head;
    for (int i = 1; i < length - pos + 1; i++)
    {
      pnode = pnode->next;
    }
   return pnode->data; 
  }
}

int main(int argc, char *argv[])
{
  int list_len = 5;
  srand(time(0));
  if (argc > 1)
    list_len = atoi(argv[1]);

  LinkedList<int> test_list;

  for (int i = 0; i < list_len; i++)
  {
    int cur_data = rand()%list_len;      
    test_list.PushNode(cur_data);
  }
  test_list.Show();
  try {  
    int pos;
    cout << "Which posision?" << endl;
    cin >> pos;
    cout << "Data is:" << endl;
    cout << test_list.FindToLast(pos) << endl;
  } catch (char const*err) {
    cout << err << endl;
  }
  return 0;
}
