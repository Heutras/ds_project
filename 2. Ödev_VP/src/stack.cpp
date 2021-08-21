#include "stack.hpp"
#include <iostream>

using namespace std;

sNode::sNode(const int& tmp_data, sNode *tmp_next=NULL)
{
    data=tmp_data;
    next=tmp_next;
}
sNode::sNode()
{
    data = 0;
    next = NULL;
}
Stack::Stack()
{
    head=NULL;
}

bool Stack::isEmpty()
{
    return head == NULL;
}

void Stack::push(const int& data)
{
    head = new sNode(data, head);
}

void Stack::pop()
{
    if (!isEmpty())
    {
        sNode *temp = head;
        head = head->next;
        delete temp;
    }
    
}

const int& Stack::top()
{
    if (!isEmpty())
    {
        return head->data;
    }
    
}

void Stack::makeEmpty()
{
    while (!isEmpty())
    {
        pop();
    }
    
}

Stack::~Stack()
{
    makeEmpty();
}