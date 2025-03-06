#ifndef FILEMANAGER_H_INCLUDED
#define FILEMANAGER_H_INCLUDED
#include <iostream>
#include <fstream>

#include "FilesHelper.h"
#include "Interface.h"
#include "Admin.h"
#include "Client.h"
#include "Employee.h"

using namespace std;

class FileManager : public DataSourceInterface
{
public:
    void addClient(Client client) override
    {
        ofstream ClientFile("Client.txt", ios::app);
        if (!ClientFile)
        {
            cout << "Unable to open file" << endl;
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
            cout << "Unable to open file" << endl;
            return;
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
    // employee
    void addEmployee(Employee employee) override
    {
        ofstream file("employee.txt", ios::app);

        file << employee.getId() << " " << employee.getName() << " " << employee.getPassword() << " " << employee.getSalary() << endl;
        file.close();
        cout << "employee added successfully." << endl;
    }

    void getAllEmployees() override
    {
        ifstream file("employee.txt");
        string line;
        while (getline(file, line))
        {
            cout << line << endl;
        }
        file.close();
    }

    void removeAllEmployees() override
    {
        ofstream file("employee.txt", ios::trunc);
        file.close();
    }
    // admin
    bool adminExists() override
    {
        ifstream Adminfile("admin.txt");
        if (!Adminfile)
            return false;
        string line;
        if (getline(Adminfile, line))
        {
            Adminfile.close();
            return true;
        }
        Adminfile.close();
        return false;
    }
    void addAdmin(Admin admin) override
    {
        if (adminExists())
        {
            cout << "An admin is already exists." << endl;
            return;
        }
        ofstream Adminfile("admin.txt", ios::app);
        if (!Adminfile)
        {
            cout << "Unable to open file " << endl;
        }
        Adminfile << admin.getId() << " " << admin.getName() << " " << admin.getPassword() << " " << admin.getSalary() << endl;
        Adminfile.close();
        cout << "Admin added successfully." << endl;
    }

    void getAllAdmins() override
    {
        ifstream Adminfile("admin.txt");
        if (!Adminfile)
        {
            cout << "Unable to open file " << endl;
        }
        string line;
        while (getline(Adminfile, line))
        {
            cout << line << endl;
        }
        Adminfile.close();
    }

    void removeAllAdmins() override
    {
        ofstream Adminfile("admin.txt", ios::trunc);
        Adminfile.close();
        cout << "All admins have been removed successfully." << endl;
    }
};
#endif // FILEMANAGER_H_INCLUDED
