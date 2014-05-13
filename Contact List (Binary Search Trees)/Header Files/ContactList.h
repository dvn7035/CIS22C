#ifndef _CONTACT_LIST
#define _CONTACT_LIST

#include <fstream>
#include <iostream>

#include "BinarySearchTree.h"
#include "Contact.h"

class ContactList
{
private:
	BinarySearchTree<Contact> contacts;
	int number_of_contacts;
public:
	ContactList();
	int how_many_contacts() {return number_of_contacts;}
	void list_alphabetical_order(); 
	void list_reverse_alphabetical_order();
	void delete_contact();
	void search_contact();
	void update_contact();
};
#endif