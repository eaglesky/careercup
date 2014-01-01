#include <iostream>
#include <map>

int main(int argc, char** argv)
{
    std::multimap<std::string, int> m;


    m.insert(std::pair<std::string, int>("a", 1));
    m.insert(std::pair<std::string, int>("c", 2));
    m.insert(std::pair<std::string, int>("b", 3));
    m.insert(std::pair<std::string, int>("b", 4));
    m.insert(std::pair<std::string, int>("a", 5));
    m.insert(std::pair<std::string, int>("b", 6));

    std::cout << "Number of elements with key a: " << m.count("a") << std::endl;
    std::cout << "Number of elements with key b: " << m.count("b") << std::endl;
    std::cout << "Number of elements with key c: " << m.count("c") << std::endl;

    std::string word("b");
    std::cout << "b: " << std::endl;
    for (std::multimap<std::string, int>::iterator it = m.lower_bound(word); it != m.upper_bound(word); it++)
    {
        std::cout << it->second << std::endl;
    }

    return 0;
}
