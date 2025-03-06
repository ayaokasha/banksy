#ifndef BANKSYSTEM_H
#define BANKSYSTEM_H

#include <iostream>
#include <vector>
#include <string>

#include "Client.h"
#include "Employee.h"

using namespace std;

class EmployeeManager
{
public:
    static void printEmployeeMenu()
    {
        cout << "Employee Menu:\n";
        cout << "1. Add Client\n";
        cout << "2. List Clients\n";
        cout << "3. Search Client\n";
        cout << "4. Edit Client\n";
        cout << "5. Logout\n";
        cout << "Enter your choice: ";
    }

    static void newClient(vector<Client> &clients)
    {
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

        clients.push_back(Client(id, name, password, balance));
        cout << "Client added successfully.\n";
    }

    static void listAllClients(const vector<Client> &clients)
    {
        cout << "Client List:\n";
        for (const Client &client : clients)
        {
            cout << "ID: " << client.getId()
                 << ", Name: " << client.getName()
                 << ", Balance: $" << client.getBalance()
                 << endl;
        }
    }

    static void searchForClient(const vector<Client> &clients)
    {
        int id;
        cout << "Enter client ID to search: ";
        cin >> id;

        for (const Client &client : clients)
        {
            if (client.getId() == id)
            {
                cout << "ID: " << client.getId()
                     << ", Name: " << client.getName()
                     << ", Balance: " << client.getBalance()
                     << endl;
                return;
            }
        }
        cout << "Client not found.\n";
    }

    static void editClientInfo(vector<Client> &clients)
    {
        int id;
        cout << "Enter client ID to edit: ";
        cin >> id;

        for (Client &client : clients)
        {
            if (client.getId() == id)
            {
                string newName, newPassword;
                double newBalance;

                cout << "Enter new name: ";
                cin >> newName;
                cout << "Enter new password: ";
                cin >> newPassword;
                cout << "Enter new balance: ";
                cin >> newBalance;

                client.setName(newName);
                client.setPassword(newPassword);
                client.setBalance(newBalance);

                cout << "Client info updated successfully.\n";
                return;
            }
        }
        cout << "Client not found.\n";
    }

    static bool employeeOptions(vector<Client> &clients)
    {
        int choice;
        printEmployeeMenu();
        cin >> choice;

        switch (choice)
        {
        case 1:
            newClient(clients);
            break;
        case 2:
            listAllClients(clients);
            break;
        case 3:
            searchForClient(clients);
            break;
        case 4:
            editClientInfo(clients);
            break;
        case 5:
            return false;
        default:
            cout << "Invalid choice.\n";
        }
        return true;
    }
};

#endif
