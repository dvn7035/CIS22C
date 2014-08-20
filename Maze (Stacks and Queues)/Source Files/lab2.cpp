// Lab 2: solve a maze
// Name: David Nguyen
// Date: 4/20/14

#include <iostream>
#include "Maze.h"

using namespace std;


int main ()
{
	Maze maze;
	
	cout << "Maze: ";
	maze.print();
	if ( maze.solved() )	
	{
		cout << "Solved mazed: ";
		maze.print();
		maze.print_Decision_Points();
	}
	else
		cout << "No solution\n";

	char stop;
	cin >> stop; 
	return 0;
}