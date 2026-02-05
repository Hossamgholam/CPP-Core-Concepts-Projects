
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iomanip>
using namespace std;

const string clientsFileName = "myfill.txt";
const string usersFileName = "user.txt";

struct client
{
    string account_number;
    string pincode;
    string name;
    string phone;
    double accountbalance;
    bool markeForDelete = false;
};
struct sUser
{
    string name;
    string password;
    int permison;
    bool markeUserForDelet = false;
};

sUser currentUser;
enum enMainMenueOpetion
{
    eShowClient = 1,
    eAddClient = 2,
    eDeleteClient = 3,
    eUpdateClient = 4,
    eFiendClient = 5,
    eTransaction = 6,
    eMangeUser = 7,
    elogin = 8
};
enum enTransactionMenueOpetion
{
    eDeposit = 1,
    eWithdraw = 2,
    eShowoTalBalance = 3,
    eShowMainMenue = 4
};
enum enMangeUserMenueOption
{
    eListUser = 1,
    eAddUser = 2,
    eDeletUser = 3,
    eUpdateUser = 4,
    eFindUser = 5,
    eMainMenue = 6
};
enum enMangeuserPermission
{
    pAll = -1,
    pShowClientList = 1,
    pAddClient = 2,
    pDeleteClient = 4,
    pUpdateClient = 8,
    pFindClient = 16,
    pTransactionMenue = 32,
    pMangeUser = 64
};

//this fuction decleration here because of the call in the code and to avoid error of undeclared function
void showMainMenue();
void showTransactionMainMenue();
void showMangeUserMenue();
void login();
bool checkAccessPermission(enMangeuserPermission permistion);
void goBackMainMenue();

void showAcessDenidPermission()
{
    cout << "\n___________________________________________\n";
    cout << "\n acess denid\n you don have permision to acess\n pleas contact you admin\n";
    cout << "\n___________________________________________\n";
}


//////////////////////////////Extention 1////////////////////////////////////////////////////
vector<string> splitstring(string your_record, string delemiter = "#//#")
{
    short pos = 0;
    string worde = "";
    vector<string> storge;
    while ((pos = your_record.find(delemiter)) != std::string::npos)
    {
        worde = your_record.substr(0, pos);
        if (worde != "")
        {
            storge.push_back(worde);
        }
        your_record.erase(0, pos + delemiter.length());
    }
    if (your_record != "")
    {
        storge.push_back(your_record);
    }
    return storge;
}
client convertLineToRecord(string your_record, string delemiter = "#//#")
{
    client my_client;
    vector<string> your_storge;
    your_storge = splitstring(your_record, delemiter);
    my_client.account_number = your_storge[0];
    my_client.pincode = your_storge[1];
    my_client.name = your_storge[2];
    my_client.phone = your_storge[3];
    my_client.accountbalance = stod(your_storge[4]);
    return my_client;
}
vector<client> loadClientDateFromFill(string your_fill)
{
    fstream my_fill;
    vector<client> my_vclient;
    my_fill.open(your_fill, ios::in);
    if (my_fill.is_open())
    {
        client my_client;
        string line = "";
        while (getline(my_fill, line))
        {
            my_client = convertLineToRecord(line);
            my_vclient.push_back(my_client);
        }
        my_fill.close();
    }
    return my_vclient;
}

void printClientRecordLine(client your_client)
{
    cout << "|" << setw(15) << your_client.account_number << "|" << setw(10) << your_client.pincode << "|" << setw(40) << your_client.name << "|" << setw(12) << your_client.phone << "|" << setw(12) << your_client.accountbalance << "|" << endl;
}

void showAllClientScreen()
{
    if (!checkAccessPermission(enMangeuserPermission::pShowClientList))
    {
        showAcessDenidPermission();
        goBackMainMenue();
        return;
    }
    cout << "___________________________________________\n";
    cout << "              show client list              \n";
    cout << "____________________________________________\n";

    vector<client> vClient = loadClientDateFromFill(clientsFileName);
    cout << "                               client list (" << vClient.size() << ") client(s)." << endl;
    cout << "_________________________________________________________________________________________________________________________________\n";
    cout << "|" << setw(15) << "accout number" << "|" << setw(10) << "pin code" << "|" << setw(40) << "client name" << "|" << setw(12) << "phone" << "|" << setw(12) << "balance" << "|" << endl;
    cout << "__________________________________________________________________________________________________________________________________\n";

    if (vClient.empty())
    {
        cout << "\t\t no client available in the system!";
    }
    else
    {
        for (const client &i : vClient)
        {
            printClientRecordLine(i);
            cout << endl;
        }
    }
    cout << "__________________________________________________________________________________________________________________________________\n";
}

