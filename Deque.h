/*
 * Deque.h
 *
 *  Created on: Feb 18, 2016
 *      Author: jjfeddock
 */

#ifndef DEQUE_H_
#define DEQUE_H_



class Deque
{

public:
	Deque();
	virtual ~Deque() {}

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



#endif /* DEQUE_H_ */
