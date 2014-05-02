// Array implementation of Stack ADT
// Created by Frank M. Carrano and Tim Henry
// Modified by CNguyen

#ifndef _ARRAY_STACK
#define _ARRAY_STACK

#include "StackInterface.h"

const int MAX_STACK = 10;

template<class ItemType>
class ArrayStack : public StackInterface<ItemType>
{
private:	
	ItemType items[MAX_STACK]; // Array of stack items
	int      top;              // Index to top of stack
	int count; //number of elements in the array, initialize in constructor
	
public:
	ArrayStack() 
	{
		top = -1;
		count = 0;
	}  
	int size () const {return top+1;} //return count
	bool isEmpty() const {return (top == -1);}
	bool push(const ItemType& newEntry);
	bool pop();
	bool peek(ItemType & var) const;	
}; 

template<class ItemType>
bool ArrayStack<ItemType>::peek(ItemType & var) const
{
	bool success = false;	
	if (!isEmpty())
	{
		var = items[top];	
		success = true; 
	}
	else 
		success = false;
	return success;
}

template<class ItemType>
bool ArrayStack<ItemType>::push(const ItemType& newEntry)
{
	bool result = false;	
	if (top < MAX_STACK - 1)  
	{
		top++;
		items[top] = newEntry;
		count++;
		result = true;
	}  
	return result;
} 


template<class ItemType>
bool ArrayStack<ItemType>::pop()
{
	bool result = false;
	if (!isEmpty())  
	{
		top--;
		result = true;
		count--;
	} 
	return result;
}  
#endif