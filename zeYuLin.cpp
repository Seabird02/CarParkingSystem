#pragma once
#include"Menu.h"
time_t setTime() {
	struct tm t;
	cout << "Enter year: "; cin >> t.tm_year;
	t.tm_year -= 1900; // mktime takes years since 1900
	cout << "Enter month (1-12): "; cin >> t.tm_mon; t.tm_mon--;
	cout << "Enter day of month: "; cin >> t.tm_mday;
	cout << "Enter hour (0-23): "; cin >> t.tm_hour;
	cout << "Enter minute (0-59): "; cin >> t.tm_min;
	cout << "Enter second (0-59): "; cin >> t.tm_sec;
	t.tm_isdst = -1; // let mktime determine DST status
	time_t timestamp = mktime(&t);
	return timestamp;
}
ParkingSpotType stringToType(string type) {
	if (type == "Big" || type == "big")
	{
		return Big;
	}
	else if (type == "Medium" || type == "midium")
	{
		return Medium;
	}
	else if (type == "Small" || type == "small")
	{
		return Small;
	}
	else
	{
		cout << "invalid type!";
	}
}

string typeToString(ParkingSpotType type) {
	if (type == Big)
	{
		return "Big";
	}
	else if (type == Medium)
	{
		return "Medium";
	}
	else if (type ==Small)
	{
		return "Small";
	}
	else
	{
		cout << "invalid type!";
	}
}

void Menu::browseCustomers()
{
	string input;
	cout << "Enter a license number or '*' to browse all customers: ";
	cin.clear();
	cin >> input;
	if (input == "*") {
		cout << "\t" << "License Number" << "\t" << "       Check-in Time      " << "\t" << "Payment\t"<<"Car Type\n";
		for (Customer& customer : customerList) {
			cout << "\t" << customer.getLicenseNumber();
			cout << "\t " << customer.getCheckinTime();
			cout << "\t" << customer.getPayment();
			cout << "\t" << typeToString(customer.getType()) << endl;
		}
	}
	else {
		for (Customer& customer : customerList) {
			if (customer.getLicenseNumber() == input) {
				cout << "License Number:" << customer.getLicenseNumber() << "\n";
				cout << "Check-in Time:" << customer.getCheckinTime()<<endl;
				cout << "Payment:" << customer.getPayment() << endl;
				return;
			}
		}
		cout << "Customer not found." << endl;
	}
}

void Menu::addCustomer() {
	string licenseNumber; bool isAdding = true; cin.clear();
	string type;
	while (isAdding)
	{
		cout << "please input the licesen number:";
		cin >> licenseNumber;
		cout << "please input the check-in time\n";
		time_t time = setTime();
		cout << "please input the car type:";
		cin >> type;
		Customer temp(licenseNumber, time,stringToType(type));
		customerList.push_back(temp);
		cout << "add custoemr successfully\n";
		cout << "Add another customer(0:no, 1:yes)?\n";
		string choice;
		cin.clear();
		cin >> choice;
		if (choice == "1")
		{
			isAdding = true;
		}
		else
		{
			isAdding = false;
		}
	}
}

