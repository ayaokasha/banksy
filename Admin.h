#ifndef ADMIN_H
#define ADMIN_H

#include <iostream>
#include <string>
#include <vector>

#include "Employee.h"
#include "Validation.h"

using namespace std;

class Admin : public Employee
{
private:
    vector<Employee> employees;
    vector<Client> clients;

public:
    Admin() : Employee(0, " ", " ", 0.0) {}
    Admin(int id, const string &name, const string &password, double salary) : Employee(id, name, password, salary) {}
    // client
    void addClient(const Client &client)
    {
        clients.push_back(client);
        cout << "client added successfully" << endl;
    }
    Client *searchclient(int id)
    {
        for (auto &client : clients)
        {
            if (client.getId() == id)
            {
                return &client;
            }
        }
        return nullptr;
    }

    void editclient(int id, string name, string password, double balance)
    {
        Client *client = searchclient(id);
        if (client != nullptr)
        {
            client->setName(name);
            client->setPassword(password);
            client->setBalance(balance);
        }
        else
        {
            cout << "Client not found" << endl;
        }
    }
    // employee
    void addEmployee(const Employee &employee)
    {
        employees.push_back(employee);
    }

    Employee *searchEmployee(int id)
    {
        for (auto &employee : employees)
        {
            if (employee.getId() == id)
            {
                return &employee;
            }
        }
        return nullptr;
    }

    void editEmployee(int id, string name, string password, double salary)
    {
        Employee *employee = searchEmployee(id);
        if (employee != nullptr)
        {
            employee->setName(name);
            employee->setPassword(password);
            employee->setSalary(salary);
        }
        else
        {
            cout << "Employee not found" << endl;
        }
    }
    void listEmployee()
    {
        if (employee.empty())
        {
            cout << "No employee registered." << endl;
        }
    }
    // display
    void display() const override
    {

        Employee::display();
        cout << "Employees managed by Admin:\n";
        for (const auto &employee : employees)
        {
            employee.display();
            cout << endl;
        }
        cout << "Clients managed by Admin:\n";
        for (const auto &client : clients)
        {
            client.display();
            cout << endl;
        }
    }
};

#endif
