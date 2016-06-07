/* CSI 3334
 * Project 2 -- BFS Maze solver
 * Filename: maze-proj2.cpp
 * Student name: Nicholas Flye
 * Date: 10/2/2013
 * Due Date: 9/27/2013
 *
 * This file contains the source code of one function (main)
 * to solve a word melt puzzle using a breadth first search method.
 */
#include "maze-proj2.h"
/*
 * Maze
 *
 * This function is the constructor that constructs a maze object.
 * 
 * Parameters:
 *
 * Return value:
 */
Maze::Maze(void){
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
    if(validLocations.find(loc) != validLocations.end())
        return true;
    else
        return false;
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
 * Return value: Boolean value confirming if Location loc is the end Location in the maze.
 */
bool Maze::isEndLocation(const Location &loc) const{
    if(validLocations.find(loc) == validLocations.find(endLocation))
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
    Location wordLocation;
    int validLocationCount = 0;
    is >> validLocationCount;
    if(!m.validLocations.empty())
        m.validLocations.clear();
    for(int x = 0; x < validLocationCount; x++){
        is >> wordLocation;
        m.validLocations.insert(wordLocation);
    }
    is >> m.startLocation;
    is >> m.endLocation;
    
    return is;
}