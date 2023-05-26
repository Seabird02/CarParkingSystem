#pragma once
#include <vector>
#include<iostream>
#include<ctime>
using namespace std;

class Ticket {
public:
    Ticket() {
        start_time = time(NULL);
        end_time = 0;
    }
    ~Ticket() {

    }
    double payment() {
        end_time = time(NULL);
        double diff = difftime(start_time, end_time)/3600;//convert into hour
        return diff * 3;
    }

private:
    time_t start_time;
    time_t end_time;
};

class Customer {
public:
    Customer(string license) {
        license_plate_number = license;
        Ticket temp;
        ticket = temp;
    }
    ~Customer() {

    }

private:
    string license_plate_number;
    Ticket ticket;
};



