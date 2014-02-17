// carRental_mk_2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "VehicleLinkedList.h"
#include <sstream>
void setup(VehicleList&);
void displayMenu();
void addVehicle(VehicleList&);

int main()
{
	VehicleList vehicleList;
	char option;
	char type;
	string regNum;
	setup(vehicleList);
	do
	{
		displayMenu();
		cout << "\nEnter your choice (1-9): ";
		cin >> option;
		cout << '\n';
		switch (option)
		{
		case '1':
		//List all vehicles
			vehicleList.displayList();
			break;
		case '2':
		//Add a vehicle(car or van)
			cout << "\n Would you like to add a car or van? (c/v) : ";
			cin >> type;
			if ((tolower(type) == 'c') || (tolower(type) == 'v'))
			{
				vehicleList.insertVehicle(tolower(type));
			}
			else
			{
				cout << "Error: Invalid Input, try again.";
			}
			break;
		case '3':
		//Remove a vehicle
			cout << "\nEnter the Reg Number to be deleated: ";
			cin >> regNum;
			vehicleList.deleteNode(regNum);
			break;
		case '4':
		//Book a vehicle(car or van)
			cout << "\nWould you like a car or van? (c/v) : ";
			cin >> type;
			vehicleList.bookVehicle(tolower(type));
			break;
		case '5':
		//Display a vehicles details
			cout << "\nEnter the desired Reg Number: ";
			cin >> regNum;
			vehicleList.displayVehicle(regNum);
			break;
		case '6':
		//List all cars not currently rented
			vehicleList.rentedStatus(false, 'c');
			break;
		case '7':
		//List all 5-door cars.
			vehicleList.findVehicleByDoors(5);
			break;
		case '8':
		//List all Ford vans currently rented.
			vehicleList.findVehicleByMake("Ford", 'v');
			break;
		case '9':
		//Quit 
			cout << "\nSee you again soon.\n";
			break;
		default:
			cout << "\nError : Invalid choice\n\n";
			break;
		}

	} while (option != '9');

	system("pause");
	return 0;
}

void setup(VehicleList& vehicleList)
{
	
	Car* newCar1 = new Car("Ford", "Ka", "W447WUA",1300, true, 3, 4);
	VehicleNode* newNode1 = new VehicleNode;
	newNode1->vehiclePtr = newCar1;
	newNode1->vehicleType = 'c';
	vehicleList.insertNewVehicle(newNode1);

	
	Car* newCar2 = new Car("Fiat", "Punto", "Y566RPG", 1000, false, 5, 5);
	VehicleNode* newNode2 = new VehicleNode;
	newNode2->vehiclePtr = newCar2;
	newNode2->vehicleType = 'c';
	vehicleList.insertNewVehicle(newNode2);

	Car* newCar3 = new Car("Daewoo", "Matiz", "G560ABC", 1100, false, 5, 5);
	VehicleNode* newNode3 = new VehicleNode;
	newNode3->vehiclePtr = newCar3;
	newNode3->vehicleType = 'c';
	vehicleList.insertNewVehicle(newNode3);

	Van* newVan1 = new Van("Ford", "Transit", "U893GHD", 1600, true, 300, 0);
	VehicleNode* newNode4 = new VehicleNode;
	newNode4->vehiclePtr = newVan1;
	newNode4->vehicleType = 'v';
	vehicleList.insertNewVehicle(newNode4);

	Van* newVan2 = new Van("Merc", "Sprint", "T363ROX", 1800, false, 400, 0);
	VehicleNode* newNode5 = new VehicleNode;
	newNode5->vehiclePtr = newVan2;
	newNode5->vehicleType = 'v';
	vehicleList.insertNewVehicle(newNode5);

	Van* newVan3 = new Van("Fiat", "Mercury", "J588SUX", 1300, false, 500, 0);
	VehicleNode* newNode6 = new VehicleNode;
	newNode6->vehiclePtr = newVan3;
	newNode6->vehicleType = 'v';
	vehicleList.insertNewVehicle(newNode6);
}

void displayMenu()
{
	cout << "\nWelcome to the Car Rental System"
		<< "\n---------------------------------"
		<< "\nWhat would you like to do?"
		<< "\n\n1. List all vehicles."
		<< "\n2. Add a vehicle (car or van)."
		<< "\n3. Remove a vehicle."
		<< "\n4. Book a vehicle(car or van)."
		<< "\n5. Display a vehicle's details."
		<< "\n6. List all cars not currently rented."
		<< "\n7. List all 5-door cars."
		<< "\n8. List all Ford vans currently rented."
		<< "\n9. Quit\n\n";
}