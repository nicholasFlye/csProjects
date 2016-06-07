/* CSI 3334
 * Project  -- BFS Maze solver
 * Filename: arrayqueue-studentproj2.h
 * Student name: Nicholas Flye
 * Date: 10/6/2013
 * Due Date: 9/27/2013
 *
 * This file contains the source code of one function (main)
 * to solve a word melt puzzle using a breadth first search method.
 */
#ifndef ARRAY_QUEUE_STUDENT_PROJ2_H
#define ARRAY_QUEUE_STUDENT_PROJ2_H

#include "arrayqueue-prof-proj2.h"
#include <cassert>
/*
 * ArrayQueue
 *
 * This function is the constructor that initializes an array queue's
 * data members and allocates memory.
 * 
 * 
 * Parameters:
 *
 * Return value:
 */
template <class Base>
ArrayQueue<Base>::ArrayQueue(){
    length = 0;
    capacity = 4;
    data = new Base [capacity];
    front = 0;
}
/*
 * ArrayQueue (copy constructor)
 *
 * This function is the copy constructor which makes a deep copy
 * into this object.
 * 
 * Parameters:
 *
 * Return value:
 */
template <class Base>
ArrayQueue<Base>::ArrayQueue(const ArrayQueue<Base> &q){
    length = q.length;
    capacity = q.capacity;
    data = new Base [capacity];
    for(int i = 0; i < capacity; i++)
        data[i] = q.data[i];
}
/*
 * ~ArrayQueue
 *
 * The destructor de-allocates any memory allocated by the array queue.
 * 
 * Parameters:
 *
 * Return value:
 */
template <class Base>
ArrayQueue<Base>::~ArrayQueue(){
    delete [] data;
    data = NULL;
}
/*
 * add
 *
 * Adds an item to the array queue in the correct position that circularly
 * puts items in an index that will not exceed one less than the capacity or
 * an index that is a result of an array with the capacity doubled if the
 * array isn't full.
 * 
 * Parameters: const Base referenced item
 *
 * Return value: void
 */
template <class Base>
void ArrayQueue<Base>::add(const Base &item){
    int element = 0;
    if((front + length) >= capacity){
        doubleCapacity();
    }
    element = (front + length) % capacity;
    data[element] = item;
    length++;
}
/*
 * remove
 *
 * Remove simulates the removal of an item from the circular array queue
 * by changing the length and index known as the front of the queue.
 * 
 * Parameters:
 *
 * Return value: void
 */
template <class Base>
void ArrayQueue<Base>::remove(){
    front = (front + 1) % capacity;
    length--;
}
/*
 * getFront
 *
 * This function returns the front element of the array queue.
 * 
 * Parameters:
 *
 * Return value: const referenced Base that is the front item in
 * the queue.
 */
template <class Base>
const Base& ArrayQueue<Base>::getFront() const{
    return data[front];
}
/*
 * getLength
 *
 * This function returns the length of the queue.
 * 
 * Parameters:
 *
 * Return value: integer representing the length of the queue
 */
template <class Base>
int ArrayQueue<Base>::getLength() const{
    return length;
}
/*
 * operator=
 *
 * This function makes a deep copy of an array queue object into this
 * object using the assignment operator.
 * 
 * Parameters: const referenced array queue object
 *
 * Return value: referenced copy of this const array queue Base object
 */
template <class Base>
const ArrayQueue<Base>& ArrayQueue<Base>::operator=(const ArrayQueue<Base> &q){
    if(this != &q){
        length = q.length;
        capacity = q.capacity;
        delete [] data;
        data = new Base [capacity];
        for(int i = 0; i < capacity; i++)
            data[i] = q.data[i];
    }
    return *this;
}
/*
 * doubleCapacity
 *
 * This function doubles the capacity of the array queue object.
 * 
 * Parameters:
 *
 * Return value: void
 */
template <class Base>
void ArrayQueue<Base>::doubleCapacity(){
    capacity *= 2;
    Base* temp = new Base [capacity];
    int element = 0;
    for(int i = front; i < (front + length); i++){
        if(i == capacity - 1)
            element = (i + 1) % capacity;
        else 
            element = i;
        temp[i] = data[element];
    }
    delete [] data;
    data = temp;  
}

#endif
