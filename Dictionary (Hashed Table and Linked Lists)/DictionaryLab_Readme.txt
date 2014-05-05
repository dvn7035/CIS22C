Write a program that builds a dictionary of common English words for look up purpose.

The input file
The input file is called wordcount.txt and has about 1300 of the most commonly used English words (source: https://github.com/first20hours/google-10000-english). These words are about 5% of the vocabulary of an average English speaker. 
Each line of the file is a word in lowercase, a space, and the number of times the word appears in a statistical sample of text documents.

The hashed array
The hashed array is created as a local array in main.cpp, which you should down load and add code to it.
Part of the lab assignment is to experiment with the size of the array, so make sure you create a constant for the array size so it’s easy to change.
The hashed table uses linked list collision resolution.

The linked list
The linked lists used in the hashed table are sorted in alphabetical, ascending order.
You should use the SortedList.h file for the linked list.

Reading in data
Create a data record class that can store a word and the count of the word.
main.cpp instantiates the hashed table, and the constructor of the hashed table reads in data from the file into the hashed array.
Each line of the input file is read into an object of the data record class, and the data record object is stored in the hashed table.

Storing data in the hashed table
Use each word as the key for the hashing function.
When the dictionary is created, main calls a function to print the statistics for the dictionary:
- the total number of words
- the size of the array
- the load factor
- all the indexes that have collision and the number of probes
- the total number of words that have no collision
- the longest length of the linked lists
- for each list that has the longest length, print the index, and all the words and their counts that are in the list
(see the sample program output)

Hashing function
Come up with your own hashing function and then use the printed statistics to refine it. 
Feel free to calculate and print more statistical data to help refine the hashing function.
Change the load factor and / or your hashing function to come up with the “best” hashed table you can. 
The best hashed table is one that balances the size of the array (don’t want an array of 100,000 elements)
and the number of probes (don’t want the probes to be too high)

When you’re happy with the performance of the hashing function, write a short comment block above the 
hashing function code to explain:
-  What hashing algorithm(s) you used
- The reason you chose your hashing function
Explain in terms of the number of probes, any clustering, and the size of the array. 
This means your explanation should justify your hashing function by using these terms as they apply to your hash statistics.

User interaction
After printing the statistics, the program interacts with the user by allowing the user to keep entering a text file name.
The filename the user enters is for a text file with only words (no numbers or punctuation marks). 
Words are separated by white space.

With every file that the user enters:
- check for words in the given file that are not in the dictionary 
- print out words from the file that are not found
- print the number of words that are not found
(see the sample program output)

Test
There are 2 input test files for you to use in addition to files that you come up with.
words1.txt is a few lines of the song “The Sun Will Come Out Tomorrow” from the musical Annie
words2.txt is a short excerpt from Steve Jobs’ commencement speech at Stanford that you may find relevant

 Sample output

Turn in
A zip file with: all files except the input text files and LinkedList.h abstract class. 
I will use the same LinkedList.h that you have and I will use my own text file.

Honors Additional Requirement
Add code to the User Interaction portion of the program to allow the user a menu choice of:
-  checking words in a file (the standard requirement described above)
-  deleting a word from the dictionary
-  adding a word to the dictionary: if the word already exists in the dictionary, let the user know that it won’t be added

You can choose how the user ends the menu loop, but prompt clearly so I don’t have to use control-c when I test your program