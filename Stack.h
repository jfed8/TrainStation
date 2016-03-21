/*
 * stack.h


 *
 *  Created on: Feb 18, 2016
 *      Author: jjfeddock
 */

#ifndef STACK_H_
#define STACK_H_


using namespace std;

class Stack
{

public:
	Stack();
	virtual ~Stack() {}

	bool findNode(int data);
	void insertHead(int value);
	void insertTail(int value);
	void insertAfter(int value, int insertionNode);
	void remove(int value);
	void clear();
	int at(int index);
	int size();
	void print();

	struct Node {

		Node(int data, Node* temp) :
				value(data), next_node(temp) {};
		int value;
		Node* next_node;

	};

	int total_nodes;
	Node* firstNode;

};



#endif /* STACK_H_ */
