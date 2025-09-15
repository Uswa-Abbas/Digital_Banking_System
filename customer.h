#ifndef CUSTOMER_H
#define  CUSTOMER_H
#include<iostream>

#include<string>



class Customer {

private:
	std::string customerID;
	std::string customerName;
	std::string cnic;
	int age;
	double income;
	std::string fatherName;

public:
	Customer();
	Customer(std::string cusID, std::string cusName, std::string cn, int a, double inc, std::string fathern);


	void getCustomerInfo();

	bool getCustomerByCNIC(std::string searchCNIC);

	void setCustomerInfo();

	std::string getCustomerID()const;

	std::string getCustomerName()const;

	std::string getCustomerCNIC()const;

	std::string generatecustomerID();
	virtual ~Customer() = default;  // Add virtual destructor for safety


};

#endif  //CUSTOMER_H#pragma once