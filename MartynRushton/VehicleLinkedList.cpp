#include "stdafx.h"
#include "VehicleLinkedList.h"
#include <iomanip>
#include <sstream>

VehicleList::VehicleList()
{
	headPtr = NULL;
}

void VehicleList::insertNewVehicle(VehicleNode*& newNode)
{
	newNode->nextNode = headPtr;
	headPtr = newNode;;
}

void VehicleList::displayVehicle(string regNo)
//finds vehicle by Reg Number and displays details
{
	bool found = false;
	VehicleNode* currentNode = headPtr;
	Car* carPtr = NULL;
	Van* vanPtr = NULL;

	while ((currentNode != NULL) && !found)
	{
		if (currentNode->vehiclePtr->getRegNo() == regNo)
		{
			string rented;
			if (currentNode->vehiclePtr->getRented() == 0)
				rented = "False";
			else
				rented = "True";

			MakeModel makeModel = currentNode->vehiclePtr->getMakeModel();

			cout << "\nMake \t Model\tRented  extraInfo";
			cout << "\n------\t------\t------  -------------\n\n";
			cout << makeModel.make << '\t';
			cout << makeModel.model << '\t';
			cout << rented << '\t';
			if (currentNode->vehicleType == 'c')
			{
				carPtr = (Car*)(currentNode->vehiclePtr);
				cout << "Doors: " << carPtr->getNumDoors() << '\t';
				cout << "Seats: " << carPtr->getNumPassengers() << endl << endl;
			}
			else
			{
				vanPtr = (Van*)(currentNode->vehiclePtr);
				cout << "Max Load: " << vanPtr->getMaxLoad() << '\t';
				cout << "Driver: " << vanPtr->getDriver() << endl << endl;
			}
			return;
		}
		currentNode = currentNode->nextNode;
	}
	cout << "\n\nError: This vehicle could not be found\n\n";
}

VehicleNode* VehicleList::findVehicle(string regNo)
//finds vehicle by regNo
{
	VehicleNode* currentNode = headPtr;
	bool found = false;

	while ((currentNode != NULL) && !found)
	{
		if (currentNode->vehiclePtr->getRegNo() == regNo)
			return currentNode;
		currentNode = currentNode->nextNode;
	}
	return NULL;
}

void VehicleList::findVehicleByMake(string make, char type)
{
	VehicleNode* currentNode = headPtr;
	bool found = false;
	cout << "\n\nRegistration Number\n";
	cout << "-----------------------";
	while ((currentNode != NULL) && !found)
	{
		MakeModel makeModel = currentNode->vehiclePtr->getMakeModel();
		if ((makeModel.make == make) && (currentNode->vehicleType == type))
		{

			cout << "\n" << currentNode->vehiclePtr->getRegNo();
		}
		currentNode = currentNode->nextNode;
	}
	cout << endl;

}

void VehicleList::findVehicleByDoors(int doors)
{
	VehicleNode* currentNode = headPtr;
	bool found = false;

	cout << "\n\nRegistration Number\n";
	cout << "-----------------------";
	while ((currentNode != NULL) && !found)
	{
		Car* carPtr = (Car*)(currentNode->vehiclePtr);
		if (carPtr->getNumDoors() == doors)
		{
			cout << "\n" << currentNode->vehiclePtr->getRegNo();
		}
		currentNode = currentNode->nextNode;
	}
	cout << "\n\n";
}


void VehicleList::displayList()
{
	if (headPtr == NULL)
	{
		cout << "\n\t\t***\a List empty *** \n\n";
		return;
	}
	VehicleNode* currentNode = headPtr;
	Car* carPtr = NULL;
	Van* vanPtr = NULL;

	cout << "\n Type \tRegNo\tRented \t extraInfo";
	cout << "\n------\t------\t------\t------------\n\n";
	do
	{
		string rented;
		MakeModel makeModel = currentNode->vehiclePtr->getMakeModel();

		if (currentNode->vehiclePtr->getRented() == 0)
			rented = "False";
		else
			rented = "True";


		if (currentNode->vehicleType == 'c')
		{
			carPtr = (Car*)(currentNode->vehiclePtr);
			cout << "Car" << '\t';
			cout << currentNode->vehiclePtr->getRegNo() << '\t';
			cout << rented << '\t';
			cout << "  Doors: " << carPtr->getNumDoors() << '\t';
			cout << "  Seats: " << carPtr->getNumPassengers() << endl;
		}
		else
		{
			vanPtr = (Van*)(currentNode->vehiclePtr);
			cout << "Van" << '\t';
			cout << currentNode->vehiclePtr->getRegNo() << '\t';
			cout << rented << '\t';
			cout << "  Max Load: " << vanPtr->getMaxLoad() << '\t';
			cout << "  Driver: " << vanPtr->getDriver() << endl;
		}
		currentNode = currentNode->nextNode;
	} while (currentNode != NULL);
	cout << "\n\n\n";
}

