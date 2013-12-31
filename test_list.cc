#include <iostream>
#include <list>

void print_list(std::list<int>& l)
{
  
    std::cout << "List content: ";    
    for (std::list<int>::iterator it = l.begin(); it != l.end(); it++)
    {
        std::cout << *it << ", ";
    }
}

void print_reverse_list(std::list<int>& l)
{
    std::cout << "Reverse print: ";
    for (std::list<int>::reverse_iterator it = l.rbegin(); it != l.rend(); it++)
    {
        std::cout << *it << ", ";
    }
}


int main(int argc, char** argv)
{
    std::list<int> int_lst;

    for (int i = 0; i < 6; i++)
    {
        int_lst.push_back(i);
    }
    std::cout << "lst size now = " << int_lst.size() << std::endl;

    print_list(int_lst);

    std::cout << std::endl;

    int first = int_lst.front();
    int last = int_lst.back();
    std::cout << "first = " << first << ", last = " << last << std::endl;

    std::list<int>::iterator it_begin = int_lst.begin();
    int_lst.insert(it_begin, -1);
    std::cout << "After inserting -1 at the begining: ";
    print_list(int_lst);
    std::cout << std::endl;

    int_lst.erase(int_lst.begin());
    std::cout << "After erasing -1 at the begining: ";
    print_list(int_lst);
    std::cout << std::endl;

    std::cout << "Navigating: ";
    for (std::list<int>::iterator it = int_lst.begin(); it != int_lst.end();)
    {
        std::cout << *it << " ";
        if (*it == 4)
            it = int_lst.erase(it);
        else
            it++;
    }
    std::cout << "After element 4 removed in the list: ";
    print_list(int_lst);
    std::cout << std::endl;


    print_reverse_list(int_lst);
    std::cout << std::endl;

    int_lst.push_front(-2);
    std::cout << "After -2 added in the front: ";
    print_list(int_lst);
    std::cout << std::endl;

    int_lst.pop_front();
    std::cout << "After front popped: ";
    print_list(int_lst);
    std::cout << std::endl;

    std::list<int> int_lst2 = int_lst;

    std::cout << "List2: ";
    print_list(int_lst2);
    std::cout << std::endl;

    int_lst2.clear();
    std::cout << "After int_lst2 cleared: size = " << int_lst2.size()  << std::endl;

    for (int i = 0; i < 4; i++)
    {
        int_lst.pop_back();
    }
    std::cout << "After 4 elements in int_lst popped back: ";
    print_list(int_lst);
    std::cout << std::endl;

    return 0;
}
