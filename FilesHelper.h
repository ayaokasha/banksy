#ifndef FILESHELPER_H_INCLUDED
#define FILESHELPER_H_INCLUDED
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
    static void saveClient(string fileName, string lastFile, Client client)
    {
        ofstream ClientFile(fileName,ios::app);
        if(!ClientFile){
            cout << " unable to open file" << endl;
            return; 
        }
        ClientFile << client.getId() << " " << client.getName() << " " << client.getPassword() << " " << client.getBalance() << endl;
        ClientFile.close();
    }
    static void savelastClient(string filename)
    {
        ofstream ClientFile(filename);
        if (!ClientFile)
        {
            cout << "Error: Unable to open file " << endl;
            return;
        }
        ClientFile << 1;
        ClientFile.close();
    }

    static int getlastClient(string filename)
    {
        ifstream ClientFile(filename);
        if (!ClientFile)
        {
            cout << "Error: Unable to open file " << endl;
            return -1;
        }
        int id;
        ClientFile >> id;
        ClientFile.close();
        return id;
    }
    static void getClients()
    {
        FileManager fm;
        fm.getAllClients();
    }

    static void ClearClientFile(string filename, string lastidfile)
    {
        ofstream ClientFile(filename, ios::trunc);
        if (!ClientFile)
        {
            cout << "Error: Unable to open file " << endl;
            return;
        }
        ClientFile.close();
        ofstream Id(lastidfile, ios::trunc);
        Id << 0;
        Id.close();
    }
    // employee
    static void saveEmployee(string fileName, string lastFile)
    {
        string file = "employee.txt";
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

    static int getlastEmployee(string filename)
    {
        ifstream EmployeeFile(filename);
        int id;
        EmployeeFile >> id;
        EmployeeFile.close();
        return id;
    }

    static void savelastEmployee(string filename)
    {
        ofstream Employeefile(filename);
        if (!Employeefile)
        {
            cout << "Error: Unable to open file " << endl;
        }
        Employeefile << 1 << endl;
        Employeefile.close();
    }

    static void ClearEmployeeFile(string filename, string lastidfile)
    {
        ofstream Employeefile(filename, ios::trunc);
        if (!Employeefile)
        {
            cout << "Error: Unable to open file " << endl;
        }
        savelastEmployee(lastidfile);
        Employeefile.close();
        ofstream lId(lastidfile, ios::trunc);
        lId << 0;
        lId.close();
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
#endif // FILESHELPER_H_INCLUDED
