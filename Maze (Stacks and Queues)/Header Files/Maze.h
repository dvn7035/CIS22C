// Maze class header file
// Name: David Nguyen

#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>
#include "LinkedQueue.h"
#include "ArrayStack.h"
#include "Position.h"

using namespace std;

const int MAX = 8;

class Maze
{
private:
	char matrix[MAX][MAX];       // 2D array of characters for the maze
	class Position Current;
	ArrayStack<Position> Decision_Stack;
	LinkedQueue<Position> Decision_Queue;
public:
	Maze(); 
	void print() const;
	void print_Decision_Points ();
	bool solved ();
	bool atEnd (Position Current);
	int countAvailablePaths ();
};