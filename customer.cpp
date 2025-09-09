#include "customer.h"
// #include "colors.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

Customer::Customer()
{

    cnic = "";
    age = 0;
    income = 0.0;
    fatherName = "";

    customerID = ""; // to generate customer ID
}

Customer::Customer(std::string cusID, std::string cusName, std::string cn, int a, double inc, std::string fathern)
{

    cnic = cn;
    age = a;
    income = inc;
    fatherName = fathern;

    customerID = "CUS" + cn.substr(0, 3); // to generate customer ID
}


void Customer::setCustomerInfo()
{
    cout << "Enter Customer name : ";
    getline(cin, customerName);

    cout << "Enter CNIC (13 digits ):";
    getline(cin, cnic);

    while (cnic.length() != 13)
    {
        cout << "Please enter 13 digits ID card number\n";
        getline(cin, cnic);
    }

    cout << "Enter Father's Name : ";
    getline(cin, fatherName);

    cout << "Enter Your Age :";
    cin >> age;

    cout << "Enter Your income :";
    cin >> income;

    cin.ignore();

    customerID = "CUS" + cnic.substr(0, 3); // to generate customer ID

    ofstream fout("customer.txt", ios::app);
    if (fout.is_open())
    {
        fout << getCustomerName() << "," << customerID << "," << cnic
            << "," << fatherName << "," << age << "," << income << endl;

        fout.close();
        cout << "Customer information is saved sucessfully \n";
    }
    else
    {
        cout << "ERROR : Unable to open file\n"
            ;
    }
}

void Customer::getCustomerInfo()const
{
    cout << "Customer Name :" << customerName << endl;
    cout << "Customer ID :" << customerID << endl;
    cout << "Customer CNIC :" << cnic << endl;

    cout << "Father's Name :" << fatherName << endl;
    cout << "Customer age :" << age << endl;
    cout << "Customer income :" << income << endl;
}

void Customer::getCustomerByCNIC(string searchCNIC)const
{
    bool found = false;
    string cusName, cusID, cusCNIC, cusFather, ageStr, incomeStr;
    ifstream fin("customer.txt");
    if (fin.is_open())
    {

        while (getline(fin, cusName, ',') &&
            getline(fin, cusID, ',') &&
            getline(fin, cusCNIC, ',') &&
            getline(fin, cusFather, ',') &&
            getline(fin, ageStr, ',') &&
            getline(fin, incomeStr))
        {

            if (cusCNIC == searchCNIC)
            {
                cout << "Customer Name :" << cusName << endl;
                cout << "Customer ID :" << cusID << endl;
                cout << "Customer CNIC :" << cusCNIC << endl;

                cout << "Father's Name :" << cusFather << endl;
                cout << "Customer age :" << ageStr << endl;
                cout << "Customer income :" << incomeStr << endl;
                found = true;
                break;
            }
        }
    }
    else
    {
        cout << "ERROR in opening file " << endl;
    }
    if (!found) {
        cout << "this CNIC is not present \n";
    }
}


string Customer::getCustomerID()const {
    return customerID;
}

string Customer::getCustomerName()const {
    return customerName;
}

string Customer::getCustomerCNIC()const {
    return cnic;

}





