/* CSI 3334
 * Project 1 -- DFS Maze solver
 * Filename: Location.cpp
 * Student name: Nicholas Flye
 * Date: 9/4/2013
 * Due Date: 9/5/2013
 *
 * This file contains the source code used to produce locations
 * in a maze using iterators to remember previously made decisions. 
 */
#include "location-proj1.h"

/*
 * Location
 *
 * This function is the constructor that initializes row, column, and nextDirection.
 * 
 * Parameters:
 *
 * Return value:
 */
Location::Location(){
    row = 0;
    col = 0;
    nextDirection = RIGHT;
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
void Location::start(void) const{
    nextDirection = RIGHT;
}
/*
 * nextNeighbor
 *
 * The nextNeighbor function creates a copy of a Location object, modifies
 * the copy so that it represents a different location (either in row or
 * column), and it advances its iterator state (so the next time it's
 * called it will do return a different neighbor).
 * 
 * Parameters:
 * void
 * 
 * Return value: returns the neighbor it created.
 */
Location Location::nextNeighbor(void) const{
    Location anotherLocation = *this;

    if(anotherLocation.nextDirection == anotherLocation.RIGHT){
        anotherLocation.col++;
        nextDirection++;
    }
    else if(anotherLocation.nextDirection == anotherLocation.DOWN){
        anotherLocation.row++;
        nextDirection++;
    }
    else if(anotherLocation.nextDirection == anotherLocation.LEFT){
        anotherLocation.col--;
        nextDirection++;
    }
    else if(anotherLocation.nextDirection == anotherLocation.UP){
        anotherLocation.row--;
        nextDirection++;
    }
    return anotherLocation;
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
    if(this->nextDirection == this->DONE)
        return true;
    else
        return false;
}
/*
 * operator==
 *
 * The operator== function allows the comparison of two Locations.
 * 
 * Parameters:
 *   &loc: a constant referenced Location
 * 
 * Return value: Boolean to compare two Locations.
 */
bool Location::operator==(const Location &loc) const{
    if(this->row == loc.row && this->col == loc.col)
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
    os << loc.row << " ";
    os << loc.col;
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
    is >> loc.row;
    is >> loc.col;
    return is;
}

/***************************************************************
* Mazes:
*
*MAZE_1
*  0 1 2 3 4 5
*0 S x         
*1   x x x     
*2         x   
*3         x E
*4            
*5             
*
*MAZE_2
*  0 1 2 3 4 5
*0 x   x x x S
*1 x x x      
*2 x          
*3 x x E      
*4            
*5             
*
*MAZE_3
*  0 1 2 3 4 5
*0 x x x x    
*1 x x   x    
*2   x   x x E
*3 S x          
*4            
*5             
*
*MAZE_4
*  0 1 2 3 4 5
*0 S x        
*1   x x      
*2     x x x E
*3     x      
*4     x      
*5             
*
*MAZE_5
*  0 1 2 3 4 5
*0   E x x x 
*1         x 
*2       x x  
*3       x    
*4       x    
*5 S x x x      
*
*MAZE_6
*  0 1 2 3 4 5
*0 x x x x x x
*1 x x x x   x
*2       S   E
*3            
*4            
*5             
*MAZE_7
*  0 1 2 3 4 5
*0 x          
*1 x x x S    
*2 x          
*3 x x        
*4 x          
*5 E           
*
*MAZE_8
*  0 1 2 3 4 5
*0 S x x x x 
*1   E     x x
*2   x   x x  
*3   x x x    
*4            
*5             
*
*MAZE_9
*  0 1 2 3 4 5
*0 x E        
*1 x x x x    
*2       x    
*3       x x x
*4           x
*5           S
*
*MAZE_10
*  0 1 2 3 4 5
*0       E  
*1       x  
*2   S   x x
*3   x   x    
*4   x x x   
*5 
***************************************************************/                      
