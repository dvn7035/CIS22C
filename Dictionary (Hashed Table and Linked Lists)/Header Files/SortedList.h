// Sorted Linked list ADT
//By David Nguyen and Ahmed Ahmed   /////////// you should work on your own for the labs
#ifndef _SORTED_LIST
#define _SORTED_LIST

#include "LinkedList.h"
#include "Node.h"

template<class ItemType>
class SortedList : public LinkedList<ItemType>
{
public:
	// Inserts an entry in the correct sorted order, position is ignored
	bool insert(const ItemType& newEntry, int newPosition = 1);
	// Removes an entry
	bool remove(const ItemType& anEntry);
	// Returns true for found, false for not found anEntry
	bool getEntry(const ItemType & target, ItemType & returnedEntry) const;
}; 

template<class ItemType>
bool SortedList<ItemType>::insert(const ItemType& newEntry, int newPosition)
{
	
	// create new node for newEntry
	Node<ItemType>* newNodePtr = new Node<ItemType>(newEntry);  
	Node<ItemType>* current = headPtr;
	Node<ItemType>* prev = current;

	if (itemCount == 0 ){
		headPtr = newNodePtr;
		newNodePtr->setNext(0);
		itemCount++;
		return true;
	} 

	while(current != 0 && current->getItem() < newEntry ){
		prev = current;
		current = current->getNext();
	}
	if(current == prev && current->getItem() > newEntry){
		newNodePtr->setNext(current);
		headPtr = newNodePtr;
		itemCount++;
		return true;
	}
	prev->setNext(newNodePtr);
	newNodePtr->setNext(current);
	itemCount++;
	return true;

}

template<class ItemType>
bool SortedList<ItemType>::remove(const ItemType& anEntry)
{
	bool found = false;
	Node<ItemType>* search = headPtr;
	Node<ItemType>* previous = NULL;
	while (search != NULL && found == false) {
		if (search->getItem() == anEntry)
			found = true;
		else {
			previous = search;
			search = search->getNext();
		}	
	}
	if (found) 
	{
		if (previous == NULL)
			headPtr = search->getNext();
		else
			previous->setNext(search->getNext());  
		itemCount--;
		delete search;
	}
	return found;
}  


template<class ItemType>
bool SortedList<ItemType>::getEntry(const ItemType & target, ItemType & returnedEntry) const
{
	bool found = false;
	Node<ItemType>* pos = headPtr;

	//walk array until entry greater than the current node
	while (pos != 0 &&  pos->getItem() < target )
	{
		pos = pos->getNext();
	}
 
	if (pos!= 0 && pos -> getItem() == target) 
	{
		returnedEntry = target;
		found = true;
	}
	return found;
}
#endif 