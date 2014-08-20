// Maze class implementation file
// Name: David Nguyen

#include "Maze.h"

// constructor for maze
// if you add member data, don't forget to initialize them
Maze::Maze()
{
	ifstream infile;
	string fname;
	int i, j;

	infile.open("maze.txt");
	while (!infile)  // check for file open success or prompt for filename
	{
		cout << "Error opening maze file\nEnter filename: ";
		cin >> fname;
		infile.open (fname.c_str());
	}

	for (i = 0; i < MAX; i++)		  // for each row
		for (j = 0; j < MAX; j++)
			infile >> matrix[i][j];   // read in each character in row
	Current.setRow (0);
	Current.setColumn (0);
}

// print maze as an 8x8 matrix
void Maze::print() const
{
	int i, j;
	cout << endl;
	for (i = 0; i < MAX; i++)
	{
		for (j = 0; j < MAX; j++)
			cout << setw(2) << matrix[i][j];
		cout << endl;
	}
	cout << endl;
}
// atEnd () will check to see if the current position is the end point if so
// it will return true and the end point will be marked
bool Maze::atEnd (Position Current)
{
	bool end = false;
	if (Current.getColumn() == (MAX-1) && Current.getRow() == (MAX-1) )
	{
		end = true;
		matrix[MAX-1][MAX-1] = '+';
	}
	return end; 
}

// countAvailablePaths () will count how many paths can be taken from the current position
// and return it
int Maze::countAvailablePaths (bool& bottom, bool& right, bool& left, bool& top)
{
	int paths = 0;
	int curCol = Current.getColumn();
	int curRow = Current.getRow();
	if (curRow+1 < MAX && matrix[curRow+1][curCol] == '.' )  //bottom is clear
	{
		paths++;
		bottom = true;
	}
	if ( curCol+1 < MAX && matrix[curRow][curCol+1] == '.')  //right is clear
	{
		paths++;
		right = true;
	}
	if (curCol-1 >= 0 && matrix[curRow][curCol-1] == '.') //left is clear
	{
		paths++;
		left = true;
	}
	if (curRow-1 >= 0 && matrix[curRow-1][curCol] == '.') //top is clear
	{
		paths++;
		top = true;
	}
	return paths;
}

// solved () goes through the algorithm for checking if there are any paths to take 
// and returns true if the maze is solvable or false if it is unsolvable
bool Maze::solved () 
{
	int pathCount;
	bool solvable = true;
	int curCol;
	int curRow;
	bool topClear;
	bool bottomClear;
	bool rightClear;
	bool leftClear;

	while ( !atEnd(Current) && solvable)
	{
		curCol = Current.getColumn();
		curRow = Current.getRow();
		matrix[curRow][curCol] = '+';
		topClear = bottomClear = rightClear = leftClear = false;
		pathCount = countAvailablePaths(bottomClear, rightClear, leftClear, topClear);
		if (pathCount > 1)
		{
			Decision_Stack.push (Current);
			Decision_Queue.enqueue (Current);
		}
		if (pathCount >= 1)
		{
			if (bottomClear) //bottom is clear
			{
				Current.setRow(curRow + 1);
			}
			else if (rightClear) //right is clear
			{
				Current.setColumn(curCol+1);
			}
			else if (leftClear) //left is clear
			{
				Current.setColumn(curCol-1);
			}
			else if (topClear) //top is clear
			{
				Current.setRow(curRow - 1);
			}
		}
		else 
		{
			if (!Decision_Stack.isEmpty())
			{
				Decision_Stack.peek(Current);
				Decision_Stack.pop();
			} 
			else //(Decision_Stack.isEmpty())
				solvable = false;
		}
	}
	return solvable;
}

// print_Decision_Points () prints all decisions points from the queue
void Maze::print_Decision_Points ()
{
	Position dec_points;
	cout<<"Decisions points are"<<endl<<"X Y"<<endl;
	while (!Decision_Queue.isEmpty())
	{
		Decision_Queue.peekFront (dec_points);
		cout<< dec_points.getRow()<<" "<<dec_points.getColumn() <<endl;
		Decision_Queue.dequeue();
	}
}