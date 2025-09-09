#define _CRT_SECURE_NO_WARNINGS

#include"transaction.h"
#include"account.h"
#include "colors.h"
#include <vector>
#include <string>
#include<fstream>
#include<ctime>




using namespace std;

 
Transaction::Transaction(){
	transactionID = "";
	date_time = "";
	accountID = "";
	amount=0.0;
	type = "";
}

void Transaction::recordTransaction(string accID,string t, double amt) {

	accountID = accID;
	type = t;
	amount = amt;
	transactionID = generateTransactionID();
	date_time = getCurrentDateTime();

	saveToFile();
}


void Transaction::transactionHistory(std::string accID)const {

	if (accountID == accID) {
		cout << "Transaction ID : " << transactionID << endl;
		cout << "Account ID : " << accountID << endl;
		cout << "Type : " << type << endl;
		cout << "Amount : " << amount<< endl;
		cout << "Date/Time : " << date_time << endl;

	}

}


void Transaction::update(double newAmount, const std::string& newType) {

	amount = newAmount;
	type = newType;

	ifstream fin("transaction.txt");
	vector<Transaction>transactions;

	string line;

	while (getline(fin, line)) {
		vector<string>fields = split(line, ',');
		if (fields.size() < 5) {
			continue;
		}

		Transaction txn;
		txn.transactionID = fields[0];
		txn.accountID = fields[1];
		txn.type = fields[2];
		txn.amount = stringToDouble(fields[3]);
		txn.date_time = fields[4];

		if (txn.transactionID == transactionID) {

			txn.type = newType ;
			txn.amount = newAmount;
		}

		transactions.push_back(txn);

	}
	fin.close();

	ofstream fout("transaction.txt", ios::trunc);
	for (const auto& txn : transactions) {
		fout << txn.transactionID << ","
			<< txn.accountID << ","
			<< txn.type << ","
			<< txn.amount << ","
			<< txn.date_time << "\n";
	}
	fout.close();
	cout << Green << "Data update sucessfully" << Reset << endl;

}


string Transaction::generateTransactionID() {
	time_t now = time(nullptr);
	return "TXN" + to_string(now);
}

string Transaction::getCurrentDateTime() {
	time_t now = time(nullptr);
	char* dt = ctime(&now);// returns a C-string like "Wed Jun 30 21:49:08 1993\n"
	string dateTimeStr(dt);

	//remove trailing newline character
	if (!dateTimeStr.empty() && dateTimeStr.back() == '\n') {
		dateTimeStr.pop_back();
	}

	return dateTimeStr;
}

vector<string> Transaction::split(const string& s, char delimiter) {

	vector<string>tokens;
	string token;
	for (char ch : s) {
		if (ch == delimiter) {
			tokens.push_back(token);
			token.clear();
		}
		else {
			token += ch;
		}
	}
	tokens.push_back(token);
	return tokens;

}

double Transaction::stringToDouble(const string& s) {

	double val = 0, frac = 0;
	int sign = 1, i = 0;
	bool decimal = false;
	double divisor = 1;

	if (s.empty()) { return 0; }

	if (s[0] == '-') {
		sign = -1;
		i = 1;
	}


	for (;i<(int)s.size();++i) {
		if (s[i] == '.') {
			decimal = true;
			continue;
		}
		if (s[i] < '0' || s[i]>'9') {
			break;
		}
		if (!decimal) {
			val = val * 10 + (s[i] - '0');

		}
		else {
			frac = frac * 10 + (s[i] - '0');
			divisor *= 10;
		}
	}
	return sign * (val + frac / divisor);
}


void Transaction::saveToFile()const {
	ofstream fout("transaction.txt", ios::app);
	if (!fout) {
		cout <<Red<< "Error in opening file"<<Reset;
		return;
	}

	fout << transactionID << "," << accountID << "," << type << ","
		<< amount << "," << date_time << "\n";
	fout.close();
	cout << Green << "Transaction data is saved\n" << Reset;
}




void Transaction::loadAllTransactions() {
	ifstream fin("transaction.txt");
	if (!fin) {
		cout << Red << "Transaction file is not found " << Reset;
		return;
	}

	string line;
	while (getline(fin, line)) {
		cout << line << endl;

	}

	fin.close();
	cout << Green << "All data load safely from transaction file" << Reset << endl;
}



