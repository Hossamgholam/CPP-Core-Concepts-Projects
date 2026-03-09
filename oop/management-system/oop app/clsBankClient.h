#pragma once
#include <iostream>
#include<fstream>
#include<string>
#include<vector>
#include"clsString.h"
#include"clsPerson.h"
#include"global.h"
using namespace std;
/// <summary>
/// what this class can do 
/// 1-subject
///      -this class work(do some opertion) withe client date that storge(porperity)
///      in fill withe name " myfill" i know that name not sutible
///        
/// 2_properity 
///      it inherit from clsperson  properity                            
///                                 __fristname lastname phone email   
///        accountNumber   pinCode   accountBalance   markedForDelete 
/// 
/// 3_method 
///       1-last    2-add       3-update        4-delete   5-find  (for client)
///       6-deposit 7-withdraw  8-totalbalance  9-transfer 10_show meta data about transfer(for account balance)
///       

/// 
/// </summary>
class clsBankClient :public clsPerson {
public:
    struct stTransferLogRecord{
        string dateTime;
        string sourceAccount;
        string distinationAccount;
        double amount;
        double sourceAcounntBalance;
        double distinationAccountBalance;
        string userName;

    };

private:
    string _accountNumber;
    string _pinCode;
    double _accountBalance;
    bool _markedForDelete = false;


    /// <summary>
    //make it private to stop any one to declartion variable and 
    //no info about client 
    /// </summary>
    enum enMode { enptymode = 0, updateMode = 1,addNewMode=2 };
    enMode _mode;
    //convert  LINE content info of client to OBJECT
    //

    static clsBankClient _convertLineToClientObject(string yourLine) {
        vector<string>clientRecord;
        clientRecord = clsString::split(yourLine, "#//#");
        return clsBankClient(enMode::updateMode, clientRecord[0], clientRecord[1],
            clientRecord[2], clientRecord[3], clientRecord[4], clientRecord[5],
            stod(clientRecord[6])
        );
    }

    //return object without info
    //it is usefull for delet client becuse 
    //delet delet from fill but current object hase info so we need
    static clsBankClient _getEmptyClientObject() {
        return clsBankClient(enMode::enptymode, "", "", "", "", "", "", 0);
    }

    //open fill retrive info from fill as string line
    // convert it to object and 
    //save it in vector of obuect
    static vector<clsBankClient> _loadClientsDateFromFile() {
        fstream my_fill;
        vector<clsBankClient> my_vclient;
        my_fill.open("myfill.txt", ios::in);
        if (my_fill.is_open()) {
            
            string line = "";
            while (getline(my_fill, line)) {
                clsBankClient my_client = _convertLineToClientObject(line);
                my_vclient.push_back(my_client);
            }
            my_fill.close();
        }
        return my_vclient;
    }

    // take client object as referenc
    //convert to line to storge in fill
    static string _convertClientObjectToLine( clsBankClient& your_client, string delemiter = "#//#") {
        string line = "";
        line = line + your_client.fristName + delemiter;
        line = line + your_client.lastName + delemiter;
        line = line + your_client.email + delemiter;
        line = line + your_client.phone + delemiter;
        line = line + your_client.accountNumber + delemiter;
        line = line + your_client.pinCode + delemiter;
        line = line + to_string(your_client.accountBalance);
        return line;
    }
    
    //take client that sorge in vector  and conver it to line then upload to fill
    static void _saveClientsDateToFile(const vector <clsBankClient>& yourVClient) {
        
            fstream fill;
            string line = "";
            fill.open("myfill.txt", ios::out);
            if (fill.is_open()) {
                for (clsBankClient i : yourVClient) {
                    if (i._markedForDelete == false) {

                        line = _convertClientObjectToLine(i);
                        fill << line << endl;
                    }
                    
                }
                fill.close();
            }

       
    }
    //it call by specific object 
    //load date form fill 
    //search about object and update 
    //then load to fill
    void _update() {
        vector<clsBankClient>vClient;
        vClient = _loadClientsDateFromFile();

        for (clsBankClient& c : vClient) {
            if (c.accountNumber == accountNumber) {
                c = *this;
                break;
            }
        }
        _saveClientsDateToFile(vClient);
    }

    /*
    add new it is private beacuse it don not need to see
    adddatelientofile not static becuse it belong to secific object
    */
    void _addDateLineToFile( string line) {
        fstream myFile;
        myFile.open("myfill.txt", ios::app);
        if (myFile.is_open()) {
            myFile << line << endl;
            myFile.close();
        }
    }
    //call by specific object withe his info
    //convert to line 

