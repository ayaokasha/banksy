#ifndef CLINET_H
#define CLINET_H

#include <iostream>
#include <string>

#include "Person.h"

using namespace std;

class Client : public Person
{
private:
    double balance;

public:
    Client() : Person(0, " ", " ") { balance = 0.0; }
    Client(string n, int i, string p, double b) : Person(i, n, p) { balance = b; }
    void setBalance(double balance)
    {

        this->balance = balance;
    }
    double getBalance() { return balance; }

    void setDeposit(double amount)
    {
        if (amount > 0)
        {
            balance += amount;
            cout << "New balance: " << balance << endl;
        }
    }
    void setWithdraw(double amount)
    {
        if (amount > 0 && amount <= balance)
        {
            balance -= amount;
            cout << "New balance : " << balance << endl;
        }
        else
        {
            cout << "Amount exceeded balance" << endl;
        }
    }
    void setTransferTo(double amount, Client &recipient)
    {
        if (amount > 0 && amount <= balance)
        {
            balance -= amount;
            recipient.balance += amount;
        }
        cout << "New balance : " << balance << endl;
    }
    void checkBalance()
    {
        cout << "Balance: " << balance << endl;
    }
    void display() const override
    {
        Person::display();
        cout << "Balance: " << balance << endl;
    }
};
#endif
