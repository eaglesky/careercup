#include <iostream>
#include <unordered_set>

typedef struct list_node {
    int data;
    struct list_node* next;
} list_node;

void remove_dup(list_node* l)
{
    std::unordered_set<int> flags;

    if (l) {
        list_node* parent = l;
        list_node* runner = l->next;

        flags.insert(parent->data);
        while (runner)
        {
            int cur_data = runner->data;
            if (flags.find(cur_data) == flags.end()) {
                flags.insert(cur_data);
                parent = runner;
                runner = runner->next;
            } else {
                parent->next = runner->next;
                delete runner;
                runner = parent->next;
                
            }
        }
    }    
}

list_node* create_list(int* node_data, int num)
{
    list_node* header = NULL;
    list_node* p;
    for (int i = 0; i < num; i++)
    {
        if (i == 0) {
            p = new list_node;
            header = p;
        } else {
            p->next = new list_node;
            p = p->next;
        }
       p->data = node_data[i];
    }
    p->next = NULL;

    return header;
}

void destroy_list(list_node* list)
{
    list_node* p = list;
    while(p)
    {
        list_node* q = p;
        p = p->next;
        delete q;
    }
    list = NULL;
}

void print_list(list_node* list)
{
    list_node* p = list;

    while(p)
    {
        std::cout << p->data << ", ";
        p = p->next;
    }
}

int main(int argc, char** argv)
{
    int test_data1[6] = {0, 1, 2, 3, 4, 5};
    int test_data2[6] = {1, 1, 1, 1, 1, 1};
    int test_data3[6] = {0, 0, 2, 3, 4, 4};
    int test_data4[6] = {0, 1, 0, 3, 4, 3};

    list_node* l = create_list(test_data1, 6);
    std::cout << "test1: ";
    print_list(l);
    std::cout << std::endl;
    remove_dup(l);
    std::cout << "Result: ";
    print_list(l);
    std::cout << std::endl;
    destroy_list(l);

    l = create_list(test_data2, 6);
    std::cout << "test2: ";
    print_list(l);
    std::cout << std::endl;
    remove_dup(l);
    std::cout << "Result: ";
    print_list(l);
    std::cout << std::endl;
    destroy_list(l);

    
    l = create_list(test_data3, 6);
    std::cout << "test3: ";
    print_list(l);
    std::cout << std::endl;
    remove_dup(l);
    std::cout << "Result: ";
    print_list(l);
    std::cout << std::endl;
    destroy_list(l);

    
    l = create_list(test_data4, 6);
    std::cout << "test4: ";
    print_list(l);
    std::cout << std::endl;
    remove_dup(l);
    std::cout << "Result: ";
    print_list(l);
    std::cout << std::endl;
    destroy_list(l);

    
    
    
    
    return 0;
}
