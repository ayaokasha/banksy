#ifndef FILESHELPER_H
#define FILESHELPER_H

#include <iostream>
#include <fstream>

#include "FileManager.h"
#include "Interface.h"
#include "Parser.h"
#include "Admin.h"
#include "Client.h"
#include "Employee.h"

using namespace std;

class FilesHelper
{
public:
    // clinet
    static void savelastClient(string filename, int id)
    {

        ofstream ClientFile(filename, ios::app);
        ClientFile << id << endl;
        ClientFile.close();
    }
    static int getlastClient(string filename)
    {
        ifstream ClientFile(filename);
        int id;
        ClientFile >> id;
        ClientFile.close();
        return id;
    }
    static void saveClient(Client c)
    {
        string file = "Client.txt";
        ofstream ClientFile(file, ios::app);
        if (!ClientFile)
        {
            cout << "unable to open file" << endl;
        }

        ClientFile << c.getId() << "," << c.getName() << "," << c.getPassword() << "," << c.getBalance() << endl;
        ClientFile.close();
    }
    static void getClients()
    {
        FileManager fm;
        fm.getAllClients();
    }

    static void ClearClientFile(string filename, string lastidfile)
    {
        ofstream ClientFile(filename, ios::trunc);
        ClientFile.close();
        savelastClient(lastidfile, 0);
    }
    // employee
    static void saveEmployee(string fileName, string lastFile, Employee e)
    {
        string file = " employee.text";
        ofstream employeeFile(file, ios::app);
        if (!employeeFile)
        {
            cout << " unable to open file" << endl;
        }
    }
    static void getemployee()
    {
        FileManager fm;
        fm.getAllEmployees();
    }

    static void savelastEmployee(string filename, int id)
    {
        ofstream Employeefile(filename);
        if (!Employeefile)
        {
            cout << "Error: Unable to open file " << endl;
        }
        Employeefile << id << endl;
        Employeefile.close();
    }

    static void ClearEmployeeFile(string filename, string lastidfile)
    {
        ofstream Employeefile(filename, ios::trunc);
        Employeefile.close();
        savelastEmployee(lastidfile, 0);
    }
    // admin
    static void savelastAdmin(string filename)
    {
        ofstream Adminfile(filename);
        if (!Adminfile)
        {
            cout << "Error: Unable to open file " << endl;
        }
        Adminfile << 1;
        Adminfile.close();
    }
    static int getlastAdmin(string filename)
    {
        ifstream Adminfile(filename);
        if (!Adminfile)
        {
            cout << "Error: Unable to open file " << endl;
        }
        int lastId;
        Adminfile >> lastId;
        Adminfile.close();
        return lastId;
    }
    static void getAdmins()
    {
        FileManager fm;
        fm.getAllAdmins();
    }
    static void ClearAdminFile(string filename, string lastidfile)
    {
        ofstream Adminfile(filename, ios::trunc);
        if (!Adminfile)
        {
            cout << "Error: Unable to open file " << endl;
        }
        Adminfile.close();
        ofstream lastId(lastidfile, ios::trunc);
        lastId << 0;
        lastId.close();
    }
};

#endif
