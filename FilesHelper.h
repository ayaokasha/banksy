#ifndef FILESHELPER_H
#define FILESHELPER_H

#include <iostream>
#include <fstream>

#include "FileManager.h"
#include "Interface.h"
#include "Parser.h"
#include "Admin.h"
#include "Client.h"
#include " employee.h"///

using namespace std;

class FilesHelper
{
public:
    // clinet
    static void savelast(string filename, int id)
    {

        ofstream ClientFile(filename, ios::app);
        ClientFile << id << endl;
        ClientFile.close();
    }
    static int getlast(string filename)
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
            return;
        }

        ClientFile << c.getId() << "," << c.getName() << "," << c.getPassword() << "," << c.getBalance() << endl;
        ClientFile.close();
    }
    static void getClients()///
    {
        FileManager fm;
        fm.getAllAdmins();
    }
    // employee
    static void saveEmployee(string fileName, string lastFile, Employee e)
    {
        string file = " employee.text";
        ofstream employeeFile(file, ios::app);
        if (!employee file)
        {
            cout << " unable to open file" << endl;
        }
    }
    static void getemployee()
    {
        FileManager fm;
        fm.getAllemployee();
    }

    static void ClearFile(string filename, string lastidfile)
    {
        ofstream ClientFile(filename, ios::trunc);
        ClientFile.close();
        savelast(lastidfile, 0);
    }
    // admin
    static void savelastAdmin(string filename, int id)
    {
        ofstream Adminfile(filename);
        Adminfile << id << endl;
        Adminfile.close();
    }
    static int getlastAdmin(string filename)
    {
        ifstream Adminfile(filename);
        int id;
        Adminfile >> id;
        Adminfile.close();
        return id;
    }
    static void getAdmins()
    {
        FileManager fm;
        fm.getAllAdmins();
    }
    static void ClearFile(string filename, string lastidfile)
    {
        ofstream Adminfile(filename, ios::trunc);
        Adminfile.close();
        savelastAdmin(lastidfile, 0);
    }
};

#endif
