#pragma once
#include<iostream>
#include<vector>
using namespace std;
class clsString
{
private:
	string _value;
public:
	clsString() {
		_value = "";
	}
	clsString(string _value) {
		this->_value = _value;
	}

	void setValue(string _value) {
		this->_value = _value;
	}
	string getValue() {
		return _value;
	}

	__declspec(property(get = getValue, put = setValue))string value;
	
	static void fristChar(string name) {
		bool frist_leter = true;
		for (int i = 0; i < name.length(); i++) {
			if (name[i] != ' ' && frist_leter) {
				cout << name[i] << "\t";
			}
			frist_leter = (name[i] == ' ') ? true : false;
		}
		
	}
	void fristChar() {
		fristChar(_value);
	}

	static string uperFristLitterOfEachWord(string name) {
		bool frist_leter = true;
		for (int i = 0; i < name.length(); i++) {
			if (name[i] != ' ' && frist_leter) {
				name[i] = toupper(name[i]);
			}

			frist_leter = (name[i] == ' ') ? true : false;
		}
		return name;
	}
	void uperFristLitterOfEachWord() {
		_value = uperFristLitterOfEachWord(_value);
	}
	
	static string lowerFristLitterOfEachword(string name) {
		bool frist_leter = true;
		for (int i = 0; i < name.length(); i++) {
			if (name[i] != ' ' && frist_leter) {
				name[i] = tolower(name[i]);
			}

			frist_leter = (name[i] == ' ') ? true : false;
		}
		return name;
	}
	void lowerFristLitterOfEachword() {
		_value = lowerFristLitterOfEachword(_value);
	}

	static string upperAllString(string name) {
		bool frist_leter = true;
		for (int i = 0; i < name.length(); i++) {

			name[i] = toupper(name[i]);
		}
		return name;
	}
	void upperAllString() {
		_value = upperAllString(_value);
	}

	static string lowerAllString (string name) {
		bool frist_leter = true;
		for (int i = 0; i < name.length(); i++) {

			name[i] = tolower(name[i]);
		}
		return name;
	}
	void lowerAllString() {
		_value = lowerAllString(_value);
	}

	static char invertLetterCase(char your_char) {

		return (isupper(your_char)) ? tolower(your_char) : toupper(your_char);

	}
	static string invertAllLetterCase(string your_char) {
		for (int i = 0; i < your_char.length(); i++) {

			your_char[i] = invertLetterCase(your_char[i]);
		}
		return your_char;
	}
	void invertAllLetterCase() {
		_value = invertAllLetterCase(_value);
	}

	enum enWhatToCoutount { upper = 1, lower = 2, all = 3 };
	static int countLetters(string your_string, enWhatToCoutount what_count = enWhatToCoutount::all) {
		if (what_count == enWhatToCoutount::all) {
			return your_string.length();
		}
		else {
			int counter = 0;
			for (int i = 0; i < your_string.length(); i++) {
				if (what_count == enWhatToCoutount::lower && islower(your_string[i])) {
					counter++;
				}
				if (what_count == enWhatToCoutount::upper && isupper(your_string[i])) {
					counter++;
				}

			}
			return counter;
		}
	}
	
	static int countCapitalLitter(string s) {
		int counter = 0;
		for (int i = 0; i < s.length(); i++) {
			if (isupper(s[i])) {
				counter++;
			}
		}
		return counter;
	}
	int countCapitalLitter() {
		return countCapitalLitter(_value);

	}
		
	static int countSmallLitter(string s) {
		int counter = 0;
		for (int i = 0; i < s.length(); i++) {
			if (islower(s[i])) {
				counter++;
			}
		}
		return counter;
	}
	int countSmallLitter() {
		return countSmallLitter(_value);

	}