bool ClientExistsByAccountNumber(string accountNumber, string fileName)
{
    vector<client> vClient;
    fstream file;
    file.open(fileName, ios::in);
    if (file.is_open())
    {
        string line = "";
        client clientt;
        while (getline(file, line))
        {
            clientt = convertLineToRecord(line);
            if (clientt.account_number == accountNumber)
            {
                file.close();
                return true;
            }
            vClient.push_back(clientt);
        }
        file.close();
    }
    return false;
}
client readNewClient()
{
    client your_client;
    cout << "please inter your account_number:";
    getline(cin >> ws, your_client.account_number);

    while (ClientExistsByAccountNumber(your_client.account_number, clientsFileName))
    {
        cout << "\nClient with [" << your_client.account_number << "] already exists, Enter another Account Number? ";
        getline(cin >> ws, your_client.account_number);
    }

    cout << "please inter your pincode:";
    getline(cin, your_client.pincode);

    cout << "please inter your name:";
    getline(cin, your_client.name);
    cout << "pleaser inter your phone:";
    getline(cin, your_client.phone);
    cout << "please inter accountbalance:";
    cin >> your_client.accountbalance;
    return your_client;
}
string convertRecordToLine(client your_client, string delemiter = "#//#")
{
    string line = "";
    line = line + your_client.account_number + delemiter;
    line = line + your_client.pincode + delemiter;
    line = line + your_client.name + delemiter;
    line = line + your_client.phone + delemiter;
    line = line + to_string(your_client.accountbalance);
    return line;
}
void addDateLineToFile(string fileName, string line)
{
    fstream myFile;
    myFile.open(fileName, ios::app);
    if (myFile.is_open())
    {
        myFile << line << endl;
        myFile.close();
    }
}
void addNewClient()
{
    client clientt = readNewClient();
    addDateLineToFile(clientsFileName, convertRecordToLine(clientt));
}

void addNewClients()
{
    char repate = 'y';
    do
    {
        cout << "add new client:\n";
        addNewClient();
        cout << "client add successfully,do you want to add more client?y/n";
        cin >> repate;
    } while (toupper(repate) == 'Y');
}

void showAddNewClientsScreen()
{
    if (!checkAccessPermission(enMangeuserPermission::pAddClient))
    {
        showAcessDenidPermission();
        goBackMainMenue();
        return;
    }
    cout << "___________________________________________\n";
    cout << "              add client list              \n";
    cout << "____________________________________________\n";
    addNewClients();
};

string readClientAccountNumber()
{
    string accountNumber = "";
    cout << "please inter account number:";
    cin >> accountNumber;
    return accountNumber;
}

