#ifndef PARSE_H
#define PARSE_H

#include <iostream>
#include <string>
#include <vector>

#include "Client.h"
#include "Employee.h"
#include "Admin.h"

using namespace std;
class Parser
{
public:
    static vector<string> split(string line, char delimiter)
    {
        vector<string> result;
        string word;
        for (size_t i = 0; i < line.length(); i++)
        {
            if (line[i] == delimiter)
            {
                result.push_back(word);
                word.clear();
            }
            else
            {
                word += line[i];
            }
        }
        result.push_back(word);
        return result;
    }
    static Client parseToClient(const string &line)
    {
        vector<string> data = split(line, ' ');
        if (data.size() < 4)
        {
            cout << "Invalid input format for client" << endl;
            return Client();
        }
        Client client(stoi(data[0]), data[1], data[2], stof(data[3]));
        return client;
    }

    static Employee parseToemployee(const string &line)
    {
        vector<string> data = split(line, ' ');
        if (data.size() < 4)
        {
            cout << "Invalid input format for employee" << endl;
            return Employee();
        }
        Employee employee(stoi(data[0]), data[1], data[2], stof(data[3]));
        return employee;
    }

    static Admin parseToAdmin(const string &line)
    {
        vector<string> data = split(line, ' ');
        if (data.size() < 4)
        {
            cout << "Invalid input format for admin" << endl;
            return Admin();
        }
        Admin admin(stoi(data[0]), data[1], data[2], stof(data[3]));
        return admin;
    }
};

#endif
