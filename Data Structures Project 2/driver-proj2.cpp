/* CSI 3334
 * Project  -- BFS Maze solver
 * Filename: driver-proj2.cpp
 * Student name: Nicholas Flye
 * Date: 10/6/2013
 * Due Date: 9/27/2013
 *
 * This file contains the source code of one function (main)
 * to solve a word melt puzzle using a breadth first search method.
 */
#include <iostream>
#include <map>
#include <cassert>
#include "location-proj2.h"
#include "maze-proj2.h"
#include "arrayqueue-student-proj2.h"

using namespace std;
/* main
 *  parameters:
 *
 *  return value: 0 (indicating a successful run)
 * 
 *  main will solve a word melt puzzle which is identified by its own valid
 *  locations(dictionary), starting,and ending location. main will keep track
 *  of its valid locations in a valid locations set. Once main has found a
 *  solution or not, a message will display with the correct solution.
 */
int main(){
    Location loc, locNeighbor, endLocation, checkLocation, startLoc;
    Maze maze;
    map<Location, Location> wordMap;
    map<Location, Location> printMap;
    map<Location, Location>::iterator lookAt;
    ArrayQueue<Location> queue;
    
    //Read in the maze and all valid locations.
    cin >> maze;
    loc = maze.getStartLocation();
    startLoc = maze.getStartLocation();
    //Start the iterator and push the starting location into the
    //queue. Map the starting location to itself.
    loc.start();
    wordMap[loc] = loc;
    queue.add(loc);
    
    //While the current location is not done checking all
    //possible directions around it, check each neighbor and
    //add that neighbor on to the queue if the neighbor is 
    //valid and has not already been visited.
    while(!maze.isEndLocation(endLocation) && queue.getLength() != -1){
        while(!loc.isDone()){
            locNeighbor = loc.nextNeighbor();
            if(locNeighbor == loc){
                locNeighbor = loc.nextNeighbor();
            }
            if(maze.isValidLocation(locNeighbor)){
                if(wordMap.find(locNeighbor) == wordMap.end()){
                    wordMap[locNeighbor] = loc;
                    queue.add(locNeighbor);
                    if(maze.isEndLocation(locNeighbor))
                        endLocation = locNeighbor;
                }
            }
        }
        //Remove that location from the front of the queue once
        //all neighbors have been iterated over.
        queue.remove();
        //Change the current location to the location that is to
        //be checked next for further exploration.
        loc = queue.getFront();
        loc.start();
    }

    //If the start location is the end location, print solution as start
    //location.
    if(maze.isEndLocation(startLoc)){
        cout << "Solution found:" << endl;
        cout << startLoc << endl;
    }
    //If the end location is found, map each location's previous 
    //location to itself. This will make a new map where each location
    //maps to its next location. Once this is done, print out the new
    //map with the correct solution.
    else if(maze.isEndLocation(endLocation)){
        bool done = false;
        checkLocation = endLocation;
        cout << "Solution found:" << endl;
        lookAt = wordMap.find(checkLocation);
        //If the start location is the end location, print the start.
        if(maze.isEndLocation(startLoc)){
            cout << startLoc << endl;
        }
        else{
            while(!done){
                printMap[lookAt->second] = lookAt->first;
                checkLocation = wordMap[checkLocation];
                lookAt = wordMap.find(checkLocation);
                if(lookAt->second == startLoc){
                    done = true;
                    printMap[lookAt->second] = lookAt->first;
                }
            }
            
            cout << startLoc << endl;
            checkLocation = lookAt->second;
            done = false;
            
            if(wordMap[endLocation] == startLoc){
                done = true;
                cout << endLocation << endl;
            }
            else{
                while(!done){
                    cout << printMap[checkLocation] << endl;
                    checkLocation = printMap[checkLocation];
                    if(printMap[checkLocation] == endLocation){
                        done = true;
                        cout << endLocation << endl;
                    }
                }
            }
        }
    }
    //If the current location never reaches the end location
    //(meaning the queue is empty), print out no solution.
    else
        cout << "No solution found" << endl;
    
    return 0;
}