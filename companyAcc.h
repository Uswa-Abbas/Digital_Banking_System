#ifndef COMPANYACC_H
#define COMPANYACC_H
#include"account.h"
#include<vector>

class CompanyAcc :public Account {
private:
    string companyName;
    string registrationNo;
    vector<string> authorizedSignatories;

public:

    CompanyAcc(string accID = "", string cuID = "", double bal = 0.0,
        string compName = "", string regNo = "", string authSigns = "")
        : Account(accID, cuID, "Company", bal),
        companyName(compName), registrationNo(regNo)
    {
    }

    // Set extra company details
    void setCompanyDetails();

    // Override required functions
    void deposit() override;
    void withdraw() override;


    // Extra functions
    void verifyDoc();
    void displayCompany() const;

    void displayAccountDetails() override;
    void openAccount() override;

    void addAuthorizedSigner(const string& signer);

};



#endif