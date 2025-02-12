#ifndef PERSON_H
#define PERSON_H
#include <iostream>
#include <string>

using namespace std;
class Person
{
protected:
    int id;
    string name;
    string password;

public:
    Person(int i, string n, string p)
    {
        this->id = i;
        this->name = n;
        this->password = p;
    }
    void setId(int id)
    {
        this->id = id;
    }
    void setName(string name)
    {
        this->name = name;
    }
    void setPassword(string password)
    {

        this->password = password;
    }
    int getId() { return id; }
    string getName() { return name; }
    string getPassword() { return password; }
    virtual void display() const
    {
        cout << "ID: " << id << endl;
        cout << "Name: " << name << endl;
        cout << "Password: " << password << endl;
    }
};
#endif