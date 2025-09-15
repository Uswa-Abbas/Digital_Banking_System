#define _CRT_SECURE_NO_WARNINGS
#include"account.h"




void Account::openAccount() {
	cout << "\n=====================================\n";
	cout << Yellow << "          Opening New Account          \n" << Reset;
	cout << "=====================================\n";



	//Customer ID
	string CNIC;
	cout << "Enter your Customer CNIC :";
	cin >> CNIC;

	ifstream fin("customer.txt");
	bool found = false;

	if (fin.is_open())
	{
		string name, id, Cnic, father, age, income;


		while (getline(fin, name, ',') &&
			getline(fin, id, ',') &&
			getline(fin, Cnic, ',') &&
			getline(fin, father, ',') &&
			getline(fin, age, ',') &&
			getline(fin, income))
		{
			if (Cnic == CNIC) {
				found = true;
				break;
			}

		}

		fin.close();
	}
	else {
		cout << Red << "ERROR: customer.txt file not found!\n" << Reset;
		return;
	}
	if (!found) {
		cout << Red << "Invalid Customer ID! Account cannot be created.\n" << Reset;
		return;
	}

	cout << Green << "Customer ID verified successfully. Proceeding...\n" << Reset;



	//Account Type

	bool validType = false;
	while (!validType)
	{
		cout << "Enter Account Type (Personal/Company):";
		cin >> account_type;

		if (account_type == "Personal" || account_type == "personal" ||
			account_type == "Company" || account_type == "company"
			)
		{
			validType = true;
		}
		else
		{
			cout << Red << "Invalid type! Please enter 'Personal'  or 'Company'.\n " << Reset;
		}
	}


	//Initial balance

	do
	{
		cout << "Enter Initial Balance (should not be less than 0): ";
		cin >> balance;
		if (balance < 0) {
			cout << Red << "Balance cannot be negative. Try again.\n" << Reset;
		}
	} while (balance < 0);




	//date of creation
	string date = date_of_creation();


	//account id generation
	accountID = generateAccountID();


	//IBAN generation
	IBAN = generateIBAN(accountID);


	//Save account details into file

	ofstream fout("Account.txt", ios::app); // append mode
	if (fout.is_open()) {
		fout << "CustomerID:" << customerID << ","
			<< "Type:" << account_type << ","
			<< "AccountID:" << accountID << ","
			<< "IBAN:" << IBAN << ","
			<< "Balance:" << balance << ","
			<< "Date:" << date << endl;
		fout.close();
	}
	else {
		cout << Red << "Error: Unable to open file for saving account.\n" << Reset;
	}


}

//generate AccountID

string Account::generateAccountID()
{
	string accNum = "";
	for (int i = 0; i < 12; i++) { // 12 random digits
		int digit = rand() % 10;
		accNum += to_string(digit);
	}
	accNum += to_string(time(0) % 10000); // last 4 digits from time
	return accNum;
}


//generate IBAN 

string  Account::generateIBAN(const string& accountID)
{
	int checkNum = rand() % 9 + 1;
	string bankCode = "MSGL";
	string iban = "PK" + to_string(checkNum) + bankCode + accountID;

	return iban;
}

//creation time

string Account::date_of_creation()
{
	time_t now = time(0);
	char dt[26];  // ctime_s requires a buffer of at least 26 chars
	ctime_s(dt, sizeof(dt), &now);
	dt[strlen(dt) - 1] = '\0';  // remove trailing newline
	return string(dt);
}


//getters

double Account::getbalance() const {
	return balance;
}


string Account::getAccountID() const {
	return accountID;
}


string Account::getIBAN() const {
	return IBAN;
}