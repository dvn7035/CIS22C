// Linked List abstract base class
// By CNguyen

#ifndef _LINKED_LIST
#define _LINKED_LIST

#include "Node.h"

template<class ItemType>
class LinkedList 
{
protected:
   Node<ItemType>* headPtr; // Pointer to first node in the list
   int itemCount;           // Current count of list items 
   
public:
	// constructor
	LinkedList ()			{headPtr = 0; itemCount = 0;} 
	// copy constructor
	LinkedList(const LinkedList<ItemType>& aList);
	// destructor
	virtual ~LinkedList()	{clear();}

	// check for empty list
	bool isEmpty() const	{return itemCount == 0;}
	// get number of entries in the list
	int size() const		{return itemCount;}
	// remove all entries from list
	void clear();
	// display list from front to end
	void display() const;
	// abstract insert function
	virtual bool insert(const ItemType& newEntry, int newPosition = 1) = 0;	//default position
}; 

template<class ItemType>
LinkedList<ItemType>::LinkedList(const LinkedList<ItemType>& aList)
{
	itemCount = aList.itemCount;
	Node<ItemType>* origChainPtr = aList.headPtr;  // Points to nodes in original list

	if (origChainPtr == 0)
		headPtr = 0;  // Original list is empty
	else
	{
		headPtr = new Node<ItemType>();		// copy first node
		headPtr->setItem(origChainPtr->getItem());
      
		// Copy remaining nodes
		Node<ItemType>* newChainPtr = headPtr;      
		origChainPtr = origChainPtr->getNext();     
		while (origChainPtr != 0)
		{
			ItemType nextItem = origChainPtr->getItem();
			Node<ItemType>* newNodePtr = new Node<ItemType>(nextItem);  
			newChainPtr->setNext(newNodePtr); 
			newChainPtr = newChainPtr->getNext();
			origChainPtr = origChainPtr->getNext();
		} 
		newChainPtr->setNext(0);              // Flag end of list
	}  
} 


template<class ItemType>
void LinkedList<ItemType>::display() const
{
	Node<ItemType>* currPtr = headPtr;		// start at front of list
	while (currPtr != 0)					// walk until end of list
	{
		cout << currPtr->getItem() << " ";	// display data of every node
		currPtr = currPtr->getNext();		// go to next node
	}
	cout << endl << endl;
} 


template<class ItemType>
void LinkedList<ItemType>::clear() 
{

	Node<ItemType> * deletePtr;
	for (int i = 1; i <= itemCount; i++) // walk each node or for (int i = 0; i < itemCount; i++) 
	{
		deletePtr = headPtr;			// delet PTR points to head..remove each node
		headPtr = headPtr->getNext();	//head pointer points to the next pointer
		delete deletePtr;				//deletes what used to be head
	}//head will be 0 or null at the end
	itemCount = 0;
} 
#endif 
