#pragma once
#include<iostream>
using namespace std;


#include"clsPerson.h"
#include"string"
#include"clsString.h"
#include"fstream"
#include"vector"
#include"clsIputValiDate.h"
#include"clsUtil.h"
/// <summary>
/// what can do
/// subject :it like client by foucs on user
/// </summary>
class clsUser:public clsPerson
{
public:
	struct stLogInRegisterRecord {
	string dateTime;
	string userName;
	string password;
	int  permesion;
};
private:
	enum enMode {
		emptyMode=1,updateMode=2,addNewMode=3
	};

	string _userName;
    string _password;
	int _permesion;
	enMode _mode;
	bool _markeForDelet = false;



	static clsUser _convertLineToUserObject(string yourLine) {
		vector<string>usersRecords;
		usersRecords = clsString::split(yourLine, "#//#");
		
		return clsUser(enMode::updateMode, usersRecords[0], usersRecords[1],
			usersRecords[2], usersRecords[3], usersRecords[4], clsUtil::decription(usersRecords[5]),
			stod(usersRecords[6])
		);
	}
	static string _convertUserObjectToLine(clsUser& yourUser, string delemiter = "#//#") {
		string line = "";
		line = line + yourUser.fristName + delemiter;
		line = line + yourUser.lastName + delemiter;
		line = line + yourUser.email + delemiter;
		line = line + yourUser.phone + delemiter;
		line = line + yourUser.userName + delemiter;
		line = line + clsUtil::encription( yourUser.password) + delemiter;
		line = line + to_string(yourUser.permission);
		return line;
	}
	static clsUser _getEmptyUserObject() {
		return clsUser(enMode::emptyMode, "", "", "", "", "", "", 0);
	}
	static vector<clsUser> _loadUsersDateFromFile() {
		fstream my_fill;
		vector<clsUser> vUsers;
		my_fill.open("user.txt", ios::in);
		if (my_fill.is_open()) {

			string line = "";
			while (getline(my_fill, line)) {
				clsUser my_client = _convertLineToUserObject(line);
				vUsers.push_back(my_client);
			}
			my_fill.close();
		}
		return vUsers;
	}

	static void _saveUsersDateToFile(const vector <clsUser>& yourVUsers) {

		fstream fill;
		string line = "";
		fill.open("user.txt", ios::out);
		if (fill.is_open()) {
			for (clsUser i : yourVUsers) {
				if (i._markeForDelet== false) {

					line = _convertUserObjectToLine(i);
					fill << line << endl;
				}

			}
			fill.close();
		}


	}
	void _update() {
		vector<clsUser>vUser;
		vUser = _loadUsersDateFromFile();

		for (clsUser& c : vUser) {
			if (c.userName == userName) {
				c = *this;
				break;
			}
		}
		_saveUsersDateToFile(vUser);
	}

	void _addDateLineToFile(string line) {
		fstream myFile;
		myFile.open("user.txt", ios::app);
		if (myFile.is_open()) {
			myFile << line << endl;
			myFile.close();
		}
	}
	void _addNew() {


		_addDateLineToFile(_convertUserObjectToLine(*this));


	}

	//have this object and call fuction from clsdate to get date 
	//tim and date  convert it in string
	string _prepareLogInRecord() {
		string stDateTime = clsDate::getSystemDateTimeString();
		return (stDateTime + "#//#"
			+ userName + "#//#"
			+ clsUtil::encription(password,3) + "#//#"
			+ to_string(permission));
	}

	
	static stLogInRegisterRecord _converLogInRegisterLineToRecord(string line) {
		vector<string> vLogInRegisterRecord = clsString::split(line, "#//#");
		stLogInRegisterRecord logInRegisterRecord;
		logInRegisterRecord.dateTime = vLogInRegisterRecord[0];
		logInRegisterRecord.userName = vLogInRegisterRecord[1];
		logInRegisterRecord.password =clsUtil::decription( vLogInRegisterRecord[2],3);
		logInRegisterRecord.permesion = stoi(vLogInRegisterRecord[3]);
		return logInRegisterRecord;

	}

public:

	clsUser(enMode mode, string fristName, string lastName, string email, string phone,
		string userName, string password, int permesion
	) :clsPerson(fristName, lastName, email, phone) {
		_mode = mode;
		_userName = userName;
		_password = password;
		_permesion = permesion;
	}

	void setUserName(string userName) {
		_userName = userName;
	}
	string getUserName() {
		return _userName;
	}
	__declspec(property(get = getUserName, put = setUserName))string userName;

