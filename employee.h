#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <iostream>
#include <string>
#include <vector>
#include "Person.h"

using namespace std;
class Employee : public Person
{
private:
    double salary;
    vector<Client> clients;

public:
    Employee(int id, const string &name, const string &password, double salary) : Person(id, name, password)
    {
        this->salary = salary;
    }

    double getSalary() const { return salary; }

    void setSalary(double salary)
    {

        this->salary = salary;
    }

    void addClient(const Client &client)
    {
        clients.push_back(client);
    }

    void display() const override
    {
        Person::display();
        cout << "Salary: " << salary << endl;
        cout << "Clients managed by " << name << ":\n";
        for (const auto &client : clients)
        {
            client.display();
            cout << endl;
        }
    }
};
#endif