bool findClientByAccountNumber(string your_account, vector<client> your_vclient, client &your_client)
{

    for (client &i : your_vclient)
    {
        if (i.account_number == your_account)
        {
            your_client = i;
            return true;
        }
    }
    return false;
}
void printClientCarde(client your_client)
{
    cout << "the client is exist and information is\n";
    cout << " your account_number:" << your_client.account_number << endl;
    cout << " your pincode       :" << your_client.pincode << endl;

    cout << " your name          :" << your_client.name << endl;
    cout << " your phone         :" << your_client.phone << endl;
    cout << " accountbalance     :" << your_client.accountbalance << endl;
}
bool markeClientforDeleteByAccountNumber(vector<client> &your_vclient, string your_account)
{
    for (client &i : your_vclient)
    {
        if (i.account_number == your_account)
        {
            i.markeForDelete = true;
            return true;
        }
    }
    return false;
}
void saveClientDateToFile(vector<client> your_vclient, string your_fill)
{
    fstream fill;
    string line = "";
    fill.open(your_fill, ios::out);
    if (fill.is_open())
    {
        for (client i : your_vclient)
        {
            if (i.markeForDelete == false)
            {
                line = convertRecordToLine(i);
                fill << line << endl;
            }
        }
        fill.close();
    }
}
bool deletClientbyAccountNumber(string accountNumber, vector<client> &vClient)
{
    client clientt;
    char answer = 'y';
    // this fuction search on vector of client by account number
    // and return true if it found and information about client
    // take clientt by refern because he back with info
    if (findClientByAccountNumber(accountNumber, vClient, clientt))
    {
        printClientCarde(clientt);

        cout << "are you sure you want to delet thei client\n";
        cin >> answer;

        if (toupper(answer) == 'Y')
        {
            // put marke on client that matche withe accountNumber
            // vClient by reference beacuse that change ecoure in fuction affect
            markeClientforDeleteByAccountNumber(vClient, accountNumber);
            // the real delet check vector and if client.marketodelet is true he don save client in file
            // vclient by reference beacuse make it faset
            saveClientDateToFile(vClient, clientsFileName);
            vClient = loadClientDateFromFill(clientsFileName);
            cout << "client delet sucessful\n";
            return true;
        }
    }
    else
    {
        cout << "\n client with account number(" << accountNumber << ")not fount";
        return false;
    }
}
void showDeleteClientScreen()
{
    if (!checkAccessPermission(enMangeuserPermission::pDeleteClient))
    {
        showAcessDenidPermission();
        goBackMainMenue();
        return;
    }
    cout << "___________________________________________\n";
    cout << "              delet client list              \n";
    cout << "____________________________________________\n";

    vector<client> vClient = loadClientDateFromFill(clientsFileName);
    string accountNumber = readClientAccountNumber();
    deletClientbyAccountNumber(accountNumber, vClient);
}

client changeClientRecord(string your_account)
{
    client my_client;
    my_client.account_number = your_account;
    cout << "please inter your pincode:";
    getline(cin >> ws, my_client.pincode);

    cout << "please inter your name:";
    getline(cin, my_client.name);
    cout << "pleaser inter your phone:";
    getline(cin, my_client.phone);
    cout << "please inter accountbalance:";
    cin >> my_client.accountbalance;
    return my_client;
}
bool updateClientbyAccountNumber(string accountNumber, vector<client> &vClient)
{
    client clientt;
    char answer = 'y';

    if (findClientByAccountNumber(accountNumber, vClient, clientt))
    {
        printClientCarde(clientt);

        cout << "are you sure you want to update thei client\n";
        cin >> answer;

        if (toupper(answer) == 'Y')
        {
            for (client &i : vClient)
            {
                if (i.account_number == accountNumber)
                {
                    i = changeClientRecord(accountNumber);
                    break;
                }
            }
            saveClientDateToFile(vClient, clientsFileName);

            cout << "client update succusfull\n";
        }
    }
    else
    {
        cout << "\n client with account number(" << accountNumber << ")not fount";
        return false;
    }
}
void showUpdateClientScreen()
{
    if (!checkAccessPermission(enMangeuserPermission::pUpdateClient))
    {
        showAcessDenidPermission();
        goBackMainMenue();
        return;
    }
    cout << "___________________________________________\n";
    cout << "              update client list              \n";
    cout << "____________________________________________\n";

    vector<client> vClient = loadClientDateFromFill(clientsFileName);
    string accountNumber = readClientAccountNumber();
    updateClientbyAccountNumber(accountNumber, vClient);
}

void findClientbyAccountNumber(string accountNumber, vector<client> vClient)
{
    client clientt;
    char answer = 'y';

    if (findClientByAccountNumber(accountNumber, vClient, clientt))
    {
        printClientCarde(clientt);
    }
    else
    {
        cout << "\n client with account number(" << accountNumber << ")not fount";
    }
}
void showFindClientScreen()
{
    if (!checkAccessPermission(enMangeuserPermission::pFindClient))
    {
        showAcessDenidPermission();
        goBackMainMenue();
        // return becuse call stack
        return;
    }
    cout << "___________________________________________\n";
    cout << "              find client list              \n";
    cout << "____________________________________________\n";

    vector<client> vClient = loadClientDateFromFill(clientsFileName);
    string accountNumber = readClientAccountNumber();
    findClientbyAccountNumber(accountNumber, vClient);
}

