#ifndef _HASHED_TABLE          
#define _HASHED_TABLE
#define HASHTABLESIZE  2687
#include <vector>
#include <cmath>
#include <fstream>
#include <iostream>
#include "SortedList.h"
#include "List.h"
#include "Word.h"

using namespace std;

class HashedTable 
{
private:
	SortedList<Word> array[HASHTABLESIZE];
	int total_number_of_words;
	float load_factor;
	int words_with_no_collsion;
public:
	HashedTable();
	int hashing (string input);
	void displayStats();
	SortedList<Word> GetListAtIndex (int index) {return array[index];}
	bool contains(Word find);
	~HashedTable();
};

//////////////////// all these functions should be in HashedTable.cpp   -1pt

//HashedTable's constructor dynamically allocates a list to all elements of the array, initalizes it's statistics to zero, and fills the array with words from the dictionary
HashedTable::HashedTable () : total_number_of_words (0) , load_factor (0), words_with_no_collsion (0)

{
	ifstream inputfile;
	string input;
	long long int occurance;
	int index;

	inputfile.open ("wordcount.txt"); 
	while (inputfile >> input >> occurance)
	{
		Word next (input, occurance);
		index = hashing (input);
		array[index].insert(next);	 
		total_number_of_words++;
	}
	inputfile.close();
}
/*
This hashing algorithm uses the sum of the cube of every ASCII value letter as the index.  If the number is larger than the array a % operation is done on the index
so that it can fit in the array.  The size of the array is 2687 because it is about twice the actual amount of elements as well as being prime.  Having the array be a
prime number gives more unique index (and thus a more even spread) when it is used as a moduluo divisor.  I was satisfied with this algorithm because the max probe was 3
and the majority of the probes were either 0, 1, or 2 making retrival easier.  The load factor was almost 40%, but I wished it was higher to be near 50-60% so that words 
were more evenly distributed with less clustering and so that less space would be wasted.

////////// good analysis

*/
int HashedTable::hashing (string input)
{
	int index = 0;
	int cube;
	for (size_t i = 0; i < input.length(); i++)
	{
		cube = (int) pow(input[i],3.0);
		index += cube;
	}
	if (index >= HASHTABLESIZE)
	{
		index = index % HASHTABLESIZE;
	}
	return index;
}

//displayStats shows and calculates the total number of words, collisions, load factor, and number of words without collisions 
void HashedTable::displayStats ()
{
	int i;
	int longest_list = 0;
	List<int> longest_list_indicies;
	cout <<"Here are the following statistics for this dictionary hash table"<<endl<<endl<<"Collisions:"<<endl;
	for (i = 0; i < HASHTABLESIZE; i++)
	{
		if (array[i].size() > 0) //if the list has at least one item, increment load factor
		{
			load_factor++;
		}

		if (array[i].size() > 1) //if the list has more than one elment, there are collisions
		{
			cout << "Index " << i << " has "<< (array[i].size() -1) << " probe(s)" <<endl;
		}

		if (array[i].size() == 1)  //if the list only has one element it is a word without collisions
		{
			words_with_no_collsion++;
		}
			
		if (array[i].size() >= longest_list) //get the value of the longest list size
		{
			if (array[i].size() > longest_list)
			{
				longest_list = array[i].size();
				longest_list_indicies.clear();
			}
			longest_list_indicies.insert(i);
		}

	}
	cout << endl;

	for (i = 1; i <= longest_list_indicies.size(); i++)
	{
		int holding_index;
		longest_list_indicies.getEntry(i, holding_index);
		cout << "Index " << holding_index << " has the (or is one of the) longest lists and it has the words:" << endl;
		array[holding_index].display();
	}
	cout <<"There are "<< total_number_of_words <<" words"<<endl;
	cout <<"The size of the hashed table is "<<HASHTABLESIZE<<endl;
	cout <<"There are "<< words_with_no_collsion << " words with no collisions "<< endl; 
	load_factor = (load_factor/HASHTABLESIZE)*100;
	cout << "The load factor is "<< load_factor <<"%" << endl;
	return;
}

bool HashedTable::contains(Word find)
{
	Word dummy_return;
	return array[hashing(find.get_word())].getEntry(find, dummy_return);
}

//HashedTable's destructor will go through the entire array and deallocate all the lists
HashedTable::~HashedTable()
{
	for (int i = 0 ; i < HASHTABLESIZE; i++)
	{
		array[i].clear();  
	}
}
#endif