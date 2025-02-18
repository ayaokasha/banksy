#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <iostream>
#include <fstream>

#include "FilesHelper.h"
#include "Interface.h"
#include "Admin.h"
#include "Client.h"
#include "employee.h"

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
     vector<string> getAllClients() override
    {
        vector<string> clients;
        ifstream ClientFile("Client.txt");
        if (!ClientFile)
        {
            cout << "Unable to open file" << endl;
        }
        string line;
        while (getline(ClientFile, line))
        {
            clients.push_back(line)
        }
        ClientFile.close();
        return clients;
    }
    void removeAllClients() override
    {
        ofstream ClientFile("Client.txt", ios::trunc);
        ClientFile.close();
        cout << "All client have been remove successfully" << endl;
    }
bool employeeExist() override{
    ifstream file("employee.txt");
    if(!file)
        cout<< "file not found" << endl;
        return false;
                      }
           string line;
           if ( getline( file,line))
              {
                file.close();
                 returnfalse;
                   }
void addemployee(Employee employee) override{
if (employee exist())
{
cout << An employee is already exists."<<endl;
return;
}
ofstream file("employee.txt", ios::app);

        file << employee.getId() << " " << employee.getName() << " " << employee.getPassword() << " " << employee.getSalary() << endl;
        file.close();
        cout << "employee added successfully." << endl
}

 void getAllemployee() override
    {
        ifstream file("employee.txt");
        string line;
        while (getline(file, line))
        {
            cout << line << endl;
        }
        file.close();
    }

    void removeAllemployee() override
    {
        ofstream file("admin.employee", ios::trunc);
        file.close();
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
