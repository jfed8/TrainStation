/*
 * main.cpp
 *
 *  Created on: Feb 18, 2016
 *      Author: jjfeddock
 */

#include "StationInterface.h"
#include "Station.h"
#include "Factory.h"

#include <iostream>
#include <string>

using namespace std;

int Menu()
{
	int option = -1;
	cout << "\nPlease choose an option: " << endl;
	cout << "1. Add a car to the station" << endl;
	cout << "2. Remove a car from the station" << endl;
	cout << "3. Add a car from the station to a storage facility" << endl;
	cout << "4. Remove a car from a storage facility (bring it to the station)" << endl;
	cout << "5. Display the currently accessible cars in all locations" << endl;
	cout << "6. Quit" << endl;
	cout << "->";


	while(!(cin >> option)){
	        cin.clear();
            cin.ignore();
	        cout << "Invalid input. Try again" << endl;
	        cout << "->";
	    }

	if (option > 0 && option < 7)
		return option;
	else
		return -1;

}

int main() {
    Station* station = new Station();

	int selection = Menu();

	if (selection == -1)
		selection = Menu();

	while (selection != 6)
	{


		switch(selection)
		{
		case 1:
			int new_car;
			cout << "Please enter car: ";
			if (cin >> new_car){
				bool success = station->addToStation(new_car);
				if (success)
					cout << "Success! Car added." << endl;
				else
                    cout << "Error. Car could not be added." << endl;
				}
			else {
				cin.clear();
                cin.ignore();
				cout << "Error. Invalid input." << endl;
			}
			break;

		case 2:
			station->removeFromStation();
			cout << "Station is now empty!" << endl;
			break;

		case 3:
			if (station->showCurrentCar() == -1)
				cout << "Station is empty." << endl;
			else
			{
				string list_choice;
				cout << "Where do you want to place the car? (stack/queue/deque): ";
				cin >> list_choice;
				if (list_choice == "stack"){
					station->addToStack();
					cout << "Car added to Stack." << endl;
				}
				else if (list_choice == "queue"){
					station->addToQueue();
					cout << "Car added to Queue." << endl;
				}
				else if (list_choice == "deque")
				{
					string side;
					cout << "Which side would you like to place it on? (right/left): ";
					cin >> side;
					if (side == "right"){
						station->addToDequeRight();
						cout << "Car added to Deque - Right." << endl;
					}
					else if (side == "left"){
						station->addToDequeLeft();
						cout << "Car added to Deque - Left." << endl;
					}
					else
						cout << "Invalid Selection" << endl;

				}
				else
					cout << "Invalid Selection." << endl;
			}
			break;

		case 4:
			int car_selection;
			cout << "What car would you like to retrieve? ";
			if (cin >> car_selection)
			{
				if (station->showCurrentCar() != -1)
					cout << "Station already occupied." << endl;

				else if (station->showTopOfStack() == car_selection)
				{
					station->addToStation(station->showTopOfStack());
					station->removeFromStack();
					cout << "Car retrieved from Stack." << endl;
				}
				else if (station->showTopOfQueue() == car_selection)
				{
					station->addToStation(station->showTopOfQueue());
					station->removeFromQueue();
					cout << "Car retrieved from Queue." << endl;
				}
				else if (station->showTopOfDequeLeft() == car_selection)
				{
					station->addToStation(station->showTopOfDequeLeft());
					station->removeFromDequeLeft();
					cout << "Car retrieved from Deque - Left." << endl;
				}
				else if (station->showTopOfDequeRight() == car_selection)
				{
					station->addToStation(station->showTopOfDequeRight());
					station->removeFromDequeRight();
					cout << "Car retrieved from Deque - Right." << endl;
				}
				else
					cout << "Invalid Entry." << endl;
			}
			else {
				cin.clear();
                cin.ignore();
				cout << "Error. Invalid input." << endl;
			}
			break;

		case 5:
			string empty = "EMPTY";

			if (station->showTopOfStack() > -1)
				cout << "Stack: " << station->showTopOfStack() << endl;
			if (station->showSizeOfDeque() > 0)
				cout << "Deque: " << station->showTopOfDequeLeft() << ", " << station->showTopOfDequeRight() << endl;
			if (station->showTopOfQueue() > -1)
				cout << "Queue: " << station->showTopOfQueue() << endl;
			if (station->showCurrentCar() > -1)
				cout << "Station: " << station->showCurrentCar() << endl;
			else
				cout << "Station: EMPTY" << endl;

			break;

		}
		selection = Menu();
	}

	if (selection == 6){
		cout << "\n\n     _________" << endl;
		cout << "      |  _  |    __" << endl;
		cout << " ---  | | | |____\\/_" << endl;
		cout << " ---  | |_| |       \\" << endl;
		cout << " ---  | __  |  _  _  |" << endl;
		cout << "      |/  \\_|_/ \\/ \\/" << endl;
		cout << "       \\__/   \\_/\\_/" << endl;

		cout << "\n\t\tChoo choo ciao!" << endl;


        station->clearAll();
	}

    delete station;
	return 0;
}


