/*Shamika Earle
Program specifications:
Please design and implement a C++  OOP program satisfying the following business requirements:
The ABC Company generally divides its customers into three groups:   preferred customers,   general customers, and  black-listed customers.
1. All customer records have attributes such as customer ID,   name, and  address. There are two operations registerCustomerInfo() and   printCustomerInfo() to set a new customer info and look up a customer info, respectively.  
2. The preferred customers have an additional attribute:  preferred-tiers. It has currently three levels: tier1, tier2, and tier3.
3. The black-listed customers has an additional attribute:  black-listed date. 
4. Create some driver code to test your program.*/

#include <iostream>
using std::cout;
using std::endl;
using std::string;

//user defined data type specifying a set of values for a variable
enum preferredTiers
{
    tier1,
    tier2,
    tier3
};

class PreferredCustomer : public GeneralCustomer
{
public:
    preferredTiers tiers;
    //register customer
    void Register(int id, string name, string addr, preferredTiers tier)
    {
        this->custId = id;
        this->name = name;
        this->address = addr;
        this->tiers = tier;
    }
    void printCustomerInfo()
    {
        cout << "Id: " << custId << endl;
        cout << "Name: " << name << endl;
        cout << "Address: " << address << endl;
        cout << "Preferred Tier is : ";
        
        switch (tiers)
        {
        case 0:
            cout << "Tier 1\n";
            break;
        case 1:
            cout << "Tier 2\n";
            break;
        case 2:
            cout << "Tier 3\n";
            break;
        }
    }
};

class GeneralCustomer
{
public:
    int custId;
    string name;
    string address;
    //to register a customer
    void Register(int id, string name, string addr)
    {
        this->custId = id;
        this->name = name;
        this->address = addr;
    }
    //print the customer info
    void printCustomerInfo()
    {
        cout << "Id: " << custId << endl;
        cout << "Name: " << name << endl;
        cout << "Address: " << address << endl;
    }
};

class BlackListedCustomer : public GeneralCustomer
{
public:
    string blackListed_date;
    //to register a customer
    void Register(int id, string name, string addr, string date)
    {
        this->custId = id;
        this->name = name;
        this->address = addr;
        this->blackListed_date;
    }
    //print customer info
    void printCustomerInfo()
    {
        cout << "Id: " << custId << endl;
        cout << "Name: " << name << endl;
        cout << "Address: " << address << endl;
        cout << "Black listed date is: " << this->blackListed_date << endl;
    }
};

int main()
{
    GeneralCustomer G;
    PreferredCustomer P;
    BlackListedCustomer B;
    return 0;
}