	static int countSpecificLetter(string your_string, char your_char, bool matchcase = true) {
		int counter = 0;

		for (int i = 0; i < your_string.length(); i++) {
			if (matchcase) {
				if (your_string[i] == your_char) {
					counter++;
				}
			}
			else {
				if (tolower(your_string[i]) == tolower(your_char)) {
					counter++;
				}
			}
		}
		return counter;
	}
	int countSpecificLetter(char yourChar, bool matchcase = true) {
		return countSpecificLetter(_value, yourChar, matchcase);
	}

	static bool isVowel(char your_letter) {
		your_letter = tolower(your_letter);

		return (your_letter == 'a' || your_letter == 'e' || your_letter == 'i' || your_letter == 'o' || your_letter == 'u') ? true : false;
	}
	static int countVowels(string your_string) {
		int counter = 0;
		for (int i = 0; i < your_string.length(); i++) {
			if (isVowel(your_string[i])) {
				counter++;
			}
		}
		return counter;
	}
	int countVowels() {
		return countVowels(_value);
	}

	static int countWords(string your_string) {
		string delim = " ";
		short pos = 0;
		string word;
		short counter = 0;
		while ((pos = your_string.find(delim)) != std::string::npos) {
			word = your_string.substr(0, pos);
			if (word != "") {
				counter++;
			}
			your_string.erase(0, pos + delim.length());
		}
		if (your_string != "") {
			counter++;
		}
		return counter;
	}
	int countWords() {
		return countWords(_value);
	}

	static vector<string> split(string your_string, string your_delim) {
		string delim = your_delim;
		short pos = 0;
		string word;
		vector<string>storg;
		while ((pos = your_string.find(delim)) != std::string::npos) {
			word = your_string.substr(0, pos);
			if (word != "") {
				storg.push_back(word);
			}
			your_string.erase(0, pos + delim.length());
		}
		if (your_string != "") {
			storg.push_back(your_string);
		}
		return storg;
	}
	vector<string> split(string delemter) {
		return split(_value, delemter);
	}


	static string trimLeft(string your_string) {

		for (int i = 0; i < your_string.length(); i++) {
			if (your_string[i] != ' ') {
				return your_string.substr(i, your_string.length() - 1);
			}
		}
		return "";
	}
	void trimLeft() {
		_value= trimLeft(_value);
	}
	static string trimRight(string your_string) {

		for (int i = your_string.length() - 1; i >= 0; i--) {
			if (your_string[i] != ' ') {
				return your_string.substr(0, i + 1);
			}
		}
		return "";
	}
	void trimRight() {
		_value = trimRight(_value);
	}
	static string trim(string your_string) {
		return trimLeft(trimRight(your_string));
	}
	void trim() {
		_value = trim(_value);
	}

	//withe vector and arry
	static string joinString(vector<string>your_test, string delimter) {
		string your_name = "";
		vector<string>::iterator item;
		for (item = your_test.begin(); item < your_test.end(); item++) {
			your_name = your_name + *item + delimter;
		}
		return your_name.substr(0, your_name.length() - delimter.length());
	}
	static string joinString(string your_array[100], int your_length, string delimter) {
		string your_name = "";
		for (int i = 0; i < your_length; i++) {
			your_name = your_name + your_array[i] + delimter;
		}
		return your_name.substr(0, your_name.length() - delimter.length());
	}

	static string replaceWorde(string your_statment, string sreplace, string storeplace, bool match = true) {
		vector<string>storge = split(your_statment, " ");
		for (string& i : storge) {
			if (match) {
				if (i == sreplace) {
					i = storeplace;
				}
			}
			else {
				if (lowerAllString(i) == lowerAllString(sreplace)) {
					i = storeplace;
				}
			}
		}
		return joinString(storge, " ");
	}
	void replaceWorde(string sreplace, string storeplace, bool matchecase) {
		_value = replaceWorde(_value, sreplace, storeplace, matchecase);
	}

	static string removePunction(string your_string) {
		string s = "";
		for (int i = 0; i < your_string.length(); i++) {
			if (!ispunct(your_string[i])) {
				s = s + your_string[i];
			}
		}
		return s;

	}
	void removePunction() {
		_value = removePunction(_value);
	}

};





