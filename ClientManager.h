#include <iostream>
#include <vector>

#include "Client.h"
#include "FileManager.h"
#include "FilesHelper.h"
#include "Validation.h"
using namespace std;

class ClientManager{
public:
    static Client login(int id , string password){
        FileManager fileManager;
        vector <Client> clients ;
        fileManager.getAllClients();
        for(Client& client : clients){
            if(client.getId() == id && client.getPassword() == password){
                cout << "Login successful" << client.getName() << endl;
                return client;
            }
        }
        cout << "Invalid ID or Password" << endl;
        return Client();
    }
    static void updatePassword(Client& client){
        string newPassword = Validation::enterPassword();
        client.setPassword(newPassword);
        cout << "Password updated successfully" << endl;
    }
    static void printClientMenu(Client& client){
        FileManager fileManager;
        int choice;
        do{
            cout << "Client Menu" << endl;
            cout << "1. View your account balance" << endl;
            cout << "2. Add money to your account" << endl;
            cout << "3. Withdraw Money" << endl;
            cout << "4. Update password" << endl;
            cout << "5. Transfer Money" << endl;
            cout << "6. logout" << endl;
            cout << "Enter your choice: " << endl;
            cin >> choice;

            switch(choice){
                case 1:
                    client.checkBalance();
                    break;
                case 2:
                    double depositAmount;
                    cout <<"Enter deposit amount: ";
                    cin >> depositAmount;
                    client.setDeposit(depositAmount);
                    break;
                case 3:
                     double WithdrawAmount;
                    cout <<"Enter withdraw amount: ";
                    cin >> WithdrawAmount;
                    client.setWithdraw(WithdrawAmount);
                    break;
                case 4:
                    updatePassword(client);
                    break;
             case 5:
                    int recipientId;
                    double transferAmount;
                    cout << "Enter recipient ID: " << endl;
                    cin >> recipientId;
                    cout << "Enter transfer amount: " << endl;
                    cin >> transferAmount;
                    vector <Client> clients;
                    FileManager fileManager;
                    fileManager.getAllClients();
                    bool found = false;
                     for(Client& recipient : clients){
                         if(recipient.getId() == recipientId){
                            client.setTransferTo(transferAmount,recipient);
                            cout << "Transfer successful" << endl;
                            found = true;
                            break;
                         }
                     }
                     if(!found){
                        cout << "Recipient ID not found" << endl;
                     }
                     break;
                case 6:
                    cout << "Logging out" << endl;
                    break;
                default:
                    cout << "Invalid choice, please try again" << endl;
            }
        }
        while(choice != 6);
    }
};
#endif // CLIENTMANAGER_H_INCLUDED


