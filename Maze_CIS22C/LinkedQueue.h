// Linked list implementation of queue ADT
// Created by Frank M. Carrano and Tim Henry.
// Modified by CNguyen

#ifndef _LINKED_QUEUE
#define _LINKED_QUEUE

#include "QueueInterface.h"
#include "Node.h"

template<class ItemType>
class LinkedQueue : public QueueInterface<ItemType>
{
private:
   Node<ItemType>* backPtr;
   Node<ItemType>* frontPtr;
   int count;

public:
	LinkedQueue() {backPtr = 0; frontPtr = 0; count = 0;}
	LinkedQueue (const LinkedQueue& aQueue);
	~LinkedQueue();
	int size() const {return count;}
	bool isEmpty() const {return (count == 0);}
	bool enqueue(const ItemType& newEntry);
	bool dequeue();
	bool peekFront(ItemType& ret_object) const;
}; 

template<class ItemType>
bool LinkedQueue<ItemType>::peekFront (ItemType& ret_object) const
{
	bool success = false;
	if ( !isEmpty() )
	{
		ret_object = frontPtr->getItem();
		success = true;
	}
	return success;
}

template<class ItemType>
LinkedQueue<ItemType>::LinkedQueue(const LinkedQueue& aQueue)
{  
	Node<ItemType>* origChainPtr = aQueue.frontPtr;  // Points to nodes in original chain
   
	if (origChainPtr == 0)
	{
		frontPtr = 0;  // Original queue is empty
		backPtr = 0;
	}   
	else
	{
		frontPtr = new Node<ItemType>();
		frontPtr->setItem(origChainPtr->getItem());
		origChainPtr = origChainPtr->getNext(); 

		Node<ItemType>* newChainPtr = frontPtr;        // Points to first node in new chain
		while (origChainPtr != 0)
		{
			ItemType nextItem = origChainPtr->getItem();
			Node<ItemType>* newNodePtr = new Node<ItemType>(nextItem);  
			newChainPtr->setNext(newNodePtr); 
			newChainPtr = newChainPtr->getNext();
			origChainPtr = origChainPtr->getNext();
		}  
		newChainPtr->setNext(nullptr);               // Flag end of chain
		backPtr = newChainPtr;
	}  
}  


template<class ItemType>
LinkedQueue<ItemType>::~LinkedQueue()
{
	Node<ItemType>* nodePtr = frontPtr;
	while (frontPtr != 0)
	{
		frontPtr = frontPtr->getNext();
		delete nodePtr;
		nodePtr = frontPtr;
	}  
}  


template<class ItemType>
bool LinkedQueue<ItemType>::enqueue(const ItemType& newEntry)
{
	Node<ItemType>* newNodePtr = new Node<ItemType>(newEntry);	

	if (count == 0)
		frontPtr = newNodePtr;        
	else
		backPtr->setNext(newNodePtr); // Insertion into nonempty queue
   
	backPtr = newNodePtr;            // New node is at back
	count++;
	return true;
} 


template<class ItemType>
bool LinkedQueue<ItemType>::dequeue()
{
	if (count == 0)
		return false;
 
	Node<ItemType>* nodeToDeletePtr = frontPtr;
	if (frontPtr == backPtr)  // delete only node
	{  
		frontPtr = 0;
		backPtr = 0;
	}
	else // more than one node
		frontPtr = frontPtr->getNext();
		
	delete nodeToDeletePtr;
	count--;
	return true;
} 

#endif
