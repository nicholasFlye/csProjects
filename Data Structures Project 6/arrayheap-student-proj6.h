/* CSI 3334
* Project  -- Network Broadcasting
* Filename: arrayheap-student-proj6.h
* Student name: Nicholas Flye
* Date: 12/15/2013
* Due Date: 12/11/2013
*
* This file contains the implementation of a heap array and its
* functions to maintain the heap order property.
*/
#ifndef ARRAY_HEAP_STUDENT_PROJ6_H
#define ARRAY_HEAP_STUDENT_PROJ6_H

#include "arrayheap-prof-proj6.h"
#include <algorithm>
#include <iostream>

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
    data = new Base[capacity];
    heapAndFreeStack = new int[capacity];
    dataToHeap = new int[capacity];
    for (int x = 0; x < capacity; x++){
        heapAndFreeStack[x] = x;
        dataToHeap[x] = x;
    }

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

    data = new Base[capacity];
    dataToHeap = new int[capacity];
    heapAndFreeStack = new int[capacity];

    capacity = h.capacity;
    numItems = h.numItems;

    for (int j = 0; j < capacity; j++){

        data[j] = h.data[j];
        heapAndFreeStack[j] = h.heapAndFreeStack[j];
        dataToHeap[j] = h.dataToHeap[j];

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

    delete[] data;
    delete[] heapAndFreeStack;
    delete[] dataToHeap;
    data = NULL;
    heapAndFreeStack = NULL;
    dataToHeap = NULL;

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
        delete[] dataToHeap;

        capacity = ah.capacity;
        numItems = ah.numItems;

        data = new Base[capacity];
        heapAndFreeStack = new int[capacity];
        dataToHeap = new int[capacity];

        for (int x = 0; x < capacity; x++){

            data[x] = ah.data[x];
            heapAndFreeStack[x] = ah.heapAndFreeStack[x];
            dataToHeap[x] = ah.dataToHeap[x];

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
int ArrayHeap<Base>::insert(const Base &item){

    if (numItems == capacity)
        doubleCapacity();
    data[heapAndFreeStack[numItems]] = item;
    dataToHeap[heapAndFreeStack[numItems]] = numItems;
    int key = heapAndFreeStack[numItems];
    bubbleUp(numItems);
    numItems++;

    return key;
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

    if (numItems > 1){
        swap(heapAndFreeStack[0], heapAndFreeStack[numItems - 1]);
        swap(dataToHeap[heapAndFreeStack[0]], dataToHeap[heapAndFreeStack[numItems - 1]]);
    }
    numItems--;
    bubbleDown(0);


}
/*
* getMinItem
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
* getNumItems
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
* the data stucture that holds the information that describes
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
    int* tempd_H = new int[capacity];
    for (int i = 0; i < this->capacity / 2; i++){

        temp[i] = data[i];
        tempd_H[i] = dataToHeap[i];
        tempH_F[i] = heapAndFreeStack[i];

    }

    delete[] data;
    delete[] heapAndFreeStack;
    delete[] dataToHeap;
    data = temp;
    heapAndFreeStack = tempH_F;
    dataToHeap = tempd_H;
    
    for (int x = numItems; x < this->capacity; x++){

        heapAndFreeStack[x] = x;

    }

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
        swap(dataToHeap[heapAndFreeStack[ndx]], dataToHeap[heapAndFreeStack[parent]]);
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

    int child1 = ndx * 2 + 1;
    int child2 = ndx * 2 + 2;

    if (child1 < numItems) {

        int lesserChild = child1;

        if ((child2 < numItems) && data[heapAndFreeStack[child2]]
            < data[heapAndFreeStack[child1]]){

            lesserChild = child2;

        }

        if (data[heapAndFreeStack[lesserChild]] < data[heapAndFreeStack[ndx]]) {

            swap(heapAndFreeStack[lesserChild], heapAndFreeStack[ndx]);
            swap(dataToHeap[heapAndFreeStack[lesserChild]],
                dataToHeap[heapAndFreeStack[ndx]]);
            bubbleDown(lesserChild);

        }
    }
}
/*
* isOnHeap
*
* This checks to see if a certain item still remains on the heap.
*
* Parameters: An integer representing the key of the item.
*
* Return value: boolean determining if item is still on the heap
*/
template<class Base>
bool ArrayHeap<Base>::isOnHeap(int key) const{

    bool onHeap = false;
    if(key < capacity)
        if(0 <= key)
            if(dataToHeap[key] < numItems)
                if(0 <= dataToHeap[key])
                     if(heapAndFreeStack[dataToHeap[key]] == key)
                            onHeap = true;
    return onHeap;

}
/*
* changeItemAtKey
*
* This function changes the item (or value) at a certain key
* on the heap. Bubble operations are performed to maintain the 
* heap order property.
*
* Parameters: An integer representing which key is to be
* changed. A new base item that is to be changed with the item already
* on the heap.
*
* Return value:
*/
template<class Base>
void ArrayHeap<Base>::changeItemAtKey(int key, const Base &newItem){

    if (isOnHeap(key)){
        data[key] = newItem;
        bubbleUp(dataToHeap[key]);
        bubbleDown(dataToHeap[key]);
    }

}

#endif
