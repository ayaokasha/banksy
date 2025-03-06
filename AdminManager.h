#ifndef ADMINMANAGER_H
#define ADMINMANAGER_H

#include <iostream>
#include <vector>
#include <string>

#include "Admin.h"
#include "Employee.h"
#include "Validation.h"

class AdminManager
{
public:
    static void printAdminMenu()
    {
        cout << "Admin Menu:" << endl;
        cout << "1. Add Employee" << endl;
        cout << "2. Remove Employee" << endl;
        cout << "3. View Employee Details" << endl;
        cout << "4. Logout" << endl;
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
    static bool AdminOptions(Employee *employee)
    {
        if (employee == nullptr)
        {
            cout << "Invalid employee data." << endl;
            return false;
        }
        cout << "Admin Options for Employee ID " << employee->getId() << ":" << endl;
        cout << "1. Promote Employee" << endl;
        cout << "2. Demote Employee" << endl;
        cout << "3. Change Employee Salary" << endl;
        cout << "4. Back to Admin Menu" << endl;

        int choice;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Employee promoted!" << endl;
            break;
        case 2:
            cout << "Employee demoted!" << endl;
            break;
        case 3:
            cout << "Enter new salary: ";
            double newSalary;
            cin >> newSalary;
            employee->setSalary(newSalary);
            cout << "Salary updated!" << endl;
            break;
        case 4:
            cout << "Returning to Admin Menu..." << endl;
            return true;
        default:
            cout << "Invalid choice. Please try again." << endl;
            break;
        }
        return false;
    }
};

#endif