void Menu::modifyCustomer() {
	cout << "input licence number to modify a customer:\n";
	string licenceNumber;
	cin.clear();
	cin >> licenceNumber;
	for (Customer& customer : customerList) {
		if (customer.getLicenseNumber() == licenceNumber) {
			cout << "License Number:" << customer.getLicenseNumber() << "\n";
			cout << "Check-in Time:" << customer.getCheckinTime() << endl;
			cout << "Payment:" << customer.getPayment() << endl;
			cout << "Car type:" << typeToString(customer.getType()) << endl;
			cout << "\n";
			cout << "1.license number\n";
			cout << "2.Check-in time\n";
			cout << "3.Car type\n";
			cout << "input a number to modify custoemr:\n";
			string choice;
			time_t newTime;
			string input = "";
			string newType;
			cin.clear();
			cin >> choice;
			try
			{
				switch (stoi(choice))
				{
				case 1:
					cin.clear();
					cout << "input new license number:";
					cin >> input;
					customer.setLicense(input);
					cout << "successfully modified!\n";
					cout << "updated License Number:" << customer.getLicenseNumber() << "\n";
					break;
				case 2:
					newTime = setTime();
					customer.setSartTime(newTime);
					cout << "successfully modified!\n";
					cout << "updated Check-in Time:" << customer.getCheckinTime() << endl;
					cout << "updated Payment:" << customer.getPayment() << endl;
					break;
				case 3:
					cout << "input new type of car";
					cin.clear();
					cin >> newType;
					customer.setCarType(stringToType(newType));
					cout << "successfully modified!\n";
					cout << "updated car type:" << typeToString(customer.getType()) << endl;
					break;
				default:
					break;
				}
			}
			catch (const std::exception&)
			{
				cout << "modifyCustomer() exception happened";
			}
			return;
		}
	}
	cout << "Customer not found." << endl;
}

void Menu::deleteCustomer() {
	cout << "input license number to delete customer or \"*\" to delete all customer\n";
	string input;
	bool isFound = false;
	cin.clear();
	cin >> input;
	if (input == "*") {
		string option;
		cout << "delete all customer?(0:No,1:Yes)\n";
		cin.clear();
		cin >> option;
		if (option == "1")
		{
			customerList.clear();
			cout << "successfully deleted\n";
			return;
		}
		else
		{
			return;
		}
	}
	else {
		for (auto it = customerList.begin(); it != customerList.end(); ++it) {
			Customer temp = *it;
			if (temp.getLicenseNumber() == input) {
				string option;
				cout << "delete the customer?(0:No,1:Yes)\n";
				cin.clear();
				cin >> option;
				if (option == "1")
				{
					customerList.erase(it);
					cout << "successfully deleted\n";
					isFound = true;
					break;
				}
				else
				{
					break;
				}
			}
		}
		if (isFound)
		{
			cout << "Customer not found." << endl;
		}
		
	}
}

void Menu::browseSelfInformation(string license_number) {
	for (Customer& customer : customerList) {
		if (customer.getLicenseNumber() == license_number) {
			cout << "License Number:" << customer.getLicenseNumber() << "\n";
			cout << "Check-in Time:" << customer.getCheckinTime() << endl;
			cout << "Car type:"<<typeToString(customer.getType())<<endl;
			cout << "Payment:" << customer.getPayment() << endl;
			return;
		}
	}
}

void Menu::check_in() {
	string lincense;
	string type;
	cout<<"input your license number:";
	cin.clear();
	cin >> lincense;
	cout << "input your car type:";
	cin.clear();
	cin >> type;

	Customer temp(lincense, stringToType(type));
	customerList.push_back(temp);
}

void Menu::check_out() {
	string lincense;
	string type;
	bool isfound = false;
	Customer temp;
	cout << "input your license number:";
	cin.clear();
	cin >> lincense;
	for (Customer customer : customerList) {
		if (customer.getLicenseNumber() == lincense)
		{
			isfound = true;
			temp = customer;
		}
	}
	if (isfound)
	{
		string select;
		cout << "your check_in time:" << temp.getCheckinTime()<<endl;
		cout << "your check_out time:" << temp.getChceckoutTime()<<endl;
		cout << "yuor vehicle type:" << typeToString(temp.getType()) << endl;
		cout << "your parking fee:" << temp.getPayment();
		cout << "Do you wish to leave the parking lot?(1:Yes,0:No)";
		cin.clear();
		cin >> select;
		if (select=="1")
		{
			for (auto it = customerList.begin(); it != customerList.end(); ++it) {
				Customer temp1 = *it;
				if (temp1.getLicenseNumber() == temp.getLicenseNumber()) {
					customerList.erase(it);
					break;
				}
			}
			cout << "check out successfully!\n";
		}
		else
		{
			return;
		}

	}
}