// void showEndScreen() {
//     cout << "___________________________________________\n";
//     cout << "             end program                  \n";
//     cout << "____________________________________________\n";
// }
void goBackMainMenue()
{
    cout << "\n\npress any key to back to main menue.............";
    system("pause>0");
    showMainMenue();
}

//////////////////////////////Extention 2///////////////////////////////////////////////////////

bool depositBalanceToClientByAccountNumber(short amount, client clienttt, vector<client> &vClient)
{
    char answer = 'y';
    cout << "are you sure you what to deposit:";
    cin >> answer;
    if (toupper(answer) == 'Y')
    {
        for (client &i : vClient)
        {
            if (i.account_number == clienttt.account_number)
            {
                i.accountbalance += amount;
                saveClientDateToFile(vClient, clientsFileName);
                cout << "\ndone successfully .new balance is :" << i.accountbalance;
                return true;
            }
        }
        return false;
    }
}
void showDepositScreen()
{
    cout << "___________________________________________\n";
    cout << "              show deposit screen              \n";
    cout << "____________________________________________\n";

    vector<client> vClient = loadClientDateFromFill(clientsFileName);
    client clientt;
    string accountNumber = readClientAccountNumber();
    while (!findClientByAccountNumber(accountNumber, vClient, clientt))
    {
        cout << "client withe account(" << accountNumber << ") not exsit:";
        cout << "please initer another account:";
        cin >> accountNumber;
    }
    printClientCarde(clientt);

    short amount = 0;
    cout << "\nplease inter deposit numbmer:";
    cin >> amount;
    depositBalanceToClientByAccountNumber(amount, clientt, vClient);
}

void showWithdrawScreen()
{
    cout << "___________________________________________\n";
    cout << "              show withdraw screen              \n";
    cout << "____________________________________________\n";

    vector<client> vClient = loadClientDateFromFill(clientsFileName);
    client clientt;
    string accountNumber = readClientAccountNumber();
    while (!findClientByAccountNumber(accountNumber, vClient, clientt))
    {
        cout << "client withe account(" << accountNumber << ") not exsit:";
        cout << "please initer another account:";
        cin >> accountNumber;
    }
    printClientCarde(clientt);

    short amount = 0;
    cout << "\nplease inter deposit numbmer:";
    cin >> amount;
    while (amount > clientt.accountbalance)
    {
        cout << "amount exceeds the balance you can withdraw up to  :" << clientt.accountbalance << endl;
        cout << "\nplease inter another deposit numbmer:";
        cin >> amount;
    }
    depositBalanceToClientByAccountNumber(-1 * amount, clientt, vClient);
}
void showTotalBalanceScreen()
{
    cout << "___________________________________________\n";
    cout << "              show total balnce list              \n";
    cout << "____________________________________________\n";

    vector<client> vClient = loadClientDateFromFill(clientsFileName);
    int totalBalnce = 0;
    cout << "                               client list (" << vClient.size() << ") client(s)." << endl;
    cout << "_________________________________________________________________________________________________________________________________\n";
    cout << "|" << setw(15) << "accout number" << "|" << setw(10) << "pin code" << "|" << setw(40) << "client name" << "|" << setw(12) << "phone" << "|" << setw(12) << "balance" << "|" << endl;
    cout << "__________________________________________________________________________________________________________________________________\n";

    if (vClient.empty())
    {
        cout << "\t\t no client available in the system!";
    }
    else
    {
        for (const client &i : vClient)
        {
            printClientRecordLine(i);
            totalBalnce += i.accountbalance;
        }
    }
    cout << "__________________________________________________________________________________________________________________________________\n";

    cout << "the totalbalnce is:" << totalBalnce;
}

void goBackTransactionMenue()
{
    cout << "\n\npress any key to back to main menue.............";
    system("pause>0");
    showTransactionMainMenue();
}

