/*
This is the position class header file for Lab2.
Created by: David Nguyen
Date: 4/20/14
*/

#ifndef _POSITION
#define _POSITION

class Position
{
private: 
	int x;
	int y;
public:
	int getColumn () {return x;}
	int getRow() {return y;}
	void setColumn (int set_x) {x = set_x;}
	void setRow (int set_y) {y = set_y;}
};
#endif