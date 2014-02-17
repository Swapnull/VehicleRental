#include "stdafx.h"
#include "VehicleHierarchy.h"

struct VehicleNode
{
	Vehicle* vehiclePtr;
	char vehicleType; // 'c' or 'v'
	VehicleNode* nextNode;
};

class VehicleList
{
private:
	VehicleNode* headPtr;
public:
	VehicleList();
	void displayVehicle(string);
	void insertVehicle(char);

	//This is only used during the initial setup.
	void insertNewVehicle(VehicleNode*& newNode);

	VehicleNode* findVehicle(string);
	void findVehicleByMake(string, char);
	void findVehicleByDoors(int);

	void rentedStatus(bool, char);
	void displayList();
	void bookVehicle(char);
	
	void deleteNode(string);
	~VehicleList();
};

