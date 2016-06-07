/* CSI 3334
 * Project 1 -- DFS Maze solver
 * Filename: locationStack.cpp
 * Student name: Nicholas Flye
 * Date: 9/19/2013
 * Due Date: 9/13/2013
 *
 * This file contains the source code of two classes used
 * to hold visited locations to help solve the maze.
 */
#include "stack-proj1.h"
/*
 * LocationStack
 *
 * This function is the constructor that initializes the top locationStackNode.
 * 
 * Parameters:
 *
 * Return value:
 */
LocationStack::LocationStack(void){
    top = NULL;
}
/*
 * ~LocationStack
 *
 * This function is the destructor that frees allocated memory.
 * 
 * Parameters:
 *
 * Return value:
 */
LocationStack::~LocationStack(){
    delete top;
}
/*
 * push
 *
 * This function pushes a location on top of the stack.
 * 
 * Parameters: A constant location object that represents visited locations.
 *
 * Return value:
 */
void LocationStack::push(const Location &loc){
    LocationStackNode* newNode = NULL;
    if(top == NULL)
        top = new LocationStackNode (loc, newNode);
    else{
        LocationStackNode* prevNode;
        prevNode = top;
        top = new LocationStackNode (loc, prevNode);
    }
}
/*
 * pop
 *
 * This function pops a location off the top of the stack.
 * If the stack is empty, return.
 *
 * Parameters:
 *
 * Return value:
 */
void LocationStack::pop(void){
    LocationStackNode* temp;
    LocationStackNode* temp2 = NULL;
    if(top == NULL)
        return;
    else{
        temp = top;
        top = top->getNextNode();
        temp->setNextNode(temp2);
        delete temp;
    }
}
/*
 * getTop
 *
 * This function returns the location of the top of the locationStack.
 * 
 * Parameters:
 *
 * Return value: A constant referenced location that is on the top of the stack.
 */
const Location& LocationStack::getTop(void) const{
    if(top == NULL){
        assert(false);
    }
    else
        return top->getLocation();
}
/*
 * isEmpty
 *
 * This function proves whether or not the stack is empty.
 * 
 * Parameters:
 *
 * Return value: A boolean value that proves either 
 * the stack is empty or contains values
 */
bool LocationStack::isEmpty(void) const{
    if(top == NULL)
        return true;
    else
        return false;
}
/*
 * isOn
 *
 * This function sees whether or not a location is on the stack.
 * 
 * Parameters: A constant location object
 *
 * Return value: Returns a boolean that confirms whether or not a location is on
 * the stack of visited locations.
 */
bool LocationStack::isOn(const Location &loc) const{
    LocationStackNode* lookAt = top;
    bool isValid = false;
    while(lookAt){
        if(lookAt->getLocation() == loc)
            isValid = true;
        lookAt = lookAt->getNextNode();
    }
    return isValid;
}
/*
 * &operator<<
 *
 * The &operator<< function allows for a LocationStack object to be streamed out.
 * 
 * Parameters:
 * &os: a referenced ostream object used to stream out the LocationStack.
 * &loc: a referenced LocationStack object that is to be streamed out.
 * 
 * Return value: a referenced ostream object to output a LocationStack
 */
ostream &operator<<(ostream &os, const LocationStack &s){
    LocationStackNode* thisNode = s.top; 
    LocationStackNode* nextNext = NULL;
    LocationStackNode* anotherNode = thisNode;

    while(anotherNode){
        thisNode = anotherNode->getNextNode();
        anotherNode->setNextNode(nextNext);
        nextNext = anotherNode;
        anotherNode = thisNode;
    }
    while(nextNext){
        os << nextNext->getLocation() << endl;
        thisNode = nextNext->getNextNode();
        nextNext->setNextNode(anotherNode);
        anotherNode = nextNext;
        nextNext = thisNode;
    }
        
    return os;
}
/*
 * LocationStackNode
 *
 * This function is the constructor that initializes location and nextNode.
 * 
 * Parameters:
 *
 * Return value:
 */
LocationStackNode::LocationStackNode(const Location &loc, LocationStackNode *next){
    location = loc;
    nextNode = next;
}
/*
 * ~LocationStackNode
 *
 * This function is the destructor that frees any allocated memory.
 * 
 * Parameters:
 *
 * Return value:
 */
LocationStackNode::~LocationStackNode(){
    delete nextNode;
}
/*
 * getLocation
 *
 * This function gets the location of the node that called it.
 * 
 * Parameters:
 *
 * Return value: A constant location reference to that particular node.
 */
const Location & LocationStackNode::getLocation() const{
    return location;
}
/*
 * getNextNode
 *
 * This function gets the nextNode of the node that called it.
 * 
 * Parameters:
 *
 * Return value: Returns a locationStackNode pointer that points to the nextNode;
 */
LocationStackNode * LocationStackNode::getNextNode() const{
    return nextNode;
}
/*
 * setNextNode
 *
 * This function sets the nextNode for the node that called it.
 * 
 * Parameters: LocationStackNode pointer to the node that is going to be the nextNode.
 *
 * Return value:
 */
void LocationStackNode::setNextNode(LocationStackNode *next){
    nextNode = next;
}
