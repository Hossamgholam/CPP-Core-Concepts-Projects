#pragma once
#include"iomanip"
#include"clsUtil.h"
#include"0_clsScreen.h"
#include"clsBankClient.h"
class clsTotalBalancesScreen:protected clsScreen
{
private:
    static void _printClientRecordBalanceLine(clsBankClient& refClient) {
        cout <<

            "|" << setw(15) << refClient.accountNumber <<
            "|" << setw(25) << refClient.fullName() <<
            "|" << setw(15) << refClient.accountBalance
            << endl;
    }
public:
    static void showTotalBalanceScreen() {
        _drawScreenHeader("total Balances  screen");
        vector<clsBankClient>vClient = clsBankClient::getClientsList();

        cout << "                               client list (" << vClient.size() << ") client(s)." << endl;
        cout << "_________________________________________________________________________________________________________________________________\n";
        cout << "|" << setw(15) << "accout number" << "|" << setw(25) << "client name" << "|" << setw(15) << "account balance" << "|" << endl;
        cout << "__________________________________________________________________________________________________________________________________\n";

        if (vClient.empty()) {
            cout << "\t\t no client available in the system!";
        }
        else {
            for (clsBankClient& i : vClient) {
                _printClientRecordBalanceLine(i);

            }
        }
        cout << "__________________________________________________________________________________________________________________________________\n";
        double totalBalnce = clsBankClient::getTotalBalnce();

        cout << "the totalbalnce is:" << totalBalnce << endl;
        cout << clsUtil::NumberToText(totalBalnce);
    }
};

