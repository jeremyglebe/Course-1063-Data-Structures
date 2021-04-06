class Node
{
public:
    Node(int data, Node *next);
    int data;
    Node *next;
};

class Stack
{
public:
    Stack();
    ~Stack();
    void push(int data);
    int pop();
    int peek();
    bool empty();

private:
    Node *top;
};