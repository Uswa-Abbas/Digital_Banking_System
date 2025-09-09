#ifndef COMPANYACC_H
#define COMPANYACC_H
#include"account.h"

class CompanyAcc {


    string companyName;
    string registrationNO;
    string authorizedSidnatories;

    void verifyDoc();

    void displayCompany();
    virtual void  deposit();
    virtual void  withdraw();


};



#endif  
