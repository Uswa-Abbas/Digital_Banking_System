#ifndef CUSTOMER_H
#define  CUSTOMER_H
#include<iostream>

#include<string>



class Customer {

protected:
	std::string customerID;
	std::string customerName;
	std::string cnic;


private:
	int age;
	double income;
	std::string fatherName;

public:
	Customer();
	Customer(std::string cusID, std::string cusName, std::string cn, int a, double inc, std::string fathern);


	void getCustomerInfo()const;

	void getCustomerByCNIC(std::string searchCNIC)const;

	void setCustomerInfo();

	std::string getCustomerID()const;

	std::string getCustomerName()const;

	std::string getCustomerCNIC()const;



};

#endif  //CUSTOMER_H#pragma once
