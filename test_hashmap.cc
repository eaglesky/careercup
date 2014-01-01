#include <iostream>
#include <unordered_map>

int main(int argc, char** argv)
{
    std::unordered_map<std::string, char> grade_list;

    grade_list["John"] = 'B';
    grade_list["Allen"] = 'A';
    grade_list["Jack"] = 'C';

    std::cout << "Grade list size = " << grade_list.size() << std::endl;
    
    if(grade_list.find("Tim") == grade_list.end())
    {
        std::cout<<"Tim is not in the map!"<<std::endl;
    }

    std::unordered_map<std::string, char>::iterator it = grade_list.find("Allen"); 
    if (it == grade_list.end())
    {
        std::cout << "Allen is not in the map!" << std::endl; 
    } else {
        std::cout << "Allen's grade is : " << it->second << std::endl;
    }

    it = grade_list.find("Jack");
    std::cout << "Jack's grade before change: " << it->second << std::endl;
    grade_list["Jack"] = 'B';
    std::cout << "Jack's grade after change: " << it->second << std::endl;
    std::cout << "Student's name: " << it->first << std::endl;

    grade_list.erase("Jack");
    if(grade_list.find("Jack") == grade_list.end())
        std::cout << "After erasing, Jack is not in the map any more!" << std::endl;

    grade_list["Lily"] = 'A';
    std::cout << "After adding Lily, the grade list: " << std::endl;
    for (it = grade_list.begin(); it != grade_list.end(); it++)
        std::cout << it->first << ", " << it->second << std::endl;

    grade_list.clear();
    std::cout << "After clearing the grade list, size = " << grade_list.size() << std::endl;
    return 0;
}
