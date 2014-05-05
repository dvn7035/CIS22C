// Lab 3: look up dictionary
//        implemented as hashed table with linked list collision resolution
// Name: David Nguyen

#include <iostream>
#include <fstream>
#include <string>
#include "HashedTable.h"

using namespace std;

//lookup will open up a user's file and analyze to see how many words are and are not in the dictionary passed into it and will print the words not in the dictionary.
void lookup (HashedTable& dictionary)
{
	SortedList<Word>* check_word;
	string FileInput;
	string buffer;
	ifstream FileOpen;
	int hash_index;
	int NumWordsNotFound;
	int NumWordsFound;
	Word Dummy_Return;
	bool FileExist;

	cout <<endl <<"Please enter a file that you want to analyze or type \"quit\":  ";
	cin >> FileInput;
	while (FileInput != "quit")
	{
		FileOpen.open(FileInput);
		if (FileOpen.is_open())
		{
			cout << "The dictionary did not have these words:"<<endl;
			NumWordsNotFound = 0;
			NumWordsFound = 0;
			while (FileOpen >> buffer)
			{
				hash_index = dictionary.hashing (buffer);
				check_word = dictionary.GetListAtIndex (hash_index);
				Word Find (buffer, 1);			//1 is a dummy long long int value
				if (!check_word->getEntry(Find, Dummy_Return))
				{
					cout<<buffer<< endl;
					NumWordsNotFound++;
				}
				else 
					NumWordsFound++;
			}
			cout << endl<< "The dictionary had "<< NumWordsFound <<" words and did not have "<< NumWordsNotFound << " words."<<endl;
			FileOpen.close();
		}//end of is_open
		else 
			cout << "That file doesn't exist"<<endl;
		cout << "Please enter another file to analyze or (\"quit\"):  ";
		cin >> FileInput;
	}
	return;
}

int main()
{	
	HashedTable dictionary;
	dictionary.displayStats();
	lookup(dictionary);
	return 0;
} 