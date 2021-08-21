#ifndef STACK_HPP
#define STACK_HPP

#include <iostream>

using namespace std;

class sNode{
	public:
		int data;
		sNode *next;
		sNode(const int&, sNode*);
		sNode();

};

class Stack{
	public:
		sNode *head;
		Stack();
		bool isEmpty();
		void push(const int& data);
		void pop();
		const int& top();		
		void makeEmpty();
		~Stack();	
};
#endif