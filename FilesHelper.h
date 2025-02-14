#ifndef FILESHELPER_H
#define FILESHELPER_H

#include <iostream>
#include <fstream>

#include "FileManager.h"
#include "Interface.h"
#include "Parser.h"
#include "Admin.h"
#include "Client.h"

using namespace std;

class FilesHelper
{
public:
     static void savelast(string filename, int id)
    {
        
        ofstream ClientFile(filename;ios::app);
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
    static void saveClient(Client c){
        string file = "Client.txt";
        ofstream ClientFile(file,ios::app);
        if(!ClientFile){
            cout << "unable to open file" << endl;
            return;
        }
        ClientFile << c.getId() << "," << c.getName() << "," << c.getPassword() << "," << c.getBalance() << endl;
        ClientFile.close();
    }
    static void getClients()
    {
        FileManager fm;
        fm.getAllAdmins();
    }
     static void ClearFile(string filename, string lastidfile)
    {
        ofstream ClientFile(filename, ios::trunc);
        file.close();
        savelast(lastidfile, 0);
    }
    static void savelast(string filename, int id)
    {
        ofstream file(filename);
        file << id << endl;
        file.close();
    }
    static int getlast(string filename)
    {
        ifstream file(filename);
        int id;
        file >> id;
        file.close();
        return id;
    }
    static void getAdmins()
    {
        FileManager fm;
        fm.getAllAdmins();
    }
    static void ClearFile(string filename, string lastidfile)
    {
        ofstream file(filename, ios::trunc);
        ClientFile.close();
        savelast(lastidfile, 0);
    }
};

#endif