short readTransactionMenueOpetioin()
{
    short number;
    cout << "choose what do you want to do?[1 to 6]:";
    cin >> number;
    return number;
}
void performTransactionMenueOpetion(enTransactionMenueOpetion TransactionMenueOpetion)
{
    switch (TransactionMenueOpetion)
    {
    case enTransactionMenueOpetion::eDeposit:
        system("cls");
        showDepositScreen();
        goBackTransactionMenue();
        break;
    case enTransactionMenueOpetion::eWithdraw:
        system("cls");
        showWithdrawScreen();
        goBackTransactionMenue();
        break;
    case enTransactionMenueOpetion::eShowoTalBalance:
        system("cls");
        showTotalBalanceScreen();
        goBackTransactionMenue();
        break;
    default:
        system("cls");
        goBackMainMenue();
        break;
    }
}
void showTransactionMainMenue()
{
    if (!checkAccessPermission(enMangeuserPermission::pTransactionMenue))
    {
        showAcessDenidPermission();
        goBackMainMenue();
        return;
    }
    system("cls");
    cout << "___________________________________________\n";
    cout << "              transaction main menue              \n";
    cout << "____________________________________________\n";
    cout << "deposit              [1]\n";
    cout << "withdraw             [2]\n";
    cout << "total balances       [3]\n";
    cout << "main menue           [4]\n";
    cout << "_______________________________________\n";

    performTransactionMenueOpetion(enTransactionMenueOpetion(readTransactionMenueOpetioin()));
}


/////////////////////////////////extention 3////////////////////////////////////////////////////

sUser convertUserLineToRecord(string line, string delmiter = "#//#")
{
    sUser user;
    vector<string> vInfo;
    vInfo = splitstring(line, delmiter);
    user.name = vInfo[0];
    user.password = vInfo[1];
    user.permison = stoi(vInfo[2]);
    return user;
}
vector<sUser> loadUserDateFromFill(string usersFile)
{
    vector<sUser> vUser;
    fstream ptFile;
    ptFile.open(usersFile, ios::in);
    if (ptFile.is_open())
    {
        string line = "";
        sUser user;
        while (getline(ptFile, line))
        {
            user = convertUserLineToRecord(line);
            vUser.push_back(user);
        }
        ptFile.close();
    }
    return vUser;
}

void printUserRecordLine(sUser user)
{
    cout << "|" << setw(15) << user.name << "|" << setw(10) << user.password << "|" << setw(10) << user.permison << endl;
}
void showlistUserScreen()
{
    cout << "                 ___________________________________________\n";
    cout << "                                               show user list              \n";
    cout << "                 ____________________________________________\n";

    vector<sUser> vUsers = loadUserDateFromFill(usersFileName);
    cout << "                               user list (" << vUsers.size() << ") user(s)." << endl;
    cout << "_________________________________________________________________________________________________________________________________\n";
    cout << "|" << setw(15) << "name" << "|" << setw(10) << "password" << "|" << setw(10) << "permsion" << endl;
    cout << "__________________________________________________________________________________________________________________________________\n";

    if (vUsers.empty())
    {
        cout << "\t\t no user available in the system!";
    }
    else
    {
        for (const sUser &i : vUsers)
        {
            printUserRecordLine(i);
            cout << endl;
        }
    }
    cout << "__________________________________________________________________________________________________________________________________\n";
}


