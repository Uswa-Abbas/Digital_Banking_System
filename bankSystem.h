#ifndef BANKSYSTEM_H
#define BANKSYSTEM_H
#include<iostream>
#include<vector>
#include"customer.h"
#include"account.h"
#include "personalAcc.h"
#include "companyAcc.h"
#include"colors.h" 


using namespace std;

class BankSystem {
public:

	vector <Customer > customers;
	// Raw pointers to Account base class (manage memory carefully)

	vector<Account* > accounts;
	~BankSystem();  // Destructor to clean up dynamically allocated accounts


	void performTransaction();
	void showDetails();
	void mainMenu();
	void addCustomer();
	void createAccount();


	Account* findAccountByID(const string& accountID);
	Customer* findCustomerByID(const string& customerID);
};


#endif