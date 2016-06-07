/* CSI 3334
 * Project 1 -- DFS Maze solver
 * Filename: driver-proj1.cpp
 * Student name: Nicholas Flye
 * Date: 9/18/2013
 * Due Date: 9/13/2013
 *
 * This file contains the source code of one function (main)
 * to solve a maze using iterators.
 */
#include "maze-proj1.h"
#include "location-proj1.h"
#include "stack-proj1.h"
#include <iostream>

using namespace std;
/* main
 *  parameters:
 *
 *  return value: 0 (indicating a successful run)
 * 
 *  main will solve a maze which is identified by its own valid locations, starting,
 *  and ending location. main will keep track of its valid locations in a location stack.
 *  Once main has found a solution or not, a message will display with the correct solution.
 */
int main(){
    Maze maze;
    LocationStack locStack;
    Location location;
    bool done = false;
    //Read in the maze and all valid locations.
    cin >> maze;
    location = maze.getStartLocation();
    //Start the iterator and push the starting location on
    //top of the stack.
    location.start();
    locStack.push(location);
    
    while(!done){
        //While the current location is not done checking all
        //possible directions around it, check each neighbor and
        //push that neighbor on top of the stack if the neighbor is 
        //valid and not already on the stack.
        while (!locStack.getTop().isDone() && !maze.isEndLocation(locStack.getTop())){
            Location locNeighbor = locStack.getTop().nextNeighbor();
            if(maze.isValidLocation(locNeighbor)){
                if(!locStack.isOn(locNeighbor)){
                    locStack.push(locNeighbor);
                    locStack.getTop().start();
                }
            }
        }
        //If the current location is done iterating, check to see if the stack
        //is empty or if the current location is the ending location.
        if(maze.isEndLocation(locStack.getTop())){
            cout << "Solution found:" << endl;
            cout << locStack;
            done = true;
        }
        //Pop the top if the current location is done iterating over
        //all of its neighbors.
        locStack.pop();
        if(locStack.isEmpty() && !done){
            cout << "No solution found" << endl;
            done = true;
        }
    }
  
    return 0;
}
