#pragma once
#include"Customer.h"
#include <vector>
#include<iostream>
using namespace std;

enum ParkingSpotType {
		Big = 1,
		Medium,
		Small
	};

class ParkingSpot {
public:
	// Parking spot types
	
    ParkingSpot(int id, ParkingSpotType type) {
        ID = id; this->type = type;
        isOccupied = false;
    }
    ~ParkingSpot() {

    }

    
private:
    int ID;
    ParkingSpotType type;
    bool isOccupied;
};

class ParkingFloor {
public:
    ParkingFloor(int floorNumber) {
        this->floorNumber = floorNumber;
        for (int i = 1; i <=20; i++)
        {
            ParkingSpotType type = Small;
            parking_spots.push_back(ParkingSpot(i,type));
        }
        for (int i = 21; i <= 40; i++)
        {
            ParkingSpotType type = Medium;
            parking_spots.push_back(ParkingSpot(i, type));
        }
        for (int i = 41; i <= 60; i++)
        {
            ParkingSpotType type = Big;
            parking_spots.push_back(ParkingSpot(i, type));
        }
    }
    ~ParkingFloor() {

    }

private:
    vector<ParkingSpot> parking_spots;
    int floorNumber;
};

class ParkingLot {
public:
    ParkingLot() {
        //initialize the ParkingLot here
        for (int i = 0; i < 3; i++)
        {
            parking_floors.push_back(ParkingFloor(i));
        }
    }
    ~ParkingLot() {

    }
    vector<ParkingFloor> getFloors() {
        return parking_floors;
    }
private:
    vector<ParkingFloor> parking_floors;
};




