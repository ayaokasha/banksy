#ifndef SCREEN_H
#define SCREEN_H

#include <iostream>
#include <string>

class Screens
{
public:
    static void bankName()
    {
        std::cout << " BANK SYSTEM" << std::endl;
    }

    static void welcome()
    {
        std::cout << "    Welcome to the Bank management system   " << std::endl;
    }

    static void loginOptions()
    {
        std::cout << "1. Login as Client" << std::endl;
        std::cout << "2. Login as Employee" << std::endl;
        std::cout << "3. Login as Admin" << std::endl;
        std::cout << "4. Log out" << std::endl;
    }

    static int loginAs()
    {
        int choice;
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        return choice;
    }

    static void invalid(int c)
    {
        std::cout << "Invalid option: " << c << std::endl;
    }

    static void logout()
    {
        std::cout << "You have successfully logged out" << std::endl;
    }

    static void loginScreen(int c)
    {
        std::cout << "Login screen for ";
        switch (c)
        {
        case 1:
            std::cout << "client" << std::endl;
            break;
        case 2:
            std::cout << "employee" << std::endl;
            break;
        case 3:
            std::cout << "admin" << std::endl;
            break;
        default:
            std::cout << "invalid" << std::endl;
        }
    }

    static void runApp()
    {
        bankName();
        welcome();
        int choice;
        do
        {
            loginOptions();
            choice = loginAs();
            switch (choice)
            {
            case 1:
            case 2:
            case 3:
                loginScreen(choice);
                break;
            case 4:
                logout();
                break;
            default:
                invalid(choice);
            }
        } while (choice != 4);
    }
};

#endif
