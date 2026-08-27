#pragma once
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <limits>
#include "lib/security.h"

using namespace activationAnd2FactorActions;
using namespace std;
namespace store {
	struct stProduct {
		string name = "";
		int avilable = 0;
		float price = 0.0;
	};

	char IsWantToComplete() {
		cout << "Are you want to Complete : ";
		char wantToComplete = 'y';
		cin >> wantToComplete;
		return wantToComplete;
	}

	int readPositiveNumber(string message) {
		int number = 0;
		cout << message;
		cin >> number;
		while (cin.fail() || number<0) {
			cin.clear();
			cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
			cout << message;
			cin >> number;
		}
		return number;
	}

	float readPrice(string message) {
		cout << message;
		float price = 0.0;
		cin >> price;
		return price;
	}

	string readProductName() {
		cin.ignore();
		string name = "";
		cout << "Enter product name : ";
		getline(cin, name);
		return name;
	}

	void printHead() {
		cout << "\t\t ________________________________________________________________________________________________";
		cout << "\n\t\t |" << setw(15) << "Name" << setw(15) << "|" << setw(15) << "price" << setw(15) << "|" << setw(20) << "Avilable" << setw(15) << "|";
		cout << "\n\t\t |_____________________________|_____________________________|__________________________________|\n";
	}

	void printTable(string name, float Cost, int avilable) {
		cout << setw(18) << "|" << setw(15) << name << setw(15) << "|" << setw(15) << Cost << setw(15) << "|" << setw(15) << avilable << setw(20) << "|";
		cout << "\n\t\t |_____________________________|_____________________________|__________________________________|\n";
	}

	void printLogo() {
		cout << "\t\t\t\t\t\t __ _  __| | ___  ___| |__   \n";
		cout << "\t\t\t\t\t\t / _` |/ _` |/ _ \\/ _ \\ '_ \\  \n";
		cout << "\t\t\t\t\t\t| (_| | (_| |  __/  __/ | | | \n";
		cout << "\t\t\t\t\t\t \\__, |\\__,_|\\___|\\___|_| |_| \n";
		cout << "\t\t\t\t\t\t   |_|                       \n";
	}

	void readVictorOfProducts(vector <stProduct>& productsList) {
		stProduct product;
		char wantToComplete = 'y';
		while (wantToComplete == 'y' || wantToComplete == 'Y') {
			product.name = readProductName();
			product.price = readPrice("Enter product price : ");
			product.avilable = readPositiveNumber(" Enter Avilable quantity :");
			productsList.push_back(product);
			wantToComplete = IsWantToComplete();
		}
	}

	void printProductsList(vector <stProduct>& productsList) {
		system("cls");
		printLogo();
		printHead();
		for (stProduct& product : productsList) {
			printTable(product.name, product.price, product.avilable);
		}
	}

	void clearStack(vector <stProduct>& productsList) {
		productsList.clear();
	}

	void mainActivityApp() {
		bool securityStatus=isPassedFromSecurityAction();
		///////////////////////////////////////////////////////////////////////
		system("cls");
		while(!securityStatus){
			system("cls");
			cout<<"Activation failed try again ! "<<endl;
			securityStatus=isPassedFromSecurityAction();
		}
	   ///////////////////////////////////////////////////////////////////////
		system("cls");
		vector <stProduct>productsList = {};
		printLogo();
		while (true) {
			cout << "Here is Tool Choices ! \n\n";
			cout << "Add new list  press 1\n";
			cout << "print element press 2\n";
			cout << "clear all  element press 3\n";
			cout << "Exit press 4\n\n";
			int choice = readPositiveNumber("Enter your choice : ");
			switch (choice) {


///////////////////////////////////////////////////////////////////////

			case 1:
			system("cls");
				readVictorOfProducts(productsList);
				break;



///////////////////////////////////////////////////////////////////////
			case 2:
				system("cls");
				if (productsList.empty()) {
					printLogo();
					cout << "\nsorry but no any list founded ! \n\n";
				}else{	
					printProductsList(productsList);
				}
				break;
///////////////////////////////////////////////////////////////////////
			case 3:
				system("cls");
				if (productsList.empty()) {
					printLogo();
					cout << "\nsorry but no any list founded ! \n\n";
				}
				else {
					clearStack(productsList);
				}

				break;
			case 4:
				return;
				break;
			}
		}
	}
	
}