	void setPassword(string password) {
		_password = password;
	}
	string getPassword() {
		return _password;
	}
	__declspec(property(get = getPassword, put = setPassword))string password;

	void setPermission(int permission) {
		_permesion = permission;
	}
	int getPermission() {
		return _permesion;
	}
	__declspec(property(get = getPermission, put = setPermission))int permission;



	static clsUser find(string yourUserName) {
		vector<clsUser>vUser;
		fstream ptFile;
		ptFile.open("user.txt");
		if (ptFile.is_open()) {
			string line;
			while (getline(ptFile, line)) {
				clsUser user = _convertLineToUserObject(line);
				if (user.userName == yourUserName) {
					ptFile.close();
					return user;
				}
				vUser.push_back(user);
			}
		}
		return _getEmptyUserObject();
	}
	static clsUser find(string yourUserName, string YourPassword) {
		vector<clsUser>vUser;
		fstream ptFile;
		ptFile.open("user.txt");
		if (ptFile.is_open()) {
			string line;
			while (getline(ptFile, line)) {
				clsUser user = _convertLineToUserObject(line);
				if (user.userName == yourUserName && user.password == YourPassword) {
					ptFile.close();
					return user;
				}
				vUser.push_back(user);
			}
		}
		return _getEmptyUserObject();
	}


	static bool isUserExist(string yourUserName) {
		clsUser client = find(yourUserName);
		return(!client.isEmpty());
	}
	bool isEmpty() {
		return (_mode == enMode::emptyMode);
	}
	static clsUser getAddNewUserObject(string yourUserName) {
		return clsUser(enMode::addNewMode, "", "", "", "", yourUserName, "", 0);
	}


	enum enSaveResult { svScusseded = 0, svFaildEmptyObject = 1, svFaildAccounNumberExsit = 3 };
	//this function for updatemode and addnewMode
	enSaveResult save() {
		switch (_mode)
		{
		case enMode::emptyMode:
			//level of security
			if (isEmpty()) {
				return enSaveResult::svFaildEmptyObject;
			}
		case enMode::updateMode:
			_update();
			return enSaveResult::svScusseded;

		case enMode::addNewMode:
			if (isUserExist(_userName)) {
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


	bool Delete() {
		vector<clsUser>vUsers;
		vUsers = _loadUsersDateFromFile();
		for (clsUser& c : vUsers) {
			if (c.userName == userName) {
				c._markeForDelet = true;
				break;
			}
		}
		_saveUsersDateToFile(vUsers);
		*this = _getEmptyUserObject();
		return true;
	}


	static vector<clsUser> getUsersList() {
		return _loadUsersDateFromFile();
	}


	enum enMangeuserPermission {
		pAll = -1,
		pShowClientList = 1, pAddClient = 2, pDeleteClient = 4, pUpdateClient = 8,
		pFindClient = 16, pTransactionMenue = 32, pMangeUser = 64, pLogInRegister = 128
	};
	 bool checkAccessPermission(enMangeuserPermission permistion) {
		if (this->permission== -1) {
			return true;
		}
		//if he not have permistion on this opertion it give zero 
		//ele it giv number of operatiion(permistion)
		if ((this->permission & permistion) == permistion) {
			return true;
		}
		else {
			return false;
		}
	}


	  //fuction for register login info in registar fill 
	 /*
	 it is public becuse to call any where and
	       nont static becuse it belong to specific object 
	 */
	 //it call in clsshowloginscreen
	 void registerLogIn() {
		 string stDateLine = _prepareLogInRecord();
		 fstream pt;
		 pt.open("logInRegister.txt", ios::out | ios::app);
		 if (pt.is_open()) {
			 pt << stDateLine << endl;

			 pt.close();
		 }
	 }

	 static vector<stLogInRegisterRecord> getLogInRegisterList() {
		 fstream ptFile;
		 vector<stLogInRegisterRecord>vLogInRegisterRecords;
		 stLogInRegisterRecord logInRegisterRecord;

		 ptFile.open("logInRegister.txt", ios::in);
		 if (ptFile.is_open()) {
			 string line = "";
			 while (getline(ptFile, line)) {
				 logInRegisterRecord = _converLogInRegisterLineToRecord(line);
				 vLogInRegisterRecords.push_back(logInRegisterRecord);
			 }
			 ptFile.close();
		 }
		 return vLogInRegisterRecords;
		 
	 }
};

