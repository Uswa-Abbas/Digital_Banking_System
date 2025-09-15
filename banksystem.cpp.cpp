#include"bankSystem.h"

#include<iostream>

BankSystem::~BankSystem() {
	for (Account* acc : accounts) {
		delete acc;
	}
	accounts.clear();
}

void BankSystem::addCustomer() {
	Customer newCustomer;
	newCustomer.setCustomerInfo();
	customers.push_back(newCustomer);
	cout << Green << "Customer added successfully" << Reset << endl;

}

void BankSystem::createAccount() {
	string type;
	cout << "Enter Account Type(Personal/Company):";
	cin >> type;
	Account* newAccount = nullptr;

	if (type == "Personal" || type == "personal") {
		newAccount = new PersonalAcc();

	}
	else if (type == "Company" || type == "company") {
		newAccount = new CompanyAcc();

	}
	else {
		cout << Red << "invalid account type \n " << Reset;
		return;
	}
	newAccount->openAccount();
	accounts.push_back(newAccount);

}

Account* BankSystem::findAccountByID(const string& accountID) {

	for (Account* acc : accounts) {
		if (acc->getAccountID() == accountID) {
			return acc;
		}
	}
	return nullptr;
}

Customer* BankSystem::findCustomerByID(const string& customerID) {
	for (Customer& cust : customers) {
		if (cust.getCustomerID() == customerID) {
			return &cust;
		}
	}
	return nullptr;
}

void BankSystem::performTransaction() {
	string accountID;
	cout << "Enter Accout ID for transaction : ";
	cin >> accountID;
	Account* acc = findAccountByID(accountID);
	if (!acc) {
		cout << Red << "Account not found " << Reset;

	}

	int choice;
	cout << "Select Transaction :\n";
	cout << "1. Deposit \n";
	cout << "2. Withdraw \n";
	cout << "Enter choice : ";
	cin >> choice;
	switch (choice) {
	case 1: {
		acc->deposit();
		break;
	}
	case 2: {
		acc->withdraw();
		break;
	}
	default: {
		cout << Red << "Invalid choice \n" << Reset;
		break;
	}
	}



}


void BankSystem::showDetails() {
	string accountID;
	cout << "Enter Account ID to show details : ";
	cin >> accountID;
	Account* acc = findAccountByID(accountID);
	if (!acc) {
		cout << Red << "Account not found ! \n" << Reset;
		return;
	}
	acc->displayAccountDetails();
}


void BankSystem::mainMenu() {
	int choice;
	do {
		cout << Yellow << "\n =====Bank System Main Menu=====\n" << Reset;
		cout << "1. Add Customer\n";
		cout << "2. Create Account\n";
		cout << "3. Perform Transaction\n";
		cout << "4. Show Account Details\n";
		cout << "5. Exit \n";
		cout << "Enter your choice : ";
		cin >> choice;

		switch (choice) {
		case 1:
			addCustomer();
			break;
		case 2:
			createAccount();
			break;
		case 3:
			performTransaction();
			break;
		case 4:
			showDetails();
			break;
		case 5:
			cout << Yellow << "Exiting......." << Reset;
			break;
		default:
			cout << Red << "Invalid choice! Try again .\n";
			break;
		}


	} while (choice != 5);

}