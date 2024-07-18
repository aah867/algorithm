// ------------ CYCLE IN LINKED LIST ---------------

class Node {
    public:
        int data;
        Node *next;
        Node(int d): data(d), next(nullptr)
        {}
};

bool checkLoop(Node* head)
{
    if (!head) return false;
    if (head->data == -1) {
        return true;
    }
    head->data = -1;
    checkLoop(head->next);
}



std::map<Node*, bool> vis;
bool flag = false;

bool checkCycle(Node* head) {
    if (head == nullptr)
    {
        flag = false;
        return flag;
    }
    if (!vis[head])
    {
        vis[head] = true;
        checkCycle(head->next);
    }
    else
    {
        flag = true;
        return flag;
    }
    return flag;   
}

int main() {
    Node *head = new Node(20);
    
    head->next = new Node(5);
    head->next->next = new Node(4);
    head->next->next->next = new Node(15);
}

// ------------ CYCLE IN LINKED LIST ---------------
