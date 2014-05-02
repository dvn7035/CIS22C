// Queue abstract base class
// Created by Frank M. Carrano and Tim Henry.
// Modified by CNguyen

#ifndef _QUEUE_INTERFACE
#define _QUEUE_INTERFACE

template<class ItemType>
class QueueInterface

{
public:
   /** Checks whether this queue is empty
    @return: True if the queue is empty, or false if not */
   virtual bool isEmpty() const = 0;
   
   /** Adds a new entry to the back of this queue
    @post: newEntry is at the back of the queue
    @param: newEntry, the object to be added as a new entry
    @return: True if successful, false if not */
   virtual bool enqueue(const ItemType& newEntry) = 0;
   
   /** Removes the front of this queue
    @post: data at the front of the queue is removed
    @return: True if successful, false if not */
   virtual bool dequeue() = 0;
   
   /** Returns the front of this queue
    @pre: The queue is not empty
    @post: no change to the queue
    @return: A copy of the front of the queue */
   virtual bool peekFront(ItemType& ret_object) const = 0;
}; 
#endif
