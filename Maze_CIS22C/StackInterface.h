// Stack abstract base class
// Created by Frank M. Carrano and Tim Henry
// Modified by CNguyen

#ifndef _STACK_INTERFACE
#define _STACK_INTERFACE

template<class ItemType>
class StackInterface
{
public:
	/** Gets the size of this stack
	@return: number of items in the stack */
	virtual int size() const = 0;

	/** Checks whether this stack is empty
    @return: True if the stack is empty, or false if not */
	virtual bool isEmpty() const = 0;
   
	/** Adds a new entry to the top of this stack
    @post: If the operation was successful, newEntry is at the top of the stack
    @param: newEntry, the object to be added as a new entry
    @return: True if the addition is successful or false if not */
	virtual bool push(const ItemType& newEntry) = 0;
   
	/** Removes the top of this stack
    @post: If the operation was successful, item at top of the stack has been removed
    @return: True if the removal is successful or false if not */
	virtual bool pop() = 0;
   
	/** Return the top of this stack
    @pre: The stack is not empty
    @post: The item at top of the stack has been copied, and the stack is unchanged
    @return: The copy of the top of the stack */
	//virtual ItemType peek() const = 0;
	virtual bool peek(ItemType &) const = 0; //reference
}; 
#endif