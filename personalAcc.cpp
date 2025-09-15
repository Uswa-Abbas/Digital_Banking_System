#include "personalAcc.h"


void PersonalAcc::setPersonalDetails()
{
	cin.ignore();
	cout << "Enter Date of Birth (DD/MM/YYYY):";
	getline(cin, dateOfBirth);

	cout << "Enter Address: ";
	getline(cin, address);

	cout << "Enter Occupation: ";
	getline(cin, occupation);
}

void PersonalAcc::openAccount() {
	Account::openAccount();
	setPersonalDetails();
}


void PersonalAcc::deposit() {
	double amount;
	cout << "Enter amount to deposit: ";
	cin >> amount;
	if (amount > 0)
	{
		balance += amount;
		cout << "Deposit successful! New Balance = " << balance << endl;

		// Save transaction

		ofstream fout("transaction.txt", ios::app);
		if (fout.is_open())
		{
			fout << "Deposit," << accountID << "," << amount << "," << getIBAN() << endl;
			fout.close();
		}
	}
	else {
		cout << "Invalid deposit amount!" << endl;
	}
}




void PersonalAcc::withdraw()
{
	double amount;
	cout << "Enter amount to withdraw: ";
	cin >> amount;
	if (amount > 0 && amount <= balance)
	{
		balance -= amount;
		cout << "Withdrawal successful! New Balance = " << balance << endl;

		// Save transaction
		ofstream fout("transaction.txt", ios::app);
		if (fout.is_open())
		{
			fout << "Withdraw," << accountID << "," << amount << "," << getIBAN() << endl;
			fout.close();
		}

	}
	else {
		cout << "Insufficient balance or invalid amount!" << endl;
	}


}



void PersonalAcc::displayAccountDetails() {
	ifstream fin("Account.txt");
	if (!fin.is_open()) {
		cout << "Error: Could not open Account.txt" << endl;
		return;
	}

	string line;
	bool found = false;

	while (getline(fin, line)) {
		if (line.find("AccountID:" + accountID) != string::npos) {
			found = true;

			cout << Yellow << "\n========== Personal Account ==========\n" << Reset;

			// Replace commas with newlines for spacing
			for (char& ch : line) {
				if (ch == ',') {
					cout << "\n";  // newline instead of comma
				}
				else {
					cout << ch;
				}
			}
			cout << "\n=====================================\n";

			break;
		}
	}
	fin.close();

	if (!found) {
		cout << "Account not found in file.\n";
	}
}