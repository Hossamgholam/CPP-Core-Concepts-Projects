#include<iostream>
#include<fstream>
#include<vector>
#include<string>
using namespace std;

enum enAtmMainMenueOpetion {
    eQuickWithdraw=1,eNormalWithdraw=2,
    eDeposit=3,eCheckBalance=4,elogOut=5
};

struct sClient {
    string account_number;
    string pincode;
    string name;
    string phone;
    double accountbalance;
    bool markeForDelete = false;
};

const string clientsFileName = "myfill.txt";

sClient currentClient;

void login();
void showATMMainMenueScreent();
void showQuicWithDrawScreen();
////////////////////////////////////////////////////////////////////////
void printClientCarde(sClient your_client) {
    cout << "the client is exist and information is\n";
    cout << " your account_number:" << your_client.account_number << endl;
    cout << " your pincode       :" << your_client.pincode << endl;

    cout << " your name          :" << your_client.name << endl;
    cout << " your phone         :" << your_client.phone << endl;
    cout << " accountbalance     :" << your_client.accountbalance << endl;

}

vector<string> splitstring(string your_record, string delemiter = "#//#") {
    short pos = 0;
    string worde = "";
    vector<string>storge;
    while ((pos = your_record.find(delemiter)) != std::string::npos) {
        worde = your_record.substr(0, pos);
        if (worde != "") {
            storge.push_back(worde);
        }
        your_record.erase(0, pos + delemiter.length());
    }
    if (your_record != "") {
        storge.push_back(your_record);
    }
    return storge;
}
sClient convertLineToRecord(string your_record, string delemiter = "#//#") {
    sClient my_client;
    vector<string>your_storge;
    your_storge = splitstring(your_record, delemiter);
    my_client.account_number = your_storge[0];
    my_client.pincode = your_storge[1];
    my_client.name = your_storge[2];
    my_client.phone = your_storge[3];
    my_client.accountbalance = stod(your_storge[4]);
    return my_client;
}
vector<sClient> loadClientDateFromFill(string your_fill) {
    fstream my_fill;
    vector<sClient> my_vclient;
    my_fill.open(your_fill, ios::in);
    if (my_fill.is_open()) {
        sClient my_client;
        string line = "";
        while (getline(my_fill, line)) {
            my_client = convertLineToRecord(line);
            my_vclient.push_back(my_client);
        }
        my_fill.close();
    }
    return my_vclient;
}
bool findClientByAccountNumberAndPinCode(string yourAcount, string yourpin, sClient& yourCurrentClient) {
    vector<sClient> vClient = loadClientDateFromFill(clientsFileName);
    for (sClient& u : vClient) {
        if (u.account_number == yourAcount && u.pincode == yourpin) {
            yourCurrentClient = u;
            return true;
        }
    }
    return false;
}
////////////////////////////////////////////////////////////////////////////


void goBackAtmManinNenue() {
    cout << "\n\npress any key to back to main menue.............";
    system("pause>0");
    showATMMainMenueScreent();
}


int readQuickWithDrawMenuOption() {
    int number=0;
    cout << "choose what to witdraw from 1:9?"; cin >> number;
    while (number < 1 || number > 9) {
        cout << "choose what to witdraw from 1:8?"; cin >> number;
    }
    return number;
}
short getWithdrawNumber(short yourOptioinNumber) {
    switch (yourOptioinNumber)
    {
    case 1: return 20;
    case 2: return 50;
    case 3: return 100;
    case 4: return 200;
    case 5: return 400;
    case 6: return 600;
    case 7: return 800;
    case 8: return 1000;
    case 9: return 0;

    
    }
}
string convertRecordToLine(sClient your_client, string delemiter = "#//#") {
    string line = "";
    line = line + your_client.account_number + delemiter;
    line = line + your_client.pincode + delemiter;
    line = line + your_client.name + delemiter;
    line = line + your_client.phone + delemiter;
    line = line + to_string(your_client.accountbalance);
    return line;
}
void saveClientDateToFile(vector<sClient> your_vclient, string your_fill) {
    fstream fill;
    string line = "";
    fill.open(your_fill, ios::out);
    if (fill.is_open()) {
        for (sClient i : your_vclient) {
            if (i.markeForDelete == false) {
                line = convertRecordToLine(i);
                fill << line << endl;
            }
        }
        fill.close();
    }

}
bool depositBalanceToClientByAccountNumber(int amount, sClient clienttt, vector<sClient>& vClient) {
    char answer = 'y';
    cout << "are you sure you what to deposit:"; cin >> answer;
    if (toupper(answer) == 'Y') {
        for (sClient& i : vClient) {
            if (i.account_number == clienttt.account_number) {
                i.accountbalance += amount;
                saveClientDateToFile(vClient, clientsFileName);
                cout << "\ndone successfully .new balance is :" << i.accountbalance;
                return true;
            }
        }
        return false;
    }


}
void performQuickWithDrawScreen(short optionNumber) {
    if (optionNumber == 9) {
        return;
    }
    cout << "the current balance is:"<< currentClient.accountbalance << endl;
  
    short withdrawNumber = getWithdrawNumber(optionNumber);

    if (currentClient.accountbalance < withdrawNumber) {
        cout << "the amount exceeds your balance make another choice :\n";
        cout << "press ankey to continue.....";
        system("pause>0");
        showQuicWithDrawScreen();
    }
    vector<sClient>vCleint = loadClientDateFromFill(clientsFileName);
    depositBalanceToClientByAccountNumber(withdrawNumber*-1, currentClient, vCleint);
    /*
    * this bacuse we oridy load client info and to see new balnce we need
    * to rerun program 
    */

    currentClient.accountbalance -= withdrawNumber;
}
void showQuicWithDrawScreen() {
    cout << "___________________________________________\n";
    cout << "           quick withdraw menue screen           \n";
    cout << "___________________________________________\n";
    cout << "withdraw 20   [1]      withdraw 50   [2]\n";
    cout << "withdraw 100  [3]      withdraw 200  [4]\n";
    cout << "withdraw 400  [5]      withdraw 600  [6]\n";
    cout << "withdraw 800  [7]      withdraw 1000 [8]\n";
    cout << "exit          [9]\n";
    cout << "___________________________________________\n";
    performQuickWithDrawScreen(readQuickWithDrawMenuOption());
}

