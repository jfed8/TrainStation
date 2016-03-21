/*
 * Station.cpp
 *
 *  Created on: Feb 12, 2016
 *      Author: jjfeddock
 */

#include "StationInterface.h"
#include "Station.h"
#include "Stack.h"

#include <cstdlib>

using namespace std;

Station::Station()
{
	Station::station = -1;
	train_stack = new Stack();
	train_queue = new Queue();
    train_deque = new Deque();
}

Station::~Station()
{
	Station::station = -1;
}

void Station::clearAll()
{
    train_stack->clear();
    train_queue->clear();
    train_deque->clear();

    delete train_deque;
    delete train_stack;
    delete train_queue;
}


bool Station::addToStation(int car)
{
    if (station == -1 && car >= 0 && train_stack->findNode(car) == false && train_queue->findNode(car) == false && train_deque->findNode(car) == false)
	{
        station = car;
		return true;
	}
	else
		return false;
}

int Station::showCurrentCar()
{
	return station;
}

bool Station::removeFromStation()
{
	station = -1;
	return true;
}

bool Station::addToStack()
{
	int test = train_stack->total_nodes;
	train_stack->insertHead(station);
	if (train_stack->total_nodes > test){
		station = -1;
		return true;
	}
	else
		return false;
}

bool Station::removeFromStack()
{
	station = train_stack->at(0);
	train_stack->remove(train_stack->at(0));

	return true;
}

int Station::showTopOfStack()
{
	if (train_stack->total_nodes == 0)
		return -1;
	return train_stack->firstNode->value;
}

int Station::showSizeOfStack()
{
	return train_stack->total_nodes;
}

bool Station::addToQueue()
{
	int test = train_queue->total_nodes;
	train_queue->insertHead(station);
	if (train_queue->total_nodes > test){
		station = -1;
		return true;
	}
	else
		return false;
}

bool Station::removeFromQueue()
{
	station = train_queue->at((train_queue->total_nodes)-1);
	train_queue->remove(train_queue->at((train_queue->total_nodes)-1));

	return true;
}

int Station::showTopOfQueue()
{
	if (train_queue->total_nodes == 0)
			return -1;
	return train_queue->at((train_queue->total_nodes)-1);
}

int Station::showSizeOfQueue()
{
	return train_queue->total_nodes;
}

bool Station::addToDequeLeft()
{
	int test = train_deque->total_nodes;
	train_deque->insertHead(station);
	if (train_deque->total_nodes > test){
		station = -1;
		return true;
	}
	else
		return false;
}

bool Station::addToDequeRight()
{
	train_deque->insertTail(station);
	station = -1;
	return true;
}

bool Station::removeFromDequeLeft()
{
	station = train_deque->at(0);
	train_deque->remove(train_deque->at(0));

	return true;
}

bool Station::removeFromDequeRight()
{
	station = train_deque->at((train_deque->total_nodes)-1);
	train_deque->remove(train_deque->at((train_deque->total_nodes)-1));

	return true;
}

int Station::showTopOfDequeLeft()
{
	if (train_deque->total_nodes == 0)
			return -1;
	return train_deque->firstNode->value;
}

int Station::showTopOfDequeRight()
{
	if (train_deque->total_nodes == 0)
			return -1;
	return train_deque->at((train_deque->total_nodes-1));
}

int Station::showSizeOfDeque()
{
	return train_deque->total_nodes;
}
