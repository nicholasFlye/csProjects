/* CSI 3334
 * Project 1 -- DFS Maze solver
 * Filename: maze.cpp
 * Student name: Nicholas Flye
 * Date: 9/16/2013
 * Due Date: 9/13/2013
 *
 * This file contains the source code used to represent maze to be solved.
 */
#include "maze-proj1.h"

/*
 * Maze
 *
 * This function is the constructor that initializes the valid Locatin count 
 * and valid Locations.
 * 
 * Parameters:
 *
 * Return value:
 */
Maze::Maze(void){
    validLocationCount = 0;
    validLocations = NULL;
}
/*
 * ~Maze
 *
 * This function is the destructor that de-allocates memory used by this class.
 * 
 * Parameters:
 *
 * Return value:
 */
Maze::~Maze(){
    delete [] validLocations;
    validLocations = NULL;
}
/*
 * getStartLocation
 *
 * This function returns the starting location of the maze.
 * 
 * Parameters:
 * void
 * 
 * Return value: Starting location of the maze.
 */
Location Maze::getStartLocation(void) const{
    return startLocation;
}
/*
 * isValidLocation
 *
 * The isValidLocation function confirms with a boolean whether or 
 * not a Location is valid.
 * 
 * Parameters:
 * const Location &loc
 * 
 * Return value: Boolean value confirming if Location loc is a valid Location in the stack.
 */
bool Maze::isValidLocation(const Location &loc) const{
    bool isValid = false;
    for(int x = 0; x < validLocationCount; x++){
        if(loc == validLocations[x]){
            isValid = true;
        }
    }
    return isValid;
}
/*
 * isEndLocation
 *
 * The isEndLocation function confirms with a boolean whether or 
 * not a Location is the end location in the maze.
 * 
 * Parameters:
 * const Location &loc
 * 
 * Return value: Boolean value confirming if Location loc is the end Loctation in the maze.
 */
bool Maze::isEndLocation(const Location &loc) const{
    if(loc == endLocation)
        return true;
    else 
        return false;
}
/*
 * operator>>
 *
 * The operator>> function allows for a Location object to be streamed in.
 * 
 * Parameters:
 * &is: a referenced istream object used to stream in the maze.
 * &loc: a referenced maze object that is to be streamed in.
 * 
 * Return value: a referenced istream object to input a maze
 */
istream &operator>>(istream &is, Maze &m){
    is >> m.validLocationCount;
    if(m.validLocations != NULL){
        delete [] m.validLocations;
    }
    m.validLocations = new Location [m.validLocationCount];
    for(int x = 0; x < m.validLocationCount; x++){
        is >> m.validLocations[x];
    }    
    is >> m.startLocation;
    is >> m.endLocation;
    return is;
}
