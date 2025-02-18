#ifndef VALIDATION_H
#define VALIDATION_H

#include <iostream>
#include <string>

using namespace std;

class Validation
{
private:
    static bool validName(string name)
    {
        if (name.length() < 5 || name.length() > 20)
            return false;
        for (int i = 0; i < name.length(); i++)
        {
            if (!isalpha(name[i]))
                return false;
        }
        return true;
    }

    static bool validPassword(string password)
    {
        if (password.length() < 8 || password.length() > 20)
            return false;
        return true;
    }

public:
    static string enterName()
    {
        string name;
        system("cls");
        cout << "Enter name: ";
        cin >> name;
        while (!validName(name))
        {
            system("cls");
            cout << "Invalid name!\n";
            cout << "Name must be 5 to 20 alphabetic characters.\n"
                 << endl;
            cout << "Enter name: ";
            cin >> name;
        }
        return name;
    }

    static string enterPassword()
    {
        string password;
        system("cls");
        cout << "Enter password: ";
        cin >> password;
        while (!validPassword(password))
        {
            system("cls");
            cout << "Invalid password!\n";
            cout << "Password must be 8 to 20 characters.\n"
                 << endl;
            cout << "Enter password: ";
            cin >> password;
        }
        return password;
    }

    static double enterBalance()
    {
        double balance;
        cout << "Enter balance: ";
        cin >> balance;
        while (balance < 1500)
        {
            system("cls");
            cout << "Invalid balance!\n";
            cout << "Balance must be at least 1500.\n"
                 << endl;
            cout << "Enter balance: ";
            cin >> balance;
        }
        return balance;
    }

    static double enterSalary()
    {
        double salary;
        cout << "Enter salary: ";
        cin >> salary;
        while (salary < 5000)
        {
            system("cls");
            cout << "Invalid salary!\n";
            cout << "Salary must be at least 5000.\n"
                 << endl;
            cout << "Enter salary: ";
            cin >> salary;
        }
        return salary;
    }
};
#endif