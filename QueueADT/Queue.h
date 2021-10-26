#pragma once
#include <iostream>
#include <string>

class Queue
{
	public:
		Queue(int size);          //initialize the queue to a capacity of 'size' elelemts without values e.g. 50 elements 
		Queue(const Queue &q);    //copy constructor will make a duplicate queue from q
		~Queue();                 //Destructor
		void Enqueue(int item);   //add one item to the front of the queue
 		void Dequeue();           //remove one items from the fromt of the queue
		bool isFull();            //checks if the queue is full
		bool isEmpty();           //check if the queue is empty
		int Size();               //return the number of elements stored in the queue
		int FrontVal();           //return the value stored at the front of the queue
		int BackVal();            //retuen the value stored at the back of the queue 
		int PeekValue(int index); //retuen teh value store at location 'index' in the queue
		Queue& operator=(const Queue & q); //copy an existing queue - q - to a new instance of queue --> left hand side
		void PrintQueue();        //print the contents of a queue instance
		
	private:
		int* m_val;
		int  m_front_val;
		int  m_back_val;
		int  m_capacity;        //capacity of the queue assigned in the constructor
		int  m_count;           //the actual number of items stored in the queue
		int  m_max_size = 1000;
		int  m_empty_val = INT_MIN;
};

