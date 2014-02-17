#include "stdafx.h"

#include <iostream>
using namespace std;

struct MakeModel
{
	string make;
	string model;
};

class Vehicle
{
protected:
	string make;
	string model;
	string regNo;
	int engineSize;
	bool rented;
public:
	Vehicle(string, string, string, int, bool);
	MakeModel getMakeModel();
	string getRegNo();
	int getEngineSize();
	bool getRented();
	void setRented();
	~Vehicle() {};
};

class Car : public Vehicle
{
private:
	int numPassengers;
	int numDoors;
public:
	Car(string, string, string, int, bool, int, int);
	int getNumPassengers();
	int getNumDoors();
	~Car();
};

class Van : public Vehicle
{
private:
	int maxLoad;
	int driverNo;
public:
	Van(string, string, string, int, bool, int, int);
	int getMaxLoad();
	void setMaxLoad(int);
	int getDriver();
	void setDriver(int);
	~Van();
};
