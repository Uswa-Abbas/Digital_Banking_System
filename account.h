#define _CRT_SECURE_NO_WARNINGS
#ifndef ACCOUNT_H
#define  ACCOUNT_H

#include"customer.h"
#include<fstream>
#include<ctime>
#include<cstring>
#include<cstdlib>  //for random acc_num
#include<iostream>
#include<string> 
#include"colors.h" 

using namespace std;

class Account {
protected:
	string accountID;
	string customerID;
	string account_type;
	double balance;
	string IBAN;

public:
	Account(string accID = "", string cuID = "", string accType = "", double bal = 0.00) {
		accountID = accID;
		customerID = cuID;
		account_type = accType;
		balance = bal;
	}

	virtual  void openAccount();  // done 
	virtual void deposit() = 0;
	virtual void withdraw() = 0;
	double getbalance() const; //done
	string getAccountID() const;  //done
	string getIBAN() const;    //done
	string generateAccountID(); //done
	string generateIBAN(const string& accountID);  //done
	string date_of_creation();  //done
	virtual void displayAccountDetails() = 0;
	virtual ~Account() = default;
};

#endif