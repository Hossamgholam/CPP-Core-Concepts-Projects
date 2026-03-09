#pragma once
#include"clsBankClient.h"
#include"0_clsScreen.h"
#include<iomanip>

class clsClientListScreen:protected clsScreen
{
private:

    static void printClientRecordLine(clsBankClient& your_client) {
        cout << "|" << setw(15) << your_client.fristName <<
            "|" << setw(10) << your_client.lastName <<
            "|" << setw(40) << your_client.email <<
            "|" << setw(12) << your_client.phone <<
            "|" << setw(12) << your_client.accountNumber <<
            "|" << setw(12) << your_client.pinCode <<
            "|" << setw(12) << your_client.accountBalance
            << endl;
    }

public:
	static void showClientList() {
        if (!checkAccessRights(clsUser::enMangeuserPermission::pShowClientList)) {
            return; //this return for finshi call statck
        }

        vector<clsBankClient>vClients = clsBankClient::getClientsList();

        //new upgrade in this fuction
        string title = "client list screen";
        string subtitle = "                               client list (" + to_string(vClients.size()) + ") client(s).";
        _drawScreenHeader(title, subtitle);


        cout << "_________________________________________________________________________________________________________________________________\n";
        cout << "|" << setw(15) << "frist Name" <<
            "|" << setw(10) << "last name" <<
            "|" << setw(40) << "email " <<
            "|" << setw(12) << "phone" <<
            "|" << setw(12) << "account number" <<
            "|" << setw(12) << "pin code" <<
            "|" << setw(12) << "account balance" <<
            "|" << endl;
        cout << "__________________________________________________________________________________________________________________________________\n";

        if (vClients.empty()) {
            cout << "\t\t no client available in the system!";
        }
        else {
            for (clsBankClient& client : vClients) {
                printClientRecordLine(client);
                cout << endl;
            }
        }
        cout << "__________________________________________________________________________________________________________________________________\n";
    }
};

