#ifndef _WORD							//////////// documentation with your name
#define _WORD
#include<string>

using namespace std;

class Word
{
private: 
	string word_string;
	long long int word_count;
public:
	Word() {}
	Word (string input, long long int occurance) {word_string = input; word_count = occurance;}
	void set_word (string input) {word_string = input;}
	void set_count (int input) {word_count = input;}
	string get_word () {return word_string;}
	long long int get_count () {return word_count;}
	bool operator < (const Word& right) {return this->word_string < right.word_string;}
	bool operator > (const Word& right) {return this->word_string > right.word_string;}
	bool operator == (const Word& right) {return this->word_string == right.word_string;}
	bool operator != (const Word& right) {return this->word_string != right.word_string;}
	Word getItem() {return *this;}
	friend ostream& operator << (ostream& os, const Word& input);
};

ostream& operator << (ostream& os, const Word& input)
{
	os << input.word_string << " " << input.word_count << endl;
	return os;
}

#endif 