//thos fuction for add new user to system
bool userExistsByName(string name, string fileName)
{
    vector<sUser> vUsers;
    fstream file;
    file.open(fileName, ios::in);
    if (file.is_open())
    {
        string line = "";
        sUser user;
        while (getline(file, line))
        {
            user = convertUserLineToRecord(line);
            if (user.name == name)
            {
                file.close();
                return true;
            }
            vUsers.push_back(user);
        }
        file.close();
    }
    return false;
}
int readPermissionToSet()
{
    int permission = 0;
    char answer = 'Y';
    cout << "do you want to give full accss:";
    cin >> answer;
    if (toupper(answer) == 'Y')
    {
        permission = -1;
        return permission;
    }
    cout << "\ndo you wan to give access to:\n ";

    cout << "show client screen:";
    cin >> answer;
    if (toupper(answer) == 'Y')
    {
        permission = permission + enMangeuserPermission::pShowClientList;
    }

    cout << "add client screen:";
    cin >> answer;
    if (toupper(answer) == 'Y')
    {
        permission = permission + enMangeuserPermission::pAddClient;
    }

    cout << "delete client screen:";
    cin >> answer;
    if (toupper(answer) == 'Y')
    {
        permission = permission + enMangeuserPermission::pDeleteClient;
    }

    cout << "update client screen:";
    cin >> answer;
    if (toupper(answer) == 'Y')
    {
        permission = permission + enMangeuserPermission::pUpdateClient;
    }
    cout << "find client screen:";
    cin >> answer;
    if (toupper(answer) == 'Y')
    {
        permission = permission + enMangeuserPermission::pFindClient;
    }
    cout << "transaction client screen:";
    cin >> answer;
    if (toupper(answer) == 'Y')
    {
        permission = permission + enMangeuserPermission::pTransactionMenue;
    }
    cout << "mange user screen:";
    cin >> answer;
    if (toupper(answer) == 'Y')
    {
        permission = permission + enMangeuserPermission::pMangeUser;
    }
    return permission;
}
bool checkAccessPermission(enMangeuserPermission permistion)
{
    if (currentUser.permison == -1)
    {
        return true;
    }
    
    if ((currentUser.permison & permistion) == permistion)
    {
        return true;
    }
    else
    {
        return false;
    }
}
sUser readNewUser()
{
    sUser user;
    cout << "please inter your name:";
    getline(cin >> ws, user.name);

    while (userExistsByName(user.name, usersFileName))
    {
        cout << "\nClient with [" << user.name << "] already exists, Enter another Account Number? ";
        getline(cin >> ws, user.name);
    }

    cout << "please inter your password:";
    getline(cin, user.password);

    user.permison = readPermissionToSet();

    return user;
}

string convertUserRecordToLine(sUser user, string delemiter = "#//#")
{
    string line = "";
    line = line + user.name + delemiter;
    line = line + user.password + delemiter;

    line = line + to_string(user.permison);
    return line;
}

void addUserDateLineToFile(string fileName, string line)
{
    fstream myFile;
    myFile.open(fileName, ios::app);
    if (myFile.is_open())
    {
        myFile << line << endl;
        myFile.close();
    }
}

void addNewUser()
{
    sUser User = readNewUser();
    addUserDateLineToFile(usersFileName, convertUserRecordToLine(User));
}
void addNewUsers()
{
    char repate = 'y';
    do
    {
        cout << "add new users:\n";
        addNewUser();
        cout << "user add successfully,do you want to add more user?y/n:";
        cin >> repate;
    } while (toupper(repate) == 'Y');
}
void showAddNewUsersScreen()
{
    cout << "___________________________________________\n";
    cout << "              add user list              \n";
    cout << "____________________________________________\n";
    addNewUsers();
};

string readUserName()
{
    string userName = "";
    cout << "please inter user Name:";
    cin >> userName;
    return userName;
}

//thos fuction for delet user from system
bool findUserByName(string userName, vector<sUser> vUser, sUser &user)
{

    for (sUser &i : vUser)
    {
        if (i.name == userName)
        {
            user = i;
            return true;
        }
    }
    return false;
}
void printUserCarde(sUser user)
{
    cout << "\n\n_______________________________________________\n";
    cout << "the user is exist and information is\n";
    cout << " his name is:" << user.name << endl;
    cout << "password      :" << user.password << endl;
    cout << "his permistion in system is:" << user.permison << endl;

    cout << "_______________________________________________\n";
}
bool markeUserforDeleteByName(vector<sUser> &vUser, string userName)
{
    for (sUser &i : vUser)
    {
        if (i.name == userName)
        {
            i.markeUserForDelet = true;
            return true;
        }
    }
    return false;
}
void saveUserDateToFile(vector<sUser> your_vUser, string your_fill)
{
    fstream fill;
    string line = "";
    fill.open(your_fill, ios::out);
    if (fill.is_open())
    {
        for (sUser i : your_vUser)
        {
            if (i.markeUserForDelet == false)
            {
                line = convertUserRecordToLine(i);
                fill << line << endl;
            }
        }
        fill.close();
    }
}
bool deletUserByName(string userName, vector<sUser> &vUser)
{
    sUser user;
    char answer = 'y';
    // this fuction search on vector of client by account number
    // and return true if it found and information about client
    // take clientt by refern because he back with info
    if (findUserByName(userName, vUser, user))
    {
        printUserCarde(user);

        cout << "are you sure you want to delet thei user\n";
        cin >> answer;

        if (toupper(answer) == 'Y')
        {
            // put marke on client that matche withe accountNumber
            // vClient by reference beacuse that change ecoure in fuction affect
            markeUserforDeleteByName(vUser, userName);
            // the real delet check vector and if client.marketodelet is true he don save client in file
            // vclient by reference beacuse make it faset
            saveUserDateToFile(vUser, usersFileName);
            vUser = loadUserDateFromFill(usersFileName);
            cout << "user delet sucessful\n";
            return true;
        }
    }
    else
    {
        cout << "\n user with name(" << userName << ")not fount";
        return false;
    }
}
void showDeletUserScreen()
{

    cout << "___________________________________________\n";
    cout << "              delet user              \n";
    cout << "____________________________________________\n";

    vector<sUser> vUser = loadUserDateFromFill(usersFileName);
    string userName = readUserName();
    deletUserByName(userName, vUser);
}


