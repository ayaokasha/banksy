#ifndef EMPLOYEEMANAGER_H
#define EMPLOYEEMANAGER_H
#include <iostream>
#include <vector>
#include < string>

#include "Employee.h"
#include  "Client.h"
#include "FileManager.h"
#include "FilesHelper.h"
#include "Validation.h"
using namespace std;

class EmployeeManager {
public:
    static void printEmployeeMenu() {
        cout << "Employee Menu:" endl;
        cout << "1. Add Client" endl;
        cout << "2. List Clients"endl;
        cout << "3. Search Client"endl;
        cout << "4. Edit Client"endl;
        cout << "5. My Info"endl;
        cout << "6. Logout"endl;
        cout << "Enter your choice: ";
    }

    static void newClient(Employee* employee, vector<Client>& clients) {
        int id;
        string name, password;
        double balance;

        cout << "Enter client ID: ";
        cin >> id;
        cout << "Enter client name: ";
        cin >> name;
        cout << "Enter client password: ";
        cin >> password;
        cout << "Enter initial balance: ";
        cin >> balance;

        clients.push_back(id, name, password, balance);
        cout << "Client added successfully."endl;
    }

    static void listAllClients(Employee* employee, const vector<Client>& clients) {
        cout << "Client List:" endl;
        for (const Client& client : clients) {
            cout << "ID: " << client.id << ", Name: " << client.name << ", Balance: $" << fixed << setprecision(2) << client.balance << endl;
        }
    }

    static void searchForClient(Employee* employee, const vector<Client>& clients) {
        int id;
        cout << "Enter client ID to search: ";
        cin >> id;

        for (const Client& client : clients) {
            if (client.id == id) {
                cout << "ID: " << client.id << ", Name: " << client.name << ", Balance: $" << fixed << setprecision(2) << client.balance << endl;
                return;
            }
        }
        cout << "Client not found." endl;
    }

    static void editClientInfo(Employee* employee, vector<Client>& clients) {
        int id;
        cout << "Enter client ID to edit: ";
        cin >> id;

        for (Client& client : clients) {
            if (client.id == id) {
                cout << "Enter new name: ";
                cin >> client.name;
                cout << "Enter new password: ";
                cin >> client.password;
                cout << "Enter new balance: ";
                cin >> client.balance;
                cout << "Client info updated successfully."endl;
                return;
            }
        }
        cout << "Client not found."endl;
    }

    static Employee* login(int id, string password, vector<Employee>& employees) {
        for (Employee& employee : employees) {
            if (employee.id == id && employee.password == password) {
                return &employee;
            }
        }
        return nullptr;
    }
    static bool employeeOptions(Employee* employee, vector<Client>& clients, vector<Employee>& employees) {
        int choice;
        printEmployeeMenu();
        cin >> choice;

        switch (choice) {
        case 1:
            newClient(employee, clients);
            break;
        case 2:
            listAllClients(employee, clients);
            break;
        case 3:
            searchForClient(employee, clients);
            break;
        case 4:
            editClientInfo(employee, clients);
            break;
        case 5:
            cout << "ID: " << employee->id << ", Name: " << employee->name << ", Salary: $" << fixed << setprecision(2) << employee->salary << endl;
            break;
        case 6:
            return false;
        default:
            cout << "Invalid choice."endl;
        }
        return true;
    }
};
