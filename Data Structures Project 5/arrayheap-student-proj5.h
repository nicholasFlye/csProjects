/* CSI 3334
* Project  -- Batch Operating System
* Filename: arrayheap-student-proj5.h
* Student name: Nicholas Flye
* Date: 11/21/2013
* Due Date: 11/15/2013
*
* This file contains the implementation of a heap array and its
* functions to maintain the heap order property.
*/
#ifndef ARRAY_HEAP_PROJ5_STUDENT_H
#define ARRAY_HEAP_PROJ5_STUDENT_H

#include "arrayheap-prof-proj5.h"
#include <algorithm>

using namespace std;
/*
* ArrayHeap
*
* This function constructs a heap array and initializes all values.
*
* Parameters:
*
* Return value:
*/
template <class Base>
ArrayHeap<Base>::ArrayHeap(){
    
    numItems = 0;
    capacity = 15;
    data = new Base [capacity];
    heapAndFreeStack = new int [capacity];
    for (int x = 0; x < capacity; x++)
        heapAndFreeStack[x] = x;

}
/*
* ArrayHeap copy constructor
*
* This function creates a deep copy of a heap array object.
*
* Parameters: Constant heap array of type base that's passed by reference.
*
* Return value:
*/
template <class Base>
ArrayHeap<Base>::ArrayHeap(const ArrayHeap<Base> &h){

    capacity = h.capacity;
    numItems = h.numItems;
    for (int i = 0; i < capacity; i++){

        data[i] = h.data[i];

    }
    for (int x = 0; x < capacity; x++){

        heapAndFreeStack[x] = h.heapAndFreeStack[x];

    }

}
/*
* ~ArrayHeap
*
* This function deallocates all memory created by new and makes
* the data look empty.
*
* Parameters:
*
* Return value:
*/
template <class Base>
ArrayHeap<Base>::~ArrayHeap(){

    delete [] data;
    delete[] heapAndFreeStack;
    data = NULL;
    heapAndFreeStack = NULL;

}
/*
* operator=
*
* This function allows a deep copy of an object to be made.
*
* Parameters: Constant heap array of type base that's passed in by
* reference.
*
* Return value: Returns a copy of this object.
*/
template <class Base>
const ArrayHeap<Base> &ArrayHeap<Base>::operator=(const ArrayHeap<Base> &ah){

    if (this != &ah){
        delete[] data;
        delete[] heapAndFreeStack;
        capacity = ah.capacity;
        numItems = ah.numItems;
        for (int i = 0; i < capacity; i++){

            data[i] = ah.data[i];

        }
        for (int x = 0; x < capacity; x++){

            heapAndFreeStack[x] = ah.heapAndFreeStack[x];

        }
    }
    
    return *this;
}
/*
* insert
*
* This function inserts an item of type base into the heap array
* of minimum priority.
*
* Parameters: Constant base referenced item.
*
* Return value:
*/
template <class Base>
void ArrayHeap<Base>::insert(const Base &item){

    if (numItems == capacity)
        doubleCapacity();
    data[heapAndFreeStack[numItems]] = item;
    bubbleUp(numItems);
    numItems++;

}
/*
* removeMinItem
*
* This function removes an item of type base from the heap array
* that has the highest priority.
*
* Parameters:
*
* Return value:
*/
template <class Base>
void ArrayHeap<Base>::removeMinItem(){
    
    if (numItems > 1)
        data[heapAndFreeStack[0]] = data[heapAndFreeStack[numItems - 1]];
    numItems--;
    bubbleDown(0);


}
/*
* insert
*
* This function returns the highest priority in a minimum heap.
*
* Parameters:
*
* Return value: Item of type base from the front of the heap.
*/
template <class Base>
const Base &ArrayHeap<Base>::getMinItem() const{

    return data[heapAndFreeStack[0]];

}
/*
* insert
*
* This function returns the number of items in the heap.
*
* Parameters:
*
* Return value: Integer representation of the amount of data
* in the heap.
*/
template <class Base>
int ArrayHeap<Base>::getNumItems() const{

    return numItems;

}
/*
* doubleCapacity
*
* This function doubles the size of the heap and 
* the data structure that holds the information that describes
* the heap's structure.
*
* Parameters:
*
* Return value:
*/
template <class Base>
void ArrayHeap<Base>::doubleCapacity(){

    capacity *= 2;
    Base* temp = new Base[capacity];
    int* tempH_F = new int[capacity];
    for (int i = 0; i < this->capacity / 2; i++){

        temp[i] = data[i];

    }
    for (int i = 0; i < this->capacity / 2; i++){

        tempH_F[i] = heapAndFreeStack[i];

    }
    for (int x = capacity/2; x < this->capacity; x++){

        tempH_F[x] = x;
    }
    delete[] data;
    delete[] heapAndFreeStack;
    data = temp;
    heapAndFreeStack = tempH_F;

}
/*
* bubbleUp
*
* This function moves an index's data from lower down in
* the heap towards the root to maintain the heap order
* property.
*
* Parameters: An integer representing the index to be bubbled
* up.
*
* Return value:
*/
template <class Base>
void ArrayHeap<Base>::bubbleUp(int ndx){

    if (ndx == 0)
        return;
    int parent = (ndx - 1) / 2;
    if (data[heapAndFreeStack[ndx]] < data[heapAndFreeStack[parent]]){

        swap(heapAndFreeStack[parent], heapAndFreeStack[ndx]);
        bubbleUp(parent);

    }

}
/*
* bubbleDown
*
* This function moves an index's data from higher up in
* the heap towards the bottom to maintain the heap order
* property.
*
* Parameters: An integer representing the index to be bubbled
* down.
*
* Return value:
*/
template <class Base>
void ArrayHeap<Base>::bubbleDown(int ndx){
    
    int child1 = 2 * ndx + 1;
    int child2 = 2 * ndx + 2;
    int lesserChild = child1;

    if (data[heapAndFreeStack[child1]] < data[heapAndFreeStack[child2]]){
            
        lesserChild = child1;

    }
    if ((data[heapAndFreeStack[child2]] < data[heapAndFreeStack[lesserChild]]) 
        && (child2 < numItems)){

        lesserChild = child2;

    }
    if (data[heapAndFreeStack[lesserChild]] < data[heapAndFreeStack[ndx]]){

        swap(heapAndFreeStack[ndx], heapAndFreeStack[lesserChild]);
        if (lesserChild * 2 < numItems - 1)
            bubbleDown(lesserChild);
    }
}


#endif

