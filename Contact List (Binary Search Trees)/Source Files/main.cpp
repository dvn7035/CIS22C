/*
Lab 4 
Created by: David Nguyen
Date: 5/12/14

This program will read in a list of contacts from a text file and build a binary tree with it. 
The user will be able to print the list, delete entries from the list, search entries for the list,
and update individual entries.

Clare Nguyen 
Data Abstraction and Structures
*/

#include "ContactList.h"
#include <iostream>
#include <fstream>
#include <string>
#define FLUSH while (getchar() != '\n')

using namespace std;

int main()
{
	char choice, choice2;
	ContactList list;

	cout << "There are " << list.how_many_contacts() << " contacts in the contact list" << endl <<endl;
	do 
	{
		cout << "l. list contacts" << endl
			 << "d. delete contact" << endl
			 << "s. search contact" << endl
			 << "u. update contact" << endl
			 << "q. quit" << endl << "Choice:  ";
		cin >> choice;
		FLUSH;
		switch (choice)
		{
			case 'l': 

				cout << "a. alphabetical order" << endl << "r. reverse alphabetical order" << endl << "Choice:  ";
				cin >> choice2;
				if (choice2 == 'a')
				{
					list.list_alphabetical_order();
					cout << endl;
				}
				else if (choice2 == 'r')
				{
					list.list_reverse_alphabetical_order();
					cout << endl;
				}
				else 
					cout << "That command wasn't understood" << endl << endl;
				break;
			case 'd':
				list.delete_contact();
				break;
			case 's':
				list.search_contact();
				break;
			case 'u':
				list.update_contact();
				break;
			case 'q':
				break;
			default: 
				cout << "That command was not understood" << endl << endl;
		}
	} while (choice != 'q');
	return 0;
}