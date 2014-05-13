Background

In lab 3 we built a dictionary from a hashed table. In this lab we will build another look up table with the binary search tree. 
In data structures, a dictionary can also be called a map or an associative array. It allows the user to enter a unique key in order to lookup a value associated with that key.

Lab Overview
Use the BST ADT to build an associative array that serves as a contact list, to look up people's contact information.

Details
Data Record Class
- Each data record has 3 fields: a name string, a phone string, and a web/email address string. 
  The name and phone strings can contain spaces, ie. "Language Arts"
- The default input file is called in.txt, and is a list of names and associated contact information. 
   Each line has a name, a phone number, and a web address. All fields are separated by comma.
- The data’s name is the key, the contact info (both the phone and the web address) is the value

Contact List Class
-  The contact list has an instance of the BST that is filled with data from the input text file
-  The BST is ordered by names
-  The contact list has 4 public member functions (and other private or public functions as you see fit):

     List
     -  ask the user for alphabetical order or reverse alphabetical order
     -  print in the correct order all the names and associated contact info, in column format

     Delete:
     -  prompt for a name
     -  if the name is not found, print an error message
     -  if the name is found, remove the data record and print a confirmation message      

     Search:
     -  prompt for a name
     -  if the name is not found, print an error message and list all the names in alphabetical order
     -  if the name is found, print the name and all the contact info

     Update:
     -  prompt for a name
     -  if the name is not found, print an error message
     -  if the name is found, prompt the user for the name, phone, and web address. 
        The user can enter new information or hit Enter for no change


Binary Tree Class, Binary Search Tree Class, and Binary Node Class
-  Use these classes from the class exercise and add any necessary function
-  Don't delete or drastically change any of the existing functions
   For example, a recursive function should not be changed to an iterative function
-  Public member function prototypes should stay the same 
-  Your program must use all 3 files
-  When adding member functions, don't forget the OO philosophy that each class takes care of its own data. 
   For example, the Binary Search Tree should not call the accessors (the "get" functions) to get data from the Data Record class and print them. Instead, the Data Record should have a print member function, and the Binary Search Tree should call this function.

The main function
-  Instantiate a Contact List object
-  Loop to print a menu with choices:  (l) list, (d) delete, (s) search, (u) update, or (q) quit. 
    Re-prompt if you don’t have a valid character for the choice
-  Inside the loop, process the menu choices as described above until the user chooses 'q'


Testing
Test your program with both the default in.txt file and a file that you create. 
When I test your program, I will test with my own file.
Each line of the input file must have a name, followed by a phone and a web address, 
spaces can be in the field, and all fields are separated by comma.

Sample program output

Upload
All your files in a lab4.zip file

Honors Cohort Requirement
Add a menu choice for the user to add a new contact
-  prompt for the new name and contact info
-  if the name is already in the contact list, print an error message and don’t add

To earn credit, the add function cannot call the search function. 
Instead, the recursive insert function should be modified so it can catch when there is matching key in the BST and not add.