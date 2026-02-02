 #include <iostream>
#include<fstream>
#include<vector>
#include<string>
#include<iomanip>
using namespace std;



const string client_fill = "myfill.txt";

struct client {
    string account_number;
    string pincode;
    string name;
    string phone;
    float accountbalance;
    bool check_delet = false;
};

enum enop_transaction{deposit=1,withdraw=2,totalbalances=3,mainmenue=4};
enum en_operation { main_menue = 0, show = 1, add = 2, delet = 3, update = 4, find = 5, transaction = 6,exsit=7 };



void print_hader_screen(en_operation operation) {

    switch (operation) {
    case en_operation::main_menue:
        cout << "___________________________________________\n";
        cout << "___________________________________________\n";
        cout << "              main menue screen            \n";
        cout << "___________________________________________\n";
        cout << "___________________________________________\n";
        break;
    case en_operation::show:
        cout << "___________________________________________\n";
        cout << "              show client list              \n";
        cout << "____________________________________________\n";
        break;
    case en_operation::add:
        cout << "___________________________________________\n";
        cout << "              add client list              \n";
        cout << "____________________________________________\n";
        break;
    case en_operation::delet:
        cout << "___________________________________________\n";
        cout << "              delet client list              \n";
        cout << "____________________________________________\n";
        break;
    case en_operation::update:
        cout << "___________________________________________\n";
        cout << "             update client list              \n";
        cout << "____________________________________________\n";
        break;
    case en_operation::find:
        cout << "___________________________________________\n";
        cout << "              find client list              \n";
        cout << "____________________________________________\n";
        break;
    case en_operation::transaction:
        cout << "___________________________________________\n";
        cout << "              transaction main menue              \n";
        cout << "____________________________________________\n";
        break;
    default:
        cout << "___________________________________________\n";
        cout << "              exist client list              \n";
        cout << "____________________________________________\n";
        break;

    }


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
client convert_line_recorde(string your_record, string delemiter = "#//#") {
    client my_client;
    vector<string>your_storge;
    your_storge = splitstring(your_record, delemiter);
    my_client.account_number = your_storge[0];
    my_client.pincode = your_storge[1];
    my_client.name = your_storge[2];
    my_client.phone = your_storge[3];
    my_client.accountbalance = stod(your_storge[4]);
    return my_client;
}
vector<client> retreve_data(string your_fill) {
    string line;
    fstream my_fill;
    client my_client;
    vector<client> my_vclient;
    my_fill.open(your_fill, ios::in);
    if (my_fill.is_open()) {
        while (getline(my_fill, line)) {
            my_client = convert_line_recorde(line);
            my_vclient.push_back(my_client);
        }
        my_fill.close();
    }
    return my_vclient;
}


//1-print client data
void print_client_data(client your_client) {
    cout << "|" << setw(15) << your_client.account_number << "|" << setw(10) << your_client.pincode << "|" << setw(40) << your_client.name << "|" << setw(12) << your_client.phone << "|" << setw(12) << your_client.accountbalance << "|" << endl;
}
void print_fill_data(vector<client> your_vclient) {
    cout << "                               client list (" << your_vclient.size() << ") client(s)." << endl;
    cout << "_________________________________________________________________________________________________________________________________\n";
    cout << "|" << setw(15) << "accout number" << "|" << setw(10) << "pin code" << "|" << setw(40) << "client name" << "|" << setw(12) << "phone" << "|" << setw(12) << "balance" << "|" << endl;
    cout << "__________________________________________________________________________________________________________________________________\n";
    if (your_vclient.size() == 0) {
        cout << "no client found\n";
    }
    else {
         for (client i : your_vclient) {
            print_client_data(i);
            cout << endl;
         }
    }
}

void show_allclient(string fill) {
    vector<client> my_vclient;
    my_vclient = retreve_data(client_fill);
    print_fill_data(my_vclient);
}



//2-add client data
bool search_account(string your_account_number, vector<client>& your_vclient) {
    for (client& i : your_vclient) {
        if (i.account_number == your_account_number) {
            return true;
        }
    }
    return false;
}
string read_account(vector<client>& your_vclient) {

    string  my_account_number;
    cout << "please inter your acccount_number of client:"; cin >> my_account_number;
    while (search_account(my_account_number, your_vclient)) {
        cout << "client exsit enter another account_number:"; cin >> my_account_number;
    }
    return my_account_number;
}

client read_client_info(string your_account_number) {
    client your_client;
    your_client.account_number = your_account_number;
    cout << "please inter your pincode:"; getline(cin >> ws, your_client.pincode);

    cout << "please inter your name:"; getline(cin, your_client.name);
    cout << "pleaser inter your phone:"; getline(cin, your_client.phone);
    cout << "please inter accountbalance:"; cin >> your_client.accountbalance;
    return your_client;
}

string convertrecord_toline(client your_client_info, string delemiter = "#//#") {
    string line = "";
    line = line + your_client_info.account_number + delemiter;
    line = line + your_client_info.pincode + delemiter;
    line = line + your_client_info.name + delemiter;
    line = line + your_client_info.phone + delemiter;
    line = line + to_string(your_client_info.accountbalance);
    return line;
}

void storgeline_infill(string your_line, string fill) {
    fstream ptfill;
    ptfill.open(fill, ios::app);
    if (ptfill.is_open()) {
        ptfill << your_line << endl;
        ptfill.close();
    }
}

void add_client() {
    vector<client>my_vclient = retreve_data(client_fill);
    string account_number = "";
    client my_client_info;
    string line = "";
    char answer = 'y';
    do {
        account_number = read_account(my_vclient);
        my_client_info = read_client_info(account_number);
        line = convertrecord_toline(my_client_info);
        storgeline_infill(line, client_fill);
        cout << "client add successfull :  do you want to add mor client[y:N]"; cin >> answer;
    } while (answer == 'y' || answer == 'Y');
}



//3-delete client data
string read_account() {
    string account_number;
    cout << "please inter your account number:"; cin >> account_number;
    return account_number;
}
bool search_account(string your_account_number, vector<client>& your_vclient,client& your_client) {
    for (client& i : your_vclient) {
        if (i.account_number == your_account_number) {
            your_client = i;
            return true;
        }
    }
    return false;
}
void show_client(client your_client) {
    cout << "\n___________________________________________________________________\n";
    cout << "the client is exist and information is\n";
    cout << " your account_number:" << your_client.account_number << endl;
    cout << " your pincode       :" << your_client.pincode << endl;

    cout << " your name          :" << your_client.name << endl;
    cout << " your phone         :" << your_client.phone << endl;
    cout << " accountbalance     :" << your_client.accountbalance << endl;
    cout << "__________________________________________________________________\n";
}
bool ensur_delet(vector<client>& your_vclient, string your_account) {
    for (client& i : your_vclient) {
        if (i.account_number == your_account) {
            i.check_delet = true;
                return true;
        }
    }
    return false;
}
void loaddata_tofill(vector<client>& your_vclient, string your_fill) {
    fstream ptfill;
    string line = "";
    ptfill.open(your_fill, ios::out);
    if (ptfill.is_open()){
        for (client& i : your_vclient) {
            if (i.check_delet == false) {
                line = convertrecord_toline(i);
                ptfill << line << endl;

            }
        }
        ptfill.close();

    }
    
}
void delete_client() {
    vector<client>my_vclient; client my_client;
    string account_number="";
    char answer = 'y';


    account_number= read_account();
    my_vclient = retreve_data(client_fill);

    if (search_account(account_number, my_vclient, my_client)) {
        show_client(my_client);
        cout << "are you sure your want to delet client[y:N]:"; cin >> answer;
        if (answer == 'y' || answer == 'Y') {
            ensur_delet(my_vclient, account_number);
            loaddata_tofill(my_vclient, client_fill);

            cout << "client are delet successful\n";
            
        }

    }
    else {
        cout << "client not found:\n";
        
    }
    
}

//4-update client data
bool change_data( client your_client, vector<client>& my_vector) { 
    for (client& i : my_vector) {
        if (i.account_number == your_client.account_number) {
            i.pincode = your_client.pincode;
            i.name = your_client.name;
            i.phone = your_client.phone;
            i.accountbalance = your_client.accountbalance;
            return true;
        }

    }
    return false;
}
void update_client() {
    string account_number="";
    vector<client>my_vclient;
    client my_client;
    char answer = 'y';

    my_vclient = retreve_data(client_fill);
    account_number = read_account();

    if (search_account(account_number, my_vclient, my_client)) {
        show_client(my_client);
        cout << "are you sure your want to update client[y:N]:"; cin >> answer;
        if (answer == 'y' || answer == 'Y') {

            cout << "please inter your pincode       :"; getline(cin >> ws, my_client.pincode);
            cout << "please inter your name          :"; getline(cin, my_client.name);
            cout << "please inter your phone         :"; getline(cin, my_client.phone);
            cout << "please inter your accountbalance:"; cin >> my_client.accountbalance;

            change_data( my_client, my_vclient);
            loaddata_tofill(my_vclient, client_fill);

            cout << "client are update successful\n";
            
        }

    }
    else {
        cout << "client not found:\n";
        
    }

}


//5-find client data
void find_client() {
    string account_number = "";
    vector<client>my_vclient;
    client my_client;
    

    my_vclient = retreve_data(client_fill);
    account_number = read_account();

    if (search_account(account_number, my_vclient, my_client)) {
        show_client(my_client);
        
    }
    else {
        cout << "client not found:\n";
        
    }
}

//7-exsit client data 
void exsit_client() {
    cout << "program end";
}

//6-transaction operation
void main_manue_screen();
void gobacke_mainmenue() {
    cout << "\n\n press any key to go backt o main menue";
    system("pause>0");
    main_manue_screen();
}


string read_account2(vector<client>& your_vclient) {

    string  my_account_number;
    cout << "please inter your acccount_number of client:"; cin >> my_account_number;
    while (!search_account(my_account_number, your_vclient)) {
        cout << "client exsit enter another account_number:"; cin >> my_account_number;
    }
    return my_account_number;
}
bool add_deposit(string your_account_number, vector<client>& your_vclient, float deposit) {
    for (client& i : your_vclient) {
        if (i.account_number == your_account_number) {
            i.accountbalance += deposit;
            return true;
        }
    }
    return false;
}
void deposit_client() {
    vector<client>my_vclient = retreve_data(client_fill);
    string account_number = read_account2(my_vclient);
    client my_client;
        float deposit;
        char answer = 'y';
    if (search_account(account_number, my_vclient, my_client)) {
        show_client(my_client);
        cout << "please enter your deposit amount you want:"; cin >> deposit;
        cout << "are your sure you want that[y:n]"; cin >> answer;
        if (answer == 'y' || answer == 'Y') {
            add_deposit(account_number, my_vclient, deposit);
            loaddata_tofill(my_vclient, client_fill);
           cout << "operation success\n";
        }
        else {
            cout << "operation rollback\n";
        }

    }

    
}

bool notposibole_number(client your_client, long long your_number) {
    
        if (your_client.accountbalance < your_number) {
            return true;
        }
    
    return false;
}
long long read_withdraw(client your_client) {
    long long x;
    cout << "please inter your withdraw:"; cin >> x;
    while (notposibole_number(your_client,x)) {
        cout << "please inter your withdraw:"; cin >> x;
    }
    return x;
}
bool sub_withdraw(string your_account_number, vector<client>& your_vclient, float your_deposit) {
    for (client& i : your_vclient) {
        if (i.account_number == your_account_number) {
            i.accountbalance -= your_deposit;
            cout << "operation success ;:";
            cout << "the new ballans is " <<i.accountbalance;
            return true;
        }
    }
    return false;
}
void withdraw_client() {
    vector<client>my_vclient = retreve_data(client_fill);
    string account_number = read_account2(my_vclient);
    client my_client;
    long long deposit;
    char answer = 'y';
    if (search_account(account_number, my_vclient, my_client)) {
        show_client(my_client);
        deposit=read_withdraw(my_client);
        cout << "are your sure you want that[y:n]"; cin >> answer;
        if (answer == 'y' || answer == 'Y') {
            sub_withdraw(account_number, my_vclient, deposit);
            loaddata_tofill(my_vclient, client_fill);
            
        }
        else {
            cout << "operation rollback\n";
        }

    }
}


void print_client_data2(client your_client) {
    cout << "|" << setw(15) << your_client.account_number <<  "|" << setw(40) << your_client.name <<  "|" << setw(12) << your_client.accountbalance << "|" << endl;
}
void print_data(vector<client> your_vclient,int your_sum) {
    cout << "                               client list (" << your_vclient.size() << ") client(s)." << endl;
    cout << "_________________________________________________________________________________________________________________________________\n";
    cout << "|" << setw(15) << "accout number" << "|"  << setw(40) << "client name"  << "|" << setw(12) << "balance" << "|" << endl;
    cout << "__________________________________________________________________________________________________________________________________\n";
    if (your_vclient.size() == 0) {
        cout << "no client found\n";
    }
    else {
        for (client i : your_vclient) {
            print_client_data2(i);
            cout << endl;
        }
    }
    cout << "\n_____________________________________________________________________\n";
    cout << "                        total balanced is =" << your_sum << "          \n";
}
int clculate_total(vector<client> your_vclient) {
    int sum = 0;
    for (client& i : your_vclient) {
        sum += i.accountbalance;
    }
    return sum;
}
void totalbalances_clients() {
    vector<client>my_vclient = retreve_data(client_fill);
    int sum=clculate_total(my_vclient);
    print_data(my_vclient,sum);
    
}


void transaction_screen();
void gobacke_transactionmenue() {
    cout << "\n\nprees any key to back to transactionmenue.........";
    system("pause>0");
    transaction_screen();
}


//transaction menue
enop_transaction list_operation_transaction(){
    short chooes;
    cout << "deposit              [1]\n";
    cout << "withdraw             [2]\n";
    cout << "total balances       [3]\n";
    cout << "main menue           [4]\n";
    cout << "_______________________________________\n";
    cout << "please inter your operation:"; cin >> chooes;
    return enop_transaction(chooes);
}
void applay_operation_transction(enop_transaction your_choice) {
    switch (your_choice) {
    case enop_transaction::deposit:
        system("cls");
        deposit_client();
        gobacke_transactionmenue();
        break;
    case enop_transaction::withdraw:
        system("cls");
        withdraw_client();
        gobacke_transactionmenue();
        break;
    case enop_transaction::totalbalances:
        system("cls");
        totalbalances_clients();
        gobacke_transactionmenue();
        break;
    default:
        main_manue_screen();
        
    }
}

void transaction_screen() {
    system("cls");
    print_hader_screen(en_operation::transaction);
    enop_transaction choees=list_operation_transaction();
    applay_operation_transction(choees);
}




//apply operation chooes
en_operation print_main_manue() {

    cout << "show client  [1]\n";
    cout << "add client   [2]\n";
    cout << "delet client [3]\n";
    cout << "update client[4]\n";
    cout << "find client  [5]\n";
    cout << "transaction  [6]\n";
    cout << "exsit        [7]\n";
    cout << "______________________________________\n";
    int number;
    cout << "please inter your number of operation:"; cin >> number;
    return en_operation(number);


}

void apply_operation_choees(en_operation operation) {
    switch (operation) {

    case en_operation::show:
        system("cls");
        print_hader_screen(en_operation::show);
        show_allclient(client_fill);
        gobacke_mainmenue();


        break;
    case en_operation::add:
        system("cls");
        print_hader_screen(en_operation::add);
        add_client();
        gobacke_mainmenue();
        break;
    case en_operation::delet:
        system("cls");
        print_hader_screen(en_operation::delet);
        delete_client();
        gobacke_mainmenue();
        break;
    case en_operation::update:
        system("cls");
        print_hader_screen(en_operation::update);
        update_client();
        gobacke_mainmenue();
        break;
    case en_operation::find:
        system("cls");
        print_hader_screen(en_operation::find);
        find_client();
        gobacke_mainmenue();
        break;
    case en_operation::transaction:
        system("cls");
        transaction_screen();
        break;
        
    default:
        system("cls");
        print_hader_screen(en_operation::exsit);
         exsit_client();
         
        break;

    }
}
void main_manue_screen() {
    system("cls");
    print_hader_screen(en_operation::main_menue);
    en_operation your_operation = print_main_manue();
    apply_operation_choees(your_operation);
}

int main()
{
    main_manue_screen();
}

