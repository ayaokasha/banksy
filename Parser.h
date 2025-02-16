#ifndef PARSE_H
#define PARSE_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;
class Parser
{
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
    static Client parsetToClient(string& line){
        vector<string> data = split(line, ' ');
        if(data.size() < 4){
            cout << "Invalid input format for client" << endl;
            return client();
        }
        int id = stoi(data[0]);
        string name = data[1];
        string password = data [2];
        double balance = stof(data[4]);
        return client(id , name , password , balance);
    } 


 static Employee parsetToemployee(string& line){
        vector<string> data = split(line, ' ');
        if(data.size() < 3){
            cout << "Invalid input format for employee" << endl;
            return employee();
        }
        int id = stoi(data[0]);
        string name = data[1];
        string password = data [2];
        double balance = stof(data[3]);
        return employee (id , name , password , balance);
    } 

    static Admin parserToAdmin(string line)
    {
        vector<string> data = split(line, ' ');
        Admin admin(stoi(data[0]), data[1], data[2], stof(data[3]));
        return admin;
    }
};

#endif
