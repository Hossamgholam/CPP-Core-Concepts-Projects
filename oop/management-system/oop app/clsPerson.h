#pragma once
#include<iostream>
#include<string>
#include"interfaceCommunication.h"
using namespace std;
class clsPerson:public interfaceCommunication {
private:
    string _fristName;
    string _lastName;
    string _email;
    string _phone;
public:
    clsPerson(string _fristName, string _lastName, string _email, string _phone) {
        this->_fristName = _fristName;
        this->_lastName = _lastName;
        this->_email = _email;
        this->_phone = _phone;

    }

    void setFristName(string fristName) {
        _fristName = fristName;
    }
    string getFristName() {
        return _fristName;

    }
    __declspec(property(get = getFristName, put = setFristName))string fristName;

    void setLastName(string lastName) {
        _lastName = lastName;
    }
    string getLastName() {
        return _lastName;

    }
    __declspec(property(get = getLastName, put = setLastName))string lastName;

    void setEmail(string email) {
        _email = email;
    }
    string getEmail() {
        return _email;

    }
    __declspec(property(get = getEmail, put = setEmail))string email;

    void setPhone(string phone) {
        _phone = phone;
    }
    string getPhone() {
        return _phone;

    }
    __declspec(property(get = getPhone, put = setPhone))string phone;

    string fullName() {
        return _fristName + " " + _lastName;
    }

     void sendEmail(string title, string body) {};
     void sendFac(string title, string body) {};
     void sendSms(string title, string body) {};

};
