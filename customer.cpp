#include "customer.h"
#include "colors.h"
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

    customerID = "CUS" + cn; // to generate customer ID
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


    ofstream fout("customer.txt", ios::app);
    if (fout.is_open())
    {
        fout << getCustomerName() << "," << customerID << "," << cnic
            << "," << fatherName << "," << age << "," << income << endl;

        fout.close();
    }
    else
    {
        cout << "ERROR : Unable to open file\n"
            ;
    }
}

void Customer::getCustomerInfo()
{
    customerID = generatecustomerID();
    cout << "Customer Name :" << customerName << endl;
    cout << "Customer ID :" << customerID << endl;
    cout << "Customer CNIC :" << cnic << endl;

    cout << "Father's Name :" << fatherName << endl;
    cout << "Customer age :" << age << endl;
    cout << "Customer income :" << income << endl;
}

bool Customer::getCustomerByCNIC(std::string searchCNIC)
{
    customerID = generatecustomerID();
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
                cout << "Customer Name :" << cusName << std::endl;
                cout << "Customer ID :" << cusID << std::endl;
                cout << "Customer CNIC :" << cusCNIC << std::endl;
                cout << "Father's Name :" << cusFather << std::endl;
                cout << "Customer age :" << ageStr << std::endl;
                cout << "Customer income :" << incomeStr << std::endl;
                return true;
            }
        }
        cout << "This CNIC is not present\n";
        return false;
    }
    else
    {
        cout << "ERROR in opening file " << std::endl;
        return false;
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



string Customer::generatecustomerID()
{
    string cusID = "CUS";
    for (int i = 0; i < 3; i++) { // 12 random digits
        int digit = rand() % 10;
        cusID += to_string(digit);
    }
    cusID += to_string(time(0) % 10); // last 4 digits from time
    return cusID;
}