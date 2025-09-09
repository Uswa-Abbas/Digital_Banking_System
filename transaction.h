#ifndef TRANSACTION_H
#define  TRANSACTION_H
#include<iostream>
#include<vector> 



class Transaction {

 
protected:
    std::string transactionID;
    std::string date_time;

    std::string accountID;
    double amount;
    std::string type;

public:

    

    Transaction();
    void recordTransaction(std::string accountID, std::string type, double amount);
    void transactionHistory(std::string accountID)const;
    void update(double newAmount, const std::string& newType );   
    std::string generateTransactionID();
    std::string getCurrentDateTime();
    std::vector<std::string> split (const std::string& s, char delimiter);
    double stringToDouble(const std::string& s);
    void saveToFile()const;
    void loadAllTransactions();
};

#endif