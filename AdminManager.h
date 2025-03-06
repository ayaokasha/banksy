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
        cout << "4. Edit Employee\n";
        cout << "5. Add Client\n";
        cout << "6. Remove Client\n";
        cout << "7. View Client Details\n";
        cout << "8. Edit Client\n";
        cout << "9. Logout\n";
        cout << "Enter your choice: ";
    }

    static Admin *Login(vector<Admin *> &admins, int id, string password)
    {
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
        cout << "Adding new employee...\n";
    }

    static void removeEmployee(vector<Employee> &employees)
    {
        cout << "Removing an employee...\n";
    }

    static void viewEmployeeDetails(vector<Employee> &employees)
    {
        cout << "Viewing employee details...\n";
    }

    static void addClient(vector<Client> &clients)
    {
        cout << "Adding new client...\n";
    }

    static void removeClient(vector<Client> &clients)
    {
        cout << "Removing a client...\n";
    }

    static void viewClientDetails(vector<Client> &clients)
    {
        cout << "Viewing client details...\n";
    }

    static void editEmployee(vector<Employee> &employees)
    {
        int id;
        cout << "Enter Employee ID to edit: ";
        cin >> id;

        for (Employee &emp : employees)
        {
            if (emp.getId() == id)
            {
                string name, password;
                double salary;

                cout << "Enter new Employee Name: ";
                cin.ignore();
                getline(cin, name);
                cout << "Enter new Employee Password: ";
                cin >> password;
                cout << "Enter new Employee Salary: ";
                cin >> salary;

                emp.setName(name);
                emp.setPassword(password);
                emp.setSalary(salary);
                cout << "Employee updated successfully.\n";
                return;
            }
        }
        cout << "Employee not found.\n";
    }

    static void editClient(vector<Client> &clients)
    {
        int id;
        cout << "Enter Client ID to edit: ";
        cin >> id;

        for (Client &client : clients)
        {
            if (client.getId() == id)
            {
                string name, password;
                double balance;

                cout << "Enter new Client Name: ";
                cin.ignore();
                getline(cin, name);
                cout << "Enter new Client Password: ";
                cin >> password;
                cout << "Enter new Balance: ";
                cin >> balance;

                client.setName(name);
                client.setPassword(password);
                client.setBalance(balance);
                cout << "Client updated successfully.\n";
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
            editEmployee(employees);
            break;
        case 5:
            addClient(clients);
            break;
        case 6:
            removeClient(clients);
            break;
        case 7:
            viewClientDetails(clients);
            break;
        case 8:
            editClient(clients);
            break;
        case 9:
            return false;
        default:
            cout << "Invalid choice. Try again.\n";
        }
        return true;
    }
};

#endif