#include "companyAcc.h"

void CompanyAcc::setCompanyDetails() {
    cout << "\n===== Enter Company Account Details =====\n";

    // Company Name
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Enter Company Name: ";
    getline(cin, companyName);

    // Registration Number
    cout << "Enter Company Registration Number: ";
    getline(cin, registrationNo);

    // Authorized Signatories
    int n;
    cout << "Enter number of authorized signatories: ";
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int i = 0; i < n; i++) {
        string signer;
        cout << "Enter name of signer " << (i + 1) << ": ";
        getline(cin, signer);
        addAuthorizedSigner(signer);
    }

    // Date/Time (account creation)
    time_t now = time(0);
    string creationDate = ctime(&now);
    if (!creationDate.empty() && creationDate.back() == '\n') {
        creationDate.pop_back();  // remove newline
    }

    cout << "\n Company details saved successfully!\n";

    // Save to file
    ofstream fout("companyAccounts.txt", ios::app);
    if (fout.is_open()) {
        fout << "Company:" << companyName << ","
            << "RegNo:" << registrationNo << ","
            << "Signatories:";
        for (size_t i = 0; i < authorizedSignatories.size(); i++) {
            fout << authorizedSignatories[i];
            if (i != authorizedSignatories.size() - 1) fout << "|";
        }
        fout << "," << "AccountID:" << accountID
            << "," << "IBAN:" << IBAN
            << "," << "Balance:" << balance
            << "," << "Date:" << creationDate << "\n";
        fout.close();
    }
    else {
        cout << "Error saving company details to file.\n";
    }
}


void CompanyAcc::openAccount() {
    Account::openAccount();
    setCompanyDetails();
}



void CompanyAcc::deposit() {
    double amount;
    cout << "Enter deposit amount: ";
    cin >> amount;

    if (amount <= 0) {
        cout << "Invalid deposit amount!\n";
        return;
    }

    balance += amount;
    cout << "Deposit successful. New Balance = " << balance << endl;

    time_t now = time(0);
    char* dt = ctime(&now);
    dt[strlen(dt) - 1] = '\0';  // newline remove



    ofstream fout("transactions.txt", ios::app);
    if (fout.is_open()) {
        fout << "Deposit," << accountID << "," << amount << "," << balance << "," << dt << endl;
        fout.close();
    }
}



void CompanyAcc::withdraw() {
    double amount;
    cout << "Enter withdrawal amount: ";
    cin >> amount;

    if (amount <= 0) {
        cout << "Invalid withdrawal amount!\n";
        return;
    }

    if (amount > balance) {
        cout << "Insufficient balance! Current Balance = " << balance << endl;
        return;
    }

    balance -= amount;   // inherited from Account
    cout << "Withdrawal successful. New Balance = " << balance << endl;




    time_t now = time(0);
    char* dt = ctime(&now);
    dt[strlen(dt) - 1] = '\0';



    // Optional: Transaction record
    ofstream fout("transactions.txt", ios::app);
    if (fout.is_open()) {
        fout << "Deposit," << accountID << "," << amount << "," << balance << "," << dt << endl;
        fout.close();
    }
}




void CompanyAcc::verifyDoc() {
    cout << "\n===== Verifying Company Documents =====\n";

    if (companyName.empty() || registrationNo.empty() || authorizedSignatories.empty()) {
        cout << " Document verification failed! Missing details.\n";
    }
    else {
        cout << " Documents verified successfully for company: " << companyName << endl;
    }
}





void CompanyAcc::addAuthorizedSigner(const string& signer) {
    authorizedSignatories.push_back(signer);
}



void CompanyAcc::displayCompany() const {
    cout << "\n========== Company Account ==========\n";
    cout << "Company Name       : " << companyName << endl;
    cout << "Registration No    : " << registrationNo << endl;
    cout << "Authorized Users   : ";
    for (const auto& s : authorizedSignatories) {
        cout << s << "  ";
    }
    cout << "\nAccount ID         : " << accountID << endl;
    cout << "IBAN               : " << IBAN << endl;
    cout << "Balance            : " << balance << endl;
    cout << "=====================================\n";
}



void CompanyAcc::displayAccountDetails() {
    ifstream fin("companyAccounts.txt");
    if (!fin.is_open()) {
        cout << "Error: Could not open companyAccounts.txt" << endl;
        return;
    }

    string line;
    bool found = false;

    while (getline(fin, line)) {
        if (line.find("AccountID:" + accountID) != string::npos) {
            cout << "\n========== Company Account ==========\n";
            cout << line << endl;  // raw line print
            found = true;
            break;
        }
    }
    fin.close();

    if (!found) {
        cout << "Company account not found in file.\n";
    }
}