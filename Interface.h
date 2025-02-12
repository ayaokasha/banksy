#ifndef INTERFACE_H
#define INTERFACE_H

#include <iostream>

#include "Client.h"
#include "Employee.h"
#include "Admin.h"

#include <string>

using namespace std;

class DataSourceInterface
{
public:
    void addClient(Client);
    void addEmployee(Employee);
    void addAdmin(Admin);

    void getAllClients();
    void getAllEmployees();
    void getAllAdmins();

    void removeAllClients();
    void removeAllEmployees();
    void removeAllAdmins();
};
#endif