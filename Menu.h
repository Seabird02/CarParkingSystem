#pragma once
#include<iostream>
#include<string>
#include"Customer.h"
#include"ParkingSpot.h"
using namespace std;
class Menu
{
public:
	Menu() {
		passWord = "12345";
		ParkingLot temp;
		parkingLot = temp;
	}
	void mainMenu() 
	{
		string str;
		bool isCorrect = false;
		string inputPass;
		while (true) {
			cout << " *************************" << endl;
			cout << " * 1: Administrator      *" << endl;
			cout << " * 2: Customer           *" << endl;
			cout << " * 3: quit the program   *" << endl;
			cout << " *************************" << endl;
			cout << " Please input a number to set your role: ";
			getline(cin, str);
			try
			{
				switch (stoi(str)) {
				case 1:
					cout << "Please enter the password: ";
					getline(cin, inputPass);

					// check if the entered password is correct
					if (inputPass != passWord)
					{
						cout << "Wrong password!";
						break;
					}
					else
					{
					adminMenu();
					}
					break;
				case 2:
					cusMenu();
					break;
				case 3:
					exit(0);
					break;
				}
			}
			catch (const std::exception&)
			{
				cout << "exception happened!\n";
				return;
			}
		}
	}

	void adminMenu()
	{
		string inputPass;
			while (true)
			{
				cout << "Which one do you want to operate:\n";
				cout << "1. Slot\n";
				cout << "2. Customer\n";
				cout << "3. Change password\n";
				cout << "4. Move to parent menu\n";
				cout << "Please enter the number to run the program: ";
				string select;
				getline(cin, select);
				string newPass1, newPass2;
				try
				{
					// call the appropriate function based on user input
					switch (stoi(select))
					{
					case 1:
						spotOpMenu();
						break;
					case 2:
						customerOpMenu();
						break;
					case 3:

						cout << "Please enter the old password to change the password: ";
						getline(cin, inputPass);

						// check if the old password is correct
						if (inputPass != passWord)
						{
							cout << "Wrong password!";
							break;
						}

						// prompt the user to input the new password twice and verify the input
						
						cout << "Please enter the new password: ";
						getline(cin, newPass1);
						cout << "Please enter the new password again: ";
						getline(cin, newPass2);

						if (newPass1 != newPass2)
						{
							for (int i = 1; i <= 2; i++)
							{
								cout << "Passwords do not match. Please try again (" << i << "/2): ";
								getline(cin, newPass2);
								if (newPass1 == newPass2)
								{
									cout << "New password set successfully.\n";
									passWord = newPass2;
									break;
								}
							}
							break;
						}
						else
						{
							cout << "New password set successfully.\n";
							passWord = newPass2;
							break;
						}
					case 4:
						return;
					default:
						cout << "invalid input!\n";
						break;
					}
				}

				catch (const std::exception&)
				{
					cout << "exception happened!\n";
					return;
				}
			}
		
	}
	

	void spotOpMenu() {
		cout << "1.browse\n";
		cout << "2.add\n";
		cout << "3.modify\n";
		cout << "4.delete\n";
		cout << "5.move to parent menu\n";
		cout << "input number to run the program:";
		string select;
		getline(cin, select);
		try
		{
			switch (stoi(select))
			{
			case 1 :
				cout << "browse the spot here\n";
				/*input "*" to check total left spots for each type of spot
				display should contain follow the format
				for all:
					floor 0:
						big:10	medium:30	small:20
					floor 1:
						big:20	medium:20	small:20
					......
				for specify type:
					medium:
						floor 0:10	floor 1:20	....
				*/
				//* situatiom
				for (ParkingFloor &p:parkingLot.getFloors())
				{

				}
				break;
			case 2:
				cout << "add spot here\n";
				/*check duplicate id.Initialize the spot with entering the new id, type, and the floor id.
				* once added, the number of spot should be automatically updated.*/
				break;
			case 3:
				cout << "modify spot here\n";//modify spot type... need discussing
				break;
			case 4:
				cout << "delete spot here\n";//erase the object from the Parking_Floors object;
				break;
			case 5:
				return;
			default:
				cout << "invalid input!\n";
				break;
			}
		}
		catch (const std::exception&)
		{
			cout << "exception happened!\n";
			return;
		}
		
	}

	void customerOpMenu() {
		cout << "1.browse\n";
		cout << "2.add\n";
		cout << "3.modify\n";
		cout << "4.delete\n";
		cout << "5.move to parent menu\n";
		cout << "input number to run the program:";
		string select;
		getline(cin, select);
		try
		{
			switch (stoi(select))
			{
			case 1:
				cout << "browse customer information here\n";
				break;
			case 2:
				cout << "add customer here\n";
				break;
			case 3:
				cout << "modify customer here\n";
				break;
			case 4:
				cout << "delete the information of a specific customer\n";
				break;
			case 5:
				return;
			default:
				cout << "invalid input!\n";
				break;
			}
		}
		catch (const std::exception&)
		{
			cout << "exception happened!\n";
			return;
		}

	}

	void cusMenu()
	{
		cout << "1.browse\n";
		cout << "2.check-in\n";
		cout << "3.check-out\n";
		cout << "4.move to parent menu\n";
		cout << "input number to run the program:";
		string select;
		getline(cin, select);
		try
		{
			switch (stoi(select))
			{
			case 1:
				cout << "browse information of vacant lots or payment";
				break;
			case 2:
				cout << "check-in here";
				break;
			case 3:
				cout << "check-out here";
				break;
			case 4:
				return;
			default:
				cout << "invalid input!\n";
				break;
			}
		}
		catch (const std::exception&)
		{
			cout << "exception happened!\n";
			return;
		}
	}
	private:
		string passWord;
		ParkingLot parkingLot;
		vector<Customer> customerList;
};

