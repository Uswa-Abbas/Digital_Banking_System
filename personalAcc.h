#ifndef PERSONALACC_H
#define PERSONALACC_H
#include "account.h"
#include "transaction.h"

class PersonalAcc : public Account {
private:
    string dateOfBirth;
    string address;
    string occupation;
public:
    PersonalAcc(string accID = "", string cuID = "", double bal = 0.00,
        string dob = "", string addr = "", string job = "")
        : Account(accID, cuID, "Personal", bal), dateOfBirth(dob), address(addr), occupation(job)
    {
    }

    void setPersonalDetails();
    void deposit() override;
    void withdraw() override;
    void displayAccountDetails() override;
    void openAccount() override;

    //void closeAcount();

};



#endif