void VehicleList::deleteNode(string regNo)
{

	VehicleNode* currentNode = headPtr;
	VehicleNode* parentNode = headPtr;
	bool found = false;

	while ((currentNode != NULL) && !found)
	{
		if (currentNode->vehiclePtr->getRegNo() == regNo)
		{
			parentNode->nextNode = currentNode->nextNode;
			currentNode->nextNode = NULL;
			cout << "\nVehicle " << regNo << " has been deleted.\n\n";
			found = true;
			return;
		}
		parentNode = currentNode;
		currentNode = currentNode->nextNode;
	}
	cout << "\nError : Vehicle could not be found\n"; 
}

void VehicleList::bookVehicle(char type)
{
	VehicleNode* currentNode = headPtr;
	bool found = false;
	while ((currentNode != NULL) && !found)
	{
		MakeModel makeModel = currentNode->vehiclePtr->getMakeModel();
		if ((currentNode->vehiclePtr->getRented() == 0) && (currentNode->vehicleType == type))
		{
			currentNode->vehiclePtr->setRented();
			cout << "\nA " << makeModel.make << " " << makeModel.model <<
				" with Registration " << currentNode->vehiclePtr->getRegNo() << " has been rented\n\n";
			found = true;
		}
		currentNode = currentNode->nextNode;
	}
}

VehicleList::~VehicleList()
//Deallocates Memory used for nodes.
{
	VehicleNode* oldHead;
	cout << "\nThe memory will now be deallocated\n";
	cout << "-------------------------------------\n";
	while (headPtr != NULL)
	{
		oldHead = headPtr;
		if (headPtr->vehicleType == 'c')
		{
			Car* carPtr = (Car*)(headPtr->vehiclePtr);
			cout << "\nReg Number: " << carPtr->getRegNo();
			cout << "\nDeleting Car.\n";
			delete carPtr;
		}
		else
		{
			Van* vanPtr = (Van*)(headPtr->vehiclePtr);
			cout << "\nReg Number: " << vanPtr->getRegNo();
			cout << "\nDeleting Van.\n";
			delete vanPtr;
		}

		headPtr = headPtr->nextNode;
		delete oldHead;
	}
	cout << "\n\n All the memory has been deallocated \n\n";
	system("pause");
}

void VehicleList::insertVehicle(char type)
{
	string make, model, regNo;
	int engineSize, numDoors, numPassengers, maxLoad;

	cout << "\n\n";
	cout << "Enter vehicle information.";

	cout << "\nMake: ";
	cin >> make;

	cout << "\nModel: ";
	cin >> model;

	cout << "\nReg Number (No spaces) : ";
	cin >> regNo;

	if (findVehicle(regNo) != NULL)
	{
		cout << "\nThis is a duplicate registration number\n"
			<< "so it has not been added to the table. \n\n";
	}
	else
	{
		cout << "\nEngine Size: ";
		cin >> engineSize;

		if (type == 'c')
		{
			cout << "\nNumber of Doors: ";
			cin >> numDoors;

			cout << "\nNumber of Seats: ";
			cin >> numPassengers;

			Car* newCar = new Car(make, model, regNo,
				engineSize, false, numPassengers, numDoors);

			VehicleNode* newNode = new VehicleNode;
			newNode->vehiclePtr = newCar;
			newNode->vehicleType = 'c';

			newNode->nextNode = headPtr;
			headPtr = newNode;;
			cout << "\n\n";
		}
		else //type == 'v'
		{
			cout << "\nMax Load: ";
			cin >> maxLoad;

			Van* newVan = new Van(make, model, regNo,
				engineSize, false, maxLoad, false);
			VehicleNode* newNode = new VehicleNode;

			newNode->vehiclePtr = newVan;
			newNode->vehicleType = 'v';

			newNode->nextNode = headPtr;
			headPtr = newNode;;
			cout << "\n\n";
		}
	}
}

void VehicleList::rentedStatus(bool desired, char type)
//The incoming 'desired' can be true or false depending
//on weather you want to display the rented ones.
//Type contains weather it is a car or van. 
{
	if ((tolower(type) == 'c') || (tolower(type) == 'v'))
	{
		if ((headPtr == NULL) && (desired == true))
		{
			if (type == 'c')
				cout << "\n\t\t***\a No Cars Rented *** \n\n";
			else
				cout << "\n\t\t***\a No Vans Rented *** \n\n";

			return;
		}
		else if ((headPtr == NULL) && (desired == false))
		{
			if (type == 'c')
				cout << "\n\t\t***\a All Cars Rented *** \n\n";
			else
				cout << "\n\t\t***\a All Vans Rented *** \n\n";

			return;
		}

		VehicleNode* currentNode = headPtr;
		Car* carPtr = NULL;
		Van* vanPtr = NULL;

		{
			cout << "\nMake \t Model \t RegNo ";
			cout << "\n------\t------\t-------\n\n";
			do
			{
				if (currentNode->vehiclePtr->getRented() == desired)
				{
					string rented;
					if (currentNode->vehiclePtr->getRented() == 0)
						rented = "False";
					else
						rented = "True";

					MakeModel makeModel = currentNode->vehiclePtr->getMakeModel();

					cout << makeModel.make << '\t';
					cout << makeModel.model << '\t';
					cout << currentNode->vehiclePtr->getRegNo() << '\n';
				}
				currentNode = currentNode->nextNode;
			} while (currentNode != NULL);
		}
	}
	else
	{
		cout << "Error : Invalid Choice";
	}
}

