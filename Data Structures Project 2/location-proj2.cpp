/* CSI 3334
 * Project 2 -- BFS Maze solver
 * Filename: location-proj2.cpp
 * Student name: Nicholas Flye
 * Date: 10/2/2013
 * Due Date: 9/27/2013
 *
 * This file contains the source code of one function (main)
 * to solve a word melt puzzle using a breadth first search method.
 */
#include "location-proj2.h"

/*
 * Location
 *
 * This function is the constructor that initializes word, iteration
 * mode and next letter.
 * 
 * Parameters:
 *
 * Return value:
 */
Location::Location(){
    nextLetter = 'a';
    word = "word";
    iterationMode = CHANGE_LETTER;
    indexToChange = 0;
}
/*
 * start
 *
 * The start function initializes the iteration capability of a Location object.
 * 
 * Parameters:
 * void
 * 
 * Return value: void
 */
void Location::start(void){
    iterationMode = CHANGE_LETTER;
    nextLetter = 'a';
    indexToChange = 0;
}
/*
 * nextNeighbor
 *
 * The nextNeighbor function creates a copy of a Location object, modifies
 * the copy so that it represents a different location, 
 * and it advances its iterator state (so the next time it's
 * called it will return a different neighbor).
 * 
 * Parameters:
 * void
 * 
 * Return value: returns the neighbor it created.
 */
Location Location::nextNeighbor(void){
    const int ALPHABET_SIZE = 26;
    Location copy = *this;
    
    if(iterationMode == CHANGE_LETTER){
        int x = 0;
        if(x <= ALPHABET_SIZE){
            copy.word[indexToChange] = nextLetter;
            x++;
            nextLetter++;
            if(nextLetter == word[indexToChange]){
                nextLetter++;
            }
        }
        if(nextLetter == '{'){
            indexToChange++;
            nextLetter = 'a';
        }
        else if(indexToChange >= word.size()){
            iterationMode++;
            indexToChange = 0;
            nextLetter = 'a';
        }
    }
    else if(iterationMode == INSERT_LETTER){
        int x = 0;
        if(x <= ALPHABET_SIZE){
            copy.word.insert(indexToChange, 1, nextLetter); 
            nextLetter++;
        }
        if(nextLetter == '{'){
            indexToChange++;
            nextLetter = 'a';
        }
        if(indexToChange == word.size() + 1)
        iterationMode++;
    }
    else if(iterationMode == DELETE_LETTER){
        if(indexToChange >= word.size())
            indexToChange = 0;
        copy.word.erase(indexToChange, 1);
        indexToChange++;
        if(indexToChange >= word.size())
            iterationMode++;
    }
    return copy;
}
/*
 * isDone
 *
 * The isDone function checks to see if all neighbors have been visited.
 * 
 * Parameters:
 * void
 * 
 * Return value: Returns true if all neighbors have been visited which is noticeable
 * from the enumerated data type.
 */
bool Location::isDone(void) const{
    if(this->iterationMode == this->DONE)
        return true;
    else
        return false;
}
/*
 * operator==
 *
 * The operator== function allows the comparison of two Locations to see if they
 * are equal.
 * 
 * Parameters:
 *   &loc: a constant referenced Location
 * 
 * Return value: Boolean to compare two Locations.
 */
bool Location::operator==(const Location &loc) const{
    if(this->word == loc.word)
        return true;
    else
        return false;
}
/*
 * operator<
 *
 * The operator< function allows the comparison of two Locations to see if they
 * one location is less than the other.
 * 
 * Parameters:
 *   &loc: a constant referenced Location
 * 
 * Return value: Boolean to compare two Locations.
 */
bool Location::operator<(const Location &loc) const{
    if(loc.word < this->word)
        return true;
    else 
        return false;
}
/*
 * &operator<<
 *
 * The &operator<< function allows for a Location object to be streamed out.
 * 
 * Parameters:
 * &os: a referenced ostream object used to stream out the Location.
 * &loc: a referenced Location object that is to be streamed out.
 * 
 * Return value: a referenced ostream object to output a Location
 */
ostream& operator<<(ostream &os, const Location &loc){
    os << loc.word;
    return os;
}
/*
 * operator>>
 *
 * The operator>> function allows for a Location object to be streamed in.
 * 
 * Parameters:
 * &is: a referenced istream object used to stream in the Location.
 * &loc: a referenced Location object that is to be streamed in.
 * 
 * Return value: a referenced istream object to input a Location
 */
istream& operator>>(istream &is, Location &loc){
    is >> loc.word;
    return is;
}                 
