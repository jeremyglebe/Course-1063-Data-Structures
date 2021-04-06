#include <climits>
#include "Stack.h"

Node::Node(int data, Node *next)
{
    this->data = data;
    this->next = next;
}

Stack::Stack()
{
    top = nullptr;
}

Stack::~Stack()
{
    while (!empty())
    {
        pop();
    }
}

bool Stack::empty()
{
    return top == nullptr;
}

int Stack::peek()
{
    return top->data;
}

int Stack::pop()
{
    if (!empty())
    {
        int returnMe = top->data;
        Node *deleteMe = top;
        top = top->next;
        delete deleteMe;
        return returnMe;
    }
    else
    {
        return INT_MIN;
    }
}

void Stack::push(int data)
{
    top = new Node(data, top);
}