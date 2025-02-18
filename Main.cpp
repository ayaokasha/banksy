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
    Admin admin1;
    admin1.getId();
    admin1.getName();
    admin1.setName(Validation::enterName());

    admin1.getPassword();
    admin1.setPassword(Validation::enterPassword());

    admin1.getSalary();
    admin1.setSalary(Validation::enterSalary());

    Admin admin2;
    admin2.getId();

    admin2.getName();
    admin2.setName(Validation::enterName());

    admin2.getPassword();
    admin2.setPassword(Validation::enterPassword());

    admin2.getSalary();
    admin2.setSalary(Validation::enterSalary());

    FileManager fm;
    fm.addAdmin(admin1);
    fm.addAdmin(admin2);
    cout << "-------------------" << endl;

    cout << "All Admins:" << endl;
    fm.getAllAdmins();
    cout << "-------------------" << endl;

    FilesHelper::savelastAdmin("AdminLast.txt");

    int lastAdminId = FilesHelper::getlastAdmin("AdminLast.txt");
    cout << "Last Admin ID: " << lastAdminId << endl;
    cout << "-------------------" << endl;

    FilesHelper::ClearAdminFile("admin.txt", "AdminLast.txt");
    cout << "Admins file cleared and last ID reset." << endl;
    cout << "All Admins after clearing:" << endl;
    fm.getAllAdmins();
    cout << "-------------------" << endl;
}