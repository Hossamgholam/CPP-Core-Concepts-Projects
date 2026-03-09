#pragma once
#include<iostream>
#include"clsDate.h"
#include"clsUser.h"
#include"global.h"

using namespace std;

class clsScreen
{
protected:
	static void _drawScreenHeader(string title, string subtitle = "") {
		
		cout << "\t\t\t\t\t________________________________________";
		cout << "\n\n\t\t\t\t\t" << title;
		if (subtitle != "")
		{
			cout << "\n\t  " << subtitle;
		}
		cout << "\n\t\t\t\t\t________________________________________";

		cout << "\n\t\t\t\t\tuser:" << currentUser.userName;
		cout << "\n\t\t\t\t\tdate:" << clsDate::dateToString(clsDate()) << endl<<endl<<endl;
	}
	
	static bool checkAccessRights(clsUser::enMangeuserPermission permission) {
		if (currentUser.checkAccessPermission(permission)) {
			return true;
		}
		else {
			cout << "\n\t\t\t\t\t___________________________________________\n";
			cout << "\t\t\t\t\t            acess denid\n";
			cout << "\t\t\t\t\t            you don have permision to acess\n";
			cout << "\t\t\t\t\t            pleas contact you admin\n";
			cout << "\n\t\t\t\t\t___________________________________________\n";
			return false;
		}
	}


};

