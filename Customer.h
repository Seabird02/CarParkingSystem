#pragma once
#include <vector>
#include<iostream>
#include<ctime>
#include"ParkingSpot.h"
using namespace std;

class Ticket {
public:
    Ticket() {
        start_time = time(NULL);
        end_time = 0;
    }
    //for function addCustomer()
    Ticket(time_t startTime) {
        start_time = startTime;
        end_time = 0;
    }
    ~Ticket() {

    }
    double payment(ParkingSpotType type) {
        end_time = time(NULL);
        int diff = difftime(end_time, start_time);
        int totalCharge = 0;
        int hours = diff / ( 60 * 60);
        int minutes = (diff % ( 60 * 60)) / ( 60);
        if (minutes > 0) {
            hours++;
        }
        if (hours > 1) {
            switch (type) {
            case Small:
                totalCharge += (hours - 1) * 1;
                break;
            case Medium:
                totalCharge += (hours - 1) * 2;
                break;
            case Big:
                totalCharge += (hours - 1) * 3;
                break;
            }
        }
        return totalCharge;
    }
	string getStratTime() {
		char str[26];
        ctime_s(str, sizeof(str), &start_time);
        str[24] = 0;
        return str;
	}
    string getEndTime() {
        char str[26];
        ctime_s(str, sizeof(str), &end_time);
        str[24] = 0;
        return str;
    }
   
    void setStartTime(time_t newtime) {
        start_time = newtime;
    }
    
private:
    time_t start_time;
    time_t end_time;
};

class Customer {
public:
    Customer(string license,ParkingSpotType type) {
        license_plate_number = license;
        Ticket temp;
        ticket = temp;
        carType = type;
    }
    //used for function addCustomer()
    Customer(string license, time_t startTime, ParkingSpotType carType) {
        license_plate_number = license;
        this->carType = carType;
        Ticket temp(startTime);
        ticket = temp;
    }
    Customer(const Customer& customer) {
        this->license_plate_number = customer.license_plate_number;
        this->carType = customer.carType;
        this->ticket = customer.ticket;
    }
    Customer() {

    }
    ~Customer() {

    }
    string getLicenseNumber() {
        return license_plate_number;
    }
    string getCheckinTime() {
        return ticket.getStratTime();
    }
    string getChceckoutTime() {
        return ticket.getEndTime();
    }
    double getPayment() {
        ParkingSpotType type = carType;
        return ticket.payment(type);
    }
    ParkingSpotType getType() {
        return carType;
    }
    void setLicense(string newNumber) {
        license_plate_number = newNumber;
    }
    void setSartTime(time_t newtime) {
        ticket.setStartTime(newtime);
    }
    void setCarType(ParkingSpotType carType) {
        this->carType = carType;
    }
private:
    string license_plate_number;
    Ticket ticket;
    ParkingSpotType carType;
};



