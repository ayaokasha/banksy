#ifndef FILESHELPER_H
#define FILESHELPER_H
#include <iostream>
#include <fstream>

#include "FileManager.h"
#include "Interface.h"
#include "parser.h"
#include "Admin.h"

using namespace std;

class FilesHelper
{
public:
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
        file.close();
        savelast(lastidfile, 0);
    }
};

#endif