    void _addNew() {
        
            
            _addDateLineToFile( _convertClientObjectToLine(*this));

        
    }

    //function to prepart information of transfer in specific string format to storge in fill 
    string _preparTransferLogRecord(double amount, clsBankClient& distinatioin, string userName,string delemter="#//#") {
        string record = "";
        string dateTime = clsDate::getSystemDateTimeString();
        record = dateTime + delemter
            + accountNumber + delemter
            + distinatioin.accountNumber + delemter
            + to_string(amount) + delemter
            + to_string(accountBalance) + delemter
            + to_string(distinatioin.accountBalance) + delemter
            + userName;
        return record;
    }
    //it is non satic becuse it call by sourceclient
    //funtion to storge result from preparTransferLOgRecord funtion in filll
    void _registerTransferLog(double amount, clsBankClient distination, string userName) {
        string record = _preparTransferLogRecord(amount, distination, userName);
        fstream ptFile;
        ptFile.open("TransferLog.txt", ios::out | ios::app);
        if (ptFile.is_open()) {
            ptFile << record << endl;
            ptFile.close();
        }
    }

    static stTransferLogRecord _convertTransferLogLineToRecord(string line) {
        vector<string>vTransferLogRecord = clsString::split(line,"#//#");
        stTransferLogRecord transferLogRecord;
        transferLogRecord.dateTime = vTransferLogRecord[0];
        transferLogRecord.sourceAccount = vTransferLogRecord[1];
        transferLogRecord.distinationAccount = vTransferLogRecord[2];
        transferLogRecord.amount =stod( vTransferLogRecord[3]);
        transferLogRecord.sourceAcounntBalance =stod( vTransferLogRecord[4]);
        transferLogRecord.distinationAccountBalance =stod( vTransferLogRecord[5]);
        transferLogRecord.userName = vTransferLogRecord[6];
        return transferLogRecord;
    }
public:


    clsBankClient(enMode mode, string fristName, string lastName, string email, string phone
        , string accountNumbmer, string pinCode, double accountBalance)
        :clsPerson(fristName, lastName, email, phone) {
        _mode = mode;
        _accountNumber = accountNumbmer;
        _pinCode = pinCode;
        _accountBalance = accountBalance;

    }


    void setMode(enMode mode) { _mode = mode; }
    enMode getMode() { return _mode; }

    void setAccountNumber(string accountNumber) { _accountNumber = accountNumber; }
    string getAccountNumber() { return _accountNumber; }

    void setPinCode(string pinCode) { _pinCode = pinCode; }
    string getPinCode() { return _pinCode; }

    void setAccountBalance(double accountBalance) { _accountBalance = accountBalance; }
    double getAccountBalance() { return _accountBalance; }


    __declspec(property(get = getMode, put = setMode)) enMode mode;
    __declspec(property(get = getAccountNumber, put = setAccountNumber)) string accountNumber;
    __declspec(property(get = getPinCode, put = setPinCode)) string pinCode;
    __declspec(property(get = getAccountBalance, put = setAccountBalance)) double accountBalance;

    /*
    * make ui separity of database
    void print() {
        cout << "\n client carde\n";
        cout << "------------------------------\n";
        cout << "\nfristName  :" << fristName;
        cout << "\nlastName   :" << lastName;
        cout << "\nfullName   :" << fullName();
        cout << "\nemail       :" << email;
        cout << "\nphone       :" << phone;
        cout << "\nacc. number :" << _accountNumber;
        cout << "\npin code    : " << _pinCode;
        cout << "\naccounfBalan:" << _accountBalance;
    }
    */

    // can call without need object 
    //searech about object in fill.text if it found it return information on object
    //every function call it make object in update mode
    static clsBankClient find(string yourAccountNumber) {
        vector<clsBankClient>vClient;
        fstream ptFile;
        ptFile.open("myfill.txt");
        if (ptFile.is_open()) {
            string line;
            while (getline(ptFile, line)) {
                clsBankClient client = _convertLineToClientObject(line);
                if (client.accountNumber == yourAccountNumber) {
                    ptFile.close();
                    return client;
                }
                vClient.push_back(client);
            }
        }
        return _getEmptyClientObject();
    }
    static clsBankClient find(string yourAccountNumber, string yourPinCode) {
        vector<clsBankClient>vClient;
        fstream ptFile;
        ptFile.open("myfill.txt");
        if (ptFile.is_open()) {
            string line;
            while (getline(ptFile, line)) {
                clsBankClient client = _convertLineToClientObject(line);
                if (client.accountNumber == yourAccountNumber && client.pinCode == yourPinCode) {
                    ptFile.close();
                    return client;
                }
                vClient.push_back(client);
            }
        }
        return _getEmptyClientObject();
    }
    
