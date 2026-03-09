#pragma once
#include<iostream>
using namespace std;

/*
//this is interface to force drive class to implmention this
*/

class interfaceCommunication
{
public:
	 virtual void sendEmail(string title, string body) = 0;
	 virtual void sendFac(string title, string body) = 0;
	 virtual void sendSms(string title, string body) = 0;
};