// thos fuction for update user information in system
sUser changeUserRecord(string yourUserName)
{
    sUser myUser;
    myUser.name = yourUserName;
    cout << "please inter your passwor:";
    getline(cin >> ws, myUser.password);
    myUser.permison = readPermissionToSet();

    return myUser;
}
bool updateUserbyName(string YourUserName, vector<sUser> &YourvUser)
{
    sUser user;
    char answer = 'y';

    if (findUserByName(YourUserName, YourvUser, user))
    {
        printUserCarde(user);

        cout << "are you sure you want to update this User[Y/N]?\n";
        cin >> answer;

        if (toupper(answer) == 'Y')
        {
            for (sUser &i : YourvUser)
            {
                if (i.name == YourUserName)
                {
                    i = changeUserRecord(YourUserName);
                    break;
                }
            }
            saveUserDateToFile(YourvUser, usersFileName);

            cout << "client update succusfull\n";
        }
    }
    else
    {
        cout << "\n client with account number(" << YourUserName << ")not fount";
        return false;
    }
}
void showUpdateUserScreen()
{

    cout << "___________________________________________\n";
    cout << "              update User              \n";
    cout << "____________________________________________\n";

    vector<sUser> vUser = loadUserDateFromFill(usersFileName);
    string userName = readUserName();
    updateUserbyName(userName, vUser);
}


//thos fuction for find user in system and show his information
void findUserByName(string yourUserNmae, vector<sUser> yourVUser)
{
    sUser user;
    char answer = 'y';

    if (findUserByName(yourUserNmae, yourVUser, user))
    {
        printUserCarde(user);
    }
    else
    {
        cout << "\n client with name(" << yourUserNmae << ")not fount";
    }
}
void showFindUserScreen()
{

    cout << "___________________________________________\n";
    cout << "              find user              \n";
    cout << "____________________________________________\n";

    vector<sUser> vUser = loadUserDateFromFill(usersFileName);
    string userName = readUserName();
    findUserByName(userName, vUser);
}

//this fuction for back to mange user menue after perform any operation in mange user menue
void goBackMangeUserMenue()
{
    cout << "\n\npress any key to back to main menue.............";
    system("pause>0");
    showMangeUserMenue();
}

