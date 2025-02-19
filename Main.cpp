#include <iostream>
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
    // Client
    Client c1;
    c1.getId();
    c1.setId(4);
    c1.getName();
    c1.setName(Validation::enterName());
    c1.getPassword();
    c1.setPassword(Validation::enterPassword());
    c1.getBalance();
    c1.setBalance(Validation::enterBalance());

    Client c2;
    c2.getId();
    c2.setId(1);
    c2.getName();
    c2.setName(Validation::enterName());
    c2.getPassword();
    c2.setPassword(Validation::enterPassword());
    c2.getBalance();
    c2.setBalance(Validation::enterBalance());

    FileManager fm;
    fm.addClient(c1);
    fm.addClient(c2);

    fm.getAllClients();

    FilesHelper::savelastClient("ClientLast.txt", 4);

    FilesHelper::ClearClientFile("Client.txt", "lastIdClient.xxt");

    // EMPLOYEE

    Employee e1;
    e1.getId();
    e1.setId(2);
    e1.getName();
    e1.setName(Validation::enterName());
    e1.getPassword();
    e1.setPassword(Validation::enterPassword());
    e1.getSalary();
    e1.setSalary(Validation::enterSalary());

    Employee e2;
    e2.getId();
    e2.setId(3);
    e2.getName();
    e2.setName(Validation::enterName());
    e2.getPassword();
    e2.setPassword(Validation::enterPassword());
    e2.getSalary();
    e2.setSalary(Validation::enterSalary());

    Employee e3;
    e3.getId();
    e3.setId(5);
    e3.getName();
    e3.setName(Validation::enterName());
    e3.getPassword();
    e3.setPassword(Validation::enterPassword());
    e3.getSalary();
    e3.setSalary(Validation::enterSalary());

    FileManager f;
    f.addEmployee(e1);
    f.addEmployee(e2);
    f.addEmployee(e3);

    cout << "All Employee:" << endl;
    f.getAllEmployees();
    cout << "-------------------" << endl;

    FilesHelper::savelastEmployee("EmployeeLast.txt" ,2);

    int lastEmployeeId = FilesHelper::getlastEmployee("EmployeeLast.txt");
    cout << "Last Employee ID: " << lastEmployeeId << endl;
    cout << "-------------------" << endl;

    FilesHelper::ClearEmployeeFile("employee.txt", "EmployeeLast.txt");
    cout << "Employee file cleared and last ID reset." << endl;
    cout << "All Employee after clearing:" << endl;
    f.getAllEmployees();
    cout << "-------------------" << endl;

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

    FileManager m;
    m.addAdmin(admin1);
    m.addAdmin(admin2);
    cout << "-------------------" << endl;

    cout << "All Admins:" << endl;
    m.getAllAdmins();
    cout << "-------------------" << endl;

    FilesHelper::savelastAdmin("AdminLast.txt");

    int lastAdminId = FilesHelper::getlastAdmin("AdminLast.txt");
    cout << "Last Admin ID: " << lastAdminId << endl;
    cout << "-------------------" << endl;

    FilesHelper::ClearAdminFile("admin.txt", "AdminLast.txt");
    cout << "Admins file cleared and last ID reset." << endl;
    cout << "All Admins after clearing:" << endl;
    m.getAllAdmins();
    cout << "-------------------" << endl;
}
