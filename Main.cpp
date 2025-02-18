#include <iostream>

#include "Validation.h"
#include "Person.h"
#include "Client.h"
#include "Employee.h"
#include "Admin.h"
#include "Parser.h"
#include "Interface.h"
#include "FilesHelper.h"
#include "FileManager.h"

#include <vector>
#include <string>
#include <fstream>

using namespace std;

int main()
{

    // Admin
    Admin admin1(1, "Admin User one", "adminPass", 100);
    Admin admin2(2, "Admin User two", "adminPass", 10000);
    Admin admin3(3, "Admin User three", "adminPass", 10000);
    Admin admin4(4, "Admin User four", "adminPass", 10000);

    FileManager fm;
    fm.addAdmin(admin1);
    fm.addAdmin(admin2);
    fm.addAdmin(admin3);
    fm.addAdmin(admin4);
    cout << "-------------------" << endl;

    cout << "All Admins:" << endl;
    fm.getAllAdmins();
    cout << "-------------------" << endl;

    FilesHelper::savelastAdmin("AdminLast.txt", 1);

    int lastAdminId = FilesHelper::getlastAdmin("AdminLast.txt");
    cout << "Last Admin ID: " << lastAdminId << endl;
    cout << "-------------------" << endl;

    FilesHelper::ClearFile("admin.txt", "AdminLast.txt");
    cout << "Admins file cleared and last ID reset." << endl;
    cout << "All Admins after clearing:" << endl;
    fm.getAllAdmins();
    cout << "-------------------" << endl;
}