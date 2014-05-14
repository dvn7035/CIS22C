/*
Lab 4
Created by: David Nguyen
Date: 5/12/14
*/
#ifndef _CONTACT
#define _CONTACT

#include <string>
#include <iomanip>

using namespace std;

class Contact
{
private:
	string name;
	string phone_number;
	string web_email;
public:
	Contact () {}
	Contact (string input_name, string input_phone, string input_web) {name = input_name; phone_number = input_phone; web_email = input_web;}
	void update_name (string input) {name = input;}
	void update_phone_number (string input) {phone_number = input;}
	void update_web_email (string input) {web_email = input;}

	bool operator == (const Contact& right){return this->name == right.name;}
	bool operator < (const Contact& right){return this->name < right.name;}
	bool operator > (const Contact& right){return this->name > right.name;}
	friend ostream& operator << (ostream& os, const Contact& print) //I couldn't define it outside the class declaration for some reason
	{
		os << setw(20);
		os << left << print.name << " " << print.phone_number << " "
		<< right << print.web_email << endl; return os;
	}
};
#endif
