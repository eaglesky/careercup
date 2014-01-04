#include <iostream>

typedef struct list_node {
    int data;
    struct list_node* next;
} list_node;

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

list_node* add_lists(list_node* l1, list_node* l2)
{
    list_node* p1 = l1;
    list_node* p2 = l2;
    list_node* sum = NULL;
    list_node* ps = sum;
    int carry = 0;

    while (p1 || p2)
    {
        int d1 = p1 ? p1->data : 0;
        int d2 = p2 ? p2->data : 0;

        int d_sum = carry + d1 + d2;

        if (d_sum >= 10) {
            d_sum -= 10;
            carry = 1;
        } else
            carry = 0;

        if (!ps) {
            ps = new list_node;
            sum = ps;
        }
        else {
            ps->next = new list_node;
            ps = ps->next;
        }

        ps->data = d_sum;
        ps->next = NULL;

        if (p1)
            p1 = p1->next;

        if (p2)
            p2 = p2->next;
    }

    if (carry) {
        ps->next = new list_node;
        ps = ps->next;
        ps->data = 1;
        ps->next = NULL;
    }
    return sum;
}

list_node* add_lists(list_node* l1, list_node* l2, int carry)
{
    list_node* sum = NULL;
    int next_carry = 0;
    if (l1||l2) {
        sum = new list_node;
        int d1 = l1 ? l1->data : 0;
        int d2 = l2 ? l2->data : 0;
        sum->data = carry + d1 + d2;
        if (sum->data >= 10) {
            sum->data -= 10;
            next_carry = 1;
        }

        list_node* lnext1 = l1 ? l1->next : NULL;
        list_node* lnext2 = l2 ? l2->next : NULL;
        sum->next = add_lists(lnext1, lnext2, next_carry);

    } else if (carry) {
        sum = new list_node;
        sum->data = carry;
        sum->next = NULL;
    }

    return sum;
}


int main(int argc, char** argv)
{
    int test_data1[3] = {0, 1, 2};
    int test_data2[2] = {9, 9};
    int test_data3 = 8;
    int test_data4[3] = {8, 7, 9};

    list_node* l1 = create_list(test_data1, 3);
    list_node* l2 = create_list(test_data2, 2);
    list_node* l3 = create_list(&test_data3, 1);
    list_node* l4 = create_list(test_data4, 3);

    std::cout << "Test1: ";
    print_list(l1);
    std::cout << " + ";
    print_list(l2);
    std::cout << std::endl;
    list_node* sum1 = add_lists(l1, l2, 0);
    std::cout << " = ";
    print_list(sum1);
    std::cout << std::endl;

    std::cout << "Test2: ";
    print_list(l2);
    std::cout << " + ";
    print_list(l3);
    std::cout << std::endl;
    list_node* sum2 = add_lists(l2, l3, 0);
    std::cout << " = ";
    print_list(sum2);
    std::cout << std::endl;

    std::cout << "Test3: ";
    print_list(l1);
    std::cout << " + ";
    print_list(l4);
    std::cout << std::endl;
    list_node* sum3 = add_lists(l1, l4, 0);
    std::cout << " = ";
    print_list(sum3);
    std::cout << std::endl;

 
    std::cout << "Test4: ";
    print_list(l4);
    std::cout << " + ";
    print_list(NULL);
    std::cout << std::endl;
    list_node* sum4 = add_lists(l4, NULL, 0);
    std::cout << " = ";
    print_list(sum4);
    std::cout << std::endl;

    std::cout << "Test5: ";
    print_list(NULL);
    std::cout << " + ";
    print_list(NULL);
    std::cout << std::endl;
    list_node* sum5 = add_lists(NULL, NULL, 0);
    std::cout << " = ";
    print_list(sum5);
    std::cout << std::endl;


   
    destroy_list(l1);
    destroy_list(l2);
    destroy_list(l3);
    destroy_list(l4);
    destroy_list(sum1);
    destroy_list(sum2);
    destroy_list(sum3);
    destroy_list(sum4);
    destroy_list(sum5);
    return 0;
}
