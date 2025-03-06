#include <iostream>
#include <vector>
#include <string>

#include "Validation.h"
#include "Person.h"
#include "Client.h"
#include "Employee.h"
#include "Admin.h"
#include "Parser.h"
#include "Interface.h"
#include "FilesHelper.h"
#include "FileManager.h"
#include "AdminManager.h"
#include "ClientManager.h"
#include "EmployeeManager.h"
#include "Screen.h"

using namespace std;

int main()
{
    Screen::showMainScreen();

    vector<Client> clients;
    vector<Employee> employees;
    vector<Admin> admins;

    admins.push_back(Admin(1, "basmala", "admin123"));
    employees.push_back(Employee(101, "ayaaaa", "pass123", 5000.0));
    clients.push_back(Client(201, "nadaaaa", "client123", 1500.0));

    while (true)
    {
        int userType;
        cout << "\nWelcome to the Bank System\n";
        cout << "1. Admin Login\n";
        cout << "2. Employee Login\n";
        cout << "3. Client Login\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> userType;

        if (userType == 4)
            break;

        int id;
        string password;
        cout << "Enter your ID: ";
        cin >> id;
        cout << "Enter your password: ";
        cin >> password;

        if (userType == 1)
        {
            for (Admin &admin : admins)
            {
                if (admin.getId() == id && admin.getPassword() == password)
                {
                    cout << "Admin Access Granted!\n";
                    while (AdminManager::adminOptions(employees, clients))
                        ;
                    break;
                }
            }
            cout << "Invalid Admin Credentials!\n";
        }
        else if (userType == 2)
        {
            for (Employee &emp : employees)
            {
                if (emp.getId() == id && emp.getPassword() == password)
                {
                    cout << "Employee Access Granted!\n";
                    while (EmployeeManager::employeeOptions(clients))
                        ;
                    break;
                }
            }
            cout << "Invalid Employee Credentials!\n";
        }
        else if (userType == 3)
        {
            for (Client &client : clients)
            {
                if (client.getId() == id && client.getPassword() == password)
                {
                    cout << "Client Access Granted!\n";
                    ClientManager::printClientMenu(client);
                    break;
                }
            }
            cout << "Invalid Client Credentials!\n";
        }
        else
        {
            cout << "Invalid choice. Try again.\n";
        }
    }
    return 0;
}
