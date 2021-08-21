#include "node.hpp"
#include <iostream>

using namespace std;

Node::Node(person* Person, Node* left, Node* right, Stack* height, Stack* depth)
{
    this->Person = Person;
    this->left = left;
    this->right = right;
    this->height = height;
    this->depth = depth;
    
}

Node::Node()
{
    this->Person = NULL;
    this->left = NULL;
    this->right = NULL;
    this->height = NULL;
    this->depth = NULL;
}