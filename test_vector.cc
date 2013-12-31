#include <iostream>
#include <vector>

void print_vector(std::vector<int>& v)
{
  
    
    std::cout << "(v.size= " << v.size() << ", v.capacity= " << v.capacity() << "): ";
    for (std::vector<int>::iterator it = v.begin(); it != v.end(); it++)
    {
        std::cout << *it << ", ";
    }
}

void print_reverse_vector(std::vector<int>& v)
{
    std::cout << "Reverse print: ";
    for (std::vector<int>::reverse_iterator it = v.rbegin(); it != v.rend(); it++)
    {
        std::cout << *it << ", ";
    }
}

int main(int argc, char** argv)
{
    std::vector<int> int_vec;
    int_vec.reserve(5);
    std::cout << "vec element number = " << int_vec.size() << std::endl;
    std::cout << "vec size without reallocation= " << int_vec.capacity() << std::endl;

    for (int i = 0; i < 6; i++)
    {
        int_vec.push_back(i);
    }
    std::cout << "vec size now = " << int_vec.size() << std::endl;
    std::cout << "vec capacity now = " << int_vec.capacity() << std::endl;

    std::cout << "vec content: " ;

    print_vector(int_vec);

    std::cout << ";  ";
    
    for (int i = 0; i < int_vec.size(); i++)
        std::cout << int_vec.at(i) << ", ";
    std::cout << std::endl;

    int first = int_vec.front();
    int last = int_vec.back();
    std::cout << "first = " << first << ", last = " << last << std::endl;

    std::vector<int>::iterator it_begin = int_vec.begin();
    int_vec.insert(it_begin, -1);
    std::cout << "After inserting -1 at the begining: ";
    print_vector(int_vec);
    std::cout << std::endl;

    int_vec.erase(int_vec.begin());
    std::cout << "After erasing -1 at the begining: ";
    print_vector(int_vec);
    std::cout << std::endl;

    std::vector<int> int_vec2 = int_vec;
    std::cout << "int_vec2 capacity = " << int_vec2.capacity()<< std::endl;

    print_vector(int_vec2);
    std::cout << std::endl;

    int_vec2.clear();
    std::cout << "After int_vec2 cleared: size = " << int_vec2.size() << ", capacity= " << int_vec2.capacity() << std::endl;


    print_reverse_vector(int_vec);
    std::cout << std::endl;

    for (int i = 0; i < 4; i++)
    {
        int_vec.pop_back();
    }
    std::cout << "After 4 elements in int_vec popped back: ";
    print_vector(int_vec);
    std::cout << std::endl;

    return 0;
}
