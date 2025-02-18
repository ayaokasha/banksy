#ifndef ADMIN_H
#define ADMIN_H

#include <iostream>
#include <string>
#include <vector>

#include "Employee.h"

using namespace std;

class Admin : public Employee
{
private:
    vector<Employee> employees;
    vector<Client> clients;

public:
    Admin(int id, const string &name, const string &password, double salary) : Employee(id, name, password, salary) {}

   void addClient(const Client &client)
    {
        clients.push_back(client);
        cout << "client added successfully"<< endl;
    }
    void addEmployee(const Employee &employee)
    {
        employees.push_back(employee);
    }
client* searchEmployee(int id)
   {
       for(auto& employee : employee){
        if(employee.getId() == id){
            return &employee;
        }
       }
      return nullptr;
   }

<<<<<<< HEAD
    // client*searchclient(int id){
    //     for(auto&client:clients){
    //         if(client.id ==id){
    //             return &client;
    //         }
    //     }
    //     return nullptr;
    // }
    // void listclients(){
    //     if( clients.empty()){
    //         cout << "No clients registered."<< endl;
    //     }
    // }
    // void editclient( int id, string name,string password ,double balance){
    //     client*client =searchclient(id);
    //     if(client){
    //         client->name = name;
    //         client->password = password;
    //         client->balance = balance;
    //         cout << " client information updated." <<endl;
    //     }
    //     else{
    //         cout << " client not found." <<endl;
    //     }
    // }
=======
 void editEmployee( int id, string name, string password, double salary){
       Employee* employee = searchemployee(id);
       if(employee != nullptr){
        employee->setName(name);
        employee->setPassword(password);
        employee->setSalary(salery);
       }
       else{
        cout <<"Employee not found" << endl;
       }
   }
void listEmployee(){
    if( employee.empty()){
        cout << "No employee registered."<< endl;
    }
}
client* searchclient(int id)
   {
       for(auto& client : clients){
        if(client.getId() == id){
            return &client;
        }
       }
      return nullptr;
   }
>>>>>>> 7c240eb14ca3be05d22bc71983b3706b14f26f8e

 void editclient( int id, string name, string password, double balance){
       Client* client = searchclient(id);
       if(client != nullptr){
        client->setName(name);
        client->setPassword(password);
        client->setBalance(balance);
       }
       else{
        cout <<"Client not found" << endl;
       }
   }
    void display() const override
    {

        Employee::display();
        cout << "Employees managed by Admin:\n";
        for (const auto &employee : employees)
        {
            employee.display();
            cout << endl;
        }
        cout << "Clients managed by Admin:\n";
        for (const auto &client : clients)
        {
            client.display();
            cout << endl;
        }
    }
};

#endif
