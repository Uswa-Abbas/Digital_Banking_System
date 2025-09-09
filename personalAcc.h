#ifndef PERSONALACC_H
#define PERSONALACC_H
#include "account.h"

class PersonalAcc : public Account {
    string dateOfBirth;
    string address;
    string occupation;


    void closeAcount();
    void deposit() override;
    void withdraw() override;


};



#endif  
