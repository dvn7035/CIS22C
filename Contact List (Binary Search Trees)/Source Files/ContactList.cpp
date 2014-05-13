#include "ContactList.h"
#include "Contact.h"
#include "BinaryTree.h"

/*
display will call upon the overloaded << to print a Contact object to the terminal 
Pre: Contact object
Post: Contact's contents will appear onscreen
*/
void display(Contact& anItem)
{
   cout << anItem;
   return;
} 

/*
Strtok takes in a source string and finds a substring up to the delimiter. It puts the 
substring and erases it (including delimiter) from the original source string
Pre: A source string, a destination string, and a delimiter
Post: The source string will deleted up to and including the delimiter and the 
destination string will hold the substring deleted not including the delimiter
*/
void Strtok(string& source, string& destination, const string delimiter)
{
	size_t position;
	position = source.find(delimiter); 
	destination = source.substr(0, position);
	source.erase(0, position + delimiter.length());
	return;
}

/*
ContactList constructor will read in a file, tokenize a string, create a contact 
instance and insert it in the binary tree.
Pre: 
Post: Binary tree is populated and number_of_contacts holds the number of contacts 
in the file
*/
ContactList::ContactList() : number_of_contacts (0)
{
	ifstream contact_input;
	string buffer, name_buffer, phone_buffer, web_buffer;

	contact_input.open("in.txt");
	while (getline (contact_input, buffer))
	{
		//I don't really know C++ string handling well and it shows
		Strtok(buffer, name_buffer, ",");
		Strtok(buffer, phone_buffer, ",");
		Strtok(buffer, web_buffer, ",");
		Contact contact_input (name_buffer, phone_buffer, web_buffer);  //create a contact instance to input in the tree
		contacts.insert(contact_input);
		number_of_contacts++;
	}
}

/*
delete_contact will remove a contact from the binary tree
Pre: 
Post: A contact from the tree will be deleted
*/
void ContactList::delete_contact()
{
	string delete_name;

	cout << "Enter a contact name to delete: ";
	getline (cin, delete_name);
	Contact del (delete_name, " ", " "); //create a contact instance for the search
	if (contacts.remove(del))
		cout << delete_name << " is deleted from the contact list" << endl << endl;
	else
		cout << delete_name << " was not found and could not be deleted" << endl <<endl;
	return;
}

/*
search_contact will search for a contact in the binary tree and display its contents on screen
pre:
post: The contents of a specified contact will be displayed on-screen
*/
void ContactList::search_contact()
{
	string name;
	Contact ret_val;

	cout << "Enter a contact to search: ";
	getline (cin, name);
	Contact search (name, " ", " ");
	if (contacts.getEntry(search, ret_val))
		cout << ret_val << endl ;
	else 
	{
		cout << name << " was not found among these names:" << endl;
		contacts.inOrder(display);
		cout << endl << endl;
	}

}

/*
update_contact will grab a contact from the tree, delete the contact, update the contact, and 
reinsert it back into the tree
Pre:
Post: A contact in the tree will be updated
*/
void ContactList::update_contact()
{
	string buffer;
	Contact ret_val;

	cout << "Enter a contact that you want to change: ";
	getline (cin, buffer);
	Contact search (buffer, " " , " ");
	if (contacts.getEntry(search, ret_val)) //get the entry
	{
		cout << ret_val; 
		contacts.remove(ret_val); //delete the entry
		cout << "New name (enter for no change): ";
		getline (cin, buffer);
		if (buffer != "")
			ret_val.update_name(buffer);
		cout << "New phone (enter for no change): ";
		getline (cin, buffer);
		if (buffer != "")
			ret_val.update_phone_number(buffer);
		cout << "New website or email (enter for no change): ";
		getline (cin, buffer);
		cout << endl;
		if (buffer != "")
			ret_val.update_web_email(buffer);
		contacts.insert(ret_val);  //insert it back to the tree
	}
	else 
		cout << "Contact could not be found to be updated" << endl << endl;
	return;
}

/*
list_alphabetical_order will display on screen the binary tree in alpahbetical order
Pre:
Post: ""
*/
void ContactList::list_alphabetical_order()
{
	contacts.inOrder(display);
	return;
}

/*
list_reverse_alphabetical_order will display on-screen the binary tree in reverse
alphabetical order
Pre:
Post: ""
*/
void ContactList::list_reverse_alphabetical_order()
{
	contacts.reverseOrder(display);
	return;
}