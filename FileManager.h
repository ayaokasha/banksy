#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <iostream>
#include <fstream>

#include "FilesHelper.h"
#include "Interface.h"
#include "Admin.h"
#include "Client.h"

using namespace std;

class FileManager : public DataSourceInterface
{
public:
    // bool fileExists() override
    // {
    //     ifstream ClientFile("Client.txt");
    //     if (!ClientFile)
    //     {
    //         cout << "File not found" << endl;
    //         return false;
    //     }

    //     string line;
    //     if (getline(ClientFile, line))
    //     {
    //         ClientFile.close();
    //         return true;
    //     }
    //     ClientFile.close();
    //     return false;
    // }
    void addClient(Client client) override
    {
        ofstream ClientFile("Client.txt", ios::app);
        if (!ClientFile)
        {
            cout << "Unable to open file" << endl;
            return;
        }
        ClientFile << client.getId() << " " << client.getName() << " " << client.getPassword() << " " << client.getBalance() << endl;
        ClientFile.close();
        cout << "Client added successfully" << endl;
    }
    void getAllClients() override
    {
        ifstream ClientFile("Client.txt");
        if (!ClientFile)
        {
            cout << "UNable to open file" << endl;
        }
        string line;
        while (getline(ClientFile, line))
        {
            cout << line << endl;
        }
        ClientFile.close();
    }
    void removeAllClients() override
    {
        ofstream ClientFile("Client.txt", ios::trunc);
        ClientFile.close();
        cout << "All client have been remove successfully" << endl;
    }
    bool adminExists() override
    {
        ifstream file("admin.txt");
        if (!file)
            return false;
        string line;
        if (getline(file, line))
        {
            file.close();
            return true;
        }
        file.close();
        return false;
    }
    void addAdmin(Admin admin) override
    {
        if (adminExists())
        {
            cout << "An admin is already exists." << endl;
            return;
        }
        ofstream file("admin.txt", ios::app);

        file << admin.getId() << " " << admin.getName() << " " << admin.getPassword() << " " << admin.getSalary() << endl;
        file.close();
        cout << "Admin added successfully." << endl;
    }

    void getAllAdmins() override
    {
        ifstream file("admin.txt");
        string line;
        while (getline(file, line))
        {
            cout << line << endl;
        }
        file.close();
    }

    void removeAllAdmins() override
    {
        ofstream file("admin.txt", ios::trunc);
        file.close();
    }
};
#endif
