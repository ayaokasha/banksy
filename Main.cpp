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
    //EMPLOYEE
    
Employee employee1( "Mahmoud",123,"password156",5000);
     Employee employee2( "Ahmed",122,"password234",6000);
     Employee employee3( "Ashraf",121,"password111",7000);
     Employee employee4( "Mohamed",120,"password362",8000);
    
    FileManager fm;
    fm.addEmployee( employee1);
    fm.addEmployee( employee2);
    fm.addEmployee( employee3);
    fm.addEmployee( employee4);

    fm.searchEmployee( employee2);
    
fm.listEmployee( employee1);
 fm.listEmployee( employee3);

fm.editEmployee( employee2);
fm.editEmployee( employee4);
     
    cout<< "--------------------------" << endl;
    cout << " All Employee" << endl;

FilesHelper::savelastEmployee("EmployeeLast.txt");

int lastEmployeeId = FilesHelper::getlastEmployee("EmployeeLast.txt");
cout << "Last Employee ID: " << lastEmployeeId << endl;
cout << "-------------------" << endl;

FilesHelper::ClearEmployeeFile("employee.txt", "EmployeeLast.txt");
cout << "Employee file cleared and last ID reset." << endl;
cout << "All Employee after clearing:" << endl;
fm.getAllEmployee();
cout << "------------------" << endl;
    
}

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
