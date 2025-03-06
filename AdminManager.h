#ifndef ADMINMANAGER_H
#define ADMINMANAGER_H

#include <iostream>
#include <vector>
#include <string>
#include "Admin.h"
#include "Employee.h"
#include "Client.h"
#include "Validation.h"

using namespace std;

class AdminManager
{
public:
    static void printAdminMenu()
    {
        cout << "Admin Menu:\n";
        cout << "1. Add Employee\n";
        cout << "2. Remove Employee\n";
        cout << "3. View Employee Details\n";
        cout << "4. Add Client\n";
        cout << "5. Remove Client\n";
        cout << "6. View Client Details\n";
        cout << "7. Logout\n";
        cout << "Enter your choice: ";
    }

    static Admin *Login(int id, string password)
    {
        vector<Admin *> admins = {};
        for (Admin *admin : admins)
        {
            if (admin->getId() == id && admin->getPassword() == password)
            {
                cout << "Login successful!" << endl;
                return admin;
            }
        }
        cout << "Invalid credentials. Login failed." << endl;
        return nullptr;
    }

    static void addEmployee(vector<Employee> &employees)
    {
        int id;
        string name, password;
        double salary;

        cout << "Enter Employee ID: ";
        cin >> id;
        cout << "Enter Employee Name: ";
        cin >> name;
        cout << "Enter Employee Password: ";
        cin >> password;
        cout << "Enter Employee Salary: ";
        cin >> salary;

        employees.push_back(Employee(id, name, password, salary));
        cout << "Employee added successfully.\n";
    }

    static void removeEmployee(vector<Employee> &employees)
    {
        int id;
        cout << "Enter Employee ID to remove: ";
        cin >> id;

        for (auto it = employees.begin(); it != employees.end(); ++it)
        {
            if (it->getId() == id)
            {
                employees.erase(it);
                cout << "Employee removed successfully.\n";
                return;
            }
        }
        cout << "Employee not found.\n";
    }

    static void viewEmployeeDetails(const vector<Employee> &employees)
    {
        int id;
        cout << "Enter Employee ID to view: ";
        cin >> id;

        for (const Employee &emp : employees)
        {
            if (emp.getId() == id)
            {
                cout << "ID: " << emp.getId()
                     << ", Name: " << emp.getName()
                     << ", Salary: $" << emp.getSalary()
                     << endl;
                return;
            }
        }
        cout << "Employee not found.\n";
    }

    static void addClient(vector<Client> &clients)
    {
        int id;
        string name, password;
        double balance;

        cout << "Enter Client ID: ";
        cin >> id;
        cout << "Enter Client Name: ";
        cin.ignore(); // لتجنب مشاكل قراءة السطر بالكامل
        getline(cin, name);
        cout << "Enter Client Password: ";
        cin >> password;
        cout << "Enter Initial Balance: ";
        cin >> balance;

        clients.push_back(Client(id, name, password, balance));
        cout << "Client added successfully.\n";
    }

    static void removeClient(vector<Client> &clients)
    {
        int id;
        cout << "Enter Client ID to remove: ";
        cin >> id;

        for (auto it = clients.begin(); it != clients.end(); ++it)
        {
            if (it->getId() == id)
            {
                clients.erase(it);
                cout << "Client removed successfully.\n";
                return;
            }
        }
        cout << "Client not found.\n";
    }

    static void viewClientDetails(const vector<Client> &clients)
    {
        int id;
        cout << "Enter Client ID to view: ";
        cin >> id;

        for (const Client &client : clients)
        {
            if (client.getId() == id)
            {
                cout << "ID: " << client.getId()
                     << ", Name: " << client.getName()
                     << ", Balance: $" << client.getBalance()
                     << endl;
                return;
            }
        }
        cout << "Client not found.\n";
    }

    static bool adminOptions(vector<Employee> &employees, vector<Client> &clients)
    {
        int choice;
        printAdminMenu();
        cin >> choice;

        switch (choice)
        {
        case 1:
            addEmployee(employees);
            break;
        case 2:
            removeEmployee(employees);
            break;
        case 3:
            viewEmployeeDetails(employees);
            break;
        case 4:
            addClient(clients);
            break;
        case 5:
            removeClient(clients);
            break;
        case 6:
            viewClientDetails(clients);
            break;
        case 7:
            return false;
        default:
            cout << "Invalid choice. Try again.\n";
        }
        return true;
    }
};

#endif
