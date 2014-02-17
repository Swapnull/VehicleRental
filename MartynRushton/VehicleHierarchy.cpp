#include "stdafx.h"

#include "VehicleHierarchy.h"

#include <string>
#include <iostream>
using namespace std;

Vehicle::Vehicle(string Make, string Model,
			string RegNo, int EngineSize, bool Rented)
{
	this->make = Make;
	this->model = Model;
	this->regNo = RegNo;
	this->engineSize = EngineSize;
	this->rented = Rented;
}

MakeModel Vehicle::getMakeModel()
{
	MakeModel makeModel;
	makeModel.make= this->make;
	makeModel.model = this->model;
	return makeModel;
}

string Vehicle::getRegNo()
{
	return regNo;
}

int Vehicle::getEngineSize()
{
	return engineSize;
}

bool Vehicle::getRented()
{
	return rented;
}

void Vehicle::setRented()
{
	//reverses the boolean status
	if (rented == true)
	{
		rented = false;
	}
	else if (rented == false)
	{
		rented = true;
	}
}

Car::Car(string Make, string Model, string RegNo,
		int EngineSize, bool Rented, int NumPassangers,
		int NumDoors)
		:Vehicle(Make, Model, RegNo, EngineSize, Rented)
{
	this->make = Make;
	this->model = Model;
	this->regNo = RegNo;
	this->engineSize = EngineSize;
	this->rented = Rented;
	this->numPassengers = NumPassangers;
	this->numDoors = NumDoors;
}

int Car::getNumPassengers()
{
	return numPassengers;
}

int Car::getNumDoors()
{
	return numDoors;
}

Car::~Car()
{
	cout << "\nCar with Reg Number: " << regNo;
	cout << " has been deleted.\n\n";
}

Van::Van(string Make, string Model, string RegNo,
	int EngineSize, bool Rented, int MaxLoad,
	int DriverNo)
	:Vehicle(Make, Model, RegNo, EngineSize, Rented)
{
	this->make = Make;
	this->model = Model;
	this->regNo = RegNo;
	this->engineSize = EngineSize;
	this->rented = Rented;
	this->maxLoad = MaxLoad;
	this->driverNo = DriverNo;
}

int Van::getMaxLoad()
{
	return maxLoad;
}

void Van::setMaxLoad(int MaxLoad)
{
	maxLoad = MaxLoad;
}

int Van::getDriver()
{
	return driverNo;
}

void Van::setDriver(int DriverNo)
{
	this->driverNo = DriverNo;
}

Van::~Van()
{
	cout << "\nVan with Reg Number: " << regNo;
	cout << " has been deleted...\n\n";
}