//2-those function for normal withdraw option
int readNormalWithDraw() {
    int number ;
    cout << "enter an amount multiple of 5 :"; cin >> number;
    while (number % 5 != 0) {
        
        cout << "enter an amount multiple of 5 :"; cin >> number;
    }
    return number;

}
void perfromNormalWithDrawScrren() {
    cout << "the current balance is:" << currentClient.accountbalance << endl;
    int withdrawNumber = readNormalWithDraw();

    if (currentClient.accountbalance < withdrawNumber) {
        cout << "the amount exceeds your balance make another choice :\n";
        cout << "press ankey to continue.....";
        system("pause>0");
        showQuicWithDrawScreen();
    }
    vector<sClient>vCleint = loadClientDateFromFill(clientsFileName);
    depositBalanceToClientByAccountNumber(withdrawNumber * -1, currentClient, vCleint);
    /*
    * this bacuse we oridy load client info and to see new balnce we need
    * to rerun program
    */

    currentClient.accountbalance -= withdrawNumber;


}
void showNormalWithDrawScreen() {
    system("cls");
    cout << "___________________________________________\n";
    cout << "           normal withdraw menue screen           \n";
    cout << "___________________________________________\n";
     perfromNormalWithDrawScrren();
}


//3-those function for deposit option
int readDeposit() {
    int number = 0;
    while (number < 50) {
        cout << "pleas inter number to depost in account:"; cin >> number;
    }
    return number;
}
void performDepostitOption() {
    cout << "the current balance is:" << currentClient.accountbalance << endl;
    int depositNumber = readDeposit();


    vector<sClient>vCleint = loadClientDateFromFill(clientsFileName);
    depositBalanceToClientByAccountNumber(depositNumber, currentClient, vCleint);
    /*
    * this bacuse we oridy load client info and to see new balnce we need
    * to rerun program
    */

    currentClient.accountbalance += depositNumber;
}
void  showDepositScreen() {
    system("cls");
    cout << "___________________________________________\n";
    cout << "           normal withdraw menue screen           \n";
    cout << "___________________________________________\n";
    performDepostitOption();
    

}


//4-those function for check balance option
void showCheckBalanceScreen() {
    system("cls");
    cout << "===========================================\n";
    cout << "\t\tCheck Balance Screen\n"; 
    cout << "===========================================\n"; 
    cout << "Your Balance is " << currentClient.accountbalance << "\n";
    
}


//5-those function for log out option
void goBacklogin() {
    cout << "___________________________________________\n";
    cout << "             logout                 \n";
    cout << "____________________________________________\n";
    login();
}


short readAtmMainMenueOpetioin() {
    short number;
    cout << "choose what do you want to do?[1 to 6]:";
    cin >> number;
    return number;
}
void performATMMainMenueOpetion(enAtmMainMenueOpetion TransactionMenueOpetion) {
    switch (TransactionMenueOpetion) {
    case enAtmMainMenueOpetion::eQuickWithdraw:
        system("cls");
        showQuicWithDrawScreen();
        goBackAtmManinNenue();
        break;
    case enAtmMainMenueOpetion::eNormalWithdraw:
        system("cls");
        showNormalWithDrawScreen();
        goBackAtmManinNenue();
        break;
    case enAtmMainMenueOpetion::eDeposit:
        system("cls");
        showDepositScreen();
        goBackAtmManinNenue();
        break;
    case enAtmMainMenueOpetion::eCheckBalance:
        system("cls");
        showCheckBalanceScreen();
        goBackAtmManinNenue();
        break;
    case enAtmMainMenueOpetion::elogOut:
        system("cls");
        goBacklogin();
        break;

    }
}
void showATMMainMenueScreent() {
   
    system("cls");
    
    cout << "___________________________________________\n";
    cout << "              ATM main menue screen              \n";
    cout << "____________________________________________\n";
    cout << "quick withdraw              [1]\n";
    cout << "mormal withdraw             [2]\n";
    cout << "deposit                     [3]\n";
    cout << "check balance               [4]\n";
    cout << "log out                     [5]\n";
    cout << "_______________________________________\n";

    performATMMainMenueOpetion(enAtmMainMenueOpetion(readAtmMainMenueOpetioin()));
}


void login() {

    bool loginfaild = false;
    do {
        system("cls");
        cout << "___________________________________________\n";
        cout << "___________________________________________\n";
        cout << "              log in screen            \n";
        cout << "___________________________________________\n";
        cout << "___________________________________________\n";
        if (loginfaild) {
            cout << "\ninvalid account number and pin code \n";
        }
        string accountNumber, pinCode;
        cout << "\npleas inter you accountNumber:"; getline(cin >> ws, accountNumber);
        cout << "\npleas inter your pinCode"; cin >> pinCode;
        loginfaild = !findClientByAccountNumberAndPinCode(accountNumber, pinCode, currentClient);
    } while (loginfaild);
    showATMMainMenueScreent();
}
int main() {
    login();
  
}