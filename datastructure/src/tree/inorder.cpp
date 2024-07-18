#include <iostream>
#include <stack>

// https://www.geeksforgeeks.org/level-order-traversal-by-converting-n-ary-tree-into-adjacency-list-representation-with-k-as-root-node/
// https://www.geeksforgeeks.org/introduction-to-tree-data-structure/?ref=lbp

class node
{
    public:
        int data;
        node* left;
        node* right;
        node(int data)
            : data(data)
            , left(nullptr)
            , right(nullptr)
        {}
};

void inOrder(node* root)
{
    std::stack<node*> s;

    node* curr = root;

    while( (curr != nullptr) || (s.empty() == false))
    {
        while(curr != nullptr)
        {
            s.push(curr);
            curr = curr->left;
        }

        curr = s.top();
        s.pop();

        std::cout << curr->data << std::endl;

        curr = curr->right;
    }
}

int main()
{
    std::cout << "Binary tree" << std::endl;

    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node (4);
    root->left->right = new node(5);

    inOrder(root);
    return 0;
}
