#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <iostream>
#include <fstream>

#include "FilesHelper.h"
#include "Interface.h"
#include "Admin.h"

using namespace std;

class FileManager : public DataSourceInterface
{
public:
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