/*
 * Deque.cpp
 *
 *  Created on: Feb 18, 2016
 *      Author: jjfeddock
 */

#include "Deque.h"

#include <cstdlib>
#include <iostream>

using namespace std;

Deque::Deque()
{
		firstNode = NULL;
		total_nodes = 0;
}


bool Deque::findNode(int data)
{

	if (firstNode == NULL)
		return false;

	Node* runner;
	runner = firstNode;

	if (runner->value == data)
		return true;

    for (int i = 0; i < total_nodes-1; i++) {

                    if (runner->next_node != NULL)
                            runner = runner->next_node;

        if (runner->value == data) {
            return true;
        }

    }

	return false;
}

void Deque::insertHead(int value) {

    if (findNode(value) == false) {
                firstNode = new Node(value, firstNode);
                total_nodes++;
            }
}

void Deque::insertTail(int value) {

    if (findNode(value) == false) {

            if (size() == 0)
            {
                Node *test;
                test = new Node(value, NULL);
                firstNode = test;
                total_nodes++;


            }
            else {

                Node *test;
                test = firstNode;
                for (int i=0; i<size()-1; i++)
                        test = test->next_node;

                test->next_node = new Node(value, NULL);
                total_nodes++;
            }
     }
}

void Deque::insertAfter(int value, int insertionNode) {

	if (findNode(value) == false) {
		if (findNode(insertionNode) == true) {
			Node* temp1;
			temp1 = firstNode;

			if (firstNode->value == insertionNode) {
				Node *temp = new Node(value, firstNode->next_node);
				firstNode->next_node = temp;
				total_nodes++;
				return;
				}



			for (int i = 0; i < total_nodes; i++) {

				if (temp1->next_node != NULL)
					temp1 = temp1->next_node;

				if (temp1->value == insertionNode) {
					Node *temporary;
					temporary = new Node(value, temp1->next_node);
					temp1->next_node = temporary;
					total_nodes++;
				}
			}



		}
	}
}

void Deque::remove(int value) {

    if (findNode(value) == true) {

            Node* seeker;
            seeker = firstNode;

            if (firstNode->value == value)
            {
                Node* dele;
                dele = firstNode;

                firstNode = firstNode->next_node;
                delete dele;
                total_nodes--;
                return;
            }

            while (seeker->next_node->value != value && seeker->next_node != NULL)
            {
                seeker = seeker->next_node;
            }

            Node* del;
            del = seeker->next_node;

            seeker->next_node = seeker->next_node->next_node;
            total_nodes--;
            delete del;

    }

}

void Deque::clear() {

    while(firstNode != NULL) {
        remove(firstNode->value);
    }
    total_nodes = 0;
    return;
}

int Deque::at(int index) {

    Node* finder;
    finder = firstNode;


    for(int i = 0; i<index; i++){

        finder = finder->next_node;

    }

    return finder->value;
}

int Deque::size() {

    return total_nodes;
}

void Deque::print() {
	for (int i=0; i<size(); i++)
	{
		cout << at(i) << " ";
	}
}


