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
	string FileInput;
	string buffer;
	ifstream FileOpen;
	int NumWordsNotFound;
	int NumWordsFound;
	Word Dummy_Return;
	SortedList<string> WordsNotFound;

	cout <<endl <<"Please enter a file that you want to analyze or type \"quit\":  ";
	cin >> FileInput;
	while (FileInput != "quit")
	{
		FileOpen.open(FileInput);
		if (FileOpen.is_open())
		{
			NumWordsNotFound = 0;
			NumWordsFound = 0;
			while (FileOpen >> buffer)
			{
				Word Find (buffer, 1);			//1 is a dummy long long int value
				if (!dictionary.contains(Find))
				{
					WordsNotFound.insert(buffer);
					NumWordsNotFound++;
				}
				else 
					NumWordsFound++;
			}
			cout << endl<< "The dictionary had "<< NumWordsFound <<" words and did not have "<< NumWordsNotFound << " words."<<endl;
			cout << "The dictionary did not have these words:" << endl;
			WordsNotFound.display();
			WordsNotFound.clear();
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