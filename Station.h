/*
 * Station.h
 *
 *  Created on: Feb 12, 2016
 *      Author: jjfeddock
 */

#ifndef STATION_H_
#define STATION_H_

#include "StationInterface.h"
#include "Stack.h"
#include "Queue.h"
#include "Deque.h"


using namespace std;

class Station : public StationInterface
{

public:
	Station();
	virtual ~Station();

        void clearAll();
	bool addToStation(int car);
	int showCurrentCar();
	bool removeFromStation();
	bool addToStack();
	bool removeFromStack();
	int showTopOfStack();
	int showSizeOfStack();
	bool addToQueue();
	bool removeFromQueue();
	int showTopOfQueue();
	int showSizeOfQueue();
	bool addToDequeLeft();
	bool addToDequeRight();
	bool removeFromDequeLeft();
	bool removeFromDequeRight();
	int showTopOfDequeLeft();
	int showTopOfDequeRight();
	int showSizeOfDeque();




protected:
	int station;
	Stack* train_stack;
	Queue* train_queue;
	Deque* train_deque;


};



#endif /* STATION_H_ */