//mange user menue
short readMangeUserMenueOption()
{
    short number;
    cout << "choose what do you want to do?[1 to 6]:";
    cin >> number;
    return number;
}
void performMangeUserMenueOPtion(enMangeUserMenueOption MangeUserMenueOption)
{
    switch (MangeUserMenueOption)
    {
    case enMangeUserMenueOption::eListUser:
        system("cls");
        showlistUserScreen();
        goBackMangeUserMenue();
        break;
    case enMangeUserMenueOption::eAddUser:
        system("cls");
        showAddNewUsersScreen();
        goBackMangeUserMenue();
        break;
    case enMangeUserMenueOption::eDeletUser:
        system("cls");
        showDeletUserScreen();
        goBackMangeUserMenue();
        break;
    case enMangeUserMenueOption::eUpdateUser:
        system("cls");
        showUpdateUserScreen();
        goBackMangeUserMenue();
        break;
    case enMangeUserMenueOption::eFindUser:
        system("cls");
        showFindUserScreen();
        goBackMangeUserMenue();
        break;
    default:
        system("cls");
        goBackMainMenue();
        break;
    }
}
void showMangeUserMenue()
{
    if (!checkAccessPermission(enMangeuserPermission::pMangeUser))
    {
        showAcessDenidPermission();
        goBackMainMenue();
        return;
    }
    system("cls");
    cout << "___________________________________________\n";
    cout << "              mange user menue              \n";
    cout << "____________________________________________\n";

    cout << "list users  [1]\n";
    cout << "add user    [2]\n";
    cout << "delet user  [3]\n";
    cout << "update user [4]\n";
    cout << "find user   [5]\n";
    cout << "main menu   [6]\n";

    cout << "______________________________________\n";
    performMangeUserMenueOPtion(enMangeUserMenueOption(readMangeUserMenueOption()));
}

//if user want to log out from system he go back to login screen it option in main menue
void goBackLogin()
{
    cout << "___________________________________________\n";
    cout << "             logout                 \n";
    cout << "____________________________________________\n";
    login();
}
////////////////////////////////////////////////////////////////////////////////


short readMainMenueOpetioin()
{
    short number;
    cout << "choose what do you want to do?[1 to 6]:";
    cin >> number;
    return number;
}
void performMainMenueOption(enMainMenueOpetion MainMenueOption)
{
    switch (MainMenueOption)
    {
    case enMainMenueOpetion::eShowClient:
        system("cls");
        showAllClientScreen();
        goBackMainMenue();
        break;
    case enMainMenueOpetion::eAddClient:
        system("cls");
        showAddNewClientsScreen();
        goBackMainMenue();
        break;
    case enMainMenueOpetion::eDeleteClient:
        system("cls");
        showDeleteClientScreen();
        goBackMainMenue();
        break;
    case enMainMenueOpetion::eUpdateClient:
        system("cls");
        showUpdateClientScreen();
        goBackMainMenue();
        break;
    case enMainMenueOpetion::eFiendClient:
        system("cls");
        showFindClientScreen();
        goBackMainMenue();
        break;
    case enMainMenueOpetion::eTransaction:
        system("cls");
        showTransactionMainMenue();
        break;
    case enMainMenueOpetion::eMangeUser:
        system("cls");
        showMangeUserMenue();
        break;
    default:
        system("cls");
        goBackLogin();
        break;
    }
}
void showMainMenue()
{
    system("cls");
    cout << "___________________________________________\n";
    cout << "___________________________________________\n";
    cout << "              main menue screen            \n";
    cout << "___________________________________________\n";
    cout << "___________________________________________\n";
    cout << "show client  [1]\n";
    cout << "add client   [2]\n";
    cout << "delet client [3]\n";
    cout << "update client[4]\n";
    cout << "find client  [5]\n";
    cout << "transaction  [6]\n";
    cout << "mange user   [7]\n";
    cout << "log out      [8]\n";
    cout << "__________________________________________\n";
    cout << "___________________________________________\n";
    performMainMenueOption(enMainMenueOpetion(readMainMenueOpetioin()));
} /*3*/

bool findUserByUserNameAndPssword(string name, string pass, sUser &user)
{
    vector<sUser> vUser = loadUserDateFromFill(usersFileName);
    for (sUser &u : vUser)
    {
        if (u.name == name && u.password == pass)
        {
            // set current user
            user = u;
            return true;
        }
    }
    return false;
}
void login()
{

    bool loginfaild = false;
    do
    {
        system("cls");
        cout << "___________________________________________\n";
        cout << "___________________________________________\n";
        cout << "              log in screen            \n";
        cout << "___________________________________________\n";
        cout << "___________________________________________\n";
        if (loginfaild)
        {
            cout << "\ninvalid user name and password\n";
        }
        string name, password;
        cout << "\npleas inter you name:";
        getline(cin >> ws, name);
        cout << "\npleas inter your passord";
        cin >> password;
        loginfaild = !findUserByUserNameAndPssword(name, password, currentUser);
    } while (loginfaild);
    showMainMenue();
}

int main()
{

    login();
}
