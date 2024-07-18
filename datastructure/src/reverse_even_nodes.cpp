#include <iostream>
#include <vector>

/**
 * @brief Given a singly linked list, reverse the nodes at even indices
 * (starting at 1).
 *
 */

struct node
{
    int data;
    node *next;
    node(int d): data(d), next(nullptr) {}
};

class LinkedList
{
    private:
        node *head, *tail;
    public:
        LinkedList(): head(nullptr), tail(nullptr)
        {}

        void add_node(int n)
        {
            node *tmp = new node(n);

            if (head == nullptr)
            {
                head = tmp;
                tail = tmp;
            }
            else
            {
                tail->next = tmp;
                tail = tmp;
            }
        }

        void add_node(std::vector<int> arr)
        {
            for (auto i: arr)
            {
                node *tmp = new node(i);
                if (head == nullptr)
                {
                    head = tmp;
                    tail = tmp;
                }
                else
                {
                    tail->next = tmp;
                    tail = tmp;
                }
            }
        }

        void display()
        {
            node *tmp = head;
            while (tmp != nullptr)
            {
                std::cout << tmp->data << " ";
                tmp = tmp->next;
            }
        }
};

node* create_linked_list(std::vector<int> v)
{
    node *list;
    return nullptr;
}

void reverse_even_nodes(node* head)
{
    node* curr = head;
    node* list_even = nullptr;

    while(curr != nullptr && list_even != nullptr)
    {
        node* even = curr->next;
        curr->next = even->next;
        even->next = list_even;
        list_even = even;
        curr = curr->next;
    }
}

void merge_linked_list(node *list, node*list_even)
{
    node* curr = list;
    while (curr != nullptr  && list_even != nullptr)
    {
        node* item = list_even;
        list_even = list_even->next;
        item->next = curr->next;
        curr->next = item;
    }

    if(list_even != nullptr)
    {
        curr->next = list_even;
    }
}

int main()
{
    LinkedList a;
    std::vector<int> v1 = {7, 14, 21, 28, 9};
    a.add_node(v1);
    a.display();
}