    /*
    it use static functioin find to search about oject 
    if it found
     return object with info 
    else 
     return empty oject
    */
    static bool isClientExist(string yourAccountNumber) {
        clsBankClient client = find(yourAccountNumber);
        return(!client.isEmpty());
    }

    //this fuction for creat empty object from client
    // important to add new client to  make mode for client addnew 
    //as _converttoobject  is importent for update to make it in update mode
    static clsBankClient getAddNewClientObject(string yourAccountNumber) {
        return clsBankClient(enMode::addNewMode, "", "", "", "", yourAccountNumber, "", 0);
    }
    
    bool isEmpty() {
        return (_mode == enMode::enptymode);
    }


    //this enum importent for chack if operation scussed or fiald
    enum enSaveResult{svScusseded=0,svFaildEmptyObject=1,svFaildAccounNumberExsit=3};
    //this function for updatemode and addnewMode
    enSaveResult save() {
        switch (_mode)
        {
        case enMode::enptymode:
            //level of security
            if (isEmpty()) {
            return enSaveResult::svFaildEmptyObject;
            }
        case enMode::updateMode:
            _update();
            return enSaveResult::svScusseded;
            
        case enMode::addNewMode:
            if (isClientExist(_accountNumber)) {
                return enSaveResult::svFaildAccounNumberExsit;
                
            }
            else {
                _addNew();
                //if i do not put this it  still addNew mode so
                //if i need to update i can not
                _mode = enMode::updateMode;
                return enSaveResult::svScusseded;

            }
        default:
            //we can but  
            //return enSaveResult::svFaildEmptyObject;
            break;
        }
    }

    /// <summary>
    /// this fuction lode date from fille
    /// make mark in client to delet  using accountNumber
    /// call function saveclientDateToFill to save date(update in fill)
    /// make current object in program empty(update in program)
    /// </summary>
    /// <returns> if delete successed return true;</returns>
    bool Delete() {
        vector<clsBankClient>vClient;
        vClient = _loadClientsDateFromFile();
        for (clsBankClient& c : vClient) {
            if (c.accountNumber == _accountNumber) {
                c._markedForDelete = true;
                break;
            }
        }
        _saveClientsDateToFile(vClient);
        *this = _getEmptyClientObject();
        return true;
    }

    static vector<clsBankClient> getClientsList() {
        return _loadClientsDateFromFile();
    }

    //fuction to deposit amount of object and save it in fill
    void deposit(double amount) {
        //it call fin in deposit screen so mode is update
        _accountBalance += amount;
        save();
    }
    bool withdraw(double amount) {
        //it call fin in withdraw screen so mode is update
        if (amount > _accountBalance) {
            return false;
        }
        else {

        _accountBalance -= amount;
        save();
        return true;
        }
    }
    //this fuction is load date of client using _loaddatefromfille
    //i do it becuse loaddatefromfille is private and name

    static double getTotalBalnce() {
        vector<clsBankClient>vClinent = getClientsList();
        double total = 0;
        for ( clsBankClient& i : vClinent) {
            total += i.accountBalance;
        }
        return total;
    }

    bool transfer(double amount,clsBankClient& distinationClient,string userName) {
        if (amount > accountBalance) {
            return false;
        }
        else {
            withdraw(amount);
            distinationClient.deposit(amount);
            //funtion to register transfer operation info  in fill 
            //dateTime,accountNumberfrom ,accountNumbmerto,amount,accountBalancefrom,to ,username
            _registerTransferLog(amount, distinationClient, userName);
            return true;

        }
    }
    //transferlog call in side transfer

    static vector<stTransferLogRecord> getTransferLogList() {
        vector<stTransferLogRecord>vTransferLogRecord;
        fstream ptFill;
        ptFill.open("TransferLog.txt", ios::in);
        if (ptFill.is_open()) {
            stTransferLogRecord transferLogRecord;
            string line = "";

            while (getline(ptFill, line)) {
                transferLogRecord = _convertTransferLogLineToRecord(line);
                vTransferLogRecord.push_back(transferLogRecord);
            }
            ptFill.close();
        }
        return vTransferLogRecord;
    }
};

