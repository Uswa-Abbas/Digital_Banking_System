#include "customer.h"
#include"account.h"
#include <iostream>
using namespace std;

int main() {
    srand(time(0));

    // Option 1: Let user enter info interactively
    Customer c;
    c.setCustomerInfo();

    cout << "\nCustomer info you entered:\n";
    c.getCustomerInfo();

    //// Option 2: Search customer by CNIC
    string searchCNIC;
    cout << "\nEnter CNIC to search: ";
    getline(cin, searchCNIC);

    c.getCustomerByCNIC(searchCNIC);


    Account acc;
    acc.openAccount();






    